/* adxl367_spi.c - SPI routines for ADXL367 driver
 */

/*
 * Copyright (c) 2023 Analog Devices
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT adi_adxl367

#include <string.h>
#include <zephyr/logging/log.h>

#include "adxl367.h"

#if DT_ANY_INST_ON_BUS_STATUS_OKAY(spi)

LOG_MODULE_DECLARE(ADXL367, CONFIG_SENSOR_LOG_LEVEL);

static int adxl367_bus_access(const struct device *dev, uint8_t reg,
			      void *data, size_t length)
{
	const struct adxl367_dev_config *config = dev->config;
	uint8_t rw_reg, addr_reg;

	if ((reg & ADXL367_READ) != 0) {
		rw_reg = ADXL367_SPI_READ_REG;
	} else {
		rw_reg = ADXL367_SPI_WRITE_REG;
	}

	addr_reg = ADXL367_TO_REG(reg);

	const struct spi_buf buf[3] = {
		{
			.buf = &rw_reg,
			.len = 1
		}, {
			.buf = &addr_reg,
			.len = 1
		}, {
			.buf = data,
			.len = length
		}
	};

	struct spi_buf_set tx = {
		.buffers = buf,
	};

	if ((reg & ADXL367_READ) != 0) {
		const struct spi_buf_set rx = {
			.buffers = buf,
			.count = 3
		};

		tx.count = 2;

		return spi_transceive_dt(&config->spi, &tx, &rx);
	}

	tx.count = 3;

	return spi_write_dt(&config->spi, &tx);
}

static int adxl367_spi_reg_read(const struct device *dev, uint8_t reg_addr,
			    uint8_t *reg_data)
{
	return adxl367_bus_access(dev, ADXL367_REG_READ(reg_addr), reg_data, 1);
}

static int adxl367_spi_reg_read_multiple(const struct device *dev,
					 uint8_t reg_addr,
					 uint8_t *reg_data,
					 uint16_t count)
{
	return adxl367_bus_access(dev, ADXL367_REG_READ(reg_addr),
				  reg_data, count);
}

static int adxl367_spi_reg_write(const struct device *dev,
				 uint8_t reg_addr,
				 uint8_t reg_data)
{
	return adxl367_bus_access(dev, ADXL367_REG_WRITE(reg_addr),
				  &reg_data, 1);
}

int adxl367_spi_reg_write_mask(const struct device *dev,
			       uint8_t reg_addr,
			       uint32_t mask,
			       uint8_t data)
{
	int ret;
	uint8_t tmp;

	ret = adxl367_spi_reg_read(dev, reg_addr, &tmp);
	if (ret != 0) {
		return ret;
	}

	tmp &= ~mask;
	tmp |= data;

	return adxl367_spi_reg_write(dev, reg_addr, tmp);
}

static const struct adxl367_transfer_function adxl367_spi_transfer_fn = {
	.read_reg_multiple = adxl367_spi_reg_read_multiple,
	.write_reg = adxl367_spi_reg_write,
	.read_reg = adxl367_spi_reg_read,
	.write_reg_mask = adxl367_spi_reg_write_mask,
};

int adxl367_spi_init(const struct device *dev)
{
	struct adxl367_data *data = dev->data;
	const struct adxl367_dev_config *config = dev->config;

	data->hw_tf = &adxl367_spi_transfer_fn;

	if (!spi_is_ready_dt(&config->spi)) {
		return -ENODEV;
	}

	return 0;
}

#endif /* DT_ANY_INST_ON_BUS_STATUS_OKAY(spi) */
