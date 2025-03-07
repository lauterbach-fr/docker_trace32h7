/*
 * Copyright (c) 2017 Jan Van Winkel <jan.van_winkel@dxplore.eu>
 * Copyright (c) 2019 Nordic Semiconductor ASA
 * Copyright (c) 2020 Teslabs Engineering S.L.
 * Copyright (c) 2021 Krivorot Oleg <krivorot.oleg@gmail.com>
 * SPDX-License-Identifier: Apache-2.0
 */

#include "display_ili9xxx.h"

#include <zephyr/dt-bindings/display/ili9xxx.h>
#include <zephyr/drivers/display.h>
#include <zephyr/sys/byteorder.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(display_ili9xxx, CONFIG_DISPLAY_LOG_LEVEL);

struct ili9xxx_data {
	uint8_t bytes_per_pixel;
	enum display_pixel_format pixel_format;
	enum display_orientation orientation;
};

int ili9xxx_transmit(const struct device *dev, uint8_t cmd, const void *tx_data,
		     size_t tx_len)
{
	const struct ili9xxx_config *config = dev->config;

	return mipi_dbi_command_write(config->mipi_dev, &config->dbi_config,
				      cmd, tx_data, tx_len);
}

static int ili9xxx_exit_sleep(const struct device *dev)
{
	int r;

	r = ili9xxx_transmit(dev, ILI9XXX_SLPOUT, NULL, 0);
	if (r < 0) {
		return r;
	}

	k_sleep(K_MSEC(ILI9XXX_SLEEP_OUT_TIME));

	return 0;
}

static void ili9xxx_hw_reset(const struct device *dev)
{
	const struct ili9xxx_config *config = dev->config;

	if (mipi_dbi_reset(config->mipi_dev, ILI9XXX_RESET_PULSE_TIME) < 0) {
		return;
	};
	k_sleep(K_MSEC(ILI9XXX_RESET_WAIT_TIME));
}

static int ili9xxx_set_mem_area(const struct device *dev, const uint16_t x,
				const uint16_t y, const uint16_t w,
				const uint16_t h)
{
	int r;
	uint16_t spi_data[2];

	spi_data[0] = sys_cpu_to_be16(x);
	spi_data[1] = sys_cpu_to_be16(x + w - 1U);
	r = ili9xxx_transmit(dev, ILI9XXX_CASET, &spi_data[0], 4U);
	if (r < 0) {
		return r;
	}

	spi_data[0] = sys_cpu_to_be16(y);
	spi_data[1] = sys_cpu_to_be16(y + h - 1U);
	r = ili9xxx_transmit(dev, ILI9XXX_PASET, &spi_data[0], 4U);
	if (r < 0) {
		return r;
	}

	return 0;
}

static int ili9xxx_write(const struct device *dev, const uint16_t x,
			 const uint16_t y,
			 const struct display_buffer_descriptor *desc,
			 const void *buf)
{
	const struct ili9xxx_config *config = dev->config;
	struct ili9xxx_data *data = dev->data;
	struct display_buffer_descriptor mipi_desc;

	int r;
	const uint8_t *write_data_start = (const uint8_t *)buf;
	uint16_t write_cnt;
	uint16_t nbr_of_writes;
	uint16_t write_h;

	__ASSERT(desc->width <= desc->pitch, "Pitch is smaller than width");
	__ASSERT((desc->pitch * data->bytes_per_pixel * desc->height) <=
			 desc->buf_size,
		 "Input buffer to small");

	LOG_DBG("Writing %dx%d (w,h) @ %dx%d (x,y)", desc->width, desc->height,
		x, y);
	r = ili9xxx_set_mem_area(dev, x, y, desc->width, desc->height);
	if (r < 0) {
		return r;
	}

	if (desc->pitch > desc->width) {
		write_h = 1U;
		nbr_of_writes = desc->height;
		mipi_desc.height = 1;
		mipi_desc.buf_size = desc->pitch * data->bytes_per_pixel;
	} else {
		write_h = desc->height;
		mipi_desc.height = desc->height;
		mipi_desc.buf_size = desc->width * data->bytes_per_pixel * write_h;
		nbr_of_writes = 1U;
	}

	mipi_desc.width = desc->width;
	/* Per MIPI API, pitch must always match width */
	mipi_desc.pitch = desc->width;

	r = ili9xxx_transmit(dev, ILI9XXX_RAMWR, NULL, 0);
	if (r < 0) {
		return r;
	}

	for (write_cnt = 0U; write_cnt < nbr_of_writes; ++write_cnt) {
		r = mipi_dbi_write_display(config->mipi_dev,
					   &config->dbi_config,
					   write_data_start,
					   &mipi_desc,
					   data->pixel_format);
		if (r < 0) {
			return r;
		}

		write_data_start += desc->pitch * data->bytes_per_pixel;
	}

	return 0;
}

static int ili9xxx_display_blanking_off(const struct device *dev)
{
	LOG_DBG("Turning display blanking off");
	return ili9xxx_transmit(dev, ILI9XXX_DISPON, NULL, 0);
}

static int ili9xxx_display_blanking_on(const struct device *dev)
{
	LOG_DBG("Turning display blanking on");
	return ili9xxx_transmit(dev, ILI9XXX_DISPOFF, NULL, 0);
}

static int
ili9xxx_set_pixel_format(const struct device *dev,
			 const enum display_pixel_format pixel_format)
{
	struct ili9xxx_data *data = dev->data;

	int r;
	uint8_t tx_data;
	uint8_t bytes_per_pixel;

	if (pixel_format == PIXEL_FORMAT_RGB_565) {
		bytes_per_pixel = 2U;
		tx_data = ILI9XXX_PIXSET_MCU_16_BIT | ILI9XXX_PIXSET_RGB_16_BIT;
	} else if (pixel_format == PIXEL_FORMAT_RGB_888) {
		bytes_per_pixel = 3U;
		tx_data = ILI9XXX_PIXSET_MCU_18_BIT | ILI9XXX_PIXSET_RGB_18_BIT;
	} else {
		LOG_ERR("Unsupported pixel format");
		return -ENOTSUP;
	}

	r = ili9xxx_transmit(dev, ILI9XXX_PIXSET, &tx_data, 1U);
	if (r < 0) {
		return r;
	}

	data->pixel_format = pixel_format;
	data->bytes_per_pixel = bytes_per_pixel;

	return 0;
}

static int ili9xxx_set_orientation(const struct device *dev,
				   const enum display_orientation orientation)
{
	const struct ili9xxx_config *config = dev->config;
	struct ili9xxx_data *data = dev->data;

	int r;
	uint8_t tx_data = ILI9XXX_MADCTL_BGR;
	if (config->quirks->cmd_set == CMD_SET_1) {
		if (orientation == DISPLAY_ORIENTATION_NORMAL) {
			tx_data |= ILI9XXX_MADCTL_MX;
		} else if (orientation == DISPLAY_ORIENTATION_ROTATED_90) {
			tx_data |= ILI9XXX_MADCTL_MV;
		} else if (orientation == DISPLAY_ORIENTATION_ROTATED_180) {
			tx_data |= ILI9XXX_MADCTL_MY;
		} else if (orientation == DISPLAY_ORIENTATION_ROTATED_270) {
			tx_data |= ILI9XXX_MADCTL_MV | ILI9XXX_MADCTL_MX |
				   ILI9XXX_MADCTL_MY;
		}
	} else if (config->quirks->cmd_set == CMD_SET_2) {
		if (orientation == DISPLAY_ORIENTATION_NORMAL) {
			/* Do nothing */
		} else if (orientation == DISPLAY_ORIENTATION_ROTATED_90) {
			tx_data |= ILI9XXX_MADCTL_MV | ILI9XXX_MADCTL_MY;
		} else if (orientation == DISPLAY_ORIENTATION_ROTATED_180) {
			tx_data |= ILI9XXX_MADCTL_MY | ILI9XXX_MADCTL_MX;
		} else if (orientation == DISPLAY_ORIENTATION_ROTATED_270) {
			tx_data |= ILI9XXX_MADCTL_MV | ILI9XXX_MADCTL_MX;
		}
	}

	r = ili9xxx_transmit(dev, ILI9XXX_MADCTL, &tx_data, 1U);
	if (r < 0) {
		return r;
	}

	data->orientation = orientation;

	return 0;
}

static void ili9xxx_get_capabilities(const struct device *dev,
				     struct display_capabilities *capabilities)
{
	struct ili9xxx_data *data = dev->data;
	const struct ili9xxx_config *config = dev->config;

	memset(capabilities, 0, sizeof(struct display_capabilities));

	capabilities->supported_pixel_formats =
		PIXEL_FORMAT_RGB_565 | PIXEL_FORMAT_RGB_888;
	capabilities->current_pixel_format = data->pixel_format;

	if (data->orientation == DISPLAY_ORIENTATION_NORMAL ||
	    data->orientation == DISPLAY_ORIENTATION_ROTATED_180) {
		capabilities->x_resolution = config->x_resolution;
		capabilities->y_resolution = config->y_resolution;
	} else {
		capabilities->x_resolution = config->y_resolution;
		capabilities->y_resolution = config->x_resolution;
	}

	capabilities->current_orientation = data->orientation;
}

static int ili9xxx_configure(const struct device *dev)
{
	const struct ili9xxx_config *config = dev->config;

	int r;
	enum display_pixel_format pixel_format;
	enum display_orientation orientation;

	/* pixel format */
	if (config->pixel_format == ILI9XXX_PIXEL_FORMAT_RGB565) {
		pixel_format = PIXEL_FORMAT_RGB_565;
	} else {
		pixel_format = PIXEL_FORMAT_RGB_888;
	}

	r = ili9xxx_set_pixel_format(dev, pixel_format);
	if (r < 0) {
		return r;
	}

	/* orientation */
	if (config->rotation == 0U) {
		orientation = DISPLAY_ORIENTATION_NORMAL;
	} else if (config->rotation == 90U) {
		orientation = DISPLAY_ORIENTATION_ROTATED_90;
	} else if (config->rotation == 180U) {
		orientation = DISPLAY_ORIENTATION_ROTATED_180;
	} else {
		orientation = DISPLAY_ORIENTATION_ROTATED_270;
	}

	r = ili9xxx_set_orientation(dev, orientation);
	if (r < 0) {
		return r;
	}

	if (config->inversion) {
		r = ili9xxx_transmit(dev, ILI9XXX_DINVON, NULL, 0U);
		if (r < 0) {
			return r;
		}
	}

	r = config->regs_init_fn(dev);
	if (r < 0) {
		return r;
	}

	return 0;
}

static int ili9xxx_init(const struct device *dev)
{
	const struct ili9xxx_config *config = dev->config;

	int r;

	if (!device_is_ready(config->mipi_dev)) {
		LOG_ERR("MIPI DBI device is not ready");
		return -ENODEV;
	}

	ili9xxx_hw_reset(dev);

	r = ili9xxx_transmit(dev, ILI9XXX_SWRESET, NULL, 0);
	if (r < 0) {
		LOG_ERR("Error transmit command Software Reset (%d)", r);
		return r;
	}

	k_sleep(K_MSEC(ILI9XXX_RESET_WAIT_TIME));

	ili9xxx_display_blanking_on(dev);

	r = ili9xxx_configure(dev);
	if (r < 0) {
		LOG_ERR("Could not configure display (%d)", r);
		return r;
	}

	r = ili9xxx_exit_sleep(dev);
	if (r < 0) {
		LOG_ERR("Could not exit sleep mode (%d)", r);
		return r;
	}

	return 0;
}

static const struct display_driver_api ili9xxx_api = {
	.blanking_on = ili9xxx_display_blanking_on,
	.blanking_off = ili9xxx_display_blanking_off,
	.write = ili9xxx_write,
	.get_capabilities = ili9xxx_get_capabilities,
	.set_pixel_format = ili9xxx_set_pixel_format,
	.set_orientation = ili9xxx_set_orientation,
};

#ifdef CONFIG_ILI9340
static const struct ili9xxx_quirks ili9340_quirks = {
	.cmd_set = CMD_SET_1,
};
#endif

#ifdef CONFIG_ILI9341
static const struct ili9xxx_quirks ili9341_quirks = {
	.cmd_set = CMD_SET_1,
};
#endif

#ifdef CONFIG_ILI9342C
static const struct ili9xxx_quirks ili9342c_quirks = {
	.cmd_set = CMD_SET_2,
};
#endif

#ifdef CONFIG_ILI9488
static const struct ili9xxx_quirks ili9488_quirks = {
	.cmd_set = CMD_SET_1,
};
#endif

#define INST_DT_ILI9XXX(n, t) DT_INST(n, ilitek_ili##t)

#define ILI9XXX_INIT(n, t)                                                     \
	ILI##t##_REGS_INIT(n);                                                 \
									       \
	static const struct ili9xxx_config ili9xxx_config_##n = {              \
		.quirks = &ili##t##_quirks,                                    \
		.mipi_dev = DEVICE_DT_GET(DT_PARENT(INST_DT_ILI9XXX(n, t))),   \
		.dbi_config = {                                                \
			.mode = MIPI_DBI_MODE_SPI_4WIRE,                       \
			.config = MIPI_DBI_SPI_CONFIG_DT(                      \
						INST_DT_ILI9XXX(n, t),         \
						SPI_OP_MODE_MASTER |           \
						SPI_WORD_SET(8),               \
						0),                            \
		},                                                             \
		.pixel_format = DT_PROP(INST_DT_ILI9XXX(n, t), pixel_format),  \
		.rotation = DT_PROP(INST_DT_ILI9XXX(n, t), rotation),          \
		.x_resolution = ILI##t##_X_RES,                                \
		.y_resolution = ILI##t##_Y_RES,                                \
		.inversion = DT_PROP(INST_DT_ILI9XXX(n, t), display_inversion),\
		.regs = &ili9xxx_regs_##n,                                     \
		.regs_init_fn = ili##t##_regs_init,                            \
	};                                                                     \
									       \
	static struct ili9xxx_data ili9xxx_data_##n;                           \
									       \
	DEVICE_DT_DEFINE(INST_DT_ILI9XXX(n, t), ili9xxx_init,                  \
			    NULL, &ili9xxx_data_##n,                           \
			    &ili9xxx_config_##n, POST_KERNEL,                  \
			    CONFIG_DISPLAY_INIT_PRIORITY, &ili9xxx_api)

#define DT_INST_FOREACH_ILI9XXX_STATUS_OKAY(t)                                 \
	LISTIFY(DT_NUM_INST_STATUS_OKAY(ilitek_ili##t), ILI9XXX_INIT, (;), t)

#ifdef CONFIG_ILI9340
#include "display_ili9340.h"
DT_INST_FOREACH_ILI9XXX_STATUS_OKAY(9340);
#endif

#ifdef CONFIG_ILI9341
#include "display_ili9341.h"
DT_INST_FOREACH_ILI9XXX_STATUS_OKAY(9341);
#endif

#ifdef CONFIG_ILI9342C
#include "display_ili9342c.h"
DT_INST_FOREACH_ILI9XXX_STATUS_OKAY(9342c);
#endif

#ifdef CONFIG_ILI9488
#include "display_ili9488.h"
DT_INST_FOREACH_ILI9XXX_STATUS_OKAY(9488);
#endif
