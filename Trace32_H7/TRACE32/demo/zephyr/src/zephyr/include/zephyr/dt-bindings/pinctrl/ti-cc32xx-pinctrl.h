/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_PINCTRL_TI_CC32XX_PINCTRL_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_PINCTRL_TI_CC32XX_PINCTRL_H_

/*
 * The whole TI CC32XX pin configuration information is encoded in a 32-bit
 * bitfield organized as follows:
 *
 * - 31..22: Reserved
 * - 21..16: Pin.
 * - 15..10: Reserved.
 * - 9:      Pull-down flag.
 * - 8:      Pull-up flag.
 * - 7..5:   Drive strength.
 * - 4:      Enable open-drain flag.
 * - 3..0:   Configuration mode
 *
 * Note that the lower bits (11..0) map directly to the MEM_GPIO_PAD_CONFIG
 * register.
 */

/**
 * @name TI CC32XX pin configuration bit field positions and masks.
 * @{
 */

#define TI_CC32XX_PIN_MSK 0x3FU
#define TI_CC32XX_PIN_POS 16U
#define TI_CC32XX_MUX_MSK 0xFU
#define TI_CC32XX_MUX_POS 0U

/** @} */

/**
 * @brief Utility macro to build TI CC32XX pinmux property entry.
 *
 * @param pin Pin
 * @param mux Multiplexer choice
 */
#define TI_CC32XX_PINMUX(pin, mux)                                                                 \
	((((pin)&TI_CC32XX_PIN_MSK) << TI_CC32XX_PIN_POS) |                                        \
	 (((mux)&TI_CC32XX_MUX_MSK) << TI_CC32XX_MUX_POS))

/**
 * @name TI CC32XX pinctrl pin functions (reference: SWRU465).
 * @{
 */

#define GPIO10_P1     TI_CC32XX_PINMUX(1U, 0U)
#define I2C_SCL_P1    TI_CC32XX_PINMUX(1U, 1U)
#define GT_PWM06_P1   TI_CC32XX_PINMUX(1U, 3U)
#define UART1_TX_P1   TI_CC32XX_PINMUX(1U, 7U)
#define SDCARD_CLK_P1 TI_CC32XX_PINMUX(1U, 6U)
#define GT_CCP01_P1   TI_CC32XX_PINMUX(1U, 12U)

#define GPIO11_P2     TI_CC32XX_PINMUX(2U, 0U)
#define I2C_SDA_P2    TI_CC32XX_PINMUX(2U, 1U)
#define GT_PWM07_P2   TI_CC32XX_PINMUX(2U, 3U)
#define PXCLK_P2      TI_CC32XX_PINMUX(2U, 4U)
#define SDCARD_CMD_P2 TI_CC32XX_PINMUX(2U, 6U)
#define UART1_RX_P2   TI_CC32XX_PINMUX(2U, 7U)
#define GT_CCP02_P2   TI_CC32XX_PINMUX(2U, 12U)
#define MCAFSX_P2     TI_CC32XX_PINMUX(2U, 13U)

#define GPIO12_P3   TI_CC32XX_PINMUX(3U, 0U)
#define MCACLK_P3   TI_CC32XX_PINMUX(3U, 3U)
#define PVS_P3      TI_CC32XX_PINMUX(3U, 4U)
#define I2C_SCL_P3  TI_CC32XX_PINMUX(3U, 5U)
#define UART0_TX_P3 TI_CC32XX_PINMUX(3U, 7U)
#define GT_CCP03_P3 TI_CC32XX_PINMUX(3U, 12U)

#define GPIO13_P4   TI_CC32XX_PINMUX(4U, 0U)
#define I2C_SDA_P4  TI_CC32XX_PINMUX(4U, 5U)
#define PHS_P4      TI_CC32XX_PINMUX(4U, 4U)
#define UART0_RX_P4 TI_CC32XX_PINMUX(4U, 7U)
#define GT_CCP04_P4 TI_CC32XX_PINMUX(4U, 12U)

#define GPIO14_P5   TI_CC32XX_PINMUX(5U, 0U)
#define I2C_SCL_P5  TI_CC32XX_PINMUX(5U, 5U)
#define GSPI_CLK_P5 TI_CC32XX_PINMUX(5U, 7U)
#define PDATA8_P5   TI_CC32XX_PINMUX(5U, 4U)
#define GT_CCP05_P5 TI_CC32XX_PINMUX(5U, 12U)

#define GPIO15_P6       TI_CC32XX_PINMUX(6U, 0U)
#define I2C_SDA_P6      TI_CC32XX_PINMUX(6U, 5U)
#define GSPI_MISO_P6    TI_CC32XX_PINMUX(6U, 7U)
#define PDATA9_P6       TI_CC32XX_PINMUX(6U, 4U)
#define SDCARD_DATA3_P6 TI_CC32XX_PINMUX(6U, 8U)
#define GT_CCP06_P6     TI_CC32XX_PINMUX(6U, 13U)

#define GPIO16_P7     TI_CC32XX_PINMUX(7U, 0U)
#define GSPI_MOSI_P7  TI_CC32XX_PINMUX(7U, 7U)
#define PDATA10_P7    TI_CC32XX_PINMUX(7U, 4U)
#define UART1_TX_P7   TI_CC32XX_PINMUX(7U, 5U)
#define SDCARD_CLK_P7 TI_CC32XX_PINMUX(7U, 8U)
#define GT_CCP07_P7   TI_CC32XX_PINMUX(7U, 13U)

#define GPIO17_P8     TI_CC32XX_PINMUX(8U, 0U)
#define UART1_RX_P8   TI_CC32XX_PINMUX(8U, 5U)
#define GSPI_CS_P8    TI_CC32XX_PINMUX(8U, 7U)
#define SDCARD_CMD_P8 TI_CC32XX_PINMUX(8U, 8U)
#define PDATA11_P8    TI_CC32XX_PINMUX(8U, 4U)

#define GPIO22_P15   TI_CC32XX_PINMUX(15U, 0U)
#define MCAFSX_P15   TI_CC32XX_PINMUX(15U, 7U)
#define GT_CCP04_P15 TI_CC32XX_PINMUX(15U, 5U)

#define GPIO23_P16   TI_CC32XX_PINMUX(16U, 0U)
#define TDI_P16      TI_CC32XX_PINMUX(16U, 1U)
#define UART1_TX_P16 TI_CC32XX_PINMUX(16U, 2U)
#define I2C_SCL_P16  TI_CC32XX_PINMUX(16U, 9U)

#define GPIO24_P17   TI_CC32XX_PINMUX(17U, 0U)
#define TDO_P17      TI_CC32XX_PINMUX(17U, 1U)
#define PWM0_P17     TI_CC32XX_PINMUX(17U, 5U)
#define UART1_RX_P17 TI_CC32XX_PINMUX(17U, 2U)
#define I2C_SDA_P17  TI_CC32XX_PINMUX(17U, 9U)
#define GT_CCP06_P17 TI_CC32XX_PINMUX(17U, 4U)
#define MCAFSX_P17   TI_CC32XX_PINMUX(17U, 6U)

#define GPIO28_P18 TI_CC32XX_PINMUX(18U, 0U)

#define TCK_P19      TI_CC32XX_PINMUX(19U, 1U)
#define GT_PWM03_P19 TI_CC32XX_PINMUX(19U, 8U)

#define GPIO29_P20 TI_CC32XX_PINMUX(20U, 0U)
#define TMS_P20    TI_CC32XX_PINMUX(20U, 1U)

#define GPIO25_P21   TI_CC32XX_PINMUX(21U, 0U)
#define GT_PWM02_P21 TI_CC32XX_PINMUX(21U, 9U)
#define MCASFX_P21   TI_CC32XX_PINMUX(21U, 2U)

#define ANTSEL1_P29 TI_CC32XX_PINMUX(29U, 0U)

#define ANTSEL2_P30 TI_CC32XX_PINMUX(30U, 0U)

#define GPIO31_P45   TI_CC32XX_PINMUX(45U, 0U)
#define UART0_RX_P45 TI_CC32XX_PINMUX(45U, 9U)
#define MCAFSX_P45   TI_CC32XX_PINMUX(45U, 12U)
#define UART1_RX_P45 TI_CC32XX_PINMUX(45U, 2U)
#define MCAXR0_P45   TI_CC32XX_PINMUX(45U, 6U)
#define GSPI_CLK_P45 TI_CC32XX_PINMUX(45U, 7U)

#define GPIO0_P50      TI_CC32XX_PINMUX(50U, 0U)
#define UART0_CTSN_P50 TI_CC32XX_PINMUX(50U, 12U)
#define MCAXR1_P50     TI_CC32XX_PINMUX(50U, 6U)
#define GT_CCP00_P50   TI_CC32XX_PINMUX(50U, 7U)
#define GSPI_CS_P50    TI_CC32XX_PINMUX(50U, 9U)
#define UART1_RTS_P50  TI_CC32XX_PINMUX(50U, 10U)
#define UART0_RTS_P50  TI_CC32XX_PINMUX(50U, 3U)
#define MCAXR0_P50     TI_CC32XX_PINMUX(50U, 4U)

#define GPIO32_P52    TI_CC32XX_PINMUX(52U, 0U)
#define MCACLK_P52    TI_CC32XX_PINMUX(52U, 2U)
#define MCAXR0_P52    TI_CC32XX_PINMUX(52U, 4U)
#define UART0_RTS_P52 TI_CC32XX_PINMUX(52U, 6U)
#define GSPI_MOSI_P52 TI_CC32XX_PINMUX(52U, 8U)

#define GPIO30_P53    TI_CC32XX_PINMUX(53U, 0U)
#define UART0_TX_P53  TI_CC32XX_PINMUX(53U, 9U)
#define MCACLK_P53    TI_CC32XX_PINMUX(53U, 2U)
#define MCAFSX_P53    TI_CC32XX_PINMUX(53U, 3U)
#define GT_CCP05_P53  TI_CC32XX_PINMUX(53U, 4U)
#define GSPI_MISO_P53 TI_CC32XX_PINMUX(53U, 7U)

#define GPIO1_P55    TI_CC32XX_PINMUX(55U, 0U)
#define UART0_TX_P55 TI_CC32XX_PINMUX(55U, 3U)
#define PCLK_P55     TI_CC32XX_PINMUX(55U, 4U)
#define UART1_TX_P55 TI_CC32XX_PINMUX(55U, 6U)
#define GT_CCP01_P55 TI_CC32XX_PINMUX(55U, 7U)

#define GPIO2_P57    TI_CC32XX_PINMUX(57U, 0U)
#define UART0_RX_P57 TI_CC32XX_PINMUX(57U, 3U)
#define UART1_RX_P57 TI_CC32XX_PINMUX(57U, 6U)
#define GT_CCP02_P57 TI_CC32XX_PINMUX(57U, 7U)

#define GPIO3_P58    TI_CC32XX_PINMUX(58U, 0U)
#define UART1_TX_P58 TI_CC32XX_PINMUX(58U, 6U)
#define PDATA7_P58   TI_CC32XX_PINMUX(58U, 7U)

#define GPIO5_P59    TI_CC32XX_PINMUX(59U, 0U)
#define UART1_RX_P59 TI_CC32XX_PINMUX(59U, 6U)
#define PDATA6_P59   TI_CC32XX_PINMUX(59U, 4U)

#define GPIO5_P60    TI_CC32XX_PINMUX(60U, 0U)
#define PDATA5_P60   TI_CC32XX_PINMUX(60U, 4U)
#define MCAXR1_P60   TI_CC32XX_PINMUX(60U, 6U)
#define GT_CCP05_P60 TI_CC32XX_PINMUX(60U, 7U)

#define GPIO6_P61     TI_CC32XX_PINMUX(61U, 0U)
#define UART0_RTS_P61 TI_CC32XX_PINMUX(61U, 5U)
#define PDATA4_P61    TI_CC32XX_PINMUX(61U, 4U)
#define UART1_CTS_P61 TI_CC32XX_PINMUX(61U, 3U)
#define UART0_CTS_P61 TI_CC32XX_PINMUX(61U, 6U)
#define GT_CCP06_P61  TI_CC32XX_PINMUX(61U, 7U)

#define GPIO7_P62     TI_CC32XX_PINMUX(62U, 0U)
#define MCACLKX_P62   TI_CC32XX_PINMUX(62U, 13U)
#define UART1_RTS_P62 TI_CC32XX_PINMUX(62U, 3U)
#define UART0_RTS_P62 TI_CC32XX_PINMUX(62U, 10U)
#define UART0_TX_P62  TI_CC32XX_PINMUX(62U, 11U)

#define GPIO8_P63      TI_CC32XX_PINMUX(63U, 0U)
#define SDCARD_IRQ_P63 TI_CC32XX_PINMUX(63U, 6U)
#define MCAFSX_P63     TI_CC32XX_PINMUX(63U, 7U)
#define GT_CCP06_P63   TI_CC32XX_PINMUX(63U, 12U)

#define GPIO9_P64       TI_CC32XX_PINMUX(64U, 0U)
#define GT_PWM05_P64    TI_CC32XX_PINMUX(64U, 3U)
#define SDCARD_DATA_P64 TI_CC32XX_PINMUX(64U, 6U)
#define MCAXR0_P64      TI_CC32XX_PINMUX(64U, 7U)
#define GT_CCP00_P64    TI_CC32XX_PINMUX(64U, 12U)

/** @} */

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_PINCTRL_TI_CC32XX_PINCTRL_H_ */
