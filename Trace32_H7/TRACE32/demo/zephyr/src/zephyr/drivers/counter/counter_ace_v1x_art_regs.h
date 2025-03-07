/*
 * Copyright (c) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __COUNTER_ACE_V1X_ART_REGS__
#define __COUNTER_ACE_V1X_ART_REGS__

#if CONFIG_ACE_V1X_ART_COUNTER

#define ACE_ART_COUNTER_ID DT_NODELABEL(ace_art_counter)
#define ACE_TIMESTAMP_ID DT_NODELABEL(ace_timestamp)

#define ACE_TSCTRL	(DT_REG_ADDR(ACE_TIMESTAMP_ID))

#define ACE_ARTCS	(DT_REG_ADDR(ACE_ART_COUNTER_ID))
#define ACE_ARTCS_LO ACE_ARTCS
#define ACE_ARTCS_HI (ACE_ARTCS_LO + 0x04)

#define ACE_TSCTRL_CDMAS_MASK		GENMASK(4, 0)
#define ACE_TSCTRL_ODTS_MASK		BIT(5)
#define ACE_TSCTRL_LWCS_MASK		BIT(6)
#define ACE_TSCTRL_HHTSE_MASK		BIT(7)
#define ACE_TSCTRL_CLNKS_MASK		GENMASK(11, 10)
#define ACE_TSCTRL_DMATS_MASK		GENMASK(13, 12)
#define ACE_TSCTRL_IONTE_MASK		BIT(30)
#define ACE_TSCTRL_NTK_MASK		BIT(31)

#endif

#endif /*__COUNTER_ACE_V1X_ART_REGS__*/
