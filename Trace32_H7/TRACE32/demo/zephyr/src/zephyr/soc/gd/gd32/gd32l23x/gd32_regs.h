/*
 * Copyright (c) 2022, Teslabs Engineering S.L.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef SOC_ARM_GIGADEVICE_GD32L23X_GD32_REGS_H_
#define SOC_ARM_GIGADEVICE_GD32L23X_GD32_REGS_H_

#include <zephyr/sys/util_macro.h>

/* RCU */
#define RCU_CFG0_OFFSET      0x04U
#define RCU_AHBEN_OFFSET     0x14U
#define RCU_APB2EN_OFFSET    0x18U
#define RCU_APB1EN_OFFSET    0x1CU

#define RCU_CFG0_AHBPSC_POS  4U
#define RCU_CFG0_AHBPSC_MSK  (BIT_MASK(4) << RCU_CFG0_AHBPSC_POS)
#define RCU_CFG0_APB1PSC_POS 8U
#define RCU_CFG0_APB1PSC_MSK (BIT_MASK(3) << RCU_CFG0_APB1PSC_POS)
#define RCU_CFG0_APB2PSC_POS 11U
#define RCU_CFG0_APB2PSC_MSK (BIT_MASK(3) << RCU_CFG0_APB2PSC_POS)

#endif /* SOC_ARM_GIGADEVICE_GD32L23X_GD32_REGS_H_ */
