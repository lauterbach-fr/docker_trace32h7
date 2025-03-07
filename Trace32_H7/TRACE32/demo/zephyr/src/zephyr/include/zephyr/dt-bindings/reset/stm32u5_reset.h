/*
 * Copyright (c) 2022 Google Inc
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_RESET_STM32U5_RESET_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_RESET_STM32U5_RESET_H_

#include "stm32-common.h"

/* RCC bus reset register offset */
#define STM32_RESET_BUS_AHB1  0x60
#define STM32_RESET_BUS_AHB2L 0x64
#define STM32_RESET_BUS_AHB2H 0x68
#define STM32_RESET_BUS_AHB3  0x6C
#define STM32_RESET_BUS_APB1L 0x74
#define STM32_RESET_BUS_APB1H 0x78
#define STM32_RESET_BUS_APB2  0x7C
#define STM32_RESET_BUS_APB3  0x80

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_RESET_STM32U5_RESET_H_ */
