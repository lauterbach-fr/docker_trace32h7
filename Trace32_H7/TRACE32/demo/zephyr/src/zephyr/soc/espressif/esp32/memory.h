/*
 * Copyright (c) 2024 Espressif Systems (Shanghai) Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

/* SRAM0 (64k+128k)  instruction cache+memory */
#define SRAM0_IRAM_START    0x40070000
#define SRAM0_CACHE_SIZE    0x10000
#define SRAM0_SIZE          0x30000

/* SRAM1 (128k) instruction/data memory */
#define SRAM1_IRAM_START    0x400a0000
#define SRAM1_DRAM_START    0x3ffe0000
#define SRAM1_SIZE          0x20000
#define SRAM1_DRAM_PROAPP_PRIV_SIZE 0x8000
#define SRAM1_DRAM_USABLE_START 0x3ffe8000  /* Can be optimised - 0x3ffe5230 (?) */
#define SRAM1_USABLE_SIZE   (0x40000000 - SRAM1_DRAM_USABLE_START)

/* SRAM2 (200k) data memory */
#define SRAM2_DRAM_START    0x3ffae000
#define SRAM2_SIZE          0x32000
#define SRAM2_DRAM_SHM_PRIV_SIZE 0x2000
#define SRAM2_DRAM_USABLE_START  0x3ffb0000
#define SRAM2_USABLE_SIZE   (SRAM1_DRAM_START - SRAM2_DRAM_USABLE_START)

/** Simplified memory map for the bootloader.
 *  Make sure the bootloader can load into main memory without overwriting itself.
 *
 *  ESP32 ROM static data usage is as follows:
 *  - 0x3ffae000 - 0x3ffb0000 (Reserved: data memory for ROM functions)
 *  - 0x3ffb0000 - 0x3ffe0000 (RAM bank 1 for application usage)
 *  - 0x3ffe0000 - 0x3ffe0440 (Reserved: data memory for ROM PRO CPU)
 *  - 0x3ffe3f20 - 0x3ffe4350 (Reserved: data memory for ROM APP CPU)
 *  - 0x3ffe4350 - 0x3ffe5230 (BT shm buffers)
 *  - 0x3ffe8000 - 0x3fffffff (RAM bank 2 for application usage)
 */

#define DRAM1_PROCPU_RESERVED_START 0x3ffe0000
#define DRAM1_APPCPU_RESERVED_START 0x3ffe3f20
#define DRAM1_BT_SHM_BUFFERS_START  0x3ffe4350
#define DRAM1_BT_SHM_BUFFERS_END    0x3ffe5230

/* Conversion beween IRAM and DRAM in SRAM1 memory */
#define SRAM1_IRAM_DRAM_CALC(addr_iram) \
	(SRAM1_SIZE - ((addr_iram) - SRAM1_IRAM_START) + SRAM1_DRAM_START)
#define SRAM1_DRAM_IRAM_CALC(addr_dram) \
	(SRAM1_SIZE - ((addr_dram) - SRAM1_DRAM_START) + SRAM1_IRAM_START)

/* For safety margin between bootloader data section and startup stacks */
#define BOOTLOADER_DRAM_SEG_LEN        0x6400
#define BOOTLOADER_IRAM_LOADER_SEG_LEN 0x4000
#define BOOTLOADER_IRAM_SEG_LEN        0x9500

/* Start of the lower region is determined by region size and the end of the higher region */
#define BOOTLOADER_DRAM_SEG_START  0x3fff0000
#define BOOTLOADER_DRAM_SEG_END    (BOOTLOADER_DRAM_SEG_START + BOOTLOADER_DRAM_SEG_LEN)
#define BOOTLOADER_IRAM_LOADER_SEG_START 0x40078000
/* TODO: It should be possible to have this @ 0x40080400
 * but due a bug we need to use different memory location.
 */
#define BOOTLOADER_IRAM_SEG_START     0x400a0000

/* Flash */
#ifdef CONFIG_FLASH_SIZE
#define FLASH_SIZE          CONFIG_FLASH_SIZE
#else
#define FLASH_SIZE          0x400000
#endif

/* Cached memories */
#define CACHE_ALIGN        CONFIG_MMU_PAGE_SIZE
#define IROM_SEG_ORG       0x400d0000
#define IROM_SEG_LEN       (FLASH_SIZE - 0x1000)
#define DROM_SEG_ORG       0x3f400000
#define DROM_SEG_LEN       (FLASH_SIZE - 0x1000)

/* AMP: TODO utilise memory for APPCPU */
#ifndef CONFIG_SOC_ESP32_PROCPU
#define APPCPU_IRAM_SIZE   0x20000
#else
#define APPCPU_IRAM_SIZE   0x8000
#endif
