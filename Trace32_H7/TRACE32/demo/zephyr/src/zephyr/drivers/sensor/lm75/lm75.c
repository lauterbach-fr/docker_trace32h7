/*
 * Copyright (c) 2021 Leica Geosystems AG
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT lm75

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/pm/device.h>
#include <zephyr/pm/device_runtime.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(LM75, CONFIG_SENSOR_LOG_LEVEL);


#define LM75_REG_TEMP   0x00
#define LM75_REG_CONFIG 0x01
#define LM75_REG_T_HYST 0x02
#define LM75_REG_T_OS   0x03

struct lm75_data {
	int16_t temp; /*temp in 0.1°C*/
};

struct lm75_config {
	struct i2c_dt_spec i2c;
};

static inline int lm75_reg_read(const struct lm75_config *cfg, uint8_t reg,
				uint8_t *buf, uint32_t size)
{
	return i2c_burst_read_dt(&cfg->i2c, reg, buf, size);
}

static inline int lm75_fetch_temp(const struct lm75_config *cfg, struct lm75_data *data)
{
	int ret;
	uint8_t temp_read[2];
	int16_t temp;

	ret = lm75_reg_read(cfg, LM75_REG_TEMP, temp_read, sizeof(temp_read));
	if (ret) {
		LOG_ERR("Could not fetch temperature [%d]", ret);
		return -EIO;
	}

	/* temp is in two's complement.
	 *  bit 7 in the lower part corresponds to 0.5
	 */
	temp = temp_read[0] << 8 | temp_read[1];

	/* shift right by 7, multiply by 10 to get 0.1° and divide by 2 to get °C */
	data->temp = (temp / 128) * 10 / 2;

	return 0;
}

static int lm75_sample_fetch(const struct device *dev,
			     enum sensor_channel chan)
{
	struct lm75_data *data = dev->data;
	const struct lm75_config *cfg = dev->config;
	enum pm_device_state pm_state;
	int ret;

	(void)pm_device_state_get(dev, &pm_state);
	if (pm_state != PM_DEVICE_STATE_ACTIVE) {
		ret = -EIO;
		return ret;
	}

	switch (chan) {
	case SENSOR_CHAN_ALL:
	case SENSOR_CHAN_AMBIENT_TEMP:
		ret = lm75_fetch_temp(cfg, data);
		break;
	default:
		ret = -ENOTSUP;
		break;
	}

	return ret;
}

static int lm75_channel_get(const struct device *dev,
			    enum sensor_channel chan,
			    struct sensor_value *val)
{
	struct lm75_data *data = dev->data;

	switch (chan) {
	case SENSOR_CHAN_AMBIENT_TEMP:
		val->val1 = data->temp / 10;
		val->val2 = (data->temp - val->val1 * 10) * 100000U;
		return 0;
	default:
		return -ENOTSUP;
	}
}

static const struct sensor_driver_api lm75_driver_api = {
	.sample_fetch = lm75_sample_fetch,
	.channel_get = lm75_channel_get,
};

int lm75_init(const struct device *dev)
{
	const struct lm75_config *cfg = dev->config;
	int ret = 0;

	if (!device_is_ready(cfg->i2c.bus)) {
		LOG_ERR("I2C dev not ready");
		return -ENODEV;
	}

#ifdef CONFIG_PM_DEVICE_RUNTIME
	pm_device_init_suspended(dev);

	ret = pm_device_runtime_enable(dev);
	if (ret < 0 && ret != -ENOTSUP) {
		LOG_ERR("Failed to enable runtime power management");
		return ret;
	}
#endif

	return ret;
}

#ifdef CONFIG_PM_DEVICE

static int lm75_pm_action(const struct device *dev, enum pm_device_action action)
{
	switch (action) {
	case PM_DEVICE_ACTION_TURN_ON:
	case PM_DEVICE_ACTION_RESUME:
	case PM_DEVICE_ACTION_TURN_OFF:
	case PM_DEVICE_ACTION_SUSPEND:
		break;
	default:
		return -ENOTSUP;
	}

	return 0;
}

#endif

#define LM75_INST(inst)                                             \
static struct lm75_data lm75_data_##inst;                           \
static const struct lm75_config lm75_config_##inst = {              \
	.i2c = I2C_DT_SPEC_INST_GET(inst),                          \
};                                                                  \
PM_DEVICE_DT_INST_DEFINE(inst, lm75_pm_action);						\
SENSOR_DEVICE_DT_INST_DEFINE(inst, lm75_init, PM_DEVICE_DT_INST_GET(inst), &lm75_data_##inst,	\
		      &lm75_config_##inst, POST_KERNEL,             \
		      CONFIG_SENSOR_INIT_PRIORITY, &lm75_driver_api);

DT_INST_FOREACH_STATUS_OKAY(LM75_INST)
