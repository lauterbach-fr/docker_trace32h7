/*
 * Copyright (c) 2020 Seagate Technology LLC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_LPC11U6X_PINCTRL_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_LPC11U6X_PINCTRL_H_

/**
 * @brief Pin control register for standard digital I/O pins:
 *
 * [0:2]   function.
 * [3:4]   mode.
 * [5]     hysteresis.
 * [6]     invert input.
 * [7:9]   reserved.
 * [10]    open-drain mode.
 * [11:12] digital filter sample mode.
 * [13:15] clock divisor.
 * [16:31] reserved.
 */

/**
 * @brief Control registers for digital/analog I/O pins:
 *
 * [0:2]   function.
 * [3:4]   mode.
 * [5]     hysteresis.
 * [6]     invert input.
 * [7]     analog mode.
 * [8]     input glitch filter.
 * [9]     reserved.
 * [10]    open-drain mode.
 * [11:12] digital filter sample mode.
 * [13:15] clock divisor.
 * [16:31] reserved.
 */

/**
 * @brief Control registers for open-drain I/O pins (I2C):
 *
 * [0:2]   function.
 * [3:7]   reserved.
 * [8:9]   I2C mode.
 * [10]    reserved.
 * [11:12] digital filter sample mode.
 * [13:15] clock divisor.
 * [16:31] reserved.
 */

#define IOCON_FUNC0 0
#define IOCON_FUNC1 1
#define IOCON_FUNC2 2
#define IOCON_FUNC3 3
#define IOCON_FUNC4 4
#define IOCON_FUNC5 5

#define IOCON_MODE_INACT	(0 << 3) /* No pull resistor. */
#define IOCON_MODE_PULLDOWN	(1 << 3) /* Enable pull-down resistor. */
#define IOCON_MODE_PULLUP	(2 << 3) /* Enable Pull-up resistor. */
#define IOCON_MODE_REPEATER	(3 << 3) /* Repeater mode. */

#define IOCON_HYS_EN		(1 << 5) /* Enable hysteresis. */

#define IOCON_INV_EN		(1 << 6) /* Invert input polarity. */

/* Only for analog pins. */
#define IOCON_ADMODE_EN		(0 << 7) /* Enable analog input mode. */
#define IOCON_DIGMODE_EN	(1 << 7) /* Enable digital I/O mode. */
#define IOCON_FILTR_DIS		(1 << 8) /* Disable noise filtering. */

/* Only for open-drain pins (I2C). */
#define IOCON_SFI2C_EN		(0 << 8) /* I2C standard mode / Fast-mode. */
#define IOCON_STDI2C_EN		(1 << 8) /* GPIO functionality. */
#define IOCON_FASTI2C_EN	(2 << 8) /* I2C Fast-mode Plus. */

#define IOCON_OPENDRAIN_EN	(1 << 10) /* Enable open-drain mode. */

/*
 * The digital filter mode allows to discard input pulses shorter than
 * 1, 2 or 3 clock cycles.
 */
#define IOCON_S_MODE_0CLK       (0 << 11) /* No input filter. */
#define IOCON_S_MODE_1CLK       (1 << 11)
#define IOCON_S_MODE_2CLK       (2 << 11)
#define IOCON_S_MODE_3CLK       (3 << 11)

/*
 * Clock divisor.
 */
#define IOCON_CLKDIV0		(0 << 13)
#define IOCON_CLKDIV1		(1 << 13)
#define IOCON_CLKDIV2		(2 << 13)
#define IOCON_CLKDIV3		(3 << 13)
#define IOCON_CLKDIV4		(4 << 13)
#define IOCON_CLKDIV5		(5 << 13)
#define IOCON_CLKDIV6		(6 << 13)


/*
 * Pin control definitions used by LPC pin control driver to make pinmux
 * selections.
 */

#define IOCON_MUX(offset, type, mux)		\
	(((offset & 0xFFF) << 20) |		\
	(((type) & 0x3) << 18) |		\
	(((mux) & 0xF) << 0))

#define IOCON_TYPE_D 0x0
#define IOCON_TYPE_I 0x1
#define IOCON_TYPE_A 0x2

#define RESET_PIO0_0 IOCON_MUX(0, IOCON_TYPE_D, 0) /* PIO0_0 */
#define PIO0_0_PIO0_0 IOCON_MUX(0, IOCON_TYPE_D, 1) /* PIO0_0 */
#define PIO0_1_PIO0_1 IOCON_MUX(1, IOCON_TYPE_D, 0) /* PIO0_1 */
#define CLKOUT_PIO0_1 IOCON_MUX(1, IOCON_TYPE_D, 1) /* PIO0_1 */
#define CT32B0_MAT2_PIO0_1 IOCON_MUX(1, IOCON_TYPE_D, 2) /* PIO0_1 */
#define USB_FTOGGLE_PIO0_1 IOCON_MUX(1, IOCON_TYPE_D, 3) /* PIO0_1 */
#define PIO0_2_PIO0_2 IOCON_MUX(2, IOCON_TYPE_D, 0) /* PIO0_2 */
#define SSP0_SSEL_PIO0_2 IOCON_MUX(2, IOCON_TYPE_D, 1) /* PIO0_2 */
#define CT16B0_CAP0_PIO0_2 IOCON_MUX(2, IOCON_TYPE_D, 2) /* PIO0_2 */
#define R_0_PIO0_2 IOCON_MUX(2, IOCON_TYPE_D, 3) /* PIO0_2 */
#define PIO0_3_PIO0_3 IOCON_MUX(3, IOCON_TYPE_D, 0) /* PIO0_3 */
#define USB_VBUS_PIO0_3 IOCON_MUX(3, IOCON_TYPE_D, 1) /* PIO0_3 */
#define R_1_PIO0_3 IOCON_MUX(3, IOCON_TYPE_D, 2) /* PIO0_3 */
#define PIO0_4_PIO0_4 IOCON_MUX(4, IOCON_TYPE_I, 0) /* PIO0_4 */
#define I2C0_SCL_PIO0_4 IOCON_MUX(4, IOCON_TYPE_I, 1) /* PIO0_4 */
#define R_2_PIO0_4 IOCON_MUX(4, IOCON_TYPE_I, 2) /* PIO0_4 */
#define PIO0_5_PIO0_5 IOCON_MUX(5, IOCON_TYPE_I, 0) /* PIO0_5 */
#define I2C0_SDA_PIO0_5 IOCON_MUX(5, IOCON_TYPE_I, 1) /* PIO0_5 */
#define R_3_PIO0_5 IOCON_MUX(5, IOCON_TYPE_I, 2) /* PIO0_5 */
#define PIO0_6_PIO0_6 IOCON_MUX(6, IOCON_TYPE_D, 0) /* PIO0_6 */
#define R_PIO0_6 IOCON_MUX(6, IOCON_TYPE_D, 1) /* PIO0_6 */
#define SSP0_SCK_PIO0_6 IOCON_MUX(6, IOCON_TYPE_D, 2) /* PIO0_6 */
#define R_4_PIO0_6 IOCON_MUX(6, IOCON_TYPE_D, 3) /* PIO0_6 */
#define PIO0_7_PIO0_7 IOCON_MUX(7, IOCON_TYPE_D, 0) /* PIO0_7 */
#define U0_CTS_PIO0_7 IOCON_MUX(7, IOCON_TYPE_D, 1) /* PIO0_7 */
#define R_5_PIO0_7 IOCON_MUX(7, IOCON_TYPE_D, 2) /* PIO0_7 */
#define I2C1_SCL_PIO0_7 IOCON_MUX(7, IOCON_TYPE_D, 3) /* PIO0_7 */
#define PIO0_8_PIO0_8 IOCON_MUX(8, IOCON_TYPE_D, 0) /* PIO0_8 */
#define SSP0_MISO_PIO0_8 IOCON_MUX(8, IOCON_TYPE_D, 1) /* PIO0_8 */
#define CT16B0_MAT0_PIO0_8 IOCON_MUX(8, IOCON_TYPE_D, 2) /* PIO0_8 */
#define R_6_PIO0_8 IOCON_MUX(8, IOCON_TYPE_D, 3) /* PIO0_8 */
#define PIO0_9_PIO0_9 IOCON_MUX(9, IOCON_TYPE_D, 0) /* PIO0_9 */
#define SSP0_MOSI_PIO0_9 IOCON_MUX(9, IOCON_TYPE_D, 1) /* PIO0_9 */
#define CT16B0_MAT1_PIO0_9 IOCON_MUX(9, IOCON_TYPE_D, 2) /* PIO0_9 */
#define R_7_PIO0_9 IOCON_MUX(9, IOCON_TYPE_D, 3) /* PIO0_9 */
#define SWCLK_PIO0_10 IOCON_MUX(10, IOCON_TYPE_D, 0) /* PIO0_10 */
#define PIO0_10_PIO0_10 IOCON_MUX(10, IOCON_TYPE_D, 1) /* PIO0_10 */
#define SSP0_SCK_PIO0_10 IOCON_MUX(10, IOCON_TYPE_D, 2) /* PIO0_10 */
#define CT16B0_MAT2_PIO0_10 IOCON_MUX(10, IOCON_TYPE_D, 3) /* PIO0_10 */
#define TDI_PIO0_11 IOCON_MUX(11, IOCON_TYPE_A, 0) /* PIO0_11 */
#define PIO0_11_PIO0_11 IOCON_MUX(11, IOCON_TYPE_A, 1) /* PIO0_11 */
#define ADC_9_PIO0_11 IOCON_MUX(11, IOCON_TYPE_A, 2) /* PIO0_11 */
#define CT32B0_MAT3_PIO0_11 IOCON_MUX(11, IOCON_TYPE_A, 3) /* PIO0_11 */
#define U1_RTS_PIO0_11 IOCON_MUX(11, IOCON_TYPE_A, 4) /* PIO0_11 */
#define U1_SCLK_PIO0_11 IOCON_MUX(11, IOCON_TYPE_A, 5) /* PIO0_11 */
#define TMS_PIO0_12 IOCON_MUX(12, IOCON_TYPE_A, 0) /* PIO0_12 */
#define PIO0_12_PIO0_12 IOCON_MUX(12, IOCON_TYPE_A, 1) /* PIO0_12 */
#define ADC_8_PIO0_12 IOCON_MUX(12, IOCON_TYPE_A, 2) /* PIO0_12 */
#define CT32B1_CAP0_PIO0_12 IOCON_MUX(12, IOCON_TYPE_A, 3) /* PIO0_12 */
#define U1_CTS_PIO0_12 IOCON_MUX(12, IOCON_TYPE_A, 4) /* PIO0_12 */
#define PIO0_12_PIO0_12 IOCON_MUX(12, IOCON_TYPE_A, 5) /* PIO0_12 */
#define TDO_PIO0_13 IOCON_MUX(13, IOCON_TYPE_A, 0) /* PIO0_13 */
#define PIO0_13_PIO0_13 IOCON_MUX(13, IOCON_TYPE_A, 1) /* PIO0_13 */
#define ADC_7_PIO0_13 IOCON_MUX(13, IOCON_TYPE_A, 2) /* PIO0_13 */
#define CT32B1_MAT0_PIO0_13 IOCON_MUX(13, IOCON_TYPE_A, 3) /* PIO0_13 */
#define U1_RXD_PIO0_13 IOCON_MUX(13, IOCON_TYPE_A, 4) /* PIO0_13 */
#define PIO0_13_PIO0_13 IOCON_MUX(13, IOCON_TYPE_A, 5) /* PIO0_13 */
#define TRST_PIO0_14 IOCON_MUX(14, IOCON_TYPE_A, 0) /* PIO0_14 */
#define PIO0_14_PIO0_14 IOCON_MUX(14, IOCON_TYPE_A, 1) /* PIO0_14 */
#define ADC_6_PIO0_14 IOCON_MUX(14, IOCON_TYPE_A, 2) /* PIO0_14 */
#define CT32B1_MAT1_PIO0_14 IOCON_MUX(14, IOCON_TYPE_A, 3) /* PIO0_14 */
#define U1_TXD_PIO0_14 IOCON_MUX(14, IOCON_TYPE_A, 4) /* PIO0_14 */
#define SWDIO_PIO0_15 IOCON_MUX(15, IOCON_TYPE_A, 0) /* PIO0_15 */
#define PIO0_15_PIO0_15 IOCON_MUX(15, IOCON_TYPE_A, 1) /* PIO0_15 */
#define ADC_3_PIO0_15 IOCON_MUX(15, IOCON_TYPE_A, 2) /* PIO0_15 */
#define CT32B1_MAT2_PIO0_15 IOCON_MUX(15, IOCON_TYPE_A, 3) /* PIO0_15 */
#define WAKEUP_PIO0_16 IOCON_MUX(16, IOCON_TYPE_A, 0) /* PIO0_16 */
#define PIO0_16_PIO0_16 IOCON_MUX(16, IOCON_TYPE_A, 1) /* PIO0_16 */
#define ADC_2_PIO0_16 IOCON_MUX(16, IOCON_TYPE_A, 2) /* PIO0_16 */
#define CT32B1_MAT3_PIO0_16 IOCON_MUX(16, IOCON_TYPE_A, 3) /* PIO0_16 */
#define R_8_PIO0_16 IOCON_MUX(16, IOCON_TYPE_A, 4) /* PIO0_16 */
#define PIO0_17_PIO0_17 IOCON_MUX(17, IOCON_TYPE_D, 0) /* PIO0_17 */
#define U0_RTS_PIO0_17 IOCON_MUX(17, IOCON_TYPE_D, 1) /* PIO0_17 */
#define CT32B0_CAP0_PIO0_17 IOCON_MUX(17, IOCON_TYPE_D, 2) /* PIO0_17 */
#define U0_SCLK_PIO0_17 IOCON_MUX(17, IOCON_TYPE_D, 3) /* PIO0_17 */
#define PIO0_18_PIO0_18 IOCON_MUX(18, IOCON_TYPE_D, 0) /* PIO0_18 */
#define U0_RXD_PIO0_18 IOCON_MUX(18, IOCON_TYPE_D, 1) /* PIO0_18 */
#define CT32B0_MAT0_PIO0_18 IOCON_MUX(18, IOCON_TYPE_D, 2) /* PIO0_18 */
#define PIO0_19_PIO0_19 IOCON_MUX(19, IOCON_TYPE_D, 0) /* PIO0_19 */
#define U0_TXD_PIO0_19 IOCON_MUX(19, IOCON_TYPE_D, 1) /* PIO0_19 */
#define CT32B0_MAT1_PIO0_19 IOCON_MUX(19, IOCON_TYPE_D, 2) /* PIO0_19 */
#define PIO0_20_PIO0_20 IOCON_MUX(20, IOCON_TYPE_D, 0) /* PIO0_20 */
#define CT16B1_CAP0_PIO0_20 IOCON_MUX(20, IOCON_TYPE_D, 1) /* PIO0_20 */
#define U2_RXD_PIO0_20 IOCON_MUX(20, IOCON_TYPE_D, 2) /* PIO0_20 */
#define PIO0_21_PIO0_21 IOCON_MUX(21, IOCON_TYPE_D, 0) /* PIO0_21 */
#define CT16B1_MAT0_PIO0_21 IOCON_MUX(21, IOCON_TYPE_D, 1) /* PIO0_21 */
#define SSP1_MOSI_PIO0_21 IOCON_MUX(21, IOCON_TYPE_D, 2) /* PIO0_21 */
#define PIO0_22_PIO0_22 IOCON_MUX(22, IOCON_TYPE_A, 0) /* PIO0_22 */
#define ADC_11_PIO0_22 IOCON_MUX(22, IOCON_TYPE_A, 1) /* PIO0_22 */
#define CT16B1_CAP1_PIO0_22 IOCON_MUX(22, IOCON_TYPE_A, 2) /* PIO0_22 */
#define SSP1_MISO_PIO0_22 IOCON_MUX(22, IOCON_TYPE_A, 3) /* PIO0_22 */
#define PIO0_23_PIO0_23 IOCON_MUX(23, IOCON_TYPE_A, 0) /* PIO0_23 */
#define ADC_1_PIO0_23 IOCON_MUX(23, IOCON_TYPE_A, 1) /* PIO0_23 */
#define R_9_PIO0_23 IOCON_MUX(23, IOCON_TYPE_A, 2) /* PIO0_23 */
#define U0_RI_PIO0_23 IOCON_MUX(23, IOCON_TYPE_A, 3) /* PIO0_23 */
#define SSP1_SSEL_PIO0_23 IOCON_MUX(23, IOCON_TYPE_A, 4) /* PIO0_23 */
#define PIO1_0_PIO1_0 IOCON_MUX(24, IOCON_TYPE_D, 0) /* PIO1_0 */
#define CT32B1_MAT0_PIO1_0 IOCON_MUX(24, IOCON_TYPE_D, 1) /* PIO1_0 */
#define R_10_PIO1_0 IOCON_MUX(24, IOCON_TYPE_D, 2) /* PIO1_0 */
#define U2_TXD_PIO1_0 IOCON_MUX(24, IOCON_TYPE_D, 3) /* PIO1_0 */
#define PIO1_1_PIO1_1 IOCON_MUX(25, IOCON_TYPE_D, 0) /* PIO1_1 */
#define CT32B1_MAT1_PIO1_1 IOCON_MUX(25, IOCON_TYPE_D, 1) /* PIO1_1 */
#define R_11_PIO1_1 IOCON_MUX(25, IOCON_TYPE_D, 2) /* PIO1_1 */
#define U0_DTR_PIO1_1 IOCON_MUX(25, IOCON_TYPE_D, 3) /* PIO1_1 */
#define PIO1_2_PIO1_2 IOCON_MUX(26, IOCON_TYPE_D, 0) /* PIO1_2 */
#define CT32B1_MAT2_PIO1_2 IOCON_MUX(26, IOCON_TYPE_D, 1) /* PIO1_2 */
#define R_12_PIO1_2 IOCON_MUX(26, IOCON_TYPE_D, 2) /* PIO1_2 */
#define U1_RXD_PIO1_2 IOCON_MUX(26, IOCON_TYPE_D, 3) /* PIO1_2 */
#define PIO1_3_PIO1_3 IOCON_MUX(27, IOCON_TYPE_A, 0) /* PIO1_3 */
#define CT32B1_MAT3_PIO1_3 IOCON_MUX(27, IOCON_TYPE_A, 1) /* PIO1_3 */
#define R_13_PIO1_3 IOCON_MUX(27, IOCON_TYPE_A, 2) /* PIO1_3 */
#define I2C1_SDA_PIO1_3 IOCON_MUX(27, IOCON_TYPE_A, 3) /* PIO1_3 */
#define ADC_5_PIO1_3 IOCON_MUX(27, IOCON_TYPE_A, 4) /* PIO1_3 */
#define PIO1_4_PIO1_4 IOCON_MUX(28, IOCON_TYPE_D, 0) /* PIO1_4 */
#define CT32B1_CAP0_PIO1_4 IOCON_MUX(28, IOCON_TYPE_D, 1) /* PIO1_4 */
#define R_14_PIO1_4 IOCON_MUX(28, IOCON_TYPE_D, 2) /* PIO1_4 */
#define U0_DSR_PIO1_4 IOCON_MUX(28, IOCON_TYPE_D, 3) /* PIO1_4 */
#define PIO1_5_PIO1_5 IOCON_MUX(29, IOCON_TYPE_D, 0) /* PIO1_5 */
#define CT32B1_CAP1_PIO1_5 IOCON_MUX(29, IOCON_TYPE_D, 1) /* PIO1_5 */
#define R_15_PIO1_5 IOCON_MUX(29, IOCON_TYPE_D, 2) /* PIO1_5 */
#define U0_DCD_PIO1_5 IOCON_MUX(29, IOCON_TYPE_D, 3) /* PIO1_5 */
#define PIO1_6_PIO1_6 IOCON_MUX(30, IOCON_TYPE_D, 0) /* PIO1_6 */
#define R_16_PIO1_6 IOCON_MUX(30, IOCON_TYPE_D, 1) /* PIO1_6 */
#define U2_RXD_PIO1_6 IOCON_MUX(30, IOCON_TYPE_D, 2) /* PIO1_6 */
#define CT32B0_CAP1_PIO1_6 IOCON_MUX(30, IOCON_TYPE_D, 3) /* PIO1_6 */
#define PIO1_7_PIO1_7 IOCON_MUX(31, IOCON_TYPE_D, 0) /* PIO1_7 */
#define R_17_PIO1_7 IOCON_MUX(31, IOCON_TYPE_D, 1) /* PIO1_7 */
#define U2_CTS_PIO1_7 IOCON_MUX(31, IOCON_TYPE_D, 2) /* PIO1_7 */
#define CT16B1_CAP0_PIO1_7 IOCON_MUX(31, IOCON_TYPE_D, 3) /* PIO1_7 */
#define PIO1_8_PIO1_8 IOCON_MUX(32, IOCON_TYPE_D, 0) /* PIO1_8 */
#define R_18_PIO1_8 IOCON_MUX(32, IOCON_TYPE_D, 1) /* PIO1_8 */
#define U1_TXD_PIO1_8 IOCON_MUX(32, IOCON_TYPE_D, 2) /* PIO1_8 */
#define CT16B0_CAP0_PIO1_8 IOCON_MUX(32, IOCON_TYPE_D, 3) /* PIO1_8 */
#define PIO1_9_PIO1_9 IOCON_MUX(33, IOCON_TYPE_A, 0) /* PIO1_9 */
#define U0_CTS_PIO1_9 IOCON_MUX(33, IOCON_TYPE_A, 1) /* PIO1_9 */
#define CT16B1_MAT1_PIO1_9 IOCON_MUX(33, IOCON_TYPE_A, 2) /* PIO1_9 */
#define ADC_0_PIO1_9 IOCON_MUX(33, IOCON_TYPE_A, 3) /* PIO1_9 */
#define PIO1_10_PIO1_10 IOCON_MUX(34, IOCON_TYPE_D, 0) /* PIO1_10 */
#define U2_RTS_PIO1_10 IOCON_MUX(34, IOCON_TYPE_D, 1) /* PIO1_10 */
#define U2_SCLK_PIO1_10 IOCON_MUX(34, IOCON_TYPE_D, 2) /* PIO1_10 */
#define CT16B1_MAT0_PIO1_10 IOCON_MUX(34, IOCON_TYPE_D, 3) /* PIO1_10 */
#define PIO1_11_PIO1_11 IOCON_MUX(35, IOCON_TYPE_D, 0) /* PIO1_11 */
#define I2C1_SCL_PIO1_11 IOCON_MUX(35, IOCON_TYPE_D, 1) /* PIO1_11 */
#define CT16B0_MAT2_PIO1_11 IOCON_MUX(35, IOCON_TYPE_D, 2) /* PIO1_11 */
#define U0_RI_PIO1_11 IOCON_MUX(35, IOCON_TYPE_D, 3) /* PIO1_11 */
#define PIO1_12_PIO1_12 IOCON_MUX(36, IOCON_TYPE_D, 0) /* PIO1_12 */
#define SSP0_MOSI_PIO1_12 IOCON_MUX(36, IOCON_TYPE_D, 1) /* PIO1_12 */
#define CT16B0_MAT1_PIO1_12 IOCON_MUX(36, IOCON_TYPE_D, 2) /* PIO1_12 */
#define R_21_PIO1_12 IOCON_MUX(36, IOCON_TYPE_D, 3) /* PIO1_12 */
#define PIO1_13_PIO1_13 IOCON_MUX(37, IOCON_TYPE_D, 0) /* PIO1_13 */
#define U1_CTS_PIO1_13 IOCON_MUX(37, IOCON_TYPE_D, 1) /* PIO1_13 */
#define SCT0_OUT3_PIO1_13 IOCON_MUX(37, IOCON_TYPE_D, 2) /* PIO1_13 */
#define R_22_PIO1_13 IOCON_MUX(37, IOCON_TYPE_D, 3) /* PIO1_13 */
#define PIO1_14_PIO1_14 IOCON_MUX(38, IOCON_TYPE_D, 0) /* PIO1_14 */
#define I2C1_SDA_PIO1_14 IOCON_MUX(38, IOCON_TYPE_D, 1) /* PIO1_14 */
#define CT32B1_MAT2_PIO1_14 IOCON_MUX(38, IOCON_TYPE_D, 2) /* PIO1_14 */
#define R_23_PIO1_14 IOCON_MUX(38, IOCON_TYPE_D, 3) /* PIO1_14 */
#define PIO1_15_PIO1_15 IOCON_MUX(39, IOCON_TYPE_D, 0) /* PIO1_15 */
#define SSP0_SSEL_PIO1_15 IOCON_MUX(39, IOCON_TYPE_D, 1) /* PIO1_15 */
#define CT32B1_MAT3_PIO1_15 IOCON_MUX(39, IOCON_TYPE_D, 2) /* PIO1_15 */
#define R_24_PIO1_15 IOCON_MUX(39, IOCON_TYPE_D, 3) /* PIO1_15 */
#define PIO1_16_PIO1_16 IOCON_MUX(40, IOCON_TYPE_D, 0) /* PIO1_16 */
#define SSP0_MISO_PIO1_16 IOCON_MUX(40, IOCON_TYPE_D, 1) /* PIO1_16 */
#define CT16B0_MAT0_PIO1_16 IOCON_MUX(40, IOCON_TYPE_D, 2) /* PIO1_16 */
#define R_25_PIO1_16 IOCON_MUX(40, IOCON_TYPE_D, 3) /* PIO1_16 */
#define PIO1_17_PIO1_17 IOCON_MUX(41, IOCON_TYPE_D, 0) /* PIO1_17 */
#define CT16B0_CAP2_PIO1_17 IOCON_MUX(41, IOCON_TYPE_D, 1) /* PIO1_17 */
#define U0_RXD_PIO1_17 IOCON_MUX(41, IOCON_TYPE_D, 2) /* PIO1_17 */
#define R_26_PIO1_17 IOCON_MUX(41, IOCON_TYPE_D, 3) /* PIO1_17 */
#define PIO1_18_PIO1_18 IOCON_MUX(42, IOCON_TYPE_D, 0) /* PIO1_18 */
#define CT16B1_CAP1_PIO1_18 IOCON_MUX(42, IOCON_TYPE_D, 1) /* PIO1_18 */
#define U0_TXD_PIO1_18 IOCON_MUX(42, IOCON_TYPE_D, 2) /* PIO1_18 */
#define R_27_PIO1_18 IOCON_MUX(42, IOCON_TYPE_D, 3) /* PIO1_18 */
#define PIO1_19_PIO1_19 IOCON_MUX(43, IOCON_TYPE_D, 0) /* PIO1_19 */
#define U2_CTS_PIO1_19 IOCON_MUX(43, IOCON_TYPE_D, 1) /* PIO1_19 */
#define SCT0_OUT0_PIO1_19 IOCON_MUX(43, IOCON_TYPE_D, 2) /* PIO1_19 */
#define R_28_PIO1_19 IOCON_MUX(43, IOCON_TYPE_D, 3) /* PIO1_19 */
#define PIO1_20_PIO1_20 IOCON_MUX(44, IOCON_TYPE_D, 0) /* PIO1_20 */
#define U0_DSR_PIO1_20 IOCON_MUX(44, IOCON_TYPE_D, 1) /* PIO1_20 */
#define SSP1_SCK_PIO1_20 IOCON_MUX(44, IOCON_TYPE_D, 2) /* PIO1_20 */
#define CT16B0_MAT0_PIO1_20 IOCON_MUX(44, IOCON_TYPE_D, 3) /* PIO1_20 */
#define PIO1_21_PIO1_21 IOCON_MUX(45, IOCON_TYPE_D, 0) /* PIO1_21 */
#define U0_DCD_PIO1_21 IOCON_MUX(45, IOCON_TYPE_D, 1) /* PIO1_21 */
#define SSP1_MISO_PIO1_21 IOCON_MUX(45, IOCON_TYPE_D, 2) /* PIO1_21 */
#define CT16B0_CAP1_PIO1_21 IOCON_MUX(45, IOCON_TYPE_D, 3) /* PIO1_21 */
#define PIO1_22_PIO1_22 IOCON_MUX(46, IOCON_TYPE_A, 0) /* PIO1_22 */
#define SSP1_MOSI_PIO1_22 IOCON_MUX(46, IOCON_TYPE_A, 1) /* PIO1_22 */
#define CT32B1_CAP1_PIO1_22 IOCON_MUX(46, IOCON_TYPE_A, 2) /* PIO1_22 */
#define ADC_4_PIO1_22 IOCON_MUX(46, IOCON_TYPE_A, 3) /* PIO1_22 */
#define R_29_PIO1_22 IOCON_MUX(46, IOCON_TYPE_A, 4) /* PIO1_22 */
#define PIO1_23_PIO1_23 IOCON_MUX(47, IOCON_TYPE_D, 0) /* PIO1_23 */
#define CT16B1_MAT1_PIO1_23 IOCON_MUX(47, IOCON_TYPE_D, 1) /* PIO1_23 */
#define SSP1_SSEL_PIO1_23 IOCON_MUX(47, IOCON_TYPE_D, 2) /* PIO1_23 */
#define U2_TXD_PIO1_23 IOCON_MUX(47, IOCON_TYPE_D, 3) /* PIO1_23 */
#define PIO1_24_PIO1_24 IOCON_MUX(48, IOCON_TYPE_D, 0) /* PIO1_24 */
#define CT32B0_MAT0_PIO1_24 IOCON_MUX(48, IOCON_TYPE_D, 1) /* PIO1_24 */
#define I2C1_SDA_PIO1_24 IOCON_MUX(48, IOCON_TYPE_D, 2) /* PIO1_24 */
#define PIO1_25_PIO1_25 IOCON_MUX(49, IOCON_TYPE_D, 0) /* PIO1_25 */
#define U2_RTS_PIO1_25 IOCON_MUX(49, IOCON_TYPE_D, 1) /* PIO1_25 */
#define U2_SCLK_PIO1_25 IOCON_MUX(49, IOCON_TYPE_D, 2) /* PIO1_25 */
#define SCT0_IN0_PIO1_25 IOCON_MUX(49, IOCON_TYPE_D, 3) /* PIO1_25 */
#define R_30_PIO1_25 IOCON_MUX(49, IOCON_TYPE_D, 4) /* PIO1_25 */
#define PIO1_26_PIO1_26 IOCON_MUX(50, IOCON_TYPE_D, 0) /* PIO1_26 */
#define CT32B0_MAT2_PIO1_26 IOCON_MUX(50, IOCON_TYPE_D, 1) /* PIO1_26 */
#define U0_RXD_PIO1_26 IOCON_MUX(50, IOCON_TYPE_D, 2) /* PIO1_26 */
#define R_19_PIO1_26 IOCON_MUX(50, IOCON_TYPE_D, 3) /* PIO1_26 */
#define PIO1_27_PIO1_27 IOCON_MUX(51, IOCON_TYPE_D, 0) /* PIO1_27 */
#define CT32B0_MAT3_PIO1_27 IOCON_MUX(51, IOCON_TYPE_D, 1) /* PIO1_27 */
#define U0_TXD_PIO1_27 IOCON_MUX(51, IOCON_TYPE_D, 2) /* PIO1_27 */
#define R_20_PIO1_27 IOCON_MUX(51, IOCON_TYPE_D, 3) /* PIO1_27 */
#define SSP1_SCK_PIO1_27 IOCON_MUX(51, IOCON_TYPE_D, 4) /* PIO1_27 */
#define PIO1_28_PIO1_28 IOCON_MUX(52, IOCON_TYPE_D, 0) /* PIO1_28 */
#define CT32B0_CAP0_PIO1_28 IOCON_MUX(52, IOCON_TYPE_D, 1) /* PIO1_28 */
#define U0_SCLK_PIO1_28 IOCON_MUX(52, IOCON_TYPE_D, 2) /* PIO1_28 */
#define U0_RTS_PIO1_28 IOCON_MUX(52, IOCON_TYPE_D, 3) /* PIO1_28 */
#define PIO1_29_PIO1_29 IOCON_MUX(53, IOCON_TYPE_A, 0) /* PIO1_29 */
#define SSP0_SCK_PIO1_29 IOCON_MUX(53, IOCON_TYPE_A, 1) /* PIO1_29 */
#define CT32B0_CAP1_PIO1_29 IOCON_MUX(53, IOCON_TYPE_A, 2) /* PIO1_29 */
#define U0_DTRn_PIO1_29 IOCON_MUX(53, IOCON_TYPE_A, 3) /* PIO1_29 */
#define ADC_10_PIO1_29 IOCON_MUX(53, IOCON_TYPE_A, 4) /* PIO1_29 */
#define PIO1_30_PIO1_30 IOCON_MUX(54, IOCON_TYPE_D, 0) /* PIO1_30 */
#define I2C1_SCL_PIO1_30 IOCON_MUX(54, IOCON_TYPE_D, 1) /* PIO1_30 */
#define SCT0_IN3_PIO1_30 IOCON_MUX(54, IOCON_TYPE_D, 2) /* PIO1_30 */
#define R_31_PIO1_30 IOCON_MUX(54, IOCON_TYPE_D, 3) /* PIO1_30 */
#define PIO1_31_PIO1_31 IOCON_MUX(55, IOCON_TYPE_D, 0) /* PIO1_31 */
#define PIO2_0_PIO2_0 IOCON_MUX(60, IOCON_TYPE_A, 0) /* PIO2_0 */
#define XTALIN_PIO2_0 IOCON_MUX(60, IOCON_TYPE_A, 1) /* PIO2_0 */
#define PIO2_1_PIO2_1 IOCON_MUX(61, IOCON_TYPE_A, 0) /* PIO2_1 */
#define XTALOUT_PIO2_1 IOCON_MUX(61, IOCON_TYPE_A, 1) /* PIO2_1 */
#define PIO2_2_PIO2_2 IOCON_MUX(63, IOCON_TYPE_D, 0) /* PIO2_2 */
#define U3_RTS_PIO2_2 IOCON_MUX(63, IOCON_TYPE_D, 1) /* PIO2_2 */
#define U3_SCLK_PIO2_2 IOCON_MUX(63, IOCON_TYPE_D, 2) /* PIO2_2 */
#define SCT0_OUT1_PIO2_2 IOCON_MUX(63, IOCON_TYPE_D, 3) /* PIO2_2 */
#define PIO2_3_PIO2_3 IOCON_MUX(64, IOCON_TYPE_D, 0) /* PIO2_3 */
#define U3_RXD_PIO2_3 IOCON_MUX(64, IOCON_TYPE_D, 1) /* PIO2_3 */
#define CT32B0_MAT1_PIO2_3 IOCON_MUX(64, IOCON_TYPE_D, 2) /* PIO2_3 */
#define PIO2_4_PIO2_4 IOCON_MUX(65, IOCON_TYPE_D, 0) /* PIO2_4 */
#define U3_TXD_PIO2_4 IOCON_MUX(65, IOCON_TYPE_D, 1) /* PIO2_4 */
#define CT32B0_MAT2_PIO2_4 IOCON_MUX(65, IOCON_TYPE_D, 2) /* PIO2_4 */
#define PIO2_5_PIO2_5 IOCON_MUX(66, IOCON_TYPE_D, 0) /* PIO2_5 */
#define U3_CTS_PIO2_5 IOCON_MUX(66, IOCON_TYPE_D, 1) /* PIO2_5 */
#define SCT0_IN1_PIO2_5 IOCON_MUX(66, IOCON_TYPE_D, 2) /* PIO2_5 */
#define PIO2_6_PIO2_6 IOCON_MUX(67, IOCON_TYPE_D, 0) /* PIO2_6 */
#define U1_RTS_PIO2_6 IOCON_MUX(67, IOCON_TYPE_D, 1) /* PIO2_6 */
#define U1_SCLK_PIO2_6 IOCON_MUX(67, IOCON_TYPE_D, 2) /* PIO2_6 */
#define SCT0_IN2_PIO2_6 IOCON_MUX(67, IOCON_TYPE_D, 3) /* PIO2_6 */
#define PIO2_7_PIO2_7 IOCON_MUX(68, IOCON_TYPE_D, 0) /* PIO2_7 */
#define SSP0_SCK_PIO2_7 IOCON_MUX(68, IOCON_TYPE_D, 1) /* PIO2_7 */
#define SCT0_OUT2_PIO2_7 IOCON_MUX(68, IOCON_TYPE_D, 2) /* PIO2_7 */
#define PIO2_8_PIO2_8 IOCON_MUX(69, IOCON_TYPE_D, 0) /* PIO2_8 */
#define SCT1_IN0_PIO2_8 IOCON_MUX(69, IOCON_TYPE_D, 1) /* PIO2_8 */
#define PIO2_9_PIO2_9 IOCON_MUX(70, IOCON_TYPE_D, 0) /* PIO2_9 */
#define SCT1_IN1_PIO2_9 IOCON_MUX(70, IOCON_TYPE_D, 1) /* PIO2_9 */
#define PIO2_10_PIO2_10 IOCON_MUX(71, IOCON_TYPE_D, 0) /* PIO2_10 */
#define U4_RTS_PIO2_10 IOCON_MUX(71, IOCON_TYPE_D, 1) /* PIO2_10 */
#define U4_SCLK_PIO2_10 IOCON_MUX(71, IOCON_TYPE_D, 2) /* PIO2_10 */
#define PIO2_11_PIO2_11 IOCON_MUX(72, IOCON_TYPE_D, 0) /* PIO2_11 */
#define U4_RXD_PIO2_11 IOCON_MUX(72, IOCON_TYPE_D, 1) /* PIO2_11 */
#define PIO2_12_PIO2_12 IOCON_MUX(73, IOCON_TYPE_D, 0) /* PIO2_12 */
#define U4_TXD_PIO2_12 IOCON_MUX(73, IOCON_TYPE_D, 1) /* PIO2_12 */
#define PIO2_13_PIO2_13 IOCON_MUX(74, IOCON_TYPE_D, 0) /* PIO2_13 */
#define U4_CTS_PIO2_13 IOCON_MUX(74, IOCON_TYPE_D, 1) /* PIO2_13 */
#define PIO2_14_PIO2_14 IOCON_MUX(75, IOCON_TYPE_D, 0) /* PIO2_14 */
#define SCT1_IN2_PIO2_14 IOCON_MUX(75, IOCON_TYPE_D, 1) /* PIO2_14 */
#define PIO2_15_PIO2_15 IOCON_MUX(76, IOCON_TYPE_D, 0) /* PIO2_15 */
#define SCT1_IN3_PIO2_15 IOCON_MUX(76, IOCON_TYPE_D, 1) /* PIO2_15 */
#define PIO2_16_PIO2_16 IOCON_MUX(77, IOCON_TYPE_D, 0) /* PIO2_16 */
#define SCT1_OUT0_PIO2_16 IOCON_MUX(77, IOCON_TYPE_D, 1) /* PIO2_16 */
#define PIO2_17_PIO2_17 IOCON_MUX(78, IOCON_TYPE_D, 0) /* PIO2_17 */
#define SCT1_OUT1_PIO2_17 IOCON_MUX(78, IOCON_TYPE_D, 1) /* PIO2_17 */
#define PIO2_18_PIO2_18 IOCON_MUX(79, IOCON_TYPE_D, 0) /* PIO2_18 */
#define SCT1_OUT2_PIO2_18 IOCON_MUX(79, IOCON_TYPE_D, 1) /* PIO2_18 */
#define PIO2_19_PIO2_19 IOCON_MUX(80, IOCON_TYPE_D, 0) /* PIO2_19 */
#define SCT1_OUT3_PIO2_19 IOCON_MUX(80, IOCON_TYPE_D, 1) /* PIO2_19 */
#define PIO2_20_PIO2_20 IOCON_MUX(81, IOCON_TYPE_D, 0) /* PIO2_20 */
#define PIO2_21_PIO2_21 IOCON_MUX(82, IOCON_TYPE_D, 0) /* PIO2_21 */
#define PIO2_22_PIO2_22 IOCON_MUX(83, IOCON_TYPE_D, 0) /* PIO2_22 */
#define PIO2_23_PIO2_23 IOCON_MUX(84, IOCON_TYPE_D, 0) /* PIO2_23 */

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_LPC11U6X_PINCTRL_H_ */
