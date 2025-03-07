/*
 * Copyright (c) 2018 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#define DUMMY_DRIVER_NAME	"dummy_driver"

typedef int (*dummy_api_open_t)(const struct device *dev);

typedef int (*dummy_api_read_t)(const struct device *dev,
				     uint32_t *val);
typedef int (*dummy_api_write_t)(const struct device *dev,
				     uint32_t val);
typedef int (*dummy_api_close_t)(const struct device *dev);

struct dummy_driver_api {
	dummy_api_open_t open;
	dummy_api_read_t read;
	dummy_api_write_t write;
	dummy_api_close_t close;
};
