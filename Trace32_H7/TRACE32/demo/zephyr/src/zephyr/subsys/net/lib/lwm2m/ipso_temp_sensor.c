/*
 * Copyright (c) 2017 Linaro Limited
 * Copyright (c) 2018-2019 Foundries.io
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * Source material for IPSO Temperature Sensor object (3303):
 * https://github.com/IPSO-Alliance/pub/blob/master/docs/IPSO-Smart-Objects.pdf
 * Section: "10. IPSO Object: Temperature"
 */

#define LOG_MODULE_NAME net_ipso_temp_sensor
#define LOG_LEVEL CONFIG_LWM2M_LOG_LEVEL

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(LOG_MODULE_NAME);

#include <stdint.h>
#include <zephyr/init.h>

#include "lwm2m_object.h"
#include "lwm2m_engine.h"
#include "lwm2m_resource_ids.h"

#define TEMP_VERSION_MAJOR 1

#if defined(CONFIG_LWM2M_IPSO_TEMP_SENSOR_VERSION_1_1)
#define TEMP_VERSION_MINOR 1
#define TEMP_MAX_ID 12
#else
#define TEMP_VERSION_MINOR 0
#define TEMP_MAX_ID 7
#endif /* defined(CONFIG_LWM2M_IPSO_TEMP_SENSOR_VERSION_1_1) */

#define MAX_INSTANCE_COUNT	CONFIG_LWM2M_IPSO_TEMP_SENSOR_INSTANCE_COUNT

#define UNIT_STR_MAX_SIZE	8

/*
 * Calculate resource instances as follows:
 * start with TEMP_MAX_ID
 * subtract EXEC resources (1)
 */
#define RESOURCE_INSTANCE_COUNT	(TEMP_MAX_ID - 1)

/* resource state variables */
static double sensor_value[MAX_INSTANCE_COUNT];
static char units[MAX_INSTANCE_COUNT][UNIT_STR_MAX_SIZE];
static double min_measured_value[MAX_INSTANCE_COUNT];
static double max_measured_value[MAX_INSTANCE_COUNT];
static double min_range_value[MAX_INSTANCE_COUNT];
static double max_range_value[MAX_INSTANCE_COUNT];

static struct lwm2m_engine_obj temp_sensor;
static struct lwm2m_engine_obj_field fields[] = {
	OBJ_FIELD_DATA(SENSOR_VALUE_RID, R, FLOAT),
	OBJ_FIELD_DATA(SENSOR_UNITS_RID, R_OPT, STRING),
	OBJ_FIELD_DATA(MIN_MEASURED_VALUE_RID, R_OPT, FLOAT),
	OBJ_FIELD_DATA(MAX_MEASURED_VALUE_RID, R_OPT, FLOAT),
	OBJ_FIELD_DATA(MIN_RANGE_VALUE_RID, R_OPT, FLOAT),
	OBJ_FIELD_DATA(MAX_RANGE_VALUE_RID, R_OPT, FLOAT),
	OBJ_FIELD_EXECUTE_OPT(RESET_MIN_MAX_MEASURED_VALUES_RID),
#if defined(CONFIG_LWM2M_IPSO_TEMP_SENSOR_VERSION_1_1)
	OBJ_FIELD_DATA(APPLICATION_TYPE_RID, RW_OPT, STRING),
	OBJ_FIELD_DATA(TIMESTAMP_RID, R_OPT, TIME),
	OBJ_FIELD_DATA(FRACTIONAL_TIMESTAMP_RID, R_OPT, FLOAT),
	OBJ_FIELD_DATA(MEASUREMENT_QUALITY_INDICATOR_RID, R_OPT, U8),
	OBJ_FIELD_DATA(MEASUREMENT_QUALITY_LEVEL_RID, R_OPT, U8),
#endif
};

static struct lwm2m_engine_obj_inst inst[MAX_INSTANCE_COUNT];
static struct lwm2m_engine_res res[MAX_INSTANCE_COUNT][TEMP_MAX_ID];
static struct lwm2m_engine_res_inst
		res_inst[MAX_INSTANCE_COUNT][RESOURCE_INSTANCE_COUNT];

static void update_min_measured(uint16_t obj_inst_id, int index)
{
	min_measured_value[index] = sensor_value[index];
	lwm2m_notify_observer(IPSO_OBJECT_TEMP_SENSOR_ID, obj_inst_id,
			MIN_MEASURED_VALUE_RID);
}

static void update_max_measured(uint16_t obj_inst_id, int index)
{
	max_measured_value[index] = sensor_value[index];
	lwm2m_notify_observer(IPSO_OBJECT_TEMP_SENSOR_ID, obj_inst_id,
			MAX_MEASURED_VALUE_RID);
}

static int reset_min_max_measured_values_cb(uint16_t obj_inst_id,
					    uint8_t *args, uint16_t args_len)
{
	int i;

	LOG_DBG("RESET MIN/MAX %d", obj_inst_id);
	for (i = 0; i < MAX_INSTANCE_COUNT; i++) {
		if (inst[i].obj && inst[i].obj_inst_id == obj_inst_id) {
			update_min_measured(obj_inst_id, i);
			update_max_measured(obj_inst_id, i);
			return 0;
		}
	}

	return -ENOENT;
}

static int sensor_value_write_cb(uint16_t obj_inst_id,
				 uint16_t res_id, uint16_t res_inst_id,
				 uint8_t *data, uint16_t data_len,
				 bool last_block, size_t total_size)
{
	int i;

	for (i = 0; i < MAX_INSTANCE_COUNT; i++) {
		if (inst[i].obj && inst[i].obj_inst_id == obj_inst_id) {
			/* update min / max */
			if (sensor_value[i] < min_measured_value[i]) {
				update_min_measured(obj_inst_id, i);
			}

			if (sensor_value[i] > max_measured_value[i]) {
				update_max_measured(obj_inst_id, i);
			}
		}
	}

	return 0;
}

static struct lwm2m_engine_obj_inst *temp_sensor_create(uint16_t obj_inst_id)
{
	int index, i = 0, j = 0;

	/* Check that there is no other instance with this ID */
	for (index = 0; index < MAX_INSTANCE_COUNT; index++) {
		if (inst[index].obj && inst[index].obj_inst_id == obj_inst_id) {
			LOG_ERR("Can not create instance - "
				"already existing: %u", obj_inst_id);
			return NULL;
		}
	}

	for (index = 0; index < MAX_INSTANCE_COUNT; index++) {
		if (!inst[index].obj) {
			break;
		}
	}

	if (index >= MAX_INSTANCE_COUNT) {
		LOG_ERR("Can not create instance - no more room: %u",
			obj_inst_id);
		return NULL;
	}

	/* Set default values */
	sensor_value[index] = 0;
	units[index][0] = '\0';
	min_measured_value[index] = INT32_MAX;
	max_measured_value[index] = -INT32_MAX;
	min_range_value[index] = 0;
	max_range_value[index] = 0;

	(void)memset(res[index], 0,
		     sizeof(res[index][0]) * ARRAY_SIZE(res[index]));
	init_res_instance(res_inst[index], ARRAY_SIZE(res_inst[index]));

	/* initialize instance resource data */
	INIT_OBJ_RES(SENSOR_VALUE_RID, res[index], i,
		     res_inst[index], j, 1, false, true,
		     &sensor_value[index], sizeof(*sensor_value),
		     NULL, NULL, NULL, sensor_value_write_cb, NULL);
	INIT_OBJ_RES_DATA_LEN(SENSOR_UNITS_RID, res[index], i, res_inst[index], j,
			  units[index], UNIT_STR_MAX_SIZE, 0);
	INIT_OBJ_RES_DATA(MIN_MEASURED_VALUE_RID, res[index], i,
			  res_inst[index], j, &min_measured_value[index],
			  sizeof(*min_measured_value));
	INIT_OBJ_RES_DATA(MAX_MEASURED_VALUE_RID, res[index], i,
			  res_inst[index], j, &max_measured_value[index],
			  sizeof(*max_measured_value));
	INIT_OBJ_RES_DATA(MIN_RANGE_VALUE_RID, res[index], i,
			  res_inst[index], j, &min_range_value[index],
			  sizeof(*min_range_value));
	INIT_OBJ_RES_DATA(MAX_RANGE_VALUE_RID, res[index], i,
			  res_inst[index], j, &max_range_value[index],
			  sizeof(*max_range_value));
	INIT_OBJ_RES_EXECUTE(RESET_MIN_MAX_MEASURED_VALUES_RID,
			     res[index], i, reset_min_max_measured_values_cb);
#if defined(CONFIG_LWM2M_IPSO_TEMP_SENSOR_VERSION_1_1)
	INIT_OBJ_RES_OPTDATA(APPLICATION_TYPE_RID, res[index], i,
			     res_inst[index], j);
	INIT_OBJ_RES_OPTDATA(TIMESTAMP_RID, res[index], i, res_inst[index], j);
	INIT_OBJ_RES_OPTDATA(FRACTIONAL_TIMESTAMP_RID, res[index], i,
			     res_inst[index], j);
	INIT_OBJ_RES_OPTDATA(MEASUREMENT_QUALITY_INDICATOR_RID, res[index],
			     i, res_inst[index], j);
	INIT_OBJ_RES_OPTDATA(MEASUREMENT_QUALITY_LEVEL_RID, res[index], i,
			     res_inst[index], j);
#endif

	inst[index].resources = res[index];
	inst[index].resource_count = i;
	LOG_DBG("Create IPSO Temperature Sensor instance: %d", obj_inst_id);
	return &inst[index];
}

static int ipso_temp_sensor_init(void)
{
	temp_sensor.obj_id = IPSO_OBJECT_TEMP_SENSOR_ID;
	temp_sensor.version_major = TEMP_VERSION_MAJOR;
	temp_sensor.version_minor = TEMP_VERSION_MINOR;
	temp_sensor.is_core = false;
	temp_sensor.fields = fields;
	temp_sensor.field_count = ARRAY_SIZE(fields);
	temp_sensor.max_instance_count = MAX_INSTANCE_COUNT;
	temp_sensor.create_cb = temp_sensor_create;
	lwm2m_register_obj(&temp_sensor);

	return 0;
}

LWM2M_OBJ_INIT(ipso_temp_sensor_init);
