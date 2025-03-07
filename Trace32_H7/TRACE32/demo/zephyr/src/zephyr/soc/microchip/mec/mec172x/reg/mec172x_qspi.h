/*
 * Copyright (c) 2021 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _MEC_QSPI_H_
#define _MEC_QSPI_H_

#include <stdint.h>
#include <stddef.h>

#define QMPSPI_HW_VER		4u

#define MCHP_QMSPI_BASE_ADDR	0x40070000u

#define MCHP_QMSPI_MAX_DESCR	16u

#define MCHP_QMSPI_INPUT_CLOCK_FREQ_HZ	96000000u
#define MCHP_QMSPI_MAX_FREQ_KHZ	\
	((MCHP_QMSPI_INPUT_CLOCK_FREQ_HZ) / 1000u)
#define MCHP_QMSPI_MIN_FREQ_KHZ		(MCHP_QMSPI_MAX_FREQ_KHZ / 256u)

/* Mode 0: Clock idle = Low. Data change falling edge, sample rising edge */
#define MCHP_QMSPI_SPI_MODE0	0u
/* Mode 1: Clock idle = Low. Data change rising edge, sample falling edge */
#define MCHP_QMSPI_SPI_MODE1	0x06u
/* Mode 2: Clock idle = High. Data change rising edge, sample falling edge */
#define MCHP_QMSPI_SPI_MODE2	0x06u
/* Mode 3: Clock idle = High. Data change falling edge, sample rising edge */
#define MCHP_QMSPI_SPI_MODE3	0x07u

/* Device ID used in DMA channel Control.DeviceID field */
#define MCHP_QMSPI_TX_DMA_REQ_ID	10u
#define MCHP_QMSPI_RX_DMA_REQ_ID	11u

/* QMSPI transmit and receive FIFO lengths */
#define MCHP_QMSPI_TX_FIFO_LEN		8u
#define MCHP_QMSPI_RX_FIFO_LEN		8u

/* QMSPI Local DMA channels */
#define MCHP_QMSPI_LDMA_RX_CHANNELS	3u
#define MCHP_QMSPI_LDMA_TX_CHANNELS	3u

#define MCHP_QMSPI_M_ACT_SRST_OFS	0u
#define MCHP_QMSPI_M_SPI_MODE_OFS	1u
#define MCHP_QMSPI_M_CLK_DIV_OFS	2u
#define MCHP_QMSPI_CTRL_OFS		4u
#define MCHP_QMSPI_EXE_OFS		8u
#define MCHP_QMSPI_IF_CTRL_OFS		0x0cu
#define MCHP_QMSPI_STS_OFS		0x10u
#define MCHP_QMSPI_BUF_CNT_STS_OFS	0x14u
#define MCHP_QMSPI_IEN_OFS		0x18u
#define MCHP_QMSPI_BUF_CNT_TRIG_OFS	0x1cu
#define MCHP_QMSPI_TX_FIFO_OFS		0x20u
#define MCHP_QMSPI_RX_FIFO_OFS		0x24u
#define MCHP_QMSPI_CSTM_OFS		0x28u
/* 0 <= n < MCHP_QMSPI_MAX_DESCR */
#define MCHP_QMSPI_DESC0_OFS		0x30u
#define MCHP_QMSPI_DESCR_OFS(n)		(0x30u + ((uint32_t)(n) * 4u))
#define MCHP_QMSPI_ALIAS_CTRL_OFS	0xb0u
#define MCHP_QMSPI_MODE_ALT1_OFS	0xc0u
#define MCHP_QMSPI_TAPS_OFS		0xd0u
#define MCHP_QMSPI_TAPS_ADJ_OFS		0xd4u
#define MCHP_QMSPI_TAPS_CTRL_OFS	0xd8u
#define MCHP_QMSPI_LDMA_RX_EN_OFS	0x100u
#define MCHP_QMSPI_LDMA_TX_EN_OFS	0x104u
#define MCHP_QMSPI_LDMA_RX_0_CTRL_OFS	0x110u
#define MCHP_QMSPI_LDMA_RX_0_START_OFS	0x114u
#define MCHP_QMSPI_LDMA_RX_0_LEN_OFS	0x118u
#define MCHP_QMSPI_LDMA_RX_1_CTRL_OFS	0x120u
#define MCHP_QMSPI_LDMA_RX_1_START_OFS	0x124u
#define MCHP_QMSPI_LDMA_RX_1_LEN_OFS	0x128u
#define MCHP_QMSPI_LDMA_RX_2_CTRL_OFS	0x130u
#define MCHP_QMSPI_LDMA_RX_2_START_OFS	0x134u
#define MCHP_QMSPI_LDMA_RX_2_LEN_OFS	0x138u
#define MCHP_QMSPI_LDMA_TX_0_CTRL_OFS	0x140u
#define MCHP_QMSPI_LDMA_TX_0_START_OFS	0x144u
#define MCHP_QMSPI_LDMA_TX_0_LEN_OFS	0x148u
#define MCHP_QMSPI_LDMA_TX_1_CTRL_OFS	0x150u
#define MCHP_QMSPI_LDMA_TX_1_START_OFS	0x154u
#define MCHP_QMSPI_LDMA_TX_1_LEN_OFS	0x158u
#define MCHP_QMSPI_LDMA_TX_2_CTRL_OFS	0x160u
#define MCHP_QMSPI_LDMA_TX_2_START_OFS	0x164u
#define MCHP_QMSPI_LDMA_TX_2_LEN_OFS	0x168u

#define MCHP_QMSPI_MODE_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x00)
#define MCHP_QMSPI_CTRL_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x04)
#define MCHP_QMSPI_EXE_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x08)
#define MCHP_QMSPI_IFC_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x0c)
#define MCHP_QMSPI_STS_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x10)
#define MCHP_QMSPI_BUFCNT_STS_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x14)
#define MCHP_QMSPI_TX_BCNT_STS_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x14)
#define MCHP_QMSPI_RX_BCNT_STS_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x16)
#define MCHP_QMSPI_IEN_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x18)
#define MCHP_QMSPI_TXB_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x20)
#define MCHP_QMSPI_RXB_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x24)
#define MCHP_QMSPI_CSTM_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x28)
#define MCHP_QMSPI_DESCR_ADDR(n) \
	(MCHP_QMSPI_BASE_ADDR + (0x30 + (((uint32_t)(n) & 0x0Fu) << 2)))

#define MCHP_QMSPI_ALIAS_CTRL_ADDR	(MCHP_QMSPI_BASE_ADDR + 0xb0u)
#define MCHP_QMSPI_MODE_ALT1_ADDR	(MCHP_QMSPI_BASE_ADDR + 0xc0u)
#define MCHP_QMSPI_TAPS_ADDR		(MCHP_QMSPI_BASE_ADDR + 0xd0u)
#define MCHP_QMSPI_TAPS_ADJ_ADDR	(MCHP_QMSPI_BASE_ADDR + 0xd4u)
#define MCHP_QMSPI_TAPS_CTRL_ADDR	(MCHP_QMSPI_BASE_ADDR + 0xd8u)
#define MCHP_QMSPI_LDMA_RX_EN_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x100u)
#define MCHP_QMSPI_LDMA_TX_EN_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x104u)
#define MCHP_QMSPI_LDMA_RX_0_CTRL_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x110u)
#define MCHP_QMSPI_LDMA_RX_0_START_ADDR (MCHP_QMSPI_BASE_ADDR + 0x114u)
#define MCHP_QMSPI_LDMA_RX_0_LEN_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x118u)
#define MCHP_QMSPI_LDMA_RX_1_CTRL_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x120u)
#define MCHP_QMSPI_LDMA_RX_1_START_ADDR (MCHP_QMSPI_BASE_ADDR + 0x124u)
#define MCHP_QMSPI_LDMA_RX_1_LEN_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x128u)
#define MCHP_QMSPI_LDMA_RX_2_CTRL_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x130u)
#define MCHP_QMSPI_LDMA_RX_2_START_ADDR (MCHP_QMSPI_BASE_ADDR + 0x134u)
#define MCHP_QMSPI_LDMA_RX_2_LEN_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x138u)
#define MCHP_QMSPI_LDMA_TX_0_CTRL_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x140u)
#define MCHP_QMSPI_LDMA_TX_0_START_ADDR (MCHP_QMSPI_BASE_ADDR + 0x144u)
#define MCHP_QMSPI_LDMA_TX_0_LEN_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x148u)
#define MCHP_QMSPI_LDMA_TX_1_CTRL_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x150u)
#define MCHP_QMSPI_LDMA_TX_1_START_ADDR (MCHP_QMSPI_BASE_ADDR + 0x154u)
#define MCHP_QMSPI_LDMA_TX_1_LEN_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x158u)
#define MCHP_QMSPI_LDMA_TX_2_CTRL_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x160u)
#define MCHP_QMSPI_LDMA_TX_2_START_ADDR (MCHP_QMSPI_BASE_ADDR + 0x164u)
#define MCHP_QMSPI_LDMA_TX_2_LEN_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x168u)

/* Mode Register */
#define MCHP_QMSPI_M_MASK		0x00ff371fu
#define MCHP_QMSPI_M_ACTIVATE		BIT(0)
#define MCHP_QMSPI_M_SRST		BIT(1)
#define MCHP_QMSPI_M_SAF_DMA_MODE_EN	BIT(2)
#define MCHP_QMSPI_M_LDMA_RX_EN		BIT(3)
#define MCHP_QMSPI_M_LDMA_TX_EN		BIT(4)
#define MCHP_QMSPI_M_CPOL_POS		8u
#define MCHP_QMSPI_M_CPOL_CLK_IDLE_LO	0
#define MCHP_QMSPI_M_CPOL_CLK_IDLE_HI	BIT(8)

#define MCHP_QMSPI_M_CPHA_MOSI_POS	9u
/* MOSI data changes on first clock edge of clock pulse */
#define MCHP_QMSPI_M_CPHA_MOSI_CE1	0u
/* MOSI data changes on second clock edge of clock pulse */
#define MCHP_QMSPI_M_CPHA_MOSI_CE2	BIT(9)

#define MCHP_QMSPI_M_CPHA_MIS0_POS	10u
/* MISO data capture on first clock edge of clock pulse */
#define MCHP_QMSPI_M_CPHA_MISO_CE1	0u
/* MISO data capture on second clock edge of clock pulse */
#define MCHP_QMSPI_M_CPHA_MISO_CE2	BIT(10)

#define MCHP_QMSPI_M_SIG_POS		8u
#define MCHP_QMSPI_M_SIG_MASK0		0x07u
#define MCHP_QMSPI_M_SIG_MASK		0x0700u
#define MCHP_QMSPI_M_SIG_MODE0_VAL	0u
#define MCHP_QMSPI_M_SIG_MODE1_VAL	0x06u
#define MCHP_QMSPI_M_SIG_MODE2_VAL	0x01u
#define MCHP_QMSPI_M_SIG_MODE3_VAL	0x07u
#define MCHP_QMSPI_M_SIG_MODE0		0u
#define MCHP_QMSPI_M_SIG_MODE1		SHLU32(6u, MCHP_QMSPI_M_SIG_POS)
#define MCHP_QMSPI_M_SIG_MODE2		SHLU32(1u, MCHP_QMSPI_M_SIG_POS)
#define MCHP_QMSPI_M_SIG_MODE3		SHLU32(7u, MCHP_QMSPI_M_SIG_POS)
#define MCHP_QMSPI_M_CS_POS		12u
#define MCHP_QMSPI_M_CS_MASK0		0x03u
#define MCHP_QMSPI_M_CS_MASK		SHLU32(3u, 12)
#define MCHP_QMSPI_M_CS0		SHLU32(0u, 12)
#define MCHP_QMSPI_M_CS1		SHLU32(1u, 12)
/* Two chip selects only 0 and 1 */
#define MCHP_QMSPI_M_CS(n) \
	(((uint32_t)(n) & MCHP_QMSPI_M_CS_MASK0) << MCHP_QMSPI_M_CS_POS)
#define MCHP_QMSPI_M_FDIV_POS		16u
#define MCHP_QMSPI_M_FDIV_MASK0		0xffffu
#define MCHP_QMSPI_M_FDIV_MASK		0xffff0000u

/* Control/Descriptors */
#define MCHP_QMSPI_C_IFM_MASK		0x03u
#define MCHP_QMSPI_C_IFM_1X		0u
#define MCHP_QMSPI_C_IFM_2X		1u
#define MCHP_QMSPI_C_IFM_4X		2u
#define MCHP_QMSPI_C_TX_POS		2u
#define MCHP_QMSPI_C_TX_MASK		SHLU32(3u, MCHP_QMSPI_C_TX_POS)
#define MCHP_QMSPI_C_TX_DIS		0u
#define MCHP_QMSPI_C_TX_DATA		SHLU32(1u, MCHP_QMSPI_C_TX_POS)
#define MCHP_QMSPI_C_TX_ZEROS		SHLU32(2u, MCHP_QMSPI_C_TX_POS)
#define MCHP_QMSPI_C_TX_ONES		SHLU32(3u, MCHP_QMSPI_C_TX_POS)
#define MCHP_QMSPI_C_TX_DMA_POS		4u
#define MCHP_QMSPI_C_TX_DMA_MASK	SHLU32(3u, MCHP_QMSPI_C_TX_DMA_POS)
#define MCHP_QMSPI_C_TX_DMA_DIS		0u
#define MCHP_QMSPI_C_TX_DMA_1B		SHLU32(1u, MCHP_QMSPI_C_TX_DMA_POS)
#define MCHP_QMSPI_C_TX_DMA_2B		SHLU32(2u, MCHP_QMSPI_C_TX_DMA_POS)
#define MCHP_QMSPI_C_TX_DMA_4B		SHLU32(3u, MCHP_QMSPI_C_TX_DMA_POS)
#define MCHP_QMSPI_C_TX_LDMA_CH0	SHLU32(1u, MCHP_QMSPI_C_TX_DMA_POS)
#define MCHP_QMSPI_C_TX_LDMA_CH1	SHLU32(2u, MCHP_QMSPI_C_TX_DMA_POS)
#define MCHP_QMSPI_C_TX_LDMA_CH2	SHLU32(3u, MCHP_QMSPI_C_TX_DMA_POS)
#define MCHP_QMSPI_C_RX_POS		6u
#define MCHP_QMSPI_C_RX_DIS		0u
#define MCHP_QMSPI_C_RX_EN		BIT(MCHP_QMSPI_C_RX_POS)
#define MCHP_QMSPI_C_RX_DMA_POS		7u
#define MCHP_QMSPI_C_RX_DMA_MASK	SHLU32(3u, MCHP_QMSPI_C_RX_DMA_POS)
#define MCHP_QMSPI_C_RX_DMA_DIS		0u
#define MCHP_QMSPI_C_RX_DMA_1B		SHLU32(1u, MCHP_QMSPI_C_RX_DMA_POS)
#define MCHP_QMSPI_C_RX_DMA_2B		SHLU32(2u, MCHP_QMSPI_C_RX_DMA_POS)
#define MCHP_QMSPI_C_RX_DMA_4B		SHLU32(3u, MCHP_QMSPI_C_RX_DMA_POS)
#define MCHP_QMSPI_C_RX_LDMA_CH0	SHLU32(1u, MCHP_QMSPI_C_RX_DMA_POS)
#define MCHP_QMSPI_C_RX_LDMA_CH1	SHLU32(2u, MCHP_QMSPI_C_RX_DMA_POS)
#define MCHP_QMSPI_C_RX_lDMA_CH2	SHLU32(3u, MCHP_QMSPI_C_RX_DMA_POS)

#define MCHP_QMSPI_C_CLOSE_POS		9u
#define MCHP_QMSPI_C_NO_CLOSE		0u
#define MCHP_QMSPI_C_CLOSE		BIT(MCHP_QMSPI_C_CLOSE_POS)
#define MCHP_QMSPI_C_XFR_UNITS_POS	10u
#define MCHP_QMSPI_C_XFR_UNITS_MASK	SHLU32(3u, MCHP_QMSPI_C_XFR_UNITS_POS)
#define MCHP_QMSPI_C_XFR_UNITS_BITS	0u
#define MCHP_QMSPI_C_XFR_UNITS_1	SHLU32(1u, MCHP_QMSPI_C_XFR_UNITS_POS)
#define MCHP_QMSPI_C_XFR_UNITS_4	SHLU32(2u, MCHP_QMSPI_C_XFR_UNITS_POS)
#define MCHP_QMSPI_C_XFR_UNITS_16	SHLU32(3u, MCHP_QMSPI_C_XFR_UNITS_POS)
#define MCHP_QMSPI_C_NEXT_DESCR_POS	12u
#define MCHP_QMSPI_C_NEXT_DESCR_MASK0	0x0fu
#define MCHP_QMSPI_C_NEXT_DESCR_MASK	0xf000u
#define MCHP_QMSPI_C_DESCR0		0u
#define MCHP_QMSPI_C_DESCR1		0x1000u
#define MCHP_QMSPI_C_DESCR2		0x2000u
#define MCHP_QMSPI_C_DESCR3		0x3000u
#define MCHP_QMSPI_C_DESCR4		0x4000u
/* Control register start descriptor field */
#define MCHP_QMSPI_C_DESCR(n) \
	SHLU32(((n) & 0xFu), MCHP_QMSPI_C_NEXT_DESCR_POS)
/* Descriptor registers next descriptor field */
#define MCHP_QMSPI_C_NEXT_DESCR(n) \
	SHLU32(((n) & 0xFu), MCHP_QMSPI_C_NEXT_DESCR_POS)
/* Control register descriptor mode enable */
#define MCHP_QMSPI_C_DESCR_EN_POS	16u
#define MCHP_QMSPI_C_DESCR_EN		BIT(MCHP_QMSPI_C_DESCR_EN_POS)
/* Descriptor registers last descriptor flag */
#define MCHP_QMSPI_C_DESCR_LAST		BIT(MCHP_QMSPI_C_DESCR_EN_POS)
#define MCHP_QMSPI_C_MAX_UNITS		0x7fffu
#define MCHP_QMSPI_C_MAX_UNITS_MASK	0x7fffu
#define MCHP_QMSPI_C_XFR_NUNITS_POS	17u
#define MCHP_QMSPI_C_XFR_NUNITS_MASK0	0x7fffu
#define MCHP_QMSPI_C_XFR_NUNITS_MASK	0xfffe0000u
#define MCHP_QMSPI_C_XFR_NUNITS(n) SHLU32((n), MCHP_QMSPI_C_XFR_NUNITS_POS)
#define MCHP_QMSPI_C_XFR_NUNITS_GET(descr) ((uint32_t)(descr) >> 17)

/* Exe */
#define MCHP_QMSPI_EXE_START		BIT(0)
#define MCHP_QMSPI_EXE_STOP		BIT(1)
#define MCHP_QMSPI_EXE_CLR_FIFOS	BIT(2)

/* Interface Control */
#define MCHP_QMSPI_IFC_DFLT		0u
#define MCHP_QMSPI_IFC_WP_OUT_HI	BIT(0)
#define MCHP_QMSPI_IFC_WP_OUT_EN	BIT(1)
#define MCHP_QMSPI_IFC_HOLD_OUT_HI	BIT(2)
#define MCHP_QMSPI_IFC_HOLD_OUT_EN	BIT(3)
#define MCHP_QMSPI_IFC_PD_ON_NS		BIT(4)
#define MCHP_QMSPI_IFC_PU_ON_NS		BIT(5)
#define MCHP_QMSPI_IFC_PD_ON_ND		BIT(6)
#define MCHP_QMSPI_IFC_PU_ON_ND		BIT(7)

/* Status Register */
#define MCHP_QMSPI_STS_REG_MASK		0x0f01ff1fu
#define MCHP_QMSPI_STS_RO_MASK		0x0f013300u
#define MCHP_QMSPI_STS_RW1C_MASK	0x0000cc7fu
#define MCHP_QMSPI_STS_DONE		BIT(0)
#define MCHP_QMSPI_STS_DMA_DONE		BIT(1)
#define MCHP_QMSPI_STS_TXB_ERR		BIT(2)
#define MCHP_QMSPI_STS_RXB_ERR		BIT(3)
#define MCHP_QMSPI_STS_PROG_ERR		BIT(4)
#define MCHP_QMSPI_STS_LDMA_RX_ERR	BIT(5)
#define MCHP_QMSPI_STS_LDMA_TX_ERR	BIT(6)
#define MCHP_QMSPI_STS_TXBF_RO		BIT(8)
#define MCHP_QMSPI_STS_TXBE_RO		BIT(9)
#define MCHP_QMSPI_STS_TXBR		BIT(10)
#define MCHP_QMSPI_STS_TXBS		BIT(11)
#define MCHP_QMSPI_STS_RXBF_RO		BIT(12)
#define MCHP_QMSPI_STS_RXBE_RO		BIT(13)
#define MCHP_QMSPI_STS_RXBR		BIT(14)
#define MCHP_QMSPI_STS_RXBS		BIT(15)
#define MCHP_QMSPI_STS_ACTIVE_RO	BIT(16)
#define MCHP_QMSPI_STS_CD_POS		24u
#define MCHP_QMSPI_STS_CD_MASK0		0x0fu
#define MCHP_QMSPI_STS_CD_MASK		0x0f000000u

/* Buffer Count Status (RO) */
#define MCHP_QMSPI_TX_BUF_CNT_STS_POS	0u
#define MCHP_QMSPI_TX_BUF_CNT_STS_MASK	0xffffu
#define MCHP_QMSPI_RX_BUF_CNT_STS_POS	16u
#define MCHP_QMSPI_RX_BUF_CNT_STS_MASK	0xffff0000u

/* Interrupt Enable Register */
#define MCHP_QMSPI_IEN_XFR_DONE		BIT(0)
#define MCHP_QMSPI_IEN_DMA_DONE		BIT(1)
#define MCHP_QMSPI_IEN_TXB_ERR		BIT(2)
#define MCHP_QMSPI_IEN_RXB_ERR		BIT(3)
#define MCHP_QMSPI_IEN_PROG_ERR		BIT(4)
#define MCHP_QMSPI_IEN_LDMA_RX_ERR	BIT(5)
#define MCHP_QMSPI_IEN_LDMA_TX_ERR	BIT(6)
#define MCHP_QMSPI_IEN_TXB_FULL		BIT(8)
#define MCHP_QMSPI_IEN_TXB_EMPTY	BIT(9)
#define MCHP_QMSPI_IEN_TXB_REQ		BIT(10)
#define MCHP_QMSPI_IEN_RXB_FULL		BIT(12)
#define MCHP_QMSPI_IEN_RXB_EMPTY	BIT(13)
#define MCHP_QMSPI_IEN_RXB_REQ		BIT(14)

/* Buffer Count Trigger (RW) */
#define MCHP_QMSPI_TX_BUF_CNT_TRIG_POS		0u
#define MCHP_QMSPI_RX_BUF_CNT_TRIG_POS		16u

/* Chip Select Timing (RW) */
#define MCHP_QMSPI_CSTM_MASK			0xff0f0f0fu
#define MCHP_QMSPI_CSTM_DFLT			0x06060406u
#define MCHP_QMSPI_DLY_CS_ON_CK_STR_POS		0u
#define MCHP_QMSPI_DLY_CS_ON_CK_STR_MASK	0x0fu
#define MCHP_QMSPI_DLY_CK_STP_CS_OFF_POS	8u
#define MCHP_QMSPI_DLY_CK_STP_CS_OFF_MASK	0x0f00u
#define MCHP_QMSPI_DLY_LST_DAT_HLD_POS		16u
#define MCHP_QMSPI_DLY_LST_DAT_HLD_MASK		0x0f0000u
#define MCHP_QMSPI_DLY_CS_OFF_CS_ON_POS		24u
#define MCHP_QMSPI_DLY_CS_OFF_CS_ON_MASK	0x0f000000u

/* Alias Control (WO) */
#define MCHP_QMSPI_ACTRL_MASK		0xffffff7fu
#define MCHP_QMSPI_ACTRL_ESTART		BIT(0)
#define MCHP_QMSPI_ACTRL_CDE		BIT(1)
#define MCHP_QMSPI_ACTRL_TXBW		BIT(2)
#define MCHP_QMSPI_ACTRL_DLEN		BIT(3)
#define MCHP_QMSPI_ACTRL_CS_POS		4
#define MCHP_QMSPI_ACTRL_CS0		0u
#define MCHP_QMSPI_ACTRL_CS1		0x10u
#define MCHP_QMSPI_ACTRL_LDIA		BIT(6)
#define MCHP_QMSPI_ACTRL_DBP_POS	8
#define MCHP_QMSPI_ACTRL_DBP_0		0u
#define MCHP_QMSPI_ACTRL_DBP_1		0x100u
#define MCHP_QMSPI_ACTRL_DBP_N(n)	SHLU32(((n) & 0xFu), 8)
#define MCHP_QMSPI_ACTRL_BSEL_POS	12
#define MCHP_QMSPI_ACTRL_BSEL_MSK	0xf000u
#define MCHP_QMSPI_ACTRL_DBLEN_POS	16
#define MCHP_QMSPI_ACTRL_DBLEN_MSK	0xff0000u
#define MCHP_QMSPI_ACTRL_TXB_DATA_POS	24
#define MCHP_QMSPI_ACTRL_TXB_DATA_MSK	0xff000000u

/* Mode Alternate 1 (RW) */
#define MCHP_QMSPI_MA1_MASK		0xffff0001u
#define MCHP_QMSPI_MA1_CS1_CDIV_EN	BIT(0)
#define MCHP_QMSPI_MA1_CS1_CDIV_POS	16
#define MCHP_QMSPI_MA1_CS1_CDIV_MSK	0xffff0000u

/* TAPS select and TAPS Adjust registers */
#define MCHP_QMSPI_TAPS_MASK		0xffffu
#define MCHP_QMSPI_TAPS_SCK_MASK	0xffu
#define MCHP_QMSPI_TAPS_CTL_MASK	0xff00u

/* TAPS Control register */
#define MCHP_QMSPI_TCTRL_MASK		0x70107u
#define MCHP_QMSPI_TCTRL_AUTO_MODE_MASK 0x03u
#define MCHP_QMSPI_TCTRL_AM_OFF		0x00u
#define MCHP_QMSPI_TCTRL_AM_ON		0x01u
#define MCHP_QMSPI_TCTRL_AM_PERIODIC	0x02u
#define MCHP_QMSPI_TCTRL_UPDATE_EN	BIT(2)
#define MCHP_QMSPI_TCTRL_UPDATE_NOW	BIT(8)
#define MCHP_QMSPI_TCTRL_MULT_POS	16
#define MCHP_QMSPI_TCTRL_MULT_MSK	0x70000u

/* Local DMA RX Descriptor Enable bit map */
/* Local DMA TX Descriptor Enable bit map */
#define MCHP_QMSPI_LDMA_DESCR_EN_MASK	0xffffu
#define MCHP_QMSPI_LDMA_DESCR_EN(n)	BIT((n) & 0xfu)

/* Each Local DMA channel implements 4 32-bit registers.
 * Channels are identical for RX and TX
 * offset 0x00: Control
 * offset 0x04: memory start address
 * offset 0x08: transfer byte length
 * offset 0x0c: reserved read-only 0
 */

/* LDMA Channel Control register */
#define MCHP_QMSPI_LDC_MASK		0x7fu
/* enable channel */
#define MCHP_QMSPI_LDC_EN		BIT(0)
/* re-enable channel upon done */
#define MCHP_QMSPI_LDC_RS_EN		BIT(1)
/* on restart put memory start address back to its original value */
#define MCHP_QMSPI_LDC_RSA_EN		BIT(2)
/* use channel length not length in descriptor */
#define MCHP_QMSPI_LDC_UCHL_EN		BIT(3)
/* LDMA unit(access) size: 1, 2, or 4 bytes */
#define MCHP_QMSPI_LDC_ASZ_POS		4
#define MCHP_QMSPI_LDC_ASZ_MSK		0x30u
#define MCHP_QMSPI_LDC_ASZ_1		0u
#define MCHP_QMSPI_LDC_ASZ_2		0x10u
#define MCHP_QMSPI_LDC_ASZ_4		0x20u
/* LDMA increment memory start address by access size */
#define MCHP_QMSPI_LDC_INCR_EN		BIT(6)

/* LDMA Channel (memory) Start address register */
#define MCHP_QMSPI_LDMS_MASK		0xffffffffu

/* LDMA Channel Length register */
#define MCHP_QMSPI_LDLEN_MASK		0xffffffffu

/** @brief QMSPI Local DMA channel registers */
struct qldma_chan {
	volatile uint32_t CTRL;
	volatile uint32_t MSTART;
	volatile uint32_t LEN;
	uint32_t RSVD1[1];
};

/** @brief QMSPI controller. Size = 368(0x170) */
struct qmspi_regs {
	volatile uint32_t MODE;
	volatile uint32_t CTRL;
	volatile uint32_t EXE;
	volatile uint32_t IFCTRL;
	volatile uint32_t STS;
	volatile uint32_t BCNT_STS;
	volatile uint32_t IEN;
	volatile uint32_t BCNT_TRIG;
	volatile uint32_t TX_FIFO;
	volatile uint32_t RX_FIFO;
	volatile uint32_t CSTM;
	uint32_t RSVD1[1];
	volatile uint32_t DESCR[16];
	uint32_t RSVD2[16];
	volatile uint32_t ALIAS_CTRL;
	uint32_t RSVD3[3];
	volatile uint32_t MODE_ALT1;
	uint32_t RSVD4[3];
	volatile uint32_t TM_TAPS;
	volatile uint32_t TM_TAPS_ADJ;
	volatile uint32_t TM_TAPS_CTRL;
	uint32_t RSVD5[9];
	volatile uint32_t LDMA_RX_DESCR_BM;
	volatile uint32_t LDMA_TX_DESCR_BM;
	uint32_t RSVD6[2];
	struct qldma_chan LDRX[3];
	struct qldma_chan LDTX[3];
};

#endif /* #ifndef _MEC_QSPI_H */
