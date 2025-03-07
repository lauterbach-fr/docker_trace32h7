/*
 * Copyright (c) 2023 STMicroelectronics
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_ST_IIS2DLPC_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_ST_IIS2DLPC_H_

/* power-modes */
#define IIS2DLPC_DT_LP_M1			0
#define IIS2DLPC_DT_LP_M2			1
#define IIS2DLPC_DT_LP_M3			2
#define IIS2DLPC_DT_LP_M4			3
#define IIS2DLPC_DT_HP_MODE			4

/* Filter bandwidth */
#define IIS2DLPC_DT_FILTER_BW_ODR_DIV_2		0
#define IIS2DLPC_DT_FILTER_BW_ODR_DIV_4		1
#define IIS2DLPC_DT_FILTER_BW_ODR_DIV_10	2
#define IIS2DLPC_DT_FILTER_BW_ODR_DIV_20	3

/* Tap mode */
#define IIS2DLPC_DT_SINGLE_TAP			0
#define IIS2DLPC_DT_SINGLE_DOUBLE_TAP		1

/* Free-Fall threshold */
#define IIS2DLPC_DT_FF_THRESHOLD_156_mg		0
#define IIS2DLPC_DT_FF_THRESHOLD_219_mg		1
#define IIS2DLPC_DT_FF_THRESHOLD_250_mg		2
#define IIS2DLPC_DT_FF_THRESHOLD_312_mg		3
#define IIS2DLPC_DT_FF_THRESHOLD_344_mg		4
#define IIS2DLPC_DT_FF_THRESHOLD_406_mg		5
#define IIS2DLPC_DT_FF_THRESHOLD_469_mg		6
#define IIS2DLPC_DT_FF_THRESHOLD_500_mg		7

/* wakeup duration */
#define IIS2DLPC_DT_WAKEUP_1_ODR		0
#define IIS2DLPC_DT_WAKEUP_2_ODR		1
#define IIS2DLPC_DT_WAKEUP_3_ODR		2
#define IIS2DLPC_DT_WAKEUP_4_ODR		3

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_ST_IIS2DLPC_H_ */
