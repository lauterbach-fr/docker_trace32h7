/*
 * Copyright 2023 Cirrus Logic, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_CHARGER_BQ24190_H_
#define ZEPHYR_DRIVERS_CHARGER_BQ24190_H_

/* Input Source Control */
#define BQ24190_REG_ISC              0x00
#define BQ24190_REG_ISC_EN_HIZ_MASK  BIT(7)
#define BQ24190_REG_ISC_EN_HIZ_SHIFT 7
#define BQ24190_REG_ISC_VINDPM_MASK  GENMASK(6, 3)
#define BQ24190_REG_ISC_VINDPM_SHIFT 3
#define BQ24190_REG_ISC_IINLIM_MASK  GENMASK(2, 0)

/* Power-On Configuration */
#define BQ24190_REG_POC                    0x01
#define BQ24190_REG_POC_RESET_MASK         BIT(7)
#define BQ24190_REG_POC_RESET_SHIFT        7
#define BQ24190_RESET_MAX_TRIES            100
#define BQ24190_REG_POC_WDT_RESET_MASK     BIT(6)
#define BQ24190_REG_POC_WDT_RESET_SHIFT    6
#define BQ24190_REG_POC_CHG_CONFIG_MASK    GENMASK(5, 4)
#define BQ24190_REG_POC_CHG_CONFIG_SHIFT   4
#define BQ24190_REG_POC_CHG_CONFIG_DISABLE 0x0
#define BQ24190_REG_POC_CHG_CONFIG_CHARGE  0x1
#define BQ24190_REG_POC_CHG_CONFIG_OTG     0x2
#define BQ24190_REG_POC_CHG_CONFIG_OTG_ALT 0x3
#define BQ24190_REG_POC_SYS_MIN_MASK       GENMASK(3, 1)
#define BQ24190_REG_POC_SYS_MIN_SHIFT      1
#define BQ24190_REG_POC_SYS_MIN_MIN_UV     3000000
#define BQ24190_REG_POC_SYS_MIN_MAX_UV     3700000
#define BQ24190_REG_POC_BOOST_LIM_MASK     BIT(0)
#define BQ24190_REG_POC_BOOST_LIM_SHIFT    0

/* Charge Current Control */
#define BQ24190_REG_CCC                   0x02
#define BQ24190_REG_CCC_ICHG_MASK         GENMASK(7, 2)
#define BQ24190_REG_CCC_ICHG_SHIFT        2
#define BQ24190_REG_CCC_ICHG_STEP_UA      64000
#define BQ24190_REG_CCC_ICHG_OFFSET_UA    512000
#define BQ24190_REG_CCC_ICHG_MIN_UA       BQ24190_REG_CCC_ICHG_OFFSET_UA
#define BQ24190_REG_CCC_ICHG_MAX_UA       4544000
#define BQ24190_REG_CCC_FORCE_20PCT_MASK  BIT(0)
#define BQ24190_REG_CCC_FORCE_20PCT_SHIFT 0

/* Pre-charge/Termination Current Cntl */
#define BQ24190_REG_PCTCC                   0x03
#define BQ24190_REG_PCTCC_IPRECHG_MASK      GENMASK(7, 4)
#define BQ24190_REG_PCTCC_IPRECHG_SHIFT     4
#define BQ24190_REG_PCTCC_IPRECHG_STEP_UA   128000
#define BQ24190_REG_PCTCC_IPRECHG_OFFSET_UA 128000
#define BQ24190_REG_PCTCC_IPRECHG_MIN_UA    BQ24190_REG_PCTCC_IPRECHG_OFFSET_UA
#define BQ24190_REG_PCTCC_IPRECHG_MAX_UA    2048000
#define BQ24190_REG_PCTCC_ITERM_MASK        GENMASK(3, 0)
#define BQ24190_REG_PCTCC_ITERM_SHIFT       0
#define BQ24190_REG_PCTCC_ITERM_STEP_UA     128000
#define BQ24190_REG_PCTCC_ITERM_OFFSET_UA   128000
#define BQ24190_REG_PCTCC_ITERM_MIN_UA      BQ24190_REG_PCTCC_ITERM_OFFSET_UA
#define BQ24190_REG_PCTCC_ITERM_MAX_UA      2048000

/* Charge Voltage Control */
#define BQ24190_REG_CVC                0x04
#define BQ24190_REG_CVC_VREG_MASK      GENMASK(7, 2)
#define BQ24190_REG_CVC_VREG_SHIFT     2
#define BQ24190_REG_CVC_VREG_STEP_UV   16000
#define BQ24190_REG_CVC_VREG_OFFSET_UV 3504000
#define BQ24190_REG_CVC_VREG_MIN_UV    BQ24190_REG_CVC_VREG_OFFSET_UV
#define BQ24190_REG_CVC_VREG_MAX_UV    4400000
#define BQ24190_REG_CVC_BATLOWV_MASK   BIT(1)
#define BQ24190_REG_CVC_BATLOWV_SHIFT  1
#define BQ24190_REG_CVC_VRECHG_MASK    BIT(0)
#define BQ24190_REG_CVC_VRECHG_SHIFT   0

/* Charge Term/Timer Control */
#define BQ24190_REG_CTTC                  0x05
#define BQ24190_REG_CTTC_EN_TERM_MASK     BIT(7)
#define BQ24190_REG_CTTC_EN_TERM_SHIFT    7
#define BQ24190_REG_CTTC_TERM_STAT_MASK   BIT(6)
#define BQ24190_REG_CTTC_TERM_STAT_SHIFT  6
#define BQ24190_REG_CTTC_WATCHDOG_MASK    GENMASK(5, 4)
#define BQ24190_REG_CTTC_WATCHDOG_SHIFT   4
#define BQ24190_REG_CTTC_EN_TIMER_MASK    BIT(3)
#define BQ24190_REG_CTTC_EN_TIMER_SHIFT   3
#define BQ24190_REG_CTTC_CHG_TIMER_MASK   GENMASK(2, 1)
#define BQ24190_REG_CTTC_CHG_TIMER_SHIFT  1
#define BQ24190_REG_CTTC_JEITA_ISET_MASK  BIT(0)
#define BQ24190_REG_CTTC_JEITA_ISET_SHIFT 0

/* IR Comp/Thermal Regulation Control */
#define BQ24190_REG_ICTRC                0x06
#define BQ24190_REG_ICTRC_BAT_COMP_MASK  GENMASK(7, 5)
#define BQ24190_REG_ICTRC_BAT_COMP_SHIFT 5
#define BQ24190_REG_ICTRC_VCLAMP_MASK    GENMASK(4, 2)
#define BQ24190_REG_ICTRC_VCLAMP_SHIFT   2
#define BQ24190_REG_ICTRC_TREG_MASK      GENMASK(1, 0)
#define BQ24190_REG_ICTRC_TREG_SHIFT     0

/* Misc. Operation Control */
#define BQ24190_REG_MOC                      0x07
#define BQ24190_REG_MOC_DPDM_EN_MASK         BIT(7)
#define BQ24190_REG_MOC_DPDM_EN_SHIFT        7
#define BQ24190_REG_MOC_TMR2X_EN_MASK        BIT(6)
#define BQ24190_REG_MOC_TMR2X_EN_SHIFT       6
#define BQ24190_REG_MOC_BATFET_DISABLE_MASK  BIT(5)
#define BQ24190_REG_MOC_BATFET_DISABLE_SHIFT 5
#define BQ24190_REG_MOC_JEITA_VSET_MASK      BIT(4)
#define BQ24190_REG_MOC_JEITA_VSET_SHIFT     4
#define BQ24190_REG_MOC_INT_MASK_MASK        GENMASK(1, 0)
#define BQ24190_REG_MOC_INT_MASK_SHIFT       0

/* System Status */
#define BQ24190_REG_SS                  0x08
#define BQ24190_REG_SS_VBUS_STAT_MASK   GENMASK(7, 6)
#define BQ24190_REG_SS_VBUS_STAT_SHIFT  6
#define BQ24190_REG_SS_CHRG_STAT_MASK   GENMASK(5, 4)
#define BQ24190_REG_SS_CHRG_STAT_SHIFT  4
#define BQ24190_CHRG_STAT_NOT_CHRGING   0x0
#define BQ24190_CHRG_STAT_PRECHRG       0x1
#define BQ24190_CHRG_STAT_FAST_CHRG     0x2
#define BQ24190_CHRG_STAT_CHRG_TERM     0x3
#define BQ24190_REG_SS_DPM_STAT_MASK    BIT(3)
#define BQ24190_REG_SS_DPM_STAT_SHIFT   3
#define BQ24190_REG_SS_PG_STAT_MASK     BIT(2)
#define BQ24190_REG_SS_PG_STAT_SHIFT    2
#define BQ24190_REG_SS_THERM_STAT_MASK  BIT(1)
#define BQ24190_REG_SS_THERM_STAT_SHIFT 1
#define BQ24190_REG_SS_VSYS_STAT_MASK   BIT(0)
#define BQ24190_REG_SS_VSYS_STAT_SHIFT  0

/* Fault */
#define BQ24190_REG_F                      0x09
#define BQ24190_REG_F_WATCHDOG_FAULT_MASK  BIT(7)
#define BQ24190_REG_F_WATCHDOG_FAULT_SHIFT 7
#define BQ24190_REG_F_BOOST_FAULT_MASK     BIT(6)
#define BQ24190_REG_F_BOOST_FAULT_SHIFT    6
#define BQ24190_REG_F_CHRG_FAULT_MASK      GENMASK(5, 4)
#define BQ24190_REG_F_CHRG_FAULT_SHIFT     4
#define BQ24190_CHRG_FAULT_INPUT_FAULT     0x1
#define BQ24190_CHRG_FAULT_TSHUT           0x2
#define BQ24190_CHRG_SAFETY_TIMER          0x3
#define BQ24190_REG_F_BAT_FAULT_MASK       BIT(3)
#define BQ24190_REG_F_BAT_FAULT_SHIFT      3
#define BQ24190_REG_F_NTC_FAULT_MASK       GENMASK(2, 0)
#define BQ24190_REG_F_NTC_FAULT_SHIFT      0
#define BQ24190_NTC_FAULT_TS1_COLD         0x1
#define BQ24190_NTC_FAULT_TS1_HOT          0x2
#define BQ24190_NTC_FAULT_TS2_COLD         0x3
#define BQ24190_NTC_FAULT_TS2_HOT          0x4
#define BQ24190_NTC_FAULT_TS1_TS2_COLD     0x5
#define BQ24190_NTC_FAULT_TS1_TS2_HOT      0x6

/* Vendor/Part/Revision Status */
#define BQ24190_REG_VPRS                  0x0A
#define BQ24190_REG_VPRS_PN_MASK          GENMASK(5, 3)
#define BQ24190_REG_VPRS_PN_SHIFT         3
#define BQ24190_REG_VPRS_PN_24190         0x4
#define BQ24190_REG_VPRS_PN_24192         0x5 /* Also 24193, 24196 */
#define BQ24190_REG_VPRS_PN_24192I        0x3
#define BQ24190_REG_VPRS_TS_PROFILE_MASK  BIT(2)
#define BQ24190_REG_VPRS_TS_PROFILE_SHIFT 2
#define BQ24190_REG_VPRS_DEV_REG_MASK     GENMASK(1, 0)
#define BQ24190_REG_VPRS_DEV_REG_SHIFT    0

#endif
