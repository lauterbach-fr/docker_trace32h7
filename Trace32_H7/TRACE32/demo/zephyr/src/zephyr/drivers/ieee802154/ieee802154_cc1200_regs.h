/* ieee802154_cc1200_regs.h - Registers definition for TI CC1200 */

/*
 * Copyright (c) 2017 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_IEEE802154_IEEE802154_CC1200_REGS_H_
#define ZEPHYR_DRIVERS_IEEE802154_IEEE802154_CC1200_REGS_H_

/* Access types (see Section 3.2) */

#define CC1200_ACCESS_RD			BIT(7)
#define CC1200_ACCESS_WR			(0x00)
#define CC1200_ACCESS_BURST			BIT(6)

/* Configuration registers (see Section 12 for the details) */

#define CC1200_REG_IOCFG3			(0x00)
#define GPIO3_ATRAN				BIT(7)
#define GPIO3_INV				BIT(6)
#define GPIO3_CFG(_cfg_)			(_cfg_ & 0x3F)

#define CC1200_REG_IOCFG2			(0x01)
#define GPIO2_ATRAN				BIT(7)
#define GPIO2_INV				BIT(6)
#define GPIO2_CFG(_cfg_)			(_cfg_ & 0x3F)

#define CC1200_REG_IOCFG1			(0x02)
#define GPIO1_ATRAN				BIT(7)
#define GPIO1_INV				BIT(6)
#define GPIO1_CFG(_cfg_)			(_cfg_ & 0x3F)

#define CC1200_REG_IOCFG0			(0x03)
#define GPIO0_ATRAN				BIT(7)
#define GPIO0_INV				BIT(6)
#define GPIO0_CFG(_cfg_)			(_cfg_ & 0x3F)

#define CC1200_REG_SYNC3			(0x04)
#define CC1200_REG_SYNC2			(0x05)
#define CC1200_REG_SYNC1			(0x06)
#define CC1200_REG_SYNC0			(0x07)

#define CC1200_REG_SYNC_CFG1			(0x08)
#define SYNC_MODE(_cfg_)			(_cfg_ & 0xE0)
#define SYNC_THR(_cfg_)				(_cfg_ & 0x1F)


#define CC1200_REG_SYNC_CFG0			(0x09)
#define AUTO_CLEAR				BIT(5)
#define RX_CONFIG_LIMITATION			BIT(4)
#define PQT_GATING_EN				BIT(3)
#define EXT_SYNC_DETECT				BIT(2)
#define STRICT_SYNC_CHECK(_cfg_)		(_cfg_ & 0x03)

#define CC1200_REG_DEVIATION_M			(0x0A)

#define CC1200_REG_MODCFG_DEV_E			(0x0B)
#define MODEM_MODE(_cfg_)			(_cfg_ & 0xC0)
#define MOD_FORMAT(_cfg_)			(_cfg_ & 0x38)
#define DEV_E(_cfg_)				(_cfg_ & 0x07)

#define CC1200_REG_DCFILT_CFG			(0x0C)
#define DCFILT_FREEZE_COEFF			BIT(6)
#define DCFILT_BW_SETTLE(_cfg_)			(_cfg_ & 0x38)
#define DCFILT_BW(_cfg_)			(_cfg_ & 0x07)

#define CC1200_REG_PREAMBLE_CFG1		(0x0D)
#define NUM_PREAMBL(_cfg_)			(_cfg_ & 0x3C)
#define PREAMBLE_WORD(_cfg_)			(_cfg_ & 0x03)

#define CC1200_REG_PREAMBLE_CFG0		(0x0E)
#define PQT_EN					BIT(7)
#define PQT_VALID_TIMEOUT(_cfg_)		(_cfg_ & 0x70)
#define PQT(_cfg_)				(_cfg_ & 0x0F)

#define CC1200_REG_IQIC				(0x0F)
#define IQIC_EN					BIT(7)
#define IQIC_UPDATE_COEFF_EN			BIT(6)
#define IQIC_BLEN_SETTLE(_cfg_)			(_cfg_ & 0x30)
#define IQIC_BLEN(_cfg_)			(_cfg_ & 0x0C)
#define IQIC_IMGCH_LEVEL_THR(_cfg_)		(_cfg_ & 0x03)

#define CC1200_REG_CHAN_BW			(0x10)
#define ADC_CIC_DECFACT(_cfg_)			(_cfg_ & 0xC0)
#define BB_CIC_DECFAC(_cfg_)			(_cfg_ & 0x3F)

/* Is it mentioned anywhere apart from chapter 12? No known address at least
 * #define CC1200_REG_MDMCFG2			()
 * #define ASK_SHAPE(_cfg_)			(_cfg_ & 0xC0)
 * #define SYMBOL_MAP_CFG(_cfg_)		(_cfg_ & 0x30)
 * #define UPSAMPLER_P(_cfg_)			(_cfg_ & 0x0E)
 * #define CFM_DATA_EN				BIT(0)
*/

#define CC1200_REG_MDMCFG1			(0x11)
#define CARRIER_SENSE_GATE			BIT(7)
#define FIFO_EN					BIT(6)
#define MANCHESTER_EN				BIT(5)
#define INVERT_DATA_EN				BIT(4)
#define COLLISION_DETECT_EN			BIT(3)
#define DVGA_GAIN(_cfg_)			(_cfg_ & 0x06)
#define SINGLE_ADC_EN				BIT(0)

#define CC1200_REG_MDMCFG0			(0x12)
#define TRANSPARENT_MODE_EN			BIT(6)
#define TRANSPARENT_INTFACT(_cfg_)		(_cfg_ & 0x30)
#define DATA_FILTER_EN				BIT(3)
#define VITERBI_EN				BIT(2)

#define CC1200_REG_SYMBOL_RATE2			(0x13)
#define SRATE_E(_cfg_)				(_cfg_ & 0xF0)
#define SRATE_M_19_16(_cfg_)			(_cfg_ & 0x0F)

#define CC1200_REG_SYMBOL_RATE1			(0x14)
#define CC1200_REG_SYMBOL_RATE0			(0x15)
#define CC1200_REG_AGC_REF			(0x16)
#define CC1200_REG_AGC_CS_THR			(0x17)
#define CC1200_REG_AGC_GAIN_ADJUST		(0x18)

#define CC1200_REG_AGC_CFG3			(0x19)
#define AGC_SYNC_BEHAVIOUR(_cfg_)		(_cfg_ & 0xE0)
#define AGC_MIN_GAIN(_cfg_)			(_cfg_ & 0x1F)

#define CC1200_REG_AGC_CFG2			(0x1A)
#define START_PREVIOUS_GAIN_EN			BIT(7)
#define FE_PERFORMANCE_MODE(_cfg_)		(_cfg_ & 0x60)
#define AGC_MAX_GAIN(_cfg_)			(_cfg_ & 0x1F)

#define CC1200_REG_AGC_CFG1			(0x1B)
#define RSSI_STEP_THR				BIT(6)
#define AGC_WIN_SIZE(_cfg_)			(_cfg_ & 0x38)
#define AGC_SETTLE_WAIT(_cfg_)			(_cfg_ & 0x07)

#define CC1200_REG_AGC_CFG0			(0x1C)
#define AGC_HYST_LEVEL(_cfg_)			(_cfg_ & 0xC0)
#define AGC_SLEWRATE_LIMIT(_cfg_)		(_cfg_ & 0x30)
#define RSSI_VALID_CNT(_cfg_)			(_cfg_ & 0x0C)
#define AGC_ASK_DECAY(_cfg_)			(_cfg_ & 0x03)

#define CC1200_REG_FIFO_CFG			(0x1D)
#define CRC_AUTOFLUSH				BIT(7)
#define FIFO_THR(_cfg_)				(_cfg_ & 0x7F)

#define CC1200_REG_DEV_ADDR			(0x1E)

#define CC1200_REG_SETTLING_CFG			(0x1F)
#define FS_AUTOCAL(_cfg_)			(_cfg_ & 0x18)
#define LOCK_TIME(_cfg_)			(_cfg_ & 0x06)
#define FSREG_TIME				BIT(0)

#define CC1200_REG_FS_CFG			(0x20)
#define FS_LOCK_EN				BIT(4)
#define FSD_BANDSELECT(_cfg_)			(_cfg_ & 0x0F)

#define CC1200_REG_WOR_CFG1			(0x21)
#define WOR_RES(_cfg_)				(_cfg_ & 0xC0)
#define WOR_MODE(_cfg_)				(_cfg_ & 0x38)
#define EVENT1(_cfg_)				(_cfg_ & 0x07)

#define CC1200_REG_WOR_CFG0			(0x22)
#define RX_DUTY_CYCLE_MODE(_cfg_)		(_cfg_ & 0xC0)
#define DIV_256HZ_EN				BIT(5)
#define EVENT2_CFG(_cfg_)			(_cfg_ & 0x18)
#define RC_MODE(_cfg_)				(_cfg_ & 0x06)
#define RC_PD					BIT(0)

#define CC1200_REG_WOR_EVENT0_MSB		(0x23)
#define CC1200_REG_WOR_EVENT0_LSB		(0x24)
#define CC1200_REG_RXDCM_TIME			(0x25)

#define CC1200_REG_PKT_CFG2			(0x26)
#define BYTE_SWAP_EN				BIT(6)
#define FG_MODE_EN				BIT(5)
#define CCA_MODE(_cfg_)				(_cfg_ & 0x1C)
#define CCA_ALWAYS_CLEAR			(0)
#define CCA_RSSI_BELOW				(1 << 2)
#define CCA_NO_RX				(2 << 2)
#define CCA_RSSI_BELOW_NO_RX			(3 << 2)
#define CCA_RSSI_BELOW_ETSI_LBT			(4 << 2)
#define PKT_FORMAT(_cfg_)			(_cfg_ & 0x03)
#define PKT_FORMAT_NORMAL_MODE			(0)
#define PKT_FORMAT_SYNCHRONOUS_MODE		(1)
#define PKT_FORMAT_RANDOM_MODE			(2)
#define PKT_FORMAT_TRANSPARENT_MODE		(3)

#define CC1200_REG_PKT_CFG1			(0x27)
#define FEC_EN					BIT(7)
#define WHITE_DATA				BIT(6)
#define PN9_SWAP_EN				BIT(5)
#define ADDR_CHECK_CFG(_cfg_)			(_cfg_ & 0x18)
#define ADDR_NO_CHK				(0)
#define ADDR_CHK_NO_BROADCAST			(1 << 3)
#define ADDR_CHK_BROADCAST_00			(2 << 3)
#define ADDR_CHK_BROADCAST_FF			(3 << 3)
#define CRC_CFG(_cfg_)				(_cfg_ & 0x06)
#define CRC_NONE				(0)
#define CRC_FFFF				(1 << 1)
#define CRC_0000				(2 << 1)
#define CRC_1D0F				(3 << 1)
#define APPEND_STATUS				BIT(0)

#define CC1200_REG_PKT_CFG0			(0x28)
#define LENGTH_CONFIG(_cfg_)			(_cfg_ & 0x60)
#define LENGTH_FIXED				(0)
#define LENGTH_VAR_1				(1 << 5)
#define LENGTH_INFINITE				(2 << 5)
#define LENGTH_VAR_2				(3 << 5)
#define PKT_BIT_LEN(_cfg_)			(_cfg_ & 0x1C)
#define UART_MODE_EN				BIT(1)
#define UART_SWAP_EN				BIT(0)

#define CC1200_REG_RFEND_CFG1			(0x29)
#define RXOFF_MODE(_cfg_)			(_cfg_ & 0x30)
#define RX_TIME(_cfg_)				(_cfg_ & 0x0E)
#define RX_TIME_QUAL				BIT(0)

#define CC1200_REG_RFEND_CFG0			(0x2A)
#define CAL_END_WAKE_UP_EN			BIT(6)
#define TXOFF_MODE(_cfg_)			(_cfg_ & 0x30)
#define TERM_ON_BAD_PACKET_EN			BIT(3)
#define ANT_DIV_RX_TERM_CFG(_cfg_)		(_cfg_ & 0x07)

/* Common RFEND tx/rx mode */
#define RFEND_TXRX_MODE_IDLE			(0)
#define RFEND_TXRX_MODE_FSTXON			(1 << 4)
#define RFEND_TXRX_MODE_TX			(2 << 4)
#define RFEND_TXRX_MODE_RX			(3 << 4)

#define CC1200_REG_PA_CFG1			(0x2B)
#define PA_RAMP_SHAPE_EN			BIT(6)
#define PA_POWER_RAMP_MASK			(0x3F)

#define CC1200_REG_PA_CFG0			(0x2C)
#define FIRST_IPL(_cfg_)			(_cfg_ & 0xE0)
#define SECOND_IPL(_cfg_)			(_cfg_ & 0x1C)
#define RAMP_SHAPE(_cfg_)			(_cfg_ & 0x03)

#define CC1200_REG_ASK_CFG			(0x2D)
#define AGC_ASK_BW(_cfg_)			(_cfg_ & 0xC0)
#define ASK_DEPTH(_cfg_)			(_cfg_ & 0x3F)

#define CC1200_REG_PKT_LEN			(0x2E)
#define CC1200_REG_EXTENDED_ADDRESS		(0x2F)

/* Command strobes */
#define CC1200_INS_SRES				(0x30)
#define CC1200_INS_SFSTXON			(0x31)
#define CC1200_INS_SXOFF			(0x32)
#define CC1200_INS_SCAL				(0x33)
#define CC1200_INS_SRX				(0x34)
#define CC1200_INS_STX				(0x35)
#define CC1200_INS_SIDLE			(0x36)
#define CC1200_INS_SAFC				(0x37)
#define CC1200_INS_SWOR				(0x38)
#define CC1200_INS_SPWD				(0x39)
#define CC1200_INS_SFRX				(0x3A)
#define CC1200_INS_SFTX				(0x3B)
#define CC1200_INS_SWORRST			(0x3C)
#define CC1200_INS_SNOP				(0x3D)

/* Memory access */
#define CC1200_MEM_DMA				(0x3E)
#define CC1200_MEM_STD				(0x3F)

/* FIFO access */
#define CC1200_REG_TXFIFO			(0x3F)
#define CC1200_REG_RXFIFO			(0x3F)

/* Configuration registers (Extended register space) */
#define CC1200_REG_IF_MIX_CFG			(0x00)
#define CC1200_REG_FREQOFF_CFG			(0x01)
#define CC1200_REG_TOC_CFG			(0x02)
#define CC1200_REG_MARC_SPARE			(0x03)
#define CC1200_REG_ECG_CFG			(0x04)
#define CC1200_REG_MDMCFG2			(0x05)
#define CC1200_REG_EXT_CTRL			(0x06)
#define CC1200_REG_RCCAL_FINE			(0x07)
#define CC1200_REG_RCCAL_COARSE			(0x08)
#define CC1200_REG_RCCAL_OFFSET			(0x09)
#define CC1200_REG_FREQOFF1			(0x0A)
#define CC1200_REG_FREQOFF0			(0x0B)
#define CC1200_REG_FREQ2			(0x0C)
#define CC1200_REG_FREQ1			(0x0D)
#define CC1200_REG_FREQ0			(0x0E)
#define CC1200_REG_IF_ADC2			(0x0F)
#define CC1200_REG_IF_ADC1			(0x10)
#define CC1200_REG_IF_ADC0			(0x11)
#define CC1200_REG_FS_DIG1			(0x12)
#define CC1200_REG_FS_DIG0			(0x13)
#define CC1200_REG_FS_CAL3			(0x14)
#define CC1200_REG_FS_CAL2			(0x15)
#define CC1200_REG_FS_CAL1			(0x16)
#define CC1200_REG_FS_CAL0			(0x17)
#define CC1200_REG_FS_CHP			(0x18)
#define CC1200_REG_FS_DIVTWO			(0x19)
#define CC1200_REG_FS_DSM1			(0x1A)
#define CC1200_REG_FS_DSM0			(0x1B)
#define CC1200_REG_FS_DVC1			(0x1C)
#define CC1200_REG_FS_DVC0			(0x1D)
#define CC1200_REG_FS_LBI			(0x1E)
#define CC1200_REG_FS_PFD			(0x1F)
#define CC1200_REG_FS_PRE			(0x20)
#define CC1200_REG_FS_REG_DIV_CML		(0x21)
#define CC1200_REG_FS_SPARE			(0x22)
#define CC1200_REG_FS_VCO4			(0x23)
#define CC1200_REG_FS_VCO3			(0x24)
#define CC1200_REG_FS_VCO2			(0x25)
#define CC1200_REG_FS_VCO1			(0x26)
#define CC1200_REG_FS_VCO0			(0x27)
#define CC1200_REG_GBIAS6			(0x28)
#define CC1200_REG_GBIAS5			(0x29)
#define CC1200_REG_GBIAS4			(0x2A)
#define CC1200_REG_GBIAS3			(0x2B)
#define CC1200_REG_GBIAS2			(0x2C)
#define CC1200_REG_GBIAS1			(0x2D)
#define CC1200_REG_GBIAS0			(0x2E)
#define CC1200_REG_IFAMP			(0x2F)
#define CC1200_REG_LNA				(0x30)
#define CC1200_REG_RXMIX			(0x31)
#define CC1200_REG_XOSC5			(0x32)
#define CC1200_REG_XOSC4			(0x33)
#define CC1200_REG_XOSC3			(0x34)
#define CC1200_REG_XOSC2			(0x35)
#define CC1200_REG_XOSC1			(0x36)
#define CC1200_REG_XOSC0			(0x37)
#define CC1200_REG_ANALOG_SPARE			(0x38)
#define CC1200_REG_PA_CFG3			(0x39)
/* All addresses in between are unused ones */
#define CC1200_REG_WOR_TIME1			(0x64)
#define CC1200_REG_WOR_TIME0			(0x65)
#define CC1200_REG_WOR_CAPTURE1			(0x66)
#define CC1200_REG_WOR_CAPTURE0			(0x67)
#define CC1200_REG_BIST				(0x68)
#define CC1200_REG_DCFILTOFFSET_I1		(0x69)
#define CC1200_REG_DCFILTOFFSET_I0		(0x6A)
#define CC1200_REG_DCFILTOFFSET_Q1		(0x6B)
#define CC1200_REG_DCFILTOFFSET_Q0		(0x6C)
#define CC1200_REG_IQIE_I1			(0x6D)
#define CC1200_REG_IQIE_I0			(0x6E)
#define CC1200_REG_IQIE_Q1			(0x6F)
#define CC1200_REG_IQIE_Q0			(0x70)
#define CC1200_REG_RSSI1			(0x71)

#define CC1200_REG_RSSI0			(0x72)
#define RSSI(_reg_)				((_reg_ & 0x78) >> 3)
#define CARRIER_SENSE				BIT(2)
#define CARRIER_SENSE_VALID			BIT(1)
#define RSSI_VALID				BIT(0)

#define CC1200_REG_MARCSTATE			(0x73)
#define CC1200_REG_LQI_VAL			(0x74)
#define CC1200_REG_PQT_SYNC_ERR			(0x75)
#define CC1200_REG_DEM_STATUS			(0x76)
#define CC1200_REG_FREQOFF_EST1			(0x77)
#define CC1200_REG_FREQOFF_EST0			(0x78)
#define CC1200_REG_AGC_GAIN3			(0x79)
#define CC1200_REG_AGC_GAIN2			(0x7A)
#define CC1200_REG_AGC_GAIN1			(0x7B)
#define CC1200_REG_AGC_GAIN0			(0x7C)
#define CC1200_REG_CFM_RX_DATA_OUT		(0x7D)
#define CC1200_REG_CFM_RX_DATA_IN		(0x7E)
#define CC1200_REG_ASK_SOFT_RX_DATA		(0x7F)
#define CC1200_REG_RNDGEN			(0x80)
#define CC1200_REG_MAGN2			(0x81)
#define CC1200_REG_MAGN1			(0x82)
#define CC1200_REG_MAGN0			(0x83)
#define CC1200_REG_ANG1				(0x84)
#define CC1200_REG_ANG0				(0x85)
#define CC1200_REG_CHFILT_I2			(0x86)
#define CC1200_REG_CHFILT_I1			(0x87)
#define CC1200_REG_CHFILT_I0			(0x88)
#define CC1200_REG_CHFILT_Q2			(0x89)
#define CC1200_REG_CHFILT_Q1			(0x8A)
#define CC1200_REG_CHFILT_Q0			(0x8B)
#define CC1200_REG_GPIO_STATUS			(0x8C)
#define CC1200_REG_FSCAL_CTRL			(0x8D)
#define CC1200_REG_PHASE_ADJUST			(0x8E)
#define CC1200_REG_PARTNUMBER			(0x8F)
#define CC1200_REG_PARTVERSION			(0x90)
#define CC1200_REG_SERIAL_STATUS		(0x91)
#define CC1200_REG_MODEM_STATUS1		(0x92)
#define CC1200_REG_MODEM_STATUS0		(0x93)
#define CC1200_REG_MARC_STATUS1			(0x94)
#define CC1200_REG_MARC_STATUS0			(0x95)
#define CC1200_REG_PA_IFAMP_TEST		(0x96)
#define CC1200_REG_FSRF_TEST			(0x97)
#define CC1200_REG_PRE_TEST			(0x98)
#define CC1200_REG_PRE_OVR			(0x99)
#define CC1200_REG_ADC_TEST			(0x9A)
#define CC1200_REG_DVC_TEST			(0x9B)
#define CC1200_REG_ATEST			(0x9C)
#define CC1200_REG_ATEST_LVDS			(0x9D)
#define CC1200_REG_ATEST_MODE			(0x9E)
#define CC1200_REG_XOSC_TEST1			(0x9F)
#define CC1200_REG_XOSC_TEST0			(0xA0)
#define CC1200_REG_AES				(0xA1)
#define CC1200_REG_MDM_TEST			(0xA2)
/* All addresses in between are unused ones */
#define CC1200_REG_RXFIRST			(0xD2)
#define CC1200_REG_TXFIRST			(0xD3)
#define CC1200_REG_RXLAST			(0xD4)
#define CC1200_REG_TXLAST			(0xD5)
#define CC1200_REG_NUM_TXBYTES			(0xD6)
#define CC1200_REG_NUM_RXBYTES			(0xD7)
#define CC1200_REG_FIFO_NUM_TXBYTES		(0xD8)
#define CC1200_REG_FIFO_NUM_RXBYTES		(0xD9)
#define CC1200_REG_RXFIFO_PRE_BUF		(0xDA)
/* All addresses in between are unused ones */
#define CC1200_REG_AES_WORKSPACE		(0xE0)


/* Useful values
 ***************
 */


/* GPIO signals - See Section 3.4.1.1
 * Note: some signals are only available on certain GPIO
 *       thus the number CC1200_GPIOn_(...) on some which
 *       tells the GPIO line where that signal is valid.
 */
#define CC1200_GPIO_SIG_RXFIFO_THR		(0)
#define CC1200_GPIO_SIG_RXFIFO_THR_PKT		(1)
#define CC1200_GPIO_SIG_TXFIFO_THR		(2)
#define CC1200_GPIO_SIG_TXFIFO_THR_PKT		(3)
#define CC1200_GPIO_SIG_RXFIFO_OVERFLOW		(4)
#define CC1200_GPIO_SIG_TXFIFO_UNDERFLOW	(5)
#define CC1200_GPIO_SIG_PKT_SYNC_RXTX		(6)
#define CC1200_GPIO_SIG_CRC_OK			(7)
#define CC1200_GPIO_SIG_SERIAL_CLK		(8)
#define CC1200_GPIO_SIG_SERIAL_RX		(9)
#define CC1200_GPIO_SIG_PQT_REACHED		(11)
#define CC1200_GPIO_SIG_PQT_VALID		(12)
#define CC1200_GPIO_SIG_RSSI_VALID		(13)
#define CC1200_GPIO3_SIG_RSSI_UPDATE		(14)
#define CC1200_GPIO2_SIG_RSSI_UPDATE		(14)
#define CC1200_GPIO1_SIG_AGC_HOLD		(14)
#define CC1200_GPIO0_SIG_AGC_UPDATE		(14)
#define CC1200_GPIO3_SIG_CCA_STATUS		(15)
#define CC1200_GPIO2_SIG_TXONCCA_DONE		(15)
#define CC1200_GPIO1_SIG_CCA_STATUS		(15)
#define CC1200_GPIO0_SIG_TXONCCA_FAILED		(15)
#define CC1200_GPIO_SIG_CARRIER_SENSE_VALID	(16)
#define CC1200_GPIO_SIG_CARRIER_SENSE		(17)
#define CC1200_GPIO3_SIG_DSSS_CLK		(18)
#define CC1200_GPIO2_SIG_DSSS_DATA0		(18)
#define CC1200_GPIO1_SIG_DSSS_CLK		(18)
#define CC1200_GPIO0_SIG_DSSS_DATA1		(18)
#define CC1200_GPIO_SIG_PKT_CRC_OK		(19)
#define CC1200_GPIO_SIG_MCU_WAKEUP		(20)
#define CC1200_GPIO_SIG_SYNC_LOW0_HIGH1		(21)
#define CC1200_GPIO0_SIG_AES_COMMAND_ACTIVE	(22)
#define CC1200_GPIO_SIG_LNA_PA_REG_PD		(23)
#define CC1200_GPIO_SIG_LNA_PD			(24)
#define CC1200_GPIO_SIG_PA_PD			(25)
#define CC1200_GPIO_SIG_RX0TX1_CFG		(26)
#define CC1200_GPIO_SIG_IMAGE_FOUND		(28)
#define CC1200_GPIO_SIG_CLKEN_CFM		(29)
#define CC1200_GPIO_SIG_CFM_TX_DATA_CLK		(30)
#define CC1200_GPIO_SIG_RSSI_STEP_FOUND		(33)
#define CC1200_GPIO3_SIG_AES_RUN		(34)
#define CC1200_GPIO2_SIG_AES_RUN		(34)
#define CC1200_GPIO1_SIG_RSSI_STEP_EVENT	(34)
#define CC1200_GPIO0_SIG_RSSI_STEP_EVENT	(34)
#define CC1200_GPIO1_SIG_LOCK			(35)
#define CC1200_GPIO0_SIG_LOCK			(35)
#define CC1200_GPIO_SIG_ANTENNA_SELECT		(36)
#define CC1200_GPIO_SIG_MARC_2PIN_STATUS_1	(37)
#define CC1200_GPIO_SIG_MARC_2PIN_STATUS_0	(38)
#define CC1200_GPIO2_SIG_TXFIFO_OVERFLOW	(39)
#define CC1200_GPIO0_SIG_RXFIFO_UNDERFLOW	(39)
#define CC1200_GPIO3_SIG_MAGN_VALID		(40)
#define CC1200_GPIO2_SIG_CHFILT_VALID		(40)
#define CC1200_GPIO1_SIG_RCC_CAL_VALID		(40)
#define CC1200_GPIO0_SIG_CHFILT_STARTUP_VALID	(40)
#define CC1200_GPIO3_SIG_COLLISION_FOUND	(41)
#define CC1200_GPIO2_SIG_SYNC_EVENT		(41)
#define CC1200_GPIO1_SIG_COLLISION_FOUND	(41)
#define CC1200_GPIO0_SIG_COLLISION_EVENT	(41)
#define CC1200_GPIO_SIG_PA_RAMP_UP		(42)
#define CC1200_GPIO3_SIG_CRC_FAILED		(43)
#define CC1200_GPIO2_SIG_LENGTH_FAILED		(43)
#define CC1200_GPIO1_SIG_ADDR_FAILED		(43)
#define CC1200_GPIO0_SIG_UART_FRAMING_ERROR	(43)
#define CC1200_GPIO_SIG_AGC_STABLE_GAIN		(44)
#define CC1200_GPIO_SIG_AGC_UPDATE		(45)
#define CC1200_GPIO3_SIG_ADC_CLOCK		(46)
#define CC1200_GPIO2_SIG_ADC_Q_DATA_SAMPLE	(46)
#define CC1200_GPIO1_SIG_ADC_CLOCK		(46)
#define CC1200_GPIO0_SIG_ADC_I_DATA_SAMPLE	(46)
#define CC1200_GPIO_SIG_HIGHZ			(48)
#define CC1200_GPIO_SIG_EXT_CLOCK		(49)
#define CC1200_GPIO_SIG_CHIP_RDYn		(50)
#define CC1200_GPIO_SIG_HW0			(51)
#define CC1200_GPIO_SIG_CLOCK_40K		(54)
#define CC1200_GPIO_SIG_WOR_EVENT0		(55)
#define CC1200_GPIO_SIG_WOR_EVENT1		(56)
#define CC1200_GPIO_SIG_WOR_EVENT2		(57)
#define CC1200_GPIO_SIG_XOSC_STABLE		(59)
#define CC1200_GPIO_SIG_EXT_OSC_EN		(60)

/* Chip status - See Section 3.1.2 */
#define CC1200_STATUS_CHIP_NOT_READY		BIT(7)
#define CC1200_STATUS_IDLE			(0x00)
#define CC1200_STATUS_RX			(0x01 << 4)
#define CC1200_STATUS_TX			(0x02 << 4)
#define CC1200_STATUS_FSTXON			(0x03 << 4)
#define CC1200_STATUS_CALIBRATE			(0x04 << 4)
#define CC1200_STATUS_SETTLING			(0x05 << 4)
#define CC1200_STATUS_RX_FIFO_ERROR		(0x06 << 4)
#define CC1200_STATUS_TX_FIFO_ERROR		(0x07 << 4)
#define CC1200_STATUS_MASK			(0x70)

/* Appended FCS - See Section 8 */
#define CC1200_FCS_LEN				(2)
#define CC1200_FCS_CRC_OK			BIT(7)
#define CC1200_FCS_LQI_MASK			(0x7F)

/* ToDo: supporting 802.15.4g will make this header of a different size */
#define CC1200_PHY_HDR_LEN			(1)

#endif /* ZEPHYR_DRIVERS_IEEE802154_IEEE802154_CC1200_REGS_H_ */
