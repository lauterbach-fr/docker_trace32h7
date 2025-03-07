/*
 * Copyright (c) 2023 STMicroelectronics
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_ST_ISM330DHCX_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_ST_ISM330DHCX_H_

/* Accel and Gyro Data rates */
#define ISM330DHCX_DT_ODR_OFF			0x0
#define ISM330DHCX_DT_ODR_12Hz5			0x1
#define ISM330DHCX_DT_ODR_26H			0x2
#define ISM330DHCX_DT_ODR_52Hz			0x3
#define ISM330DHCX_DT_ODR_104Hz			0x4
#define ISM330DHCX_DT_ODR_208Hz			0x5
#define ISM330DHCX_DT_ODR_416Hz			0x6
#define ISM330DHCX_DT_ODR_833Hz			0x7
#define ISM330DHCX_DT_ODR_1666Hz		0x8
#define ISM330DHCX_DT_ODR_3332Hz		0x9
#define ISM330DHCX_DT_ODR_6667Hz		0xa
#define ISM330DHCX_DT_ODR_1Hz6			0xb

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_ST_ISM330DHCX_H_ */
