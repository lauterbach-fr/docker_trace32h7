/*
 * Copyright (c) 2023 Carlo Caione <ccaione@baylibre.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_MEM_ATTR_XTENSA_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_MEM_ATTR_XTENSA_H_

#include <zephyr/sys/util_macro.h>
#include <zephyr/dt-bindings/memory-attr/memory-attr.h>

/*
 * Architecture specific Xtensa related attributes.
 */
#define DT_MEM_XTENSA_MASK		DT_MEM_ARCH_ATTR_MASK
#define DT_MEM_XTENSA_GET(x)		((x) & DT_MEM_XTENSA_MASK)
#define DT_MEM_XTENSA(x)		((x) << DT_MEM_ARCH_ATTR_SHIFT)

#define  ATTR_XTENSA_INSTR_ROM		BIT(0)
#define  ATTR_XTENSA_INSTR_RAM		BIT(1)
#define  ATTR_XTENSA_DATA_ROM		BIT(2)
#define  ATTR_XTENSA_DATA_RAM		BIT(3)
#define  ATTR_XTENSA_XLMI		BIT(4)

#define DT_MEM_XTENSA_INSTR_ROM		DT_MEM_XTENSA(ATTR_XTENSA_INSTR_ROM)
#define DT_MEM_XTENSA_INSTR_RAM		DT_MEM_XTENSA(ATTR_XTENSA_INSTR_RAM)
#define DT_MEM_XTENSA_DATA_ROM		DT_MEM_XTENSA(ATTR_XTENSA_DATA_ROM)
#define DT_MEM_XTENSA_DATA_RAM		DT_MEM_XTENSA(ATTR_XTENSA_DATA_RAM)
#define DT_MEM_XTENSA_XLMI		DT_MEM_XTENSA(ATTR_XTENSA_XLMI)
#define DT_MEM_XTENSA_UNKNOWN		DT_MEM_ARCH_ATTR_UNKNOWN

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_MEM_ATTR_XTENSA_H_ */
