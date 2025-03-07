/*
 * Copyright (c) 2021 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _MEC172X_ESPI_IO_H
#define _MEC172X_ESPI_IO_H

#include <stdint.h>
#include <stddef.h>

/* Offsets from base for various register groups */
#define MCHP_ESPI_IO_PC_OFS		0x0100u
#define MCHP_ESPI_IO_HOST_BAR_OFS	0x0120u
#define MCHP_ESPI_IO_LTR_OFS		0x0220u
#define MCHP_ESPI_IO_OOB_OFS		0x0240u
#define MCHP_ESPI_IO_FC_OFS		0x0280u
#define MCHP_ESPI_IO_CAP_OFS		0x02b0u
#define MCHP_ESPI_IO_SIRQ_OFS		0x03a0u

/* eSPI Global Capabilities 0 */
#define MCHP_ESPI_GBL_CAP0_MASK		0x0fu
#define MCHP_ESPI_GBL_CAP0_PC_SUPP	BIT(0)
#define MCHP_ESPI_GBL_CAP0_VW_SUPP	BIT(1)
#define MCHP_ESPI_GBL_CAP0_OOB_SUPP	BIT(2)
#define MCHP_ESPI_GBL_CAP0_FC_SUPP	BIT(3)

/* eSPI Global Capabilities 1 */
#define MCHP_ESPI_GBL_CAP1_MASK			0xffu
#define MCHP_ESPI_GBL_CAP1_MAX_FREQ_POS		0u
#define MCHP_ESPI_GBL_CAP1_MAX_FREQ_MASK	0x07u
#define MCHP_ESPI_GBL_CAP1_MAX_FREQ_20M		0x00u
#define MCHP_ESPI_GBL_CAP1_MAX_FREQ_25M		0x01u
#define MCHP_ESPI_GBL_CAP1_MAX_FREQ_33M		0x02u
#define MCHP_ESPI_GBL_CAP1_MAX_FREQ_50M		0x03u
#define MCHP_ESPI_GBL_CAP1_MAX_FREQ_66M		0x04u
#define MCHP_ESPI_GBL_CAP1_ALERT_POS		3u /* Read-Only */
#define MCHP_ESPI_GBL_CAP1_ALERT_DED_PIN	\
	BIT(MCHP_ESPI_GBL_CAP1_ALERT_POS)
#define MCHP_ESPI_GBL_CAP1_ALERT_ON_IO1		0u
#define MCHP_ESPI_GBL_CAP1_IO_MODE_POS		4u
#define MCHP_ESPI_GBL_CAP1_IO_MODE_MASK0	0x03u
#define MCHP_ESPI_GBL_CAP1_IO_MODE_MASK		SHLU32(0x03u, 4)
#define MCHP_ESPI_GBL_CAP1_IO_MODE0_1		0u
#define MCHP_ESPI_GBL_CAP1_IO_MODE0_12		1u
#define MCHP_ESPI_GBL_CAP1_IO_MODE0_14		2u
#define MCHP_ESPI_GBL_CAP1_IO_MODE0_124		3u
#define MCHP_ESPI_GBL_CAP1_IO_MODE_1		\
	SHLU32(MCHP_ESPI_GBL_CAP1_IO_MODE0_1, MCHP_ESPI_GBL_CAP1_IO_MODE_POS)

#define MCHP_ESPI_GBL_CAP1_IO_MODE_12		\
	SHLU32(MCHP_ESPI_GBL_CAP1_IO_MODE0_12, MCHP_ESPI_GBL_CAP1_IO_MODE_POS)

#define MCHP_ESPI_GBL_CAP1_IO_MODE_14		\
	SHLU32(MCHP_ESPI_GBL_CAP1_IO_MODE0_14, MCHP_ESPI_GBL_CAP1_IO_MODE_POS)

#define MCHP_ESPI_GBL_CAP1_IO_MODE_124		\
	SHLU32(MCHP_ESPI_GBL_CAP1_IO_MODE0_124, MCHP_ESPI_GBL_CAP1_IO_MODE_POS)

/*
 * Support Open Drain ALERT pin configuration
 * EC sets this bit if it can support open-drain ESPI_ALERT#
 */
#define MCHP_ESPI_GBL_CAP1_ALERT_ODS_POS	6u
#define MCHP_ESPI_GBL_CAP1_ALERT_ODS BIT(MCHP_ESPI_GBL_CAP1_ALERT_ODS_POS)

/*
 * Read-Only ALERT Open Drain select.
 * If EC has indicated it can support open-drain ESPI_ALERT# then
 * the Host can enable open-drain ESPI_ALERT# by sending a configuration
 * message. This read-only bit reflects the configuration selection.
 */
#define MCHP_ESPI_GBL_CAP1_ALERT_ODS_SEL_POS	7u
#define MCHP_ESPI_GBL_CAP1_ALERT_SEL_ODS \
	BIT(MCHP_ESPI_GBL_CAP1_ALERT_ODS_SEL_POS)

/* Peripheral Channel(PC) Capabilities */
#define MCHP_ESPI_PC_CAP_MASK			0x07u
#define MCHP_ESPI_PC_CAP_MAX_PLD_SZ_MASK	0x07u
#define MCHP_ESPI_PC_CAP_MAX_PLD_SZ_64		0x01u
#define MCHP_ESPI_PC_CAP_MAX_PLD_SZ_128		0x02u
#define MCHP_ESPI_PC_CAP_MAX_PLD_SZ_256		0x03u

/* Virtual Wire(VW) Capabilities */
#define MCHP_ESPI_VW_CAP_MASK			0x3fu
#define MCHP_ESPI_VW_CAP_MAX_VW_CNT_MASK	0x3fu

/* Out-of-Band(OOB) Capabilities */
#define MCHP_ESPI_OOB_CAP_MASK			0x07u
#define MCHP_ESPI_OOB_CAP_MAX_PLD_SZ_MASK	0x07u
#define MCHP_ESPI_OOB_CAP_MAX_PLD_SZ_73		0x01u
#define MCHP_ESPI_OOB_CAP_MAX_PLD_SZ_137	0x02u
#define MCHP_ESPI_OOB_CAP_MAX_PLD_SZ_265	0x03u

/* Flash Channel(FC) Capabilities */
#define MCHP_ESPI_FC_CAP_MASK			0xffu
#define MCHP_ESPI_FC_CAP_MAX_PLD_SZ_MASK	0x07u
#define MCHP_ESPI_FC_CAP_MAX_PLD_SZ_64		0x01u
#define MCHP_ESPI_FC_CAP_SHARE_POS		3u
#define MCHP_ESPI_FC_CAP_SHARE_MASK0		0x03u
#define MCHP_ESPI_FC_CAP_SHARE_MASK		\
	SHLU32(MCHP_ESPI_FC_CAP_SHARE_MASK0, MCHP_ESPI_FC_CAP_SHARE_POS)

#define MCHP_ESPI_FC_CAP_SHARE_MAF_ONLY		0u
#define MCHP_ESPI_FC_CAP_SHARE_MAF2_ONLY	\
	SHLU32(1U, MCHP_ESPI_FC_CAP_SHARE_POS)

#define MCHP_ESPI_FC_CAP_SHARE_SAF_ONLY		\
	SHLU32(2U, MCHP_ESPI_FC_CAP_SHARE_POS)

#define MCHP_ESPI_FC_CAP_SHARE_MAF_SAF		\
	SHLU32(3U, MCHP_ESPI_FC_CAP_SHARE_POS)

#define MCHP_ESPI_FC_CAP_MAX_RD_SZ_POS		5u
#define MCHP_ESPI_FC_CAP_MAX_RD_SZ_MASK0	0x07u
#define MCHP_ESPI_FC_CAP_MAX_RD_SZ_MASK		\
	SHLU32(MCHP_ESPI_FC_CAP_MAX_RD_SZ_MASK0, \
	       MCHP_ESPI_FC_CAP_MAX_RD_SZ_POS)

#define MCHP_ESPI_FC_CAP_MAX_RD_SZ_64		\
	BIT(MCHP_ESPI_FC_CAP_MAX_RD_SZ_POS)

/* PC Ready */
#define MCHP_ESPI_PC_READY_MASK		0x01u;
#define MCHP_ESPI_PC_READY		0x01u;

/* OOB Ready */
#define MCHP_ESPI_OOB_READY_MASK	0x01u;
#define MCHP_ESPI_OOB_READY		0x01u;

/* FC Ready */
#define MCHP_ESPI_FC_READY_MASK		0x01u;
#define MCHP_ESPI_FC_READY		0x01u;

/* ESPI_RESET# Interrupt Status */
#define MCHP_ESPI_RST_ISTS_MASK		0x03u;
#define MCHP_ESPI_RST_ISTS_POS		0u
#define MCHP_ESPI_RST_ISTS		BIT(MCHP_ESPI_RST_ISTS_POS)
#define MCHP_ESPI_RST_ISTS_PIN_RO_POS	1u
#define MCHP_ESPI_RST_ISTS_PIN_RO_HI	BIT(MCHP_ESPI_RST_ISTS_PIN_RO_POS)

/* ESPI_RESET# Interrupt Enable */
#define MCHP_ESPI_RST_IEN_MASK		0x01u
#define MCHP_ESPI_RST_IEN		0x01u

/* eSPI Platform Reset Source */
#define MCHP_ESPI_PLTRST_SRC_MASK	0x01u
#define MCHP_ESPI_PLTRST_SRC_POS	0u
#define MCHP_ESPI_PLTRST_SRC_IS_PIN	0x01u
#define MCHP_ESPI_PLTRST_SRC_IS_VW	0x00u

/* VW Ready */
#define MCHP_ESPI_VW_READY_MASK		0x01u
#define MCHP_ESPI_VW_READY		0x01u

/* SAF Erase Block size */
#define MCHP_ESPI_SERASE_SZ_1K_BITPOS	0
#define MCHP_ESPI_SERASE_SZ_2K_BITPOS	1
#define MCHP_ESPI_SERASE_SZ_4K_BITPOS	2
#define MCHP_ESPI_SERASE_SZ_8K_BITPOS	3
#define MCHP_ESPI_SERASE_SZ_16K_BITPOS	4
#define MCHP_ESPI_SERASE_SZ_32K_BITPOS	5
#define MCHP_ESPI_SERASE_SZ_64K_BITPOS	6
#define MCHP_ESPI_SERASE_SZ_128K_BITPOS 7
#define MCHP_ESPI_SERASE_SZ_1K		BIT(0)
#define MCHP_ESPI_SERASE_SZ_2K		BIT(1)
#define MCHP_ESPI_SERASE_SZ_4K		BIT(2)
#define MCHP_ESPI_SERASE_SZ_8K		BIT(3)
#define MCHP_ESPI_SERASE_SZ_16K		BIT(4)
#define MCHP_ESPI_SERASE_SZ_32K		BIT(5)
#define MCHP_ESPI_SERASE_SZ_64K		BIT(6)
#define MCHP_ESPI_SERASE_SZ_128K	BIT(7)
#define MCHP_ESPI_SERASE_SZ(bitpos) BIT((bitpos) + 10u)

/* VW Error Status */
#define MCHP_ESPI_VW_ERR_STS_MASK		0x33u
#define MCHP_ESPI_VW_ERR_STS_FATAL_POS		0u
#define MCHP_ESPI_VW_ERR_STS_FATAL_RO		\
	BIT(MCHP_ESPI_VW_ERR_STS_FATAL_POS)

#define MCHP_ESPI_VW_ERR_STS_FATAL_CLR_POS	1u
#define MCHP_ESPI_VW_ERR_STS_FATAL_CLR_WO	\
	BIT(MCHP_ESPI_VW_ERR_STS_FATAL_CLR_POS)

#define MCHP_ESPI_VW_ERR_STS_NON_FATAL_POS	4u
#define MCHP_ESPI_VW_ERR_STS_NON_FATAL_RO	\
	BIT(MCHP_ESPI_VW_ERR_STS_NON_FATAL_POS)

#define MCHP_ESPI_VW_ERR_STS_NON_FATAL_CLR_POS	5u
#define MCHP_ESPI_VW_ERR_STS_NON_FATAL_CLR_WO	\
	BIT(MCHP_ESPI_VW_ERR_STS_NON_FATAL_CLR_POS)

/* VW Channel Enable Status */
#define MCHP_ESPI_VW_EN_STS_MASK	0x01u
#define MCHP_ESPI_VW_EN_STS_RO		0x01u

/*
 * MCHP_ESPI_IO_PC - eSPI IO Peripheral Channel registers @ 0x400F3500
 */

/* Peripheral Channel Last Cycle length, type, and tag. */
#define MCHP_ESPI_PC_LC_LEN_POS		0u
#define MCHP_ESPI_PC_LC_LEN_MASK0	0x0fffu
#define MCHP_ESPI_PC_LC_LEN_MASK	0x0fffu
#define MCHP_ESPI_PC_LC_TYPE_POS	12u
#define MCHP_ESPI_PC_LC_TYPE_MASK0	0xffu
#define MCHP_ESPI_PC_LC_TYPE_MASK	(0xffu << 12)
#define MCHP_ESPI_PC_LC_TAG_POS		20u
#define MCHP_ESPI_PC_LC_TAG_MASK0	0x0fu
#define MCHP_ESPI_PC_LC_TAG_MASK	(0x0fu << 20)

/*
 * Peripheral Channel Status
 * Bus error, Channel enable change, and Bus master enable change.
 */
#define MCHP_ESPI_PC_STS_BUS_ERR_POS	16u /* RW1C */
#define MCHP_ESPI_PC_STS_BUS_ERR	BIT(MCHP_ESPI_PC_STS_BUS_ERR_POS)
#define MCHP_ESPI_PC_STS_EN_POS		24u /* RO */
#define MCHP_ESPI_PC_STS_EN		BIT(MCHP_ESPI_PC_STS_EN_POS)
#define MCHP_ESPI_PC_STS_EN_CHG_POS	25u /* RW1C */
#define MCHP_ESPI_PC_STS_EN_CHG		BIT(MCHP_ESPI_PC_STS_EN_CHG_POS)
#define MCHP_ESPI_PC_STS_BM_EN_POS	27u /* RO */
#define MCHP_ESPI_PC_STS_BM_EN		BIT(MCHP_ESPI_PC_STS_BM_EN_POS)
#define MCHP_ESPI_PC_STS_BM_EN_CHG_POS	28u /* RW1C */
#define MCHP_ESPI_PC_STS_BM_EN_CHG	BIT(MCHP_ESPI_PC_STS_BM_EN_CHG_POS)

/*
 * Peripheral Channel Interrupt Enables for
 * Bus error, Channel enable change, and Bus master enable change.
 * PC_LC_ADDR_LSW (@ 0x0000) Periph Chan Last Cycle address LSW
 * PC_LC_ADDR_MSW (@ 0x0004) Periph Chan Last Cycle address MSW
 * PC_LC_LEN_TYPE_TAG (@ 0x0008) Periph Chan Last Cycle length/type/tag
 * PC_ERR_ADDR_LSW (@ 0x000C) Periph Chan Error Address LSW
 * PC_ERR_ADDR_MSW (@ 0x0010) Periph Chan Error Address MSW
 * PC_STATUS (@ 0x0014) Periph Chan Status
 * PC_IEN (@ 0x0018) Periph Chan IEN
 */
#define MCHP_ESPI_PC_IEN_BUS_ERR_POS	16u
#define MCHP_ESPI_PC_IEN_BUS_ERR	BIT(MCHP_ESPI_PC_IEN_BUS_ERR_POS)
#define MCHP_ESPI_PC_IEN_EN_CHG_POS	25u
#define MCHP_ESPI_PC_IEN_EN_CHG		BIT(MCHP_ESPI_PC_IEN_BUS_ERR_POS)
#define MCHP_ESPI_PC_IEN_BM_EN_CHG_POS	28u
#define MCHP_ESPI_PC_IEN_BM_EN_CHG	BIT(MCHP_ESPI_PC_IEN_BUS_ERR_POS)

/*---- ESPI_IO_LTR - eSPI IO LTR registers ----*/
#define MCHP_ESPI_LTR_STS_TX_DONE_POS	0u /* RW1C */
#define MCHP_ESPI_LTR_STS_TX_DONE	BIT(MCHP_ESPI_LTR_STS_TX_DONE_POS)
#define MCHP_ESPI_LTR_STS_OVRUN_POS	3u /* RW1C */
#define MCHP_ESPI_LTR_STS_OVRUN		BIT(MCHP_ESPI_LTR_STS_OVRUN_POS)
#define MCHP_ESPI_LTR_STS_HDIS_POS	4u /* RW1C */
#define MCHP_ESPI_LTR_STS_HDIS		BIT(MCHP_ESPI_LTR_STS_HDIS_POS)
#define MCHP_ESPI_LTR_STS_TX_BUSY_POS	8u /* RO */
#define MCHP_ESPI_LTR_STS_TX_BUSY	BIT(MCHP_ESPI_LTR_STS_TX_BUSY_POS)

#define MCHP_ESPI_LTR_IEN_TX_DONE_POS	0u
#define MCHP_ESPI_LTR_IEN_TX_DONE	BIT(MCHP_ESPI_LTR_IEN_TX_DONE_POS)

#define MCHP_ESPI_LTR_CTRL_START_POS	0u
#define MCHP_ESPI_LTR_CTRL_START	BIT(MCHP_ESPI_LTR_CTRL_START_POS)
#define MCHP_ESPI_LTR_CTRL_TAG_POS	8u
#define MCHP_ESPI_LTR_CTRL_TAG_MASK0	0x0fu
#define MCHP_ESPI_LTR_CTRL_TAG_MASK	\
	SHLU32(MCHP_ESPI_LTR_CTRL_TAG_MASK0, MCHP_ESPI_LTR_CTRL_TAG_POS)

#define MCHP_ESPI_LTR_MSG_VAL_POS	0u
#define MCHP_ESPI_LTR_MSG_VAL_MASK0	0x3ffu
#define MCHP_ESPI_LTR_MSG_VAL_MASK	\
	SHLU32(MCHP_ESPI_LTR_MSG_VAL_MASK0, MCHP_ESPI_LTR_MSG_VAL_POS)
#define MCHP_ESPI_LTR_MSG_SC_POS	10u
#define MCHP_ESPI_LTR_MSG_SC_MASK0	0x07u
#define MCHP_ESPI_LTR_MSG_SC_MASK	\
	SHLU32(MCHP_ESPI_LTR_MSG_SC_MASK0, MCHP_ESPI_LTR_MSG_SC_POS)
#define MCHP_ESPI_LTR_MSG_RT_POS	13u
#define MCHP_ESPI_LTR_MSG_RT_MASK0	0x03u
#define MCHP_ESPI_LTR_MSG_RT_MASK	\
	SHLU32(MCHP_ESPI_LTR_MSG_RT_MASK0, MCHP_ESPI_LTR_MSG_RT_POS)
/* eSPI specification indicates RT field must be 00b */
#define MCHP_ESPI_LTR_MSG_RT_VAL	0u
#define MCHP_ESPI_LTR_MSG_REQ_POS	15u
/* infinite latency(default) */
#define MCHP_ESPI_LTR_MSG_REQ_INF	0u
/* latency computed from VAL and SC(scale) fields */
#define MCHP_ESPI_LTR_MSG_REQ_VAL	 BIT(MCHP_ESPI_LTR_MSG_REQ_POS)

/*---- ESPI_IO_OOB - eSPI IO OOB registers ----*/
#define MCHP_ESPI_OOB_RX_ADDR_LSW_MASK	0xfffffffcu
#define MCHP_ESPI_OOB_TX_ADDR_LSW_MASK	0xfffffffcu

/* OOB RX_LEN register */
/* Number of bytes received (RO) */
#define MCHP_ESPI_OOB_RX_LEN_POS	0u
#define MCHP_ESPI_OOB_RX_LEN_MASK	0x1fffu
/* Receive buffer length field (RW) */
#define MCHP_ESPI_OOB_RX_BUF_LEN_POS	16u
#define MCHP_ESPI_OOB_RX_BUF_LEN_MASK0	0x1fffu
#define MCHP_ESPI_OOB_RX_BUF_LEN_MASK	\
	SHLU32(MCHP_ESPI_OOB_RX_BUF_LEN_MASK0, MCHP_ESPI_OOB_RX_BUF_LEN_POS)

/* OOB TX_LEN register */
#define MCHP_ESPI_OOB_TX_MSG_LEN_POS	0u
#define MCHP_ESPI_OOB_TX_MSG_LEN_MASK	0x1fffu

/* OOB RX_CTRL */
/* Set AVAIL bit to indicate SRAM Buffer and size has been configured */
#define MCHP_ESPI_OOB_RX_CTRL_AVAIL_POS	0u /* WO */
#define MCHP_ESPI_OOB_RX_CTRL_AVAIL	BIT(MCHP_ESPI_OOB_RX_CTRL_AVAIL_POS)
#define MCHP_ESPI_OOB_RX_CTRL_CHEN_POS	9u /* RO */
#define MCHP_ESPI_OOB_RX_CTRL_CHEN	BIT(MCHP_ESPI_OOB_RX_CTRL_CHEN_POS)
/* Copy of eSPI OOB Capabilities max. payload size */
#define MCHP_ESPI_OOB_RX_CTRL_MAX_SZ_POS	16u /* RO */
#define MCHP_ESPI_OOB_RX_CTRL_MAX_SZ_MASK0	0x07u
#define MCHP_ESPI_OOB_RX_CTRL_MAX_SZ_MASK	\
	SHLU32(MCHP_ESPI_OOB_RX_CTRL_MAX_SZ_MASK0, \
	       MCHP_ESPI_OOB_RX_CTRL_MAX_SZ_POS)

/* OOB RX_IEN */
#define MCHP_ESPI_OOB_RX_IEN_POS	0u
#define MCHP_ESPI_OOB_RX_IEN		BIT(MCHP_ESPI_OOB_RX_IEN_POS)

/* OOB RX_STS */
#define MCHP_ESPI_OOB_RX_STS_DONE_POS	0u /* RW1C */
#define MCHP_ESPI_OOB_RX_STS_DONE	BIT(MCHP_ESPI_OOB_RX_STS_DONE_POS)
#define MCHP_ESPI_OOB_RX_STS_IBERR_POS	1u  /* RW1C */
#define MCHP_ESPI_OOB_RX_STS_IBERR	BIT(MCHP_ESPI_OOB_RX_STS_IBERR_POS)
#define MCHP_ESPI_OOB_RX_STS_OVRUN_POS	2u  /* RW1C */
#define MCHP_ESPI_OOB_RX_STS_OVRUN	BIT(MCHP_ESPI_OOB_RX_STS_OVRUN_POS)
#define MCHP_ESPI_OOB_RX_STS_RXEN_POS	3u  /* RO */
#define MCHP_ESPI_OOB_RX_STS_RXEN	BIT(MCHP_ESPI_OOB_RX_STS_RXEN_POS)
#define MCHP_ESPI_OOB_RX_STS_TAG_POS	8u  /* RO */
#define MCHP_ESPI_OOB_RX_STS_TAG_MASK0	0x0fu
#define MCHP_ESPI_OOB_RX_STS_TAG_MASK	\
	SHLU32(MCHP_ESPI_OOB_RX_STS_TAG_MASK0, MCHP_ESPI_OOB_RX_STS_TAG_POS)

#define MCHP_ESPI_OOB_RX_STS_ALL_RW1C	0x07u
#define MCHP_ESPI_OOB_RX_STS_ALL	0x0fu

/* OOB TX_CTRL */
#define MCHP_ESPI_OOB_TX_CTRL_START_POS 0u /* WO */
#define MCHP_ESPI_OOB_TX_CTRL_START	BIT(MCHP_ESPI_OOB_TX_CTRL_START_POS)
#define MCHP_ESPI_OOB_TX_CTRL_TAG_POS	8u  /* RW */
#define MCHP_ESPI_OOB_TX_CTRL_TAG_MASK0 0x0fu
#define MCHP_ESPI_OOB_TX_CTRL_TAG_MASK	\
	SHLU32(MCHP_ESPI_OOB_TX_CTRL_TAG_MASK0, MCHP_ESPI_OOB_TX_CTRL_TAG_POS)

/* OOB TX_IEN */
#define MCHP_ESPI_OOB_TX_IEN_DONE_POS	0u
#define MCHP_ESPI_OOB_TX_IEN_DONE	BIT(MCHP_ESPI_OOB_TX_IEN_DONE_POS)
#define MCHP_ESPI_OOB_TX_IEN_CHG_EN_POS 1u
#define MCHP_ESPI_OOB_TX_IEN_CHG_EN	BIT(MCHP_ESPI_OOB_TX_IEN_CHG_EN_POS)
#define MCHP_ESPI_OOB_TX_IEN_ALL	0x03u

/* OOB TX_STS */
#define MCHP_ESPI_OOB_TX_STS_DONE_POS	0u /* RW1C */
#define MCHP_ESPI_OOB_TX_STS_DONE	BIT(MCHP_ESPI_OOB_TX_STS_DONE_POS)
#define MCHP_ESPI_OOB_TX_STS_CHG_EN_POS 1u /* RW1C */
#define MCHP_ESPI_OOB_TX_STS_CHG_EN	BIT(MCHP_ESPI_OOB_TX_STS_CHG_EN_POS)
#define MCHP_ESPI_OOB_TX_STS_IBERR_POS	2u /* RW1C */
#define MCHP_ESPI_OOB_TX_STS_IBERR	BIT(MCHP_ESPI_OOB_TX_STS_IBERR_POS)
#define MCHP_ESPI_OOB_TX_STS_OVRUN_POS	3u /* RW1C */
#define MCHP_ESPI_OOB_TX_STS_OVRUN	BIT(MCHP_ESPI_OOB_TX_STS_OVRUN_POS)
#define MCHP_ESPI_OOB_TX_STS_BADREQ_POS 5u /* RW1C */
#define MCHP_ESPI_OOB_TX_STS_BADREQ	BIT(MCHP_ESPI_OOB_TX_STS_BADREQ_POS)
#define MCHP_ESPI_OOB_TX_STS_BUSY_POS	8u /* RO */
#define MCHP_ESPI_OOB_TX_STS_BUSY	BIT(MCHP_ESPI_OOB_TX_STS_BUSY_POS)
/* Read-only copy of OOB Channel Enabled bit */
#define MCHP_ESPI_OOB_TX_STS_CHEN_POS	9u /* RO */
#define MCHP_ESPI_OOB_TX_STS_CHEN	BIT(MCHP_ESPI_OOB_TX_STS_CHEN_POS)

#define MCHP_ESPI_OOB_TX_STS_ALL_RW1C	0x2fu

/*---- MCHP_ESPI_IO_FC - eSPI IO Flash channel registers ----*/
/* FC MEM_ADDR_LSW */
#define MCHP_ESPI_FC_MEM_ADDR_LSW_MASK	0xfffffffcu

/* FC CTRL */
#define MCHP_ESPI_FC_CTRL_START_POS	0u /* WO */
#define MCHP_ESPI_FC_CTRL_START		BIT(MCHP_ESPI_FC_CTRL_START_POS)
#define MCHP_ESPI_FC_CTRL_FUNC_POS	2u  /* RW */
#define MCHP_ESPI_FC_CTRL_FUNC_MASK0	0x03u
#define MCHP_ESPI_FC_CTRL_FUNC_MASK	\
	SHLU32(MCHP_ESPI_FC_CTRL_FUNC_MASK0, MCHP_ESPI_FC_CTRL_FUNC_POS)
#define MCHP_ESPI_FC_CTRL_RD0		0x00u
#define MCHP_ESPI_FC_CTRL_WR0		0x01u
#define MCHP_ESPI_FC_CTRL_ERS0		0x02u
#define MCHP_ESPI_FC_CTRL_ERL0		0x03u
#define MCHP_ESPI_FC_CTRL_FUNC(f)	\
	(SHLU32((uint32_t)(f), MCHP_ESPI_FC_CTRL_FUNC_POS) & \
	MCHP_ESPI_FC_CTRL_FUNC_MASK)

#define MCHP_ESPI_FC_CTRL_TAG_POS	4u
#define MCHP_ESPI_FC_CTRL_TAG_MASK0	0x0fu
#define MCHP_ESPI_FC_CTRL_TAG_MASK	\
	SHLU32(MCHP_ESPI_FC_CTRL_TAG_MASK0, MCHP_ESPI_FC_CTRL_TAG_POS)

#define MCHP_ESPI_FC_CTRL_TAG(t)	\
	((uint32_t)(t) & MCHP_ESPI_FC_CTRL_TAG_MASK)

#define MCHP_ESPI_FC_CTRL_ABORT_POS	16u /* WO */
#define MCHP_ESPI_FC_CTRL_ABORT		BIT(MCHP_ESPI_FC_CTRL_ABORT_POS)

/* FC IEN */
#define MCHP_ESPI_FC_IEN_DONE_POS	0u
#define MCHP_ESPI_FC_IEN_DONE		BIT(MCHP_ESPI_FC_IEN_DONE_POS)
#define MCHP_ESPI_FC_IEN_CHG_EN_POS	1u
#define MCHP_ESPI_FC_IEN_CHG_EN		BIT(MCHP_ESPI_FC_IEN_CHG_EN_POS)

/* FC CFG */
#define MCHP_ESPI_FC_CFG_BUSY_POS	0u /* RO */
#define MCHP_ESPI_FC_CFG_BUSY		BIT(MCHP_ESPI_FC_CFG_BUSY_POS)
#define MCHP_ESPI_FC_CFG_ERBSZ_POS	2u  /* RO */
#define MCHP_ESPI_FC_CFG_ERBSZ_MASK0	0x07u
#define MCHP_ESPI_FC_CFG_ERBSZ_MASK	\
	SHLU32(MCHP_ESPI_FC_CFG_ERBSZ_MASK0, MCHP_ESPI_FC_CFG_ERBSZ_POS)
#define MCHP_ESPI_FC_CFG_ERBSZ_4K	\
	SHLU32(0x01u, MCHP_ESPI_FC_CFG_ERBSZ_POS)
#define MCHP_ESPI_FC_CFG_ERBSZ_64K	\
	SHLU32(0x02u, MCHP_ESPI_FC_CFG_ERBSZ_POS)
#define MCHP_ESPI_FC_CFG_ERBSZ_4K_64K	\
	SHLU32(0x03u, MCHP_ESPI_FC_CFG_ERBSZ_POS)
#define MCHP_ESPI_FC_CFG_ERBSZ_128K	\
	SHLU32(0x04u, MCHP_ESPI_FC_CFG_ERBSZ_POS)
#define MCHP_ESPI_FC_CFG_ERBSZ_256K	\
	SHLU32(0x05u, MCHP_ESPI_FC_CFG_ERBSZ_POS)
#define MCHP_ESPI_FC_CFG_MAXPLD_POS	8u /* RO */
#define MCHP_ESPI_FC_CFG_MAXPLD_MASK0	0x07u
#define MCHP_ESPI_FC_CFG_MAXPLD_MASK	\
	SHLU32(MCHP_ESPI_FC_CFG_MAXPLD_MASK0, MCHP_ESPI_FC_CFG_MAXPLD_POS)
#define MCHP_ESPI_FC_CFG_MAXPLD_64B	\
	SHLU32(0x01u, MCHP_ESPI_FC_CFG_MAXPLD_POS)
#define MCHP_ESPI_FC_CFG_MAXPLD_128B	\
	SHLU32(0x02u, MCHP_ESPI_FC_CFG_MAXPLD_POS)
#define MCHP_ESPI_FC_CFG_MAXPLD_256B	\
	SHLU32(0x03u, MCHP_ESPI_FC_CFG_MAXPLD_POS)
#define MCHP_ESPI_FC_CFG_SAFS_SEL_POS	11u
#define MCHP_ESPI_FC_CFG_SAFS_SEL	BIT(MCHP_ESPI_FC_CFG_SAFS_SEL_POS)
#define MCHP_ESPI_FC_CFG_MAXRD_POS	12u /* RO */
#define MCHP_ESPI_FC_CFG_MAXRD_MASK0	0x07u
#define MCHP_ESPI_FC_CFG_MAXRD_MASK	\
	SHLU32(MCHP_ESPI_FC_CFG_MAXRD_MASK0, MCHP_ESPI_FC_CFG_MAXRD_POS)
#define MCHP_ESPI_FC_CFG_MAXRD_64B	\
	SHLU32(0x01u, MCHP_ESPI_FC_CFG_MAXRD_POS)
#define MCHP_ESPI_FC_CFG_MAXRD_128B	\
	SHLU32(0x02u, MCHP_ESPI_FC_CFG_MAXRD_POS)
#define MCHP_ESPI_FC_CFG_MAXRD_256B	\
	SHLU32(0x03u, MCHP_ESPI_FC_CFG_MAXRD_POS)
#define MCHP_ESPI_FC_CFG_MAXRD_512B	\
	SHLU32(0x04u, MCHP_ESPI_FC_CFG_MAXRD_POS)
#define MCHP_ESPI_FC_CFG_MAXRD_1K	\
	SHLU32(0x05u, MCHP_ESPI_FC_CFG_MAXRD_POS)
#define MCHP_ESPI_FC_CFG_MAXRD_2K	\
	SHLU32(0x06u, MCHP_ESPI_FC_CFG_MAXRD_POS)
#define MCHP_ESPI_FC_CFG_MAXRD_4K	\
	SHLU32(0x07u, MCHP_ESPI_FC_CFG_MAXRD_POS)
#define MCHP_ESPI_FC_CFG_FORCE_MS_POS	28u /* RW */
#define MCHP_ESPI_FC_CFG_FORCE_MS_MASK0 0x03u
#define MCHP_ESPI_FC_CFG_FORCE_MS_MASK	\
	SHLU32(MCHP_ESPI_FC_CFG_FORCE_MS_MASK0, MCHP_ESPI_FC_CFG_FORCE_MS_POS)
/* Host (eSPI Master) can select MAFS or SAFS */
#define MCHP_ESPI_FC_CFG_FORCE_NONE	0u
/* EC forces eSPI slave HW to only allow MAFS */
#define MCHP_ESPI_FC_CFG_FORCE_MAFS	\
	SHLU32(0x02u, MCHP_ESPI_FC_CFG_FORCE_MS_POS)
/* EC forces eSPI slave HW to only allow SAFS */
#define MCHP_ESPI_FC_CFG_FORCE_SAFS	\
	SHLU32(0x03u, MCHP_ESPI_FC_CFG_FORCE_MS_POS)

/* FC STS */
#define MCHP_ESPI_FC_STS_CHAN_EN_POS	0u /* RO */
#define MCHP_ESPI_FC_STS_CHAN_EN	BIT(MCHP_ESPI_FC_STS_CHAN_EN_POS)

#define MCHP_ESPI_FC_STS_CHAN_EN_CHG_POS	1u /* RW1C */
#define MCHP_ESPI_FC_STS_CHAN_EN_CHG	BIT(MCHP_ESPI_FC_STS_CHAN_EN_CHG_POS)

#define MCHP_ESPI_FC_STS_DONE_POS	2u /* RW1C */
#define MCHP_ESPI_FC_STS_DONE		BIT(MCHP_ESPI_FC_STS_DONE_POS)
#define MCHP_ESPI_FC_STS_MDIS_POS	3u /* RW1C */
#define MCHP_ESPI_FC_STS_MDIS		BIT(MCHP_ESPI_FC_STS_MDIS_POS)
#define MCHP_ESPI_FC_STS_IBERR_POS	4u /* RW1C */
#define MCHP_ESPI_FC_STS_IBERR		BIT(MCHP_ESPI_FC_STS_IBERR_POS)
#define MCHP_ESPI_FC_STS_ABS_POS	5u /* RW1C */
#define MCHP_ESPI_FC_STS_ABS		BIT(MCHP_ESPI_FC_STS_ABS_POS)
#define MCHP_ESPI_FC_STS_OVRUN_POS	6u /* RW1C */
#define MCHP_ESPI_FC_STS_OVRUN		BIT(MCHP_ESPI_FC_STS_OVRUN_POS)
#define MCHP_ESPI_FC_STS_INC_POS	7u /* RW1C */
#define MCHP_ESPI_FC_STS_INC		BIT(MCHP_ESPI_FC_STS_INC_POS)
#define MCHP_ESPI_FC_STS_FAIL_POS	8u /* RW1C */
#define MCHP_ESPI_FC_STS_FAIL		BIT(MCHP_ESPI_FC_STS_FAIL_POS)
#define MCHP_ESPI_FC_STS_OVFL_POS	9u /* RW1C */
#define MCHP_ESPI_FC_STS_OVFL		BIT(MCHP_ESPI_FC_STS_OVFL_POS)
#define MCHP_ESPI_FC_STS_BADREQ_POS	11u /* RW1C */
#define MCHP_ESPI_FC_STS_BADREQ		BIT(MCHP_ESPI_FC_STS_BADREQ_POS)

#define MCHP_ESPI_FC_STS_ALL_RW1C	0x0bfeu

/*---- MCHP_ESPI_IO_BAR_HOST - eSPI IO Host visible BAR registers ----*/

/*
 * IOBAR_INH_LSW/MSW 64-bit register: each bit = 1 inhibits an I/O BAR
 * independent of the BAR's Valid bit.
 * Logical Device Number = bit position.
 */
#define MCHP_ESPI_IOBAR_LDN_MBOX	0u
#define MCHP_ESPI_IOBAR_LDN_KBC		1u
#define MCHP_ESPI_IOBAR_LDN_ACPI_EC_0	2u
#define MCHP_ESPI_IOBAR_LDN_ACPI_EC_1	3u
#define MCHP_ESPI_IOBAR_LDN_ACPI_EC_2	4u
#define MCHP_ESPI_IOBAR_LDN_ACPI_EC_3	5u
#define MCHP_ESPI_IOBAR_LDN_ACPI_EC_4	6u
#define MCHP_ESPI_IOBAR_LDN_ACPI_PM1	7u
#define MCHP_ESPI_IOBAR_LDN_PORT92	8u
#define MCHP_ESPI_IOBAR_LDN_UART_0	9u
#define MCHP_ESPI_IOBAR_LDN_UART_1	10u
#define MCHP_ESPI_IOBAR_LDN_IOC		13u
#define MCHP_ESPI_IOBAR_LDN_MEM		14u
#define MCHP_ESPI_IOBAR_LDN_GLUE_LOG	15u
#define MCHP_ESPI_IOBAR_LDN_EMI_0	16u
#define MCHP_ESPI_IOBAR_LDN_EMI_1	17u
#define MCHP_ESPI_IOBAR_LDN_EMI_2	18u
#define MCHP_ESPI_IOBAR_LDN_RTC		20u
#define MCHP_ESPI_IOBAR_LDN_P80CAP_0	32u	/* BDP Port80 Capture */
#define MCHP_ESPI_IOBAR_LDN_P80CAP_1	31u	/* BDP Alias Capture */
#define MCHP_ESPI_IOBAR_LDN_T32B	47u
#define MCHP_ESPI_IOBAR_LDN_LASIC	48u

/*
 * IOBAR_INIT: Default address of I/O Plug and Play Super-IO index/data
 * configuration registers. (Defaults to 0x2E/0x2F)
 */
#define MCHP_ESPI_IOBAR_INIT_DFLT	0x2eu

/*
 * EC_IRQ: A write to bit[0] triggers EC SERIRQ. The actual
 * SERIRQ slot is configured in MCHP_ESPI_IO_SIRQ.EC_SIRQ
 */
#define MCHP_ESPI_EC_IRQ_GEN (1u << 0)

/* 32-bit Host IO BAR */
#define MCHP_ESPI_IO_BAR_HOST_VALID_POS		0u
#define MCHP_ESPI_IO_BAR_HOST_VALID		\
	BIT(MCHP_ESPI_IO_BAR_HOST_VALID_POS)
#define MCHP_ESPI_IO_BAR_HOST_ADDR_POS		16u
#define MCHP_ESPI_IO_BAR_HOST_ADDR_MASK0	0xffffu
#define MCHP_ESPI_IO_BAR_HOST_ADDR_MASK		0xffff0000u

/* Offsets from first SIRQ */
#define MCHP_ESPI_SIRQ_MBOX_SIRQ	0u
#define MCHP_ESPI_SIRQ_MBOX_SMI		1u
#define MCHP_ESPI_SIRQ_KBC_KIRQ		2u
#define MCHP_ESPI_SIRQ_KBC_MIRQ		3u
#define MCHP_ESPI_SIRQ_ACPI_EC0		4u
#define MCHP_ESPI_SIRQ_ACPI_EC1		5u
#define MCHP_ESPI_SIRQ_ACPI_EC2		6u
#define MCHP_ESPI_SIRQ_ACPI_EC3		7u
#define MCHP_ESPI_SIRQ_ACPI_EC4		8u
#define MCHP_ESPI_SIRQ_UART0		9u
#define MCHP_ESPI_SIRQ_UART1		10u
#define MCHP_ESPI_SIRQ_EMI0_HOST	11u
#define MCHP_ESPI_SIRQ_EMI0_E2H		12u
#define MCHP_ESPI_SIRQ_EMI1_HOST	13u
#define MCHP_ESPI_SIRQ_EMI1_E2H		14u
#define MCHP_ESPI_SIRQ_EMI2_HOST	15u
#define MCHP_ESPI_SIRQ_EMI2_E2H		16u
#define MCHP_ESPI_SIRQ_RTC		17u
#define MCHP_ESPI_SIRQ_EC		18u
#define MCHP_ESPI_SIRQ_RSVD19		19u
#define MCHP_ESPI_SIRQ_MAX		20u

/*
 * Values for Logical Device SIRQ registers.
 * Unless disabled each logical device must have a unique value
 * programmed to its SIRQ register.
 * Values 0x00u through 0x7Fu are sent using VWire host index 0x00
 * Values 0x80h through 0xFEh are sent using VWire host index 0x01
 * All registers reset default is 0xFFu (disabled).
 */
#define MCHP_ESPI_IO_SIRQ_DIS	0xFFu

/* eSPI Memory component registers */
/* BM_STS */
#define MCHP_ESPI_BM_STS_DONE_1_POS	0u /* RW1C */
#define MCHP_ESPI_BM_STS_DONE_1		BIT(MCHP_ESPI_BM_STS_DONE_1_POS)
#define MCHP_ESPI_BM_STS_BUSY_1_POS	1u /* RO */
#define MCHP_ESPI_BM_STS_BUSY_1		BIT(MCHP_ESPI_BM_STS_BUSY_1_POS)
#define MCHP_ESPI_BM_STS_AB_EC_1_POS	2u /* RW1C */
#define MCHP_ESPI_BM_STS_AB_EC_1	BIT(MCHP_ESPI_BM_STS_AB_EC_1_POS)
#define MCHP_ESPI_BM_STS_AB_HOST_1_POS	3u /* RW1C */
#define MCHP_ESPI_BM_STS_AB_HOST_1	BIT(MCHP_ESPI_BM_STS_AB_HOST_1_POS)
#define MCHP_ESPI_BM_STS_AB_CH2_1_POS	4u /* RW1C */
#define MCHP_ESPI_BM_STS_CH2_AB_1	BIT(MCHP_ESPI_BM_STS_AB_CH2_1_POS)
#define MCHP_ESPI_BM_STS_OVFL_1_POS	5u /* RW1C */
#define MCHP_ESPI_BM_STS_OVFL_1_CH2	BIT(MCHP_ESPI_BM_STS_OVFL_1_POS)
#define MCHP_ESPI_BM_STS_OVRUN_1_POS	6u /* RW1C */
#define MCHP_ESPI_BM_STS_OVRUN_1_CH2	BIT(MCHP_ESPI_BM_STS_OVRUN_1_POS)
#define MCHP_ESPI_BM_STS_INC_1_POS	7u /* RW1C */
#define MCHP_ESPI_BM_STS_INC_1		BIT(MCHP_ESPI_BM_STS_INC_1_POS)
#define MCHP_ESPI_BM_STS_FAIL_1_POS	8u /* RW1C */
#define MCHP_ESPI_BM_STS_FAIL_1		BIT(MCHP_ESPI_BM_STS_FAIL_1_POS)
#define MCHP_ESPI_BM_STS_IBERR_1_POS	9u /* RW1C */
#define MCHP_ESPI_BM_STS_IBERR_1	BIT(MCHP_ESPI_BM_STS_IBERR_1_POS)
#define MCHP_ESPI_BM_STS_BADREQ_1_POS	11u /* RW1C */
#define MCHP_ESPI_BM_STS_BADREQ_1	BIT(MCHP_ESPI_BM_STS_BADREQ_1_POS)
#define MCHP_ESPI_BM_STS_DONE_2_POS	16u /* RW1C */
#define MCHP_ESPI_BM_STS_DONE_2		BIT(MCHP_ESPI_BM_STS_DONE_2_POS)
#define MCHP_ESPI_BM_STS_BUSY_2_POS	17u /* RO */
#define MCHP_ESPI_BM_STS_BUSY_2		BIT(MCHP_ESPI_BM_STS_BUSY_2_POS)
#define MCHP_ESPI_BM_STS_AB_EC_2_POS	18u /* RW1C */
#define MCHP_ESPI_BM_STS_AB_EC_2	BIT(MCHP_ESPI_BM_STS_AB_EC_2_POS)
#define MCHP_ESPI_BM_STS_AB_HOST_2_POS	19u /* RW1C */
#define MCHP_ESPI_BM_STS_AB_HOST_2	BIT(MCHP_ESPI_BM_STS_AB_HOST_2_POS)
#define MCHP_ESPI_BM_STS_AB_CH1_2_POS	20u /* RW1C */
#define MCHP_ESPI_BM_STS_AB_CH1_2	BIT(MCHP_ESPI_BM_STS_AB_CH1_2_POS)
#define MCHP_ESPI_BM_STS_OVFL_2_POS	21u /* RW1C */
#define MCHP_ESPI_BM_STS_OVFL_2_CH2	BIT(MCHP_ESPI_BM_STS_OVFL_2_POS)
#define MCHP_ESPI_BM_STS_OVRUN_2_POS	22u /* RW1C */
#define MCHP_ESPI_BM_STS_OVRUN_CH2_2	BIT(MCHP_ESPI_BM_STS_OVRUN_2_POS)
#define MCHP_ESPI_BM_STS_INC_2_POS	23u /* RW1C */
#define MCHP_ESPI_BM_STS_INC_2		BIT(MCHP_ESPI_BM_STS_INC_2_POS)
#define MCHP_ESPI_BM_STS_FAIL_2_POS	24u /* RW1C */
#define MCHP_ESPI_BM_STS_FAIL_2		BIT(MCHP_ESPI_BM_STS_FAIL_2_POS)
#define MCHP_ESPI_BM_STS_IBERR_2_POS	25u /* RW1C */
#define MCHP_ESPI_BM_STS_IBERR_2	BIT(MCHP_ESPI_BM_STS_IBERR_2_POS)
#define MCHP_ESPI_BM_STS_BADREQ_2_POS	27u /* RW1C */
#define MCHP_ESPI_BM_STS_BADREQ_2	BIT(MCHP_ESPI_BM_STS_BADREQ_2_POS)

#define MCHP_ESPI_BM_STS_ALL_RW1C_1	0x0bfdu
#define MCHP_ESPI_BM_STS_ALL_RW1C_2	0x0bfd0000u

/* BM_IEN */
#define MCHP_ESPI_BM1_IEN_DONE_POS	0u
#define MCHP_ESPI_BM1_IEN_DONE		BIT(MCHP_ESPI_BM1_IEN_DONE_POS)
#define MCHP_ESPI_BM2_IEN_DONE_POS	16u
#define MCHP_ESPI_BM2_IEN_DONE		BIT(MCHP_ESPI_BM2_IEN_DONE_POS)

/* BM_CFG */
#define MCHP_ESPI_BM1_CFG_TAG_POS	0u
#define MCHP_ESPI_BM1_CFG_TAG_MASK0	0x0fu
#define MCHP_ESPI_BM1_CFG_TAG_MASK	0x0fu
#define MCHP_ESPI_BM2_CFG_TAG_POS	16u
#define MCHP_ESPI_BM2_CFG_TAG_MASK0	0x0fu
#define MCHP_ESPI_BM2_CFG_TAG_MASK	0x0f0000u

/* BM1_CTRL */
#define MCHP_ESPI_BM1_CTRL_START_POS	0u /* WO */
#define MCHP_ESPI_BM1_CTRL_START	BIT(MCHP_ESPI_BM1_CTRL_START_POS)
#define MCHP_ESPI_BM1_CTRL_ABORT_POS	1u /* WO */
#define MCHP_ESPI_BM1_CTRL_ABORT	BIT(MCHP_ESPI_BM1_CTRL_ABORT_POS)
#define MCHP_ESPI_BM1_CTRL_EN_INC_POS	2u /* RW */
#define MCHP_ESPI_BM1_CTRL_EN_INC	BIT(MCHP_ESPI_BM1_CTRL_EN_INC_POS)
#define MCHP_ESPI_BM1_CTRL_WAIT_NB2_POS 3u  /* RW */
#define MCHP_ESPI_BM1_CTRL_WAIT_NB2	BIT(MCHP_ESPI_BM1_CTRL_WAIT_NB2_POS)
#define MCHP_ESPI_BM1_CTRL_CTYPE_POS	8u
#define MCHP_ESPI_BM1_CTRL_CTYPE_MASK0	0x03u
#define MCHP_ESPI_BM1_CTRL_CTYPE_MASK	\
	SHLU32(MCHP_ESPI_BM1_CTRL_CTYPE_MASK0, MCHP_ESPI_BM1_CTRL_CTYPE_POS)
#define MCHP_ESPI_BM1_CTRL_CTYPE_RD_ADDR32	0x00u
#define MCHP_ESPI_BM1_CTRL_CTYPE_WR_ADDR32	\
	SHLU32(0x01u, MCHP_ESPI_BM1_CTRL_CTYPE_POS)
#define MCHP_ESPI_BM1_CTRL_CTYPE_RD_ADDR64	\
	SHLU32(0x02u, MCHP_ESPI_BM1_CTRL_CTYPE_POS)
#define MCHP_ESPI_BM1_CTRL_CTYPE_WR_ADDR64	\
	SHLU32(0x03u, MCHP_ESPI_BM1_CTRL_CTYPE_POS)
#define MCHP_ESPI_BM1_CTRL_LEN_POS	16u
#define MCHP_ESPI_BM1_CTRL_LEN_MASK0	0x1fffu
#define MCHP_ESPI_BM1_CTRL_LEN_MASK	0x1fff0000u

/* BM1_EC_ADDR_LSW */
#define MCHP_ESPI_BM1_EC_ADDR_LSW_MASK	0xfffffffcu

/* BM2_CTRL */
#define MCHP_ESPI_BM2_CTRL_START_POS	0u /* WO */
#define MCHP_ESPI_BM2_CTRL_START	BIT(MCHP_ESPI_BM2_CTRL_START_POS)
#define MCHP_ESPI_BM2_CTRL_ABORT_POS	1u /* WO */
#define MCHP_ESPI_BM2_CTRL_ABORT	BIT(MCHP_ESPI_BM2_CTRL_ABORT_POS)
#define MCHP_ESPI_BM2_CTRL_EN_INC_POS	2u /* RW */
#define MCHP_ESPI_BM2_CTRL_EN_INC	BIT(MCHP_ESPI_BM2_CTRL_EN_INC_POS)
#define MCHP_ESPI_BM2_CTRL_WAIT_NB2_POS 3u /* RW */
#define MCHP_ESPI_BM2_CTRL_WAIT_NB2	BIT(MCHP_ESPI_BM2_CTRL_WAIT_NB2_POS)
#define MCHP_ESPI_BM2_CTRL_CTYPE_POS		8u
#define MCHP_ESPI_BM2_CTRL_CTYPE_MASK0		0x03u
#define MCHP_ESPI_BM2_CTRL_CTYPE_MASK		0x0300u
#define MCHP_ESPI_BM2_CTRL_CTYPE_RD_ADDR32	0x00u
#define MCHP_ESPI_BM2_CTRL_CTYPE_WR_ADDR32	0x0100u
#define MCHP_ESPI_BM2_CTRL_CTYPE_RD_ADDR64	0x0200u
#define MCHP_ESPI_BM2_CTRL_CTYPE_WR_ADDR64	0x0300u
#define MCHP_ESPI_BM2_CTRL_LEN_POS		16u
#define MCHP_ESPI_BM2_CTRL_LEN_MASK0		0x1fffu
#define MCHP_ESPI_BM2_CTRL_LEN_MASK		0x1fff0000u

/* BM2_EC_ADDR_LSW */
#define MCHP_ESPI_BM2_EC_ADDR_LSW_MASK	0xfffffffcu

/*
 * MCHP_ESPI_MEM_BAR_EC @ 0x400F3930
 * Half-word H0 of each EC Memory BAR contains
 * Memory BAR memory address mask bits in bits[7:0]
 * Logical Device Number in bits[13:8]
 */
#define MCHP_ESPI_EBAR_H0_MEM_MASK_POS	0u
#define MCHP_ESPI_EBAR_H0_MEM_MASK_MASK 0xffu
#define MCHP_ESPI_EBAR_H0_LDN_POS	8u
#define MCHP_ESPI_EBAR_H0_LDN_MASK0	0x3fu
#define MCHP_ESPI_EBAR_H0_LDN_MASK	0x3f00u

/*
 * MCHP_ESPI_MEM_BAR_HOST @ 0x400F3B30
 * Each Host BAR contains:
 * bit[0] (RW) = Valid bit
 * bits[15:1] = Reserved, read-only 0
 * bits[47:16] (RW) = bits[31:0] of the Host Memory address.
 */

/* Memory BAR Host address valid */
#define MCHP_ESPI_HBAR_VALID_POS	0u
#define MCHP_ESPI_HBAR_VALID_MASK	0x01u
/*
 * Host address is in bits[47:16] of the HBAR
 * HBAR's are spaced every 10 bytes (80 bits) but
 * only implement bits[47:0]
 */
#define MCHP_ESPI_HBAR_VALID_OFS	0x00u	/* byte 0 */
/* 32-bit Host Address */
#define MCHP_ESPI_HBAR_ADDR_B0_OFS	0x02u	/* byte 2 */
#define MCHP_ESPI_HBAR_ADDR_B1_OFS	0x03u	/* byte 3 */
#define MCHP_ESPI_HBAR_ADDR_B2_OFS	0x04u	/* byte 4 */
#define MCHP_ESPI_HBAR_ADDR_B3_OFS	0x05u	/* byte 5 */

#define MCHP_EC_SRAM_BAR_H0_VALID_POS		0u
#define MCHP_EC_SRAM_BAR_H0_VALID_MASK0		0x01u
#define MCHP_EC_SRAM_BAR_H0_VALID_MASK		0x01u
#define MCHP_EC_SRAM_BAR_H0_VALID		0x01u
#define MCHP_EC_SRAM_BAR_H0_ACCESS_POS		1u
#define MCHP_EC_SRAM_BAR_H0_ACCESS_MASK0	0x03u
#define MCHP_EC_SRAM_BAR_H0_ACCESS_MASK		0x06u
#define MCHP_EC_SRAM_BAR_H0_ACCESS_NONE		0x00u
#define MCHP_EC_SRAM_BAR_H0_ACCESS_RO		0x02u
#define MCHP_EC_SRAM_BAR_H0_ACCESS_WO		0x04u
#define MCHP_EC_SRAM_BAR_H0_ACCESS_RW		0x06u
#define MCHP_EC_SRAM_BAR_H0_SIZE_POS		4u
#define MCHP_EC_SRAM_BAR_H0_SIZE_MASK0		0x0fu
#define MCHP_EC_SRAM_BAR_H0_SIZE_MASK		0xf0u
#define MCHP_EC_SRAM_BAR_H0_SIZE_1B		0x00u
#define MCHP_EC_SRAM_BAR_H0_SIZE_2B		0x10u
#define MCHP_EC_SRAM_BAR_H0_SIZE_4B		0x20u
#define MCHP_EC_SRAM_BAR_H0_SIZE_8B		0x30u
#define MCHP_EC_SRAM_BAR_H0_SIZE_16B		0x40u
#define MCHP_EC_SRAM_BAR_H0_SIZE_32B		0x50u
#define MCHP_EC_SRAM_BAR_H0_SIZE_64B		0x60u
#define MCHP_EC_SRAM_BAR_H0_SIZE_128B		0x70u
#define MCHP_EC_SRAM_BAR_H0_SIZE_256B		0x80u
#define MCHP_EC_SRAM_BAR_H0_SIZE_512B		0x90u
#define MCHP_EC_SRAM_BAR_H0_SIZE_1KB		0xa0u
#define MCHP_EC_SRAM_BAR_H0_SIZE_2KB		0xb0u
#define MCHP_EC_SRAM_BAR_H0_SIZE_4KB		0xc0u
#define MCHP_EC_SRAM_BAR_H0_SIZE_8KB		0xd0u
#define MCHP_EC_SRAM_BAR_H0_SIZE_16KB		0xe0u
#define MCHP_EC_SRAM_BAR_H0_SIZE_32KB		0xf0u
/* EC and Host SRAM BAR start offset of EC or Host memory address */
#define MCHP_EC_SRAM_BAR_MADDR_OFS1		2u
#define MCHP_EC_SRAM_BAR_MADDR_OFS2		4u

/* Interfaces to any C modules */
#ifdef __cplusplus
extern "C" {
#endif

/* Array indices for eSPI IO BAR Host and EC-only register structures */
enum espi_io_bar_idx {
	IOB_IOC = 0,
	IOB_MEM,
	IOB_MBOX,
	IOB_KBC,
	IOB_ACPI_EC0,
	IOB_ACPI_EC1,
	IOB_ACPI_EC2,
	IOB_ACPI_EC3,
	IOB_ACPI_EC4,
	IOB_ACPI_PM1,
	IOB_PORT92,
	IOB_UART0,
	IOB_UART1,
	IOB_EMI0,
	IOB_EMI1,
	IOB_EMI2,
	IOB_P80BD,		/* MEC152x IOB_P80_CAP0 */
	IOB_P80BD_ALIAS,	/* MEC152x IOB_P80_CAP1 */
	IOB_RTC,
	IOB_RSVD19,
	IOB_T32B,
	IOB_RSVD21,
	IOB_GLUE,
	IOB_MAX
};

/** @brief Serial IRQ byte register indices */
enum espi_io_sirq_idx {
	SIRQ_MBOX = 0,	   SIRQ_MBOX_SMI,     SIRQ_KBC_KIRQ,
	SIRQ_KBC_MIRQ,	   SIRQ_ACPI_EC0_OBF, SIRQ_ACPI_EC1_OBF,
	SIRQ_ACPI_EC2_OBF, SIRQ_ACPI_EC3_OBF, SIRQ_ACPI_EC4_OBF,
	SIRQ_UART0,	   SIRQ_UART1,	      SIRQ_EMI0_HEV,
	SIRQ_EMI0_E2H,	   SIRQ_EMI1_HEV,     SIRQ_EMI1_E2H,
	SIRQ_EMI2_HEV,	   SIRQ_EMI2_E2H,     SIRQ_RTC,
	SIRQ_EC,	   SIRQ_MAX
};

enum espi_mem_bar_idx {
	MEMB_MBOX = 0,
	MEMB_ACPI_EC0,
	MEMB_ACPI_EC1,
	MEMB_ACPI_EC2,
	MEMB_ACPI_EC3,
	MEMB_ACPI_EC4,
	MEMB_EMI0,
	MEMB_EMI1,
	MEMB_EMI2,
	MEMB_T32B,
	MEMB_MAX
};

/* eSPI */
struct espi_io_mbar { /* 80-bit register */
	volatile uint16_t  LDN_MASK;
	volatile uint16_t  RESERVED[4];
}; /* Size = 10 (0xa) */

struct espi_mbar_host {
	volatile uint16_t  VALID;
	volatile uint16_t  HADDR_LSH;
	volatile uint16_t  HADDR_MSH;
	volatile uint16_t  RESERVED[2];
}; /* Size = 10 (0xa) */

struct espi_sram_bar {
	volatile uint16_t  VACCSZ;
	volatile uint16_t  EC_SRAM_BASE_LSH;
	volatile uint16_t  EC_SRAM_BASE_MSH;
	volatile uint16_t  RESERVED[2];
}; /* Size = 10 (0xa) */

struct espi_sram_host_bar {
	volatile uint16_t  ACCSZ;
	volatile uint16_t  HBASE_LSH;
	volatile uint16_t  HBASE_MSH;
	volatile uint16_t  RESERVED[2];
}; /* Size = 10 (0xa) */

/** @brief eSPI Capabilities, I/O and Memory components in one structure */
struct espi_iom_regs { /* @ 0x400F3400 */
	volatile uint8_t   RTIDX;		/* @ 0x0000 */
	volatile uint8_t   RTDAT;		/* @ 0x0001 */
	volatile uint16_t  RESERVED;
	volatile uint32_t  RESERVED1[63];
	volatile uint32_t  PCLC[3];		/* @ 0x0100 */
	volatile uint32_t  PCERR[2];		/* @ 0x010C */
	volatile uint32_t  PCSTS;		/* @ 0x0114 */
	volatile uint32_t  PCIEN;		/* @ 0x0118 */
	volatile uint32_t  RESERVED2;
	volatile uint32_t  PCBINH[2];		/* @ 0x0120 */
	volatile uint32_t  PCBINIT;		/* @ 0x0128 */
	volatile uint32_t  PCECIRQ;		/* @ 0x012C */
	volatile uint32_t  PCCKNP;		/* @ 0x0130 */
	volatile uint32_t  PCBARI[29];		/* @ 0x0134 */
	volatile uint32_t  RESERVED3[30];
	volatile uint32_t  PCLTRSTS;		/* @ 0x0220 */
	volatile uint32_t  PCLTREN;		/* @ 0x0224 */
	volatile uint32_t  PCLTRCTL;		/* @ 0x0228 */
	volatile uint32_t  PCLTRM;		/* @ 0x022C */
	volatile uint32_t  RESERVED4[4];
	volatile uint32_t  OOBRXA[2];		/* @ 0x0240 */
	volatile uint32_t  OOBTXA[2];		/* @ 0x0248 */
	volatile uint32_t  OOBRXL;		/* @ 0x0250 */
	volatile uint32_t  OOBTXL;		/* @ 0x0254 */
	volatile uint32_t  OOBRXC;		/* @ 0x0258 */
	volatile uint32_t  OOBRXIEN;		/* @ 0x025C */
	volatile uint32_t  OOBRXSTS;		/* @ 0x0260 */
	volatile uint32_t  OOBTXC;		/* @ 0x0264 */
	volatile uint32_t  OOBTXIEN;		/* @ 0x0268 */
	volatile uint32_t  OOBTXSTS;		/* @ 0x026C */
	volatile uint32_t  RESERVED5[4];
	volatile uint32_t  FCFA[2];		/* @ 0x0280 */
	volatile uint32_t  FCBA[2];		/* @ 0x0288 */
	volatile uint32_t  FCLEN;		/* @ 0x0290 */
	volatile uint32_t  FCCTL;		/* @ 0x0294 */
	volatile uint32_t  FCIEN;		/* @ 0x0298 */
	volatile uint32_t  FCCFG;		/* @ 0x029C */
	volatile uint32_t  FCSTS;		/* @ 0x02A0 */
	volatile uint32_t  RESERVED6[3];
	volatile uint32_t  VWSTS;		/* @ 0x02B0 */
	volatile uint32_t  RESERVED7[11];
	volatile uint8_t   CAPID;		/* @ 0x02E0 */
	volatile uint8_t   CAP0;		/* @ 0x02E1 */
	volatile uint8_t   CAP1;		/* @ 0x02E2 */
	volatile uint8_t   CAPPC;		/* @ 0x02E3 */
	volatile uint8_t   CAPVW;		/* @ 0x02E4 */
	volatile uint8_t   CAPOOB;		/* @ 0x02E5 */
	volatile uint8_t   CAPFC;		/* @ 0x02E6 */
	volatile uint8_t   PCRDY;		/* @ 0x02E7 */
	volatile uint8_t   OOBRDY;		/* @ 0x02E8 */
	volatile uint8_t   FCRDY;		/* @ 0x02E9 */
	volatile uint8_t   ERIS;		/* @ 0x02EA */
	volatile uint8_t   ERIE;		/* @ 0x02EB */
	volatile uint8_t   PLTSRC;		/* @ 0x02EC */
	volatile uint8_t   VWRDY;		/* @ 0x02ED */
	volatile uint8_t   SAFEBS;		/* @ 0x02EE */
	volatile uint8_t   RESERVED8;
	volatile uint32_t  RESERVED9[16];
	volatile uint32_t  ACTV;		/* @ 0x0330 */
	volatile uint32_t  IOHBAR[29];		/* @ 0x0334 */
	volatile uint32_t  RESERVED10;
	volatile uint8_t   SIRQ[19];		/* @ 0x03ac */
	volatile uint8_t   RESERVED11;
	volatile uint32_t  RESERVED12[12];
	volatile uint32_t  VWERREN;		/* @ 0x03f0 */
	volatile uint32_t  RESERVED13[79];
	struct espi_io_mbar MBAR[10];		/* @ 0x0530 */
	volatile uint32_t  RESERVED14[6];
	struct espi_sram_bar SRAMBAR[2];	/* @ 0x05AC */
	volatile uint32_t  RESERVED15[16];
	volatile uint32_t  BM_STATUS;		/* @ 0x0600 */
	volatile uint32_t  BM_IEN;		/* @ 0x0604 */
	volatile uint32_t  BM_CONFIG;		/* @ 0x0608 */
	volatile uint32_t  RESERVED16;
	volatile uint32_t  BM_CTRL1;		/* @ 0x0610 */
	volatile uint32_t  BM_HADDR1_LSW;	/* @ 0x0614 */
	volatile uint32_t  BM_HADDR1_MSW;	/* @ 0x0618 */
	volatile uint32_t  BM_EC_ADDR1_LSW;	/* @ 0x061C */
	volatile uint32_t  BM_EC_ADDR1_MSW;	/* @ 0x0620 */
	volatile uint32_t  BM_CTRL2;		/* @ 0x0624 */
	volatile uint32_t  BM_HADDR2_LSW;	/* @ 0x0628 */
	volatile uint32_t  BM_HADDR2_MSW;	/* @ 0x062C */
	volatile uint32_t  BM_EC_ADDR2_LSW;	/* @ 0x0630 */
	volatile uint32_t  BM_EC_ADDR2_MSW;	/* @ 0x0634 */
	volatile uint32_t  RESERVED17[62];
	struct espi_mbar_host HMBAR[10];	/* @ 0x0730 */
	volatile uint32_t  RESERVED18[6];
	struct espi_sram_host_bar HSRAMBAR[2];	/* @ 0x07AC */
}; /* Size = 1984 (0x7c0) */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _MEC172X_ESPI_IO_H */
