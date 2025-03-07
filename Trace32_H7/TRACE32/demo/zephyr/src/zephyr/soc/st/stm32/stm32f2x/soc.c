/*
 * Copyright (c) 2018 qianfan Zhao <qianfanguijin@163.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief System/hardware module for stm32f2 processor
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/init.h>
#include <soc.h>
#include <stm32_ll_system.h>
#include <zephyr/linker/linker-defs.h>
#include <string.h>

#include <cmsis_core.h>

/**
 * @brief Perform basic hardware initialization at boot.
 *
 * This needs to be run from the very beginning.
 * So the init priority has to be 0 (zero).
 *
 * @return 0
 */
static int stm32f2_init(void)
{
	/* Enable ART Flash cache accelerator for both Instruction and Data */
	LL_FLASH_EnableInstCache();
	LL_FLASH_EnableDataCache();

	/* Update CMSIS SystemCoreClock variable (HCLK) */
	/* At reset, system core clock is set to 16 MHz from HSI */
	SystemCoreClock = 16000000;

	return 0;
}

SYS_INIT(stm32f2_init, PRE_KERNEL_1, 0);
