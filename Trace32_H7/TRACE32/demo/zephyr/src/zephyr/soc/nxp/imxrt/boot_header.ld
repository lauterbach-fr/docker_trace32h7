/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

. = CONFIG_FLEXSPI_CONFIG_BLOCK_OFFSET;
#if defined(CONFIG_SOC_SERIES_IMXRT11XX) || defined(CONFIG_SOC_SERIES_IMXRT10XX)
KEEP(*(.boot_hdr.conf))
#endif
#if defined(CONFIG_SOC_SERIES_IMXRT6XX) || defined(CONFIG_SOC_SERIES_IMXRT5XX)
KEEP(*(.flash_conf))
#endif
. = CONFIG_IMAGE_VECTOR_TABLE_OFFSET;
KEEP(*(.boot_hdr.ivt))
#if defined(CONFIG_SOC_SERIES_IMXRT11XX) || defined(CONFIG_SOC_SERIES_IMXRT10XX)
KEEP(*(.boot_hdr.data))
#ifdef CONFIG_DEVICE_CONFIGURATION_DATA
	KEEP(*(.boot_hdr.dcd_data))
#endif /* CONFIG_DEVICE_CONFIGURATION_DATA */
#endif /* CONFIG_SOC_SERIES_IMXRT10XX || CONFIG_SOC_SERIES_IMXRT11XX */
