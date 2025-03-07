/*
 * Copyright (c) 2023 Benjamin Björnsson <benjamin.bjornsson@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_CLOCK_STM32C0_CLOCK_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_CLOCK_STM32C0_CLOCK_H_

#include "stm32_common_clocks.h"

/** Bus clocks */
#define STM32_CLOCK_BUS_IOP     0x034
#define STM32_CLOCK_BUS_AHB1    0x038
#define STM32_CLOCK_BUS_APB1    0x03c
#define STM32_CLOCK_BUS_APB1_2  0x040

#define STM32_PERIPH_BUS_MIN	STM32_CLOCK_BUS_IOP
#define STM32_PERIPH_BUS_MAX	STM32_CLOCK_BUS_APB1_2

/** Domain clocks */
/* RM0490, §5.4.21/22 Clock configuration register (RCC_CCIPRx) */

/** System clock */
/* defined in stm32_common_clocks.h */
/** Fixed clocks  */
/* Low speed clocks defined in stm32_common_clocks.h */
#define STM32_SRC_HSI48		(STM32_SRC_LSI + 1)
#define STM32_SRC_HSE		(STM32_SRC_HSI48 + 1)
/** Peripheral bus clock */
#define STM32_SRC_PCLK		(STM32_SRC_HSE + 1)

#define STM32_CLOCK_REG_MASK    0xFFU
#define STM32_CLOCK_REG_SHIFT   0U
#define STM32_CLOCK_SHIFT_MASK  0x1FU
#define STM32_CLOCK_SHIFT_SHIFT 8U
#define STM32_CLOCK_MASK_MASK   0x7U
#define STM32_CLOCK_MASK_SHIFT  13U
#define STM32_CLOCK_VAL_MASK    0x7U
#define STM32_CLOCK_VAL_SHIFT   16U

/**
 * @brief STM32 clock configuration bit field.
 *
 * - reg   (1/2/3)         [ 0 : 7 ]
 * - shift (0..31)         [ 8 : 12 ]
 * - mask  (0x1, 0x3, 0x7) [ 13 : 15 ]
 * - val   (0..7)          [ 16 : 18 ]
 *
 * @param reg RCC_CCIPRx register offset
 * @param shift Position within RCC_CCIPRx.
 * @param mask Mask for the RCC_CCIPRx field.
 * @param val Clock value (0, 1, ... 7).
 */
#define STM32_CLOCK(val, mask, shift, reg)					\
	((((reg) & STM32_CLOCK_REG_MASK) << STM32_CLOCK_REG_SHIFT) |		\
	 (((shift) & STM32_CLOCK_SHIFT_MASK) << STM32_CLOCK_SHIFT_SHIFT) |	\
	 (((mask) & STM32_CLOCK_MASK_MASK) << STM32_CLOCK_MASK_SHIFT) |		\
	 (((val) & STM32_CLOCK_VAL_MASK) << STM32_CLOCK_VAL_SHIFT))

/** @brief RCC_CCIPR register offset */
#define CCIPR_REG		0x54

/** @brief RCC_CSR1 register offset */
#define CSR1_REG		0x5C

/** @brief Device domain clocks selection helpers */
/** CCIPR devices */
#define USART1_SEL(val)		STM32_CLOCK(val, 3, 0, CCIPR_REG)
#define I2C1_SEL(val)		STM32_CLOCK(val, 3, 12, CCIPR_REG)
#define I2C2_I2S1_SEL(val)	STM32_CLOCK(val, 3, 14, CCIPR_REG)
#define ADC_SEL(val)		STM32_CLOCK(val, 3, 30, CCIPR_REG)
/** CSR1 devices */
#define RTC_SEL(val)		STM32_CLOCK(val, 3, 8, CSR1_REG)

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_CLOCK_STM32C0_CLOCK_H_ */
