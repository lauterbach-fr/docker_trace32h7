/*
 * Copyright (c) 2021 Espressif Systems (Shanghai) Co., Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <soc/periph_defs.h>
#include <limits.h>
#include <assert.h>
#include "soc/soc.h"
#include <soc.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/interrupt_controller/intc_esp32c3.h>
#include <zephyr/sw_isr_table.h>
#include <riscv/interrupt.h>

#define ESP32C3_INTC_DEFAULT_PRIO			15

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(intc_esp32c3, CONFIG_LOG_DEFAULT_LEVEL);

/*
 * Define this to debug the choices made when allocating the interrupt. This leads to much debugging
 * output within a critical region, which can lead to weird effects like e.g. the interrupt watchdog
 * being triggered, that is why it is separate from the normal LOG* scheme.
 */
#ifdef CONFIG_INTC_ESP32C3_DECISIONS_LOG
# define INTC_LOG(...) LOG_INF(__VA_ARGS__)
#else
# define INTC_LOG(...) do {} while (0)
#endif

#define ESP32C3_INTC_DEFAULT_PRIORITY   15
#define ESP32C3_INTC_DEFAULT_THRESHOLD  1
#define ESP32C3_INTC_DISABLED_SLOT      31
#define ESP32C3_INTC_SRCS_PER_IRQ       2
#define ESP32C3_INTC_AVAILABLE_IRQS     30

static uint32_t esp_intr_enabled_mask[2] = {0, 0};

static uint32_t esp_intr_find_irq_for_source(uint32_t source)
{
	/* in general case, each 2 sources goes routed to
	 * 1 IRQ line.
	 */
	uint32_t irq = (source / ESP32C3_INTC_SRCS_PER_IRQ);

	if (irq > ESP32C3_INTC_AVAILABLE_IRQS) {
		INTC_LOG("Clamping the source: %d no more IRQs available", source);
		irq = ESP32C3_INTC_AVAILABLE_IRQS;
	} else if (irq == 0) {
		irq = 1;
	}

	INTC_LOG("Found IRQ: %d for source: %d", irq, source);

	return irq;
}

void esp_intr_initialize(void)
{
	/* IRQ 31 is reserved for disabled interrupts,
	 * so route all sources to it
	 */
	for (int i = 0 ; i < ESP32C3_INTC_AVAILABLE_IRQS + 2; i++) {
		irq_disable(i);
	}

	for (int i = 0; i < ETS_MAX_INTR_SOURCE; i++) {
		esp_rom_intr_matrix_set(0, i, ESP32C3_INTC_DISABLED_SLOT);
	}

	/* set global esp32c3's INTC masking level */
	esprv_intc_int_set_threshold(ESP32C3_INTC_DEFAULT_THRESHOLD);
}

int esp_intr_alloc(int source,
		int flags,
		isr_handler_t handler,
		void *arg,
		void **ret_handle)
{
	ARG_UNUSED(flags);
	ARG_UNUSED(ret_handle);

	if (handler == NULL) {
		return -EINVAL;
	}

	if (source < 0 || source >= ETS_MAX_INTR_SOURCE) {
		return -EINVAL;
	}

	uint32_t key = irq_lock();

	irq_connect_dynamic(source,
		ESP32C3_INTC_DEFAULT_PRIORITY,
		handler,
		arg,
		0);

	if (source < 32) {
		esp_intr_enabled_mask[0] |= (1 << source);
	} else {
		esp_intr_enabled_mask[1] |= (1 << (source - 32));
	}

	INTC_LOG("Enabled ISRs -- 0: 0x%X -- 1: 0x%X",
		esp_intr_enabled_mask[0], esp_intr_enabled_mask[1]);

	irq_unlock(key);
	irq_enable(source);

	return 0;
}

int esp_intr_disable(int source)
{
	if (source < 0 || source >= ETS_MAX_INTR_SOURCE) {
		return -EINVAL;
	}

	uint32_t key = irq_lock();

	esp_rom_intr_matrix_set(0,
		source,
		ESP32C3_INTC_DISABLED_SLOT);

	if (source < 32) {
		esp_intr_enabled_mask[0] &= ~(1 << source);
	} else {
		esp_intr_enabled_mask[1] &= ~(1 << (source - 32));
	}

	INTC_LOG("Enabled ISRs -- 0: 0x%X -- 1: 0x%X",
		esp_intr_enabled_mask[0], esp_intr_enabled_mask[1]);

	irq_unlock(key);

	return 0;
}

int esp_intr_enable(int source)
{
	if (source < 0 || source >= ETS_MAX_INTR_SOURCE) {
		return -EINVAL;
	}

	uint32_t key = irq_lock();
	uint32_t irq = esp_intr_find_irq_for_source(source);

	esp_rom_intr_matrix_set(0, source, irq);

	if (source < 32) {
		esp_intr_enabled_mask[0] |= (1 << source);
	} else {
		esp_intr_enabled_mask[1] |= (1 << (source - 32));
	}

	INTC_LOG("Enabled ISRs -- 0: 0x%X -- 1: 0x%X",
		esp_intr_enabled_mask[0], esp_intr_enabled_mask[1]);

	esprv_intc_int_set_priority(irq, ESP32C3_INTC_DEFAULT_PRIO);
	esprv_intc_int_set_type(irq, INTR_TYPE_LEVEL);
	esprv_intc_int_enable(1 << irq);

	irq_unlock(key);

	return 0;
}

uint32_t esp_intr_get_enabled_intmask(int status_mask_number)
{
	INTC_LOG("Enabled ISRs -- 0: 0x%X -- 1: 0x%X",
		esp_intr_enabled_mask[0], esp_intr_enabled_mask[1]);

	if (status_mask_number == 0) {
		return esp_intr_enabled_mask[0];
	} else {
		return esp_intr_enabled_mask[1];
	}
}
