/* ieee802154_mcr20a_regs.h - Registers definition for NXP MCR20A */

/*
 * Copyright (c) 2017 PHYTEC Messtechnik GmbH
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * This file is based on MCR20reg.h, it was modified to meet the
 * coding style and restructured to make it easier to read.
 * Additional identifiers was inserted (_MASK and _SHIFT endings),
 * which are used in the macros for the bit field manipulation.
 *
 * This file are derived from material that is
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ZEPHYR_DRIVERS_IEEE802154_IEEE802154_MCR20A_REGS_H_
#define ZEPHYR_DRIVERS_IEEE802154_IEEE802154_MCR20A_REGS_H_

#define MCR20A_REG_READ			(BIT(7))
#define MCR20A_BUF_READ			(BIT(7) | BIT(6))
#define MCR20A_BUF_BYTE_READ		(BIT(7) | BIT(6) | BIT(5))
#define MCR20A_REG_WRITE		(0)
#define MCR20A_BUF_WRITE		(BIT(6))
#define MCR20A_BUF_BYTE_WRITE		(BIT(6) | BIT(5))

#define MCR20A_IRQSTS1				(0x0)
#define MCR20A_IRQSTS2				(0x1)
#define MCR20A_IRQSTS3				(0x2)
#define MCR20A_PHY_CTRL1			(0x3)
#define MCR20A_PHY_CTRL2			(0x4)
#define MCR20A_PHY_CTRL3			(0x5)
#define MCR20A_RX_FRM_LEN			(0x6)
#define MCR20A_PHY_CTRL4			(0x7)
#define MCR20A_SRC_CTRL				(0x8)
#define MCR20A_SRC_ADDRS_SUM_LSB		(0x9)
#define MCR20A_SRC_ADDRS_SUM_MSB		(0xa)
#define MCR20A_CCA1_ED_FNL			(0xb)
#define MCR20A_EVENT_TIMER_LSB			(0xc)
#define MCR20A_EVENT_TIMER_MSB			(0xd)
#define MCR20A_EVENT_TIMER_USB			(0xe)
#define MCR20A_TIMESTAMP_LSB			(0xf)
#define MCR20A_TIMESTAMP_MSB			(0x10)
#define MCR20A_TIMESTAMP_USB			(0x11)
#define MCR20A_T3CMP_LSB			(0x12)
#define MCR20A_T3CMP_MSB			(0x13)
#define MCR20A_T3CMP_USB			(0x14)
#define MCR20A_T2PRIMECMP_LSB			(0x15)
#define MCR20A_T2PRIMECMP_MSB			(0x16)
#define MCR20A_T1CMP_LSB			(0x17)
#define MCR20A_T1CMP_MSB			(0x18)
#define MCR20A_T1CMP_USB			(0x19)
#define MCR20A_T2CMP_LSB			(0x1a)
#define MCR20A_T2CMP_MSB			(0x1b)
#define MCR20A_T2CMP_USB			(0x1c)
#define MCR20A_T4CMP_LSB			(0x1d)
#define MCR20A_T4CMP_MSB			(0x1e)
#define MCR20A_T4CMP_USB			(0x1f)
#define MCR20A_PLL_INT0				(0x20)
#define MCR20A_PLL_FRAC0_LSB			(0x21)
#define MCR20A_PLL_FRAC0_MSB			(0x22)
#define MCR20A_PA_PWR				(0x23)
#define MCR20A_SEQ_STATE			(0x24)
#define MCR20A_LQI_VALUE			(0x25)
#define MCR20A_RSSI_CCA_CNT			(0x26)
/* ----------------				(0x27) */
#define MCR20A_ASM_CTRL1			(0x28)
#define MCR20A_ASM_CTRL2			(0x29)
#define MCR20A_ASM_DATA_0			(0x2a)
#define MCR20A_ASM_DATA_1			(0x2b)
#define MCR20A_ASM_DATA_2			(0x2c)
#define MCR20A_ASM_DATA_3			(0x2d)
#define MCR20A_ASM_DATA_4			(0x2e)
#define MCR20A_ASM_DATA_5			(0x2f)
#define MCR20A_ASM_DATA_6			(0x30)
#define MCR20A_ASM_DATA_7			(0x31)
#define MCR20A_ASM_DATA_8			(0x32)
#define MCR20A_ASM_DATA_9			(0x33)
#define MCR20A_ASM_DATA_A			(0x34)
#define MCR20A_ASM_DATA_B			(0x35)
#define MCR20A_ASM_DATA_C			(0x36)
#define MCR20A_ASM_DATA_D			(0x37)
#define MCR20A_ASM_DATA_E			(0x38)
#define MCR20A_ASM_DATA_F			(0x39)
/* ----------------				(0x3a) */
#define MCR20A_OVERWRITE_VER			(0x3b)
#define MCR20A_CLK_OUT_CTRL			(0x3c)
#define MCR20A_PWR_MODES			(0x3d)
#define MCR20A_IAR_INDEX			(0x3e)
#define MCR20A_IAR_DATA				(0x3f)

#define MCR20A_IRQSTS1_RX_FRM_PEND		BIT(7)
#define MCR20A_IRQSTS1_PLL_UNLOCK_IRQ		BIT(6)
#define MCR20A_IRQSTS1_FILTERFAIL_IRQ		BIT(5)
#define MCR20A_IRQSTS1_RXWTRMRKIRQ		BIT(4)
#define MCR20A_IRQSTS1_CCAIRQ			BIT(3)
#define MCR20A_IRQSTS1_RXIRQ			BIT(2)
#define MCR20A_IRQSTS1_TXIRQ			BIT(1)
#define MCR20A_IRQSTS1_SEQIRQ			BIT(0)
#define MCR20A_IRQSTS1_IRQ_MASK			(0x7f)

#define MCR20A_IRQSTS2_CRCVALID			BIT(7)
#define MCR20A_IRQSTS2_CCA			BIT(6)
#define MCR20A_IRQSTS2_SRCADDR			BIT(5)
#define MCR20A_IRQSTS2_PI			BIT(4)
#define MCR20A_IRQSTS2_TMRSTATUS		BIT(3)
#define MCR20A_IRQSTS2_ASM_IRQ			BIT(2)
#define MCR20A_IRQSTS2_PB_ERR_IRQ		BIT(1)
#define MCR20A_IRQSTS2_WAKE_IRQ			BIT(0)
#define MCR20A_IRQSTS2_IRQ_MASK			(0x7)

#define MCR20A_IRQSTS3_TMR4MSK			BIT(7)
#define MCR20A_IRQSTS3_TMR3MSK			BIT(6)
#define MCR20A_IRQSTS3_TMR2MSK			BIT(5)
#define MCR20A_IRQSTS3_TMR1MSK			BIT(4)
#define MCR20A_IRQSTS3_TMR_MASK			(0xf0)
#define MCR20A_IRQSTS3_TMR4IRQ			BIT(3)
#define MCR20A_IRQSTS3_TMR3IRQ			BIT(2)
#define MCR20A_IRQSTS3_TMR2IRQ			BIT(1)
#define MCR20A_IRQSTS3_TMR1IRQ			BIT(0)
#define MCR20A_IRQSTS3_IRQ_MASK			(0xf)
#define MCR20A_IRQSTS3_IRQ_SHIFT		(0)

#define MCR20A_PHY_CTRL1_TMRTRIGEN		BIT(7)
#define MCR20A_PHY_CTRL1_SLOTTED		BIT(6)
#define MCR20A_PHY_CTRL1_CCABFRTX		BIT(5)
#define MCR20A_PHY_CTRL1_RXACKRQD		BIT(4)
#define MCR20A_PHY_CTRL1_AUTOACK		BIT(3)
#define MCR20A_PHY_CTRL1_XCVSEQ_MASK		(0x7)
#define MCR20A_PHY_CTRL1_XCVSEQ_SHIFT		(0)

#define MCR20A_XCVSEQ_IDLE			(0)
#define MCR20A_XCVSEQ_RECEIVE			(1)
#define MCR20A_XCVSEQ_TX			(2)
#define MCR20A_XCVSEQ_CCA			(3)
#define MCR20A_XCVSEQ_TX_RX			(4)
#define MCR20A_XCVSEQ_CONTINUOUS_CCA		(5)

#define MCR20A_PHY_CTRL2_CRC_MSK		BIT(7)
#define MCR20A_PHY_CTRL2_PLL_UNLOCK_MSK		BIT(6)
#define MCR20A_PHY_CTRL2_FILTERFAIL_MSK		BIT(5)
#define MCR20A_PHY_CTRL2_RX_WMRK_MSK		BIT(4)
#define MCR20A_PHY_CTRL2_CCAMSK			BIT(3)
#define MCR20A_PHY_CTRL2_RXMSK			BIT(2)
#define MCR20A_PHY_CTRL2_TXMSK			BIT(1)
#define MCR20A_PHY_CTRL2_SEQMSK			BIT(0)

#define MCR20A_PHY_CTRL3_TMR4CMP_EN		BIT(7)
#define MCR20A_PHY_CTRL3_TMR3CMP_EN		BIT(6)
#define MCR20A_PHY_CTRL3_TMR2CMP_EN		BIT(5)
#define MCR20A_PHY_CTRL3_TMR1CMP_EN		BIT(4)
#define MCR20A_PHY_CTRL3_ASM_MSK		BIT(2)
#define MCR20A_PHY_CTRL3_PB_ERR_MSK		BIT(1)
#define MCR20A_PHY_CTRL3_WAKE_MSK		BIT(0)

#define MCR20A_RX_FRM_LENGTH_MASK		(0x7f)

#define MCR20A_PHY_CTRL4_TRCV_MSK		BIT(7)
#define MCR20A_PHY_CTRL4_TC3TMOUT		BIT(6)
#define MCR20A_PHY_CTRL4_PANCORDNTR0		BIT(5)
#define MCR20A_PHY_CTRL4_CCATYPE_MASK		(0x18)
#define MCR20A_PHY_CTRL4_CCATYPE_SHIFT		(3)
#define MCR20A_PHY_CTRL4_TMRLOAD		BIT(2)
#define MCR20A_PHY_CTRL4_PROMISCUOUS		BIT(1)
#define MCR20A_PHY_CTRL4_TC2PRIME_EN		BIT(0)

#define MCR20A_SRC_CTRL_INDEX_MASK		(0xf0)
#define MCR20A_SRC_CTRL_INDEX_SHIFT		(4)
#define MCR20A_SRC_CTRL_ACK_FRM_PND		BIT(3)
#define MCR20A_SRC_CTRL_SRCADDR_EN		BIT(2)
#define MCR20A_SRC_CTRL_INDEX_EN		BIT(1)
#define MCR20A_SRC_CTRL_INDEX_DISABLE		BIT(0)

#define MCR20A_PLL_INT0_VAL_MASK		(0x1f)
#define MCR20A_PLL_INT0_VAL_SHIFT		(0)

#define MCR20A_PA_PWR_VAL_MASK			(0x1f)
#define MCR20A_PA_PWR_VAL_SHIFT			(0)

#define MCR20A_SEQ_STATE_MASK			(0x1f)

#define MCR20A_ASM_CTRL1_CLEAR			BIT(7)
#define MCR20A_ASM_CTRL1_START			BIT(6)
#define MCR20A_ASM_CTRL1_SELFTST		BIT(5)
#define MCR20A_ASM_CTRL1_CTR			BIT(4)
#define MCR20A_ASM_CTRL1_CBC			BIT(3)
#define MCR20A_ASM_CTRL1_AES			BIT(2)
#define MCR20A_ASM_CTRL1_LOAD_MAC		BIT(1)

#define MCR20A_ASM_CTRL2_DATA_REG_TYPE_SELECT_MASK	(0x7)
#define MCR20A_ASM_CTRL2_DATA_REG_TYPE_SELECT_SHIFT	(5)
#define MCR20A_ASM_CTRL2_TSTPAS				BIT(1)

#define MCR20A_CLK_OUT_EXTEND			BIT(7)
#define MCR20A_CLK_OUT_HIZ			BIT(6)
#define MCR20A_CLK_OUT_SR			BIT(5)
#define MCR20A_CLK_OUT_DS			BIT(4)
#define MCR20A_CLK_OUT_EN			BIT(3)
#define MCR20A_CLK_OUT_DIV_MASK			(0x07)
#define MCR20A_CLK_OUT_DIV_SHIFT		(0)

#define MCR20A_PWR_MODES_XTAL_READY		BIT(5)
#define MCR20A_PWR_MODES_XTALEN			BIT(4)
#define MCR20A_PWR_MODES_ASM_CLK_EN		BIT(3)
#define MCR20A_PWR_MODES_AUTODOZE		BIT(1)
#define MCR20A_PWR_MODES_PMC_MODE		BIT(0)

#define MCR20A_PART_ID				(0x00)
#define MCR20A_XTAL_TRIM			(0x01)
#define MCR20A_PMC_LP_TRIM			(0x02)
#define MCR20A_MACPANID0_LSB			(0x03)
#define MCR20A_MACPANID0_MSB			(0x04)
#define MCR20A_MACSHORTADDRS0_LSB		(0x05)
#define MCR20A_MACSHORTADDRS0_MSB		(0x06)
#define MCR20A_MACLONGADDRS0_0			(0x07)
#define MCR20A_MACLONGADDRS0_1			(0x08)
#define MCR20A_MACLONGADDRS0_2			(0x09)
#define MCR20A_MACLONGADDRS0_3			(0x0a)
#define MCR20A_MACLONGADDRS0_4			(0x0b)
#define MCR20A_MACLONGADDRS0_5			(0x0c)
#define MCR20A_MACLONGADDRS0_6			(0x0d)
#define MCR20A_MACLONGADDRS0_7			(0x0e)
#define MCR20A_RX_FRAME_FILTER			(0x0f)
#define MCR20A_PLL_INT1				(0x10)
#define MCR20A_PLL_FRAC1_LSB			(0x11)
#define MCR20A_PLL_FRAC1_MSB			(0x12)
#define MCR20A_MACPANID1_LSB			(0x13)
#define MCR20A_MACPANID1_MSB			(0x14)
#define MCR20A_MACSHORTADDRS1_LSB		(0x15)
#define MCR20A_MACSHORTADDRS1_MSB		(0x16)
#define MCR20A_MACLONGADDRS1_0			(0x17)
#define MCR20A_MACLONGADDRS1_1			(0x18)
#define MCR20A_MACLONGADDRS1_2			(0x19)
#define MCR20A_MACLONGADDRS1_3			(0x1a)
#define MCR20A_MACLONGADDRS1_4			(0x1b)
#define MCR20A_MACLONGADDRS1_5			(0x1c)
#define MCR20A_MACLONGADDRS1_6			(0x1d)
#define MCR20A_MACLONGADDRS1_7			(0x1e)
#define MCR20A_DUAL_PAN_CTRL			(0x1f)
#define MCR20A_DUAL_PAN_DWELL			(0x20)
#define MCR20A_DUAL_PAN_STS			(0x21)
#define MCR20A_CCA1_THRESH			(0x22)
#define MCR20A_CCA1_ED_OFFSET_COMP		(0x23)
#define MCR20A_LQI_OFFSET_COMP			(0x24)
#define MCR20A_CCA_CTRL				(0x25)
#define MCR20A_CCA2_CORR_PEAKS			(0x26)
#define MCR20A_CCA2_THRESH			(0x27)
#define MCR20A_TMR_PRESCALE			(0x28)
/* ----------------				(0x29) */
#define MCR20A_GPIO_DATA			(0x2a)
#define MCR20A_GPIO_DIR				(0x2b)
#define MCR20A_GPIO_PUL_EN			(0x2c)
#define MCR20A_GPIO_SEL				(0x2d)
#define MCR20A_GPIO_DS				(0x2e)
/* ----------------				(0x2f) */
#define MCR20A_ANT_PAD_CTRL			(0x30)
#define MCR20A_MISC_PAD_CTRL			(0x31)
#define MCR20A_BSM_CTRL				(0x32)
/* ----------------				(0x33) */
#define MCR20A_RNG				(0x34)
#define MCR20A_RX_BYTE_COUNT			(0x35)
#define MCR20A_RX_WTR_MARK			(0x36)
#define MCR20A_SOFT_RESET			(0x37)
#define MCR20A_TXDELAY				(0x38)
#define MCR20A_ACKDELAY				(0x39)
#define MCR20A_SEQ_MGR_CTRL			(0x3a)
#define MCR20A_SEQ_MGR_STS			(0x3b)
#define MCR20A_SEQ_T_STS			(0x3c)
#define MCR20A_ABORT_STS			(0x3d)
#define MCR20A_CCCA_BUSY_CNT			(0x3e)
#define MCR20A_SRC_ADDR_CHECKSUM1		(0x3f)
#define MCR20A_SRC_ADDR_CHECKSUM2		(0x40)
#define MCR20A_SRC_TBL_VALID1			(0x41)
#define MCR20A_SRC_TBL_VALID2			(0x42)
#define MCR20A_FILTERFAIL_CODE1			(0x43)
#define MCR20A_FILTERFAIL_CODE2			(0x44)
#define MCR20A_SLOT_PRELOAD			(0x45)
/* ----------------				(0x46) */
#define MCR20A_CORR_VT				(0x47)
#define MCR20A_SYNC_CTRL			(0x48)
#define MCR20A_PN_LSB_0				(0x49)
#define MCR20A_PN_LSB_1				(0x4a)
#define MCR20A_PN_MSB_0				(0x4b)
#define MCR20A_PN_MSB_1				(0x4c)
#define MCR20A_CORR_NVAL			(0x4d)
#define MCR20A_TX_MODE_CTRL			(0x4e)
#define MCR20A_SNF_THR				(0x4f)
#define MCR20A_FAD_THR				(0x50)
#define MCR20A_ANT_AGC_CTRL			(0x51)
#define MCR20A_AGC_THR1				(0x52)
#define MCR20A_AGC_THR2				(0x53)
#define MCR20A_AGC_HYS				(0x54)
#define MCR20A_AFC				(0x55)
#define MCR20A_LPPS_CTRL			(0x56)
/* ----------------				(0x57) */
#define MCR20A_PHY_STS				(0x58)
#define MCR20A_RX_MAX_CORR			(0x59)
#define MCR20A_RX_MAX_PREAMBLE			(0x5a)
#define MCR20A_RSSI				(0x5b)
/* ----------------				(0x5c) */
/* ----------------				(0x5d) */
#define MCR20A_PLL_DIG_CTRL			(0x5e)
#define MCR20A_VCO_CAL				(0x5f)
#define MCR20A_VCO_BEST_DIFF			(0x60)
#define MCR20A_VCO_BIAS				(0x61)
#define MCR20A_KMOD_CTRL			(0x62)
#define MCR20A_KMOD_CAL				(0x63)
#define MCR20A_PA_CAL				(0x64)
#define MCR20A_PA_PWRCAL			(0x65)
#define MCR20A_ATT_RSSI1			(0x66)
#define MCR20A_ATT_RSSI2			(0x67)
#define MCR20A_RSSI_OFFSET			(0x68)
#define MCR20A_RSSI_SLOPE			(0x69)
#define MCR20A_RSSI_CAL1			(0x6a)
#define MCR20A_RSSI_CAL2			(0x6b)
/* ----------------				(0x6c) */
/* ----------------				(0x6d) */
#define MCR20A_XTAL_CTRL			(0x6e)
#define MCR20A_XTAL_COMP_MIN			(0x6f)
#define MCR20A_XTAL_COMP_MAX			(0x70)
#define MCR20A_XTAL_GM				(0x71)
/* ----------------				(0x72) */
/* ----------------				(0x73) */
#define MCR20A_LNA_TUNE				(0x74)
#define MCR20A_LNA_AGCGAIN			(0x75)
/* ----------------				(0x76) */
/* ----------------				(0x77) */
#define MCR20A_CHF_PMA_GAIN			(0x78)
#define MCR20A_CHF_IBUF				(0x79)
#define MCR20A_CHF_QBUF				(0x7a)
#define MCR20A_CHF_IRIN				(0x7b)
#define MCR20A_CHF_QRIN				(0x7c)
#define MCR20A_CHF_IL				(0x7d)
#define MCR20A_CHF_QL				(0x7e)
#define MCR20A_CHF_CC1				(0x7f)
#define MCR20A_CHF_CCL				(0x80)
#define MCR20A_CHF_CC2				(0x81)
#define MCR20A_CHF_IROUT			(0x82)
#define MCR20A_CHF_QROUT			(0x83)
/* ----------------				(0x84) */
/* ----------------				(0x85) */
#define MCR20A_RSSI_CTRL			(0x86)
/* ----------------				(0x87) */
/* ----------------				(0x88) */
#define MCR20A_PA_BIAS				(0x89)
#define MCR20A_PA_TUNING			(0x8a)
/* ----------------				(0x8b) */
/* ----------------				(0x8c) */
#define MCR20A_PMC_HP_TRIM			(0x8d)
#define MCR20A_VREGA_TRIM			(0x8e)
/* ----------------				(0x8f) */
/* ----------------				(0x90) */
#define MCR20A_VCO_CTRL1			(0x91)
#define MCR20A_VCO_CTRL2			(0x92)
/* ----------------				(0x93) */
/* ----------------				(0x94) */
#define MCR20A_ANA_SPARE_OUT1			(0x95)
#define MCR20A_ANA_SPARE_OUT2			(0x96)
#define MCR20A_ANA_SPARE_IN			(0x97)
#define MCR20A_MISCELLANEOUS			(0x98)
/* ----------------				(0x99) */
#define MCR20A_SEQ_MGR_OVRD0			(0x9a)
#define MCR20A_SEQ_MGR_OVRD1			(0x9b)
#define MCR20A_SEQ_MGR_OVRD2			(0x9c)
#define MCR20A_SEQ_MGR_OVRD3			(0x9d)
#define MCR20A_SEQ_MGR_OVRD4			(0x9e)
#define MCR20A_SEQ_MGR_OVRD5			(0x9f)
#define MCR20A_SEQ_MGR_OVRD6			(0xa0)
#define MCR20A_SEQ_MGR_OVRD7			(0xa1)
/* ----------------				(0xa2) */
#define MCR20A_TESTMODE_CTRL			(0xa3)
#define MCR20A_DTM_CTRL1			(0xa4)
#define MCR20A_DTM_CTRL2			(0xa5)
#define MCR20A_ATM_CTRL1			(0xa6)
#define MCR20A_ATM_CTRL2			(0xa7)
#define MCR20A_ATM_CTRL3			(0xa8)
/* ----------------				(0xa9) */
#define MCR20A_LIM_FE_TEST_CTRL			(0xaa)
#define MCR20A_CHF_TEST_CTRL			(0xab)
#define MCR20A_VCO_TEST_CTRL			(0xac)
#define MCR20A_PLL_TEST_CTRL			(0xad)
#define MCR20A_PA_TEST_CTRL			(0xae)
#define MCR20A_PMC_TEST_CTRL			(0xaf)

#define MCR20A_SCAN_DTM_PROTECT_1		(0xfe)
#define MCR20A_SCAN_DTM_PROTECT_0		(0xff)

#define MCR20A_RX_FRAME_FILTER_FRM_VER_MASK		(0xc0)
#define MCR20A_RX_FRAME_FILTER_FRM_VER_SHIFT		(6)
#define MCR20A_RX_FRAME_FILTER_ACTIVE_PROMISCUOUS	BIT(5)
#define MCR20A_RX_FRAME_FILTER_NS_FT			BIT(4)
#define MCR20A_RX_FRAME_FILTER_CMD_FT			BIT(3)
#define MCR20A_RX_FRAME_FILTER_ACK_FT			BIT(2)
#define MCR20A_RX_FRAME_FILTER_DATA_FT			BIT(1)
#define MCR20A_RX_FRAME_FILTER_BEACON_FT		BIT(0)

#define MCR20A_PLL_INT1_MASK				(0x1f)

#define MCR20A_DUAL_PAN_CTRL_DUAL_PAN_SAM_LVL_MASK	(0xf0)
#define MCR20A_DUAL_PAN_CTRL_DUAL_PAN_SAM_LVL_SHIFT	(4)
#define MCR20A_DUAL_PAN_CTRL_CURRENT_NETWORK		BIT(3)
#define MCR20A_DUAL_PAN_CTRL_PANCORDNTR1		BIT(2)
#define MCR20A_DUAL_PAN_CTRL_DUAL_PAN_AUTO		BIT(1)
#define MCR20A_DUAL_PAN_CTRL_ACTIVE_NETWORK		BIT(0)

#define MCR20A_DUAL_PAN_STS_RECD_ON_PAN1		BIT(7)
#define MCR20A_DUAL_PAN_STS_RECD_ON_PAN0		BIT(6)
#define MCR20A_DUAL_PAN_STS_DUAL_PAN_REMAIN_MASK	(0x3f)

#define MCR20A_CCA_CTRL_AGC_FRZ_EN			BIT(6)
#define MCR20A_CCA_CTRL_CONT_RSSI_EN			BIT(5)
#define MCR20A_CCA_CTRL_QI_RSSI_NOT_CORR		BIT(4)
#define MCR20A_CCA_CTRL_CCA3_AND_NOT_OR			BIT(3)
#define MCR20A_CCA_CTRL_OWER_COMP_EN_LQI		BIT(2)
#define MCR20A_CCA_CTRL_OWER_COMP_EN_ED			BIT(1)
#define MCR20A_CCA_CTRL_OWER_COMP_EN_CCA1		BIT(0)

#define MCR20A_CCA2_CORR_PEAKS_CCA2_MIN_NUM_CORR_TH_MASK	(0x70)
#define MCR20A_CCA2_CORR_PEAKS_CCA2_MIN_NUM_CORR_TH_SHIFT	(4)
#define MCR20A_CCA2_CORR_PEAKS_CCA2_NUM_CORR_PEAKS_MASK		(0x0f)

#define MCR20A_TMR_PRESCALE_VAL_MASK			(0x7)
#define MCR20A_TMR_PRESCALE_VAL_SHIFT			(0)

#define MCR20A_TIMEBASE_500000HZ		(2)
#define MCR20A_TIMEBASE_250000HZ		(3)
#define MCR20A_TIMEBASE_125000HZ		(4)
#define MCR20A_TIMEBASE_62500HZ			(5)
#define MCR20A_TIMEBASE_31250HZ			(6)
#define MCR20A_TIMEBASE_15625HZ			(7)

#define MCR20A_GPIO_DATA8			BIT(7)
#define MCR20A_GPIO_DATA7			BIT(6)
#define MCR20A_GPIO_DATA6			BIT(5)
#define MCR20A_GPIO_DATA5			BIT(4)
#define MCR20A_GPIO_DATA4			BIT(3)
#define MCR20A_GPIO_DATA3			BIT(2)
#define MCR20A_GPIO_DATA2			BIT(1)
#define MCR20A_GPIO_DATA1			BIT(0)

#define MCR20A_GPIO_DIR8			BIT(7)
#define MCR20A_GPIO_DIR7			BIT(6)
#define MCR20A_GPIO_DIR6			BIT(5)
#define MCR20A_GPIO_DIR5			BIT(4)
#define MCR20A_GPIO_DIR4			BIT(3)
#define MCR20A_GPIO_DIR3			BIT(2)
#define MCR20A_GPIO_DIR2			BIT(1)
#define MCR20A_GPIO_DIR1			BIT(0)

#define MCR20A_GPIO_PUL_EN8			BIT(7)
#define MCR20A_GPIO_PUL_EN7			BIT(6)
#define MCR20A_GPIO_PUL_EN6			BIT(5)
#define MCR20A_GPIO_PUL_EN5			BIT(4)
#define MCR20A_GPIO_PUL_EN4			BIT(3)
#define MCR20A_GPIO_PUL_EN3			BIT(2)
#define MCR20A_GPIO_PUL_EN2			BIT(1)
#define MCR20A_GPIO_PUL_EN1			BIT(0)

#define MCR20A_GPIO_PUL_SEL8			BIT(7)
#define MCR20A_GPIO_PUL_SEL7			BIT(6)
#define MCR20A_GPIO_PUL_SEL6			BIT(5)
#define MCR20A_GPIO_PUL_SEL5			BIT(4)
#define MCR20A_GPIO_PUL_SEL4			BIT(3)
#define MCR20A_GPIO_PUL_SEL3			BIT(2)
#define MCR20A_GPIO_PUL_SEL2			BIT(1)
#define MCR20A_GPIO_PUL_SEL1			BIT(0)

#define MCR20A_GPIO_DS8				BIT(7)
#define MCR20A_GPIO_DS7				BIT(6)
#define MCR20A_GPIO_DS6				BIT(5)
#define MCR20A_GPIO_DS5				BIT(4)
#define MCR20A_GPIO_DS4				BIT(3)
#define MCR20A_GPIO_DS3				BIT(2)
#define MCR20A_GPIO_DS2				BIT(1)
#define MCR20A_GPIO_DS1				BIT(0)

#define MCR20A_ANT_PAD_CTRL_ANTX_POL3			BIT(7)
#define MCR20A_ANT_PAD_CTRL_ANTX_POL2			BIT(6)
#define MCR20A_ANT_PAD_CTRL_ANTX_POL1			BIT(5)
#define MCR20A_ANT_PAD_CTRL_ANTX_POL0			BIT(4)
#define MCR20A_ANT_PAD_CTRL_ANTX_CTRLMODE		BIT(3)
#define MCR20A_ANT_PAD_CTRL_ANTX_HZ			BIT(2)
#define MCR20A_ANT_PAD_CTRL_ANTX_EN_MASK		(0x03)
#define MCR20A_ANT_PAD_CTRL_ANTX_EN_SHIFT		(0)

#define MCR20A_MISC_PAD_CTRL_MISO_HIZ_EN		BIT(3)
#define MCR20A_MISC_PAD_CTRL_IRQ_B_OD			BIT(2)
#define MCR20A_MISC_PAD_CTRL_NON_GPIO_DS		BIT(1)
#define MCR20A_MISC_PAD_CTRL_ANTX_CURR			BIT(0)

#define MCR20A_ANT_AGC_CTRL_SNF_EN			BIT(7)
#define MCR20A_ANT_AGC_CTRL_AGC_EN			BIT(6)
#define MCR20A_ANT_AGC_CTRL_AGC_LEVEL_MASK		(0x30)
#define MCR20A_ANT_AGC_CTRL_AGC_LEVEL_SHIFT		(4)
#define MCR20A_ANT_AGC_CTRL_ANTX			BIT(1)
#define MCR20A_ANT_AGC_CTRL_AD_EN			BIT(0)

#define MCR20A_LPPS_BUFMIX_EN				BIT(4)
#define MCR20A_LPPS_LIM_EN				BIT(3)
#define MCR20A_LPPS_RSSI_EN				BIT(2)
#define MCR20A_LPPS_LNA_EN				BIT(1)
#define MCR20A_LPPS_CTRL_LPPS_EN			BIT(0)

/* Undocumented part copied from MCR20reg.h */
#define MCR20A_SOFT_RESET_SOG_RST			BIT(7)
#define MCR20A_SOFT_RESET_REGS_RST			BIT(4)
#define MCR20A_SOFT_RESET_PLL_RST			BIT(3)
#define MCR20A_SOFT_RESET_TX_RST			BIT(2)
#define MCR20A_SOFT_RESET_RX_RST			BIT(1)
#define MCR20A_SOFT_RESET_SEQ_MGR_RST			BIT(0)

#define MCR20A_SEQ_MGR_CTRL_SEQ_STATE_CTRL_MASK		(0x3)
#define MCR20A_SEQ_MGR_CTRL_SEQ_STATE_CTRL_SHIFT	(6)
#define MCR20A_SEQ_MGR_CTRL_NO_RX_RECYCLE		BIT(5)
#define MCR20A_SEQ_MGR_CTRL_LATCH_PREAMBLE		BIT(4)
#define MCR20A_SEQ_MGR_CTRL_EVENT_TMR_DO_NOT_LATCH	BIT(3)
#define MCR20A_SEQ_MGR_CTRL_CLR_NEW_SEQ_INHIBIT		BIT(2)
#define MCR20A_SEQ_MGR_CTRL_PSM_LOCK_DIS		BIT(1)
#define MCR20A_SEQ_MGR_CTRL_PLL_ABORT_OVRD		BIT(0)

#define MCR20A_SEQ_MGR_STS_TMR2_SEQ_TRIG_ARMED		BIT(7)
#define MCR20A_SEQ_MGR_STS_RX_MODE			BIT(6)
#define MCR20A_SEQ_MGR_STS_RX_TIMEOUT_PENDING		BIT(5)
#define MCR20A_SEQ_MGR_STS_NEW_SEQ_INHIBIT		BIT(4)
#define MCR20A_SEQ_MGR_STS_SEQ_IDLE			BIT(3)
#define MCR20A_SEQ_MGR_STS_XCVSEQ_ACTUAL_MASK		(0x7)
#define MCR20A_SEQ_MGR_STS_XCVSEQ_ACTUAL_SHIFT		(0)

#define MCR20A_ABORT_STS_PLL_ABORTED			BIT(2)
#define MCR20A_ABORT_STS_TC3_ABORTED			BIT(1)
#define MCR20A_ABORT_STS_SW_ABORTED			BIT(0)

#define MCR20A_PHY_STS_PLL_UNLOCK			BIT(7)
#define MCR20A_PHY_STS_PLL_LOCK_ERR			BIT(6)
#define MCR20A_PHY_STS_PLL_LOCK				BIT(5)
#define MCR20A_PHY_STS_CRCVALID				BIT(3)
#define MCR20A_PHY_STS_FILTERFAIL_FLAG_SEL		BIT(2)
#define MCR20A_PHY_STS_SFD_DET				BIT(1)
#define MCR20A_PHY_STS_PREAMBLE_DET			BIT(0)

#define MCR20A_TESTMODE_CTRL_HOT_ANT			BIT(4)
#define MCR20A_TESTMODE_CTRL_IDEAL_RSSI_EN		BIT(3)
#define MCR20A_TESTMODE_CTRL_IDEAL_PFC_EN		BIT(2)
#define MCR20A_TESTMODE_CTRL_CONTINUOUS_EN		BIT(1)
#define MCR20A_TESTMODE_CTRL_FPGA_EN			BIT(0)

#define MCR20A_DTM_CTRL1_ATM_LOCKED			BIT(7)
#define MCR20A_DTM_CTRL1_DTM_EN				BIT(6)
#define MCR20A_DTM_CTRL1_PAGE5				BIT(5)
#define MCR20A_DTM_CTRL1_PAGE4				BIT(4)
#define MCR20A_DTM_CTRL1_PAGE3				BIT(3)
#define MCR20A_DTM_CTRL1_PAGE2				BIT(2)
#define MCR20A_DTM_CTRL1_PAGE1				BIT(1)
#define MCR20A_DTM_CTRL1_PAGE0				BIT(0)

#define MCR20A_TX_MODE_CTRL_TX_INV			BIT(4)
#define MCR20A_TX_MODE_CTRL_BT_EN			BIT(3)
#define MCR20A_TX_MODE_CTRL_DTS2			BIT(2)
#define MCR20A_TX_MODE_CTRL_DTS1			BIT(1)
#define MCR20A_TX_MODE_CTRL_DTS0			BIT(0)
#define MCR20A_TX_MODE_CTRL_DTS_MASK			(7)

#endif /* ZEPHYR_DRIVERS_IEEE802154_IEEE802154_MCR20A_REGS_H_ */
