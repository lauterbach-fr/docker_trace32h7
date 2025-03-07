/*
 * Copyright (c) 2023 Espressif Systems (Shanghai) Co., Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_INPUT_ESP32_TOUCH_SENSOR_INPUT_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_INPUT_ESP32_TOUCH_SENSOR_INPUT_H_

#include <zephyr/dt-bindings/dt-util.h>

/* Touch sensor IIR filter mode */
#define ESP32_TOUCH_FILTER_MODE_IIR_4		0
#define ESP32_TOUCH_FILTER_MODE_IIR_8		1
#define ESP32_TOUCH_FILTER_MODE_IIR_16		2
#define ESP32_TOUCH_FILTER_MODE_IIR_32		3
#define ESP32_TOUCH_FILTER_MODE_IIR_64		4
#define ESP32_TOUCH_FILTER_MODE_IIR_128		5
#define ESP32_TOUCH_FILTER_MODE_IIR_256		6
#define ESP32_TOUCH_FILTER_MODE_JITTER		7

/* Touch sensor level of filter noise threshold coefficient*/
#define ESP32_TOUCH_FILTER_NOISE_THR_4_8TH	0
#define ESP32_TOUCH_FILTER_NOISE_THR_3_8TH	1
#define ESP32_TOUCH_FILTER_NOISE_THR_2_8TH	2
#define ESP32_TOUCH_FILTER_NOISE_THR_8_8TH	3

/* Touch sensor level of filter applied on the original data */
#define ESP32_TOUCH_FILTER_SMOOTH_MODE_OFF	0
#define ESP32_TOUCH_FILTER_SMOOTH_MODE_IIR_2	1
#define ESP32_TOUCH_FILTER_SMOOTH_MODE_IIR_4	2
#define ESP32_TOUCH_FILTER_SMOOTH_MODE_IIR_8	3

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_INPUT_ESP32_TOUCH_SENSOR_INPUT_H_ */
