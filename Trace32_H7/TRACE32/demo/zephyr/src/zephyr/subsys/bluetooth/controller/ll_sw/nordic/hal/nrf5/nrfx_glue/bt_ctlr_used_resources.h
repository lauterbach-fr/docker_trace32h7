/*
 * Copyright (c) 2021-2024 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "../radio/radio_nrf5_resources.h"
#include "../radio/radio_nrf5_fem.h"

/* NOTE: BT_CTLR_USED_PPI_CHANNELS is defined based on PPI defines being
 *       defined in the below PPI/DPPI resources header file. Take care to
 *       conditionally compile them based on feature Kconfig defines in those
 *       resources header file.
 */
#ifdef DPPI_PRESENT
#include "../radio/radio_nrf5_dppi_resources.h"
#else
#include "../radio/radio_nrf5_ppi_resources.h"
#endif

#if defined(HAL_RADIO_GPIO_HAVE_PA_PIN) || \
	defined(HAL_RADIO_GPIO_HAVE_LNA_PIN)
#define HAL_PALNA_GPIOTE_CHAN 0
#define HAL_PALNA_GPIOTE_MASK BIT(HAL_PALNA_GPIOTE_CHAN)
#else
#define HAL_PALNA_GPIOTE_MASK 0
#endif

#if defined(HAL_RADIO_FEM_IS_NRF21540)
#define HAL_PDN_GPIOTE_CHAN 1
#define HAL_CSN_GPIOTE_CHAN 2
#define HAL_PDN_CSN_GPIOTE_MASK (BIT(HAL_PDN_GPIOTE_CHAN) | BIT(HAL_CSN_GPIOTE_CHAN))
#else
#define HAL_PDN_CSN_GPIOTE_MASK 0
#endif

/* Mask with all GPIOTE channels used by the bluetooth controller. */
#define BT_CTLR_USED_GPIOTE_CHANNELS (HAL_PALNA_GPIOTE_MASK | HAL_PDN_CSN_GPIOTE_MASK)

/* Mask with all (D)PPI channels used by the bluetooth controller. */
#define BT_CTLR_USED_PPI_CHANNELS \
	(BIT(HAL_RADIO_ENABLE_TX_ON_TICK_PPI) | \
	 BIT(HAL_RADIO_ENABLE_RX_ON_TICK_PPI) | \
	 BIT(HAL_RADIO_RECV_TIMEOUT_CANCEL_PPI) | \
	 BIT(HAL_RADIO_DISABLE_ON_HCTO_PPI) | \
	 BIT(HAL_RADIO_END_TIME_CAPTURE_PPI) | \
	 BIT(HAL_EVENT_TIMER_START_PPI) | \
	 BIT(HAL_RADIO_READY_TIME_CAPTURE_PPI) | \
	 BIT(HAL_TRIGGER_CRYPT_PPI) | \
	 BIT(HAL_TRIGGER_AAR_PPI) | \
	 BT_CTLR_USED_PPI_CHANNELS_2 | BT_CTLR_USED_PPI_CHANNELS_3 | \
	 BT_CTLR_USED_PPI_CHANNELS_4 | BT_CTLR_USED_PPI_CHANNELS_5 | \
	 BT_CTLR_USED_PPI_CHANNELS_6 | HAL_USED_PPI_CHANNELS_7)

#if defined(HAL_TRIGGER_RATEOVERRIDE_PPI)
#define BT_CTLR_USED_PPI_CHANNELS_2 \
	BIT(HAL_TRIGGER_RATEOVERRIDE_PPI)
#else
#define BT_CTLR_USED_PPI_CHANNELS_2 0
#endif

#if defined(HAL_ENABLE_PALNA_PPI)
#define BT_CTLR_USED_PPI_CHANNELS_3 \
	(BIT(HAL_ENABLE_PALNA_PPI) | \
	 BIT(HAL_DISABLE_PALNA_PPI))
#else
#define BT_CTLR_USED_PPI_CHANNELS_3 0
#endif

#if defined(HAL_SW_SWITCH_TIMER_CLEAR_PPI)
#define BT_CTLR_USED_PPI_CHANNELS_4 \
	(BIT(HAL_SW_SWITCH_TIMER_CLEAR_PPI) | \
	 BIT(HAL_SW_SWITCH_GROUP_TASK_DISABLE_PPI_BASE) | \
	 BIT(HAL_SW_SWITCH_GROUP_TASK_DISABLE_PPI_BASE + 1) | \
	 BIT(HAL_SW_SWITCH_GROUP_TASK_ENABLE_PPI) | \
	 BIT(HAL_SW_SWITCH_RADIO_ENABLE_PPI_BASE) | \
	 BIT(HAL_SW_SWITCH_RADIO_ENABLE_PPI_BASE + 1))
#else
#define BT_CTLR_USED_PPI_CHANNELS_4 0
#endif

#if defined(HAL_SW_SWITCH_RADIO_ENABLE_S2_PPI_BASE)
#define BT_CTLR_USED_PPI_CHANNELS_5 \
	(BIT(HAL_SW_SWITCH_RADIO_ENABLE_S2_PPI_BASE) | \
	 BIT(HAL_SW_SWITCH_RADIO_ENABLE_S2_PPI_BASE + 1) | \
	 BIT(HAL_SW_SWITCH_TIMER_S8_DISABLE_PPI))
#else
#define BT_CTLR_USED_PPI_CHANNELS_5 0
#endif

#if defined(HAL_ENABLE_FEM_PPI)
#define BT_CTLR_USED_PPI_CHANNELS_6 \
	(BIT(HAL_ENABLE_FEM_PPI) | \
	 BIT(HAL_DISABLE_FEM_PPI))
#else
#define BT_CTLR_USED_PPI_CHANNELS_6 0
#endif

#if defined(CONFIG_BT_CTLR_DF_PHYEND_OFFSET_COMPENSATION_ENABLE)
#ifdef DPPI_PRESENT
#define HAL_USED_PPI_CHANNELS_7 \
	(BIT(HAL_SW_SWITCH_TIMER_PHYEND_DELAY_COMPENSATION_DISABLE_PPI))
#else
#define HAL_USED_PPI_CHANNELS_7 \
	(BIT(HAL_SW_SWITCH_RADIO_ENABLE_PHYEND_DELAY_COMPENSATION_PPI_BASE) | \
	 BIT(HAL_SW_SWITCH_RADIO_ENABLE_PHYEND_DELAY_COMPENSATION_PPI_BASE + 1) | \
	 BIT(HAL_SW_SWITCH_TIMER_PHYEND_DELAY_COMPENSATION_DISABLE_PPI))
#endif /* DPPI_PRESENT */
#else
#define HAL_USED_PPI_CHANNELS_7 0
#endif /* CONFIG_BT_CTLR_DF_PHYEND_OFFSET_COMPENSATION_ENABLE */

#if defined(CONFIG_BT_CTLR_DF_CONN_CTE_RX)
#define HAL_USED_PPI_CHANNELS_8 \
	BIT(HAL_TRIGGER_CRYPT_DELAY_PPI)
#else
#define HAL_USED_PPI_CHANNELS_8 0
#endif /* CONFIG_BT_CTLR_DF_CONN_CTE_RX */

/* Mask with all (D)PPI groups used by the bluetooth controller. */
#if defined(SW_SWITCH_TIMER_TASK_GROUP_BASE)
#define BT_CTLR_USED_PPI_GROUPS \
	(BIT(SW_SWITCH_TIMER_TASK_GROUP_BASE) | \
	 BIT(SW_SWITCH_TIMER_TASK_GROUP_BASE + 1))
#else
#define BT_CTLR_USED_PPI_GROUPS 0
#endif
