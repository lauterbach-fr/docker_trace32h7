/*
 * Copyright (c) 2023 STMicroelectronics
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_ST_LIS2DH_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_ST_LIS2DH_H_

/* GPIO interrupt configuration */
#define LIS2DH_DT_GPIO_INT_EDGE				0
#define LIS2DH_DT_GPIO_INT_EDGE_RISING			1
#define LIS2DH_DT_GPIO_INT_EDGE_FALLING			2
#define LIS2DH_DT_GPIO_INT_LEVEL_HIGH			3
#define LIS2DH_DT_GPIO_INT_LEVEL_LOW			4

/* Any Motion mode */
#define LIS2DH_DT_ANYM_OR_COMBINATION			0
#define LIS2DH_DT_ANYM_6D_MOVEMENT			1
#define LIS2DH_DT_ANYM_AND_COMBINATION			2
#define LIS2DH_DT_ANYM_6D_POSITION			3

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_ST_LIS2DH_H_ */
