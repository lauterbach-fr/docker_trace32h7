/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_SOC_ARM_NXP_LPC_11U6X_PINCTRL_SOC_H_
#define ZEPHYR_SOC_ARM_NXP_LPC_11U6X_PINCTRL_SOC_H_

#include <zephyr/devicetree.h>
#include <zephyr/types.h>
#include <soc.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @cond INTERNAL_HIDDEN */

typedef uint32_t pinctrl_soc_pin_t;

#define Z_PINCTRL_IOCON_PINCFG(node_id)						\
	(IF_ENABLED(DT_PROP(node_id, bias_pull_down), (IOCON_PIO_MODE(0x1) |))	\
	IF_ENABLED(DT_PROP(node_id, bias_pull_up), (IOCON_PIO_MODE(0x2) |))	\
	IF_ENABLED(DT_PROP(node_id, drive_push_pull), (IOCON_PIO_MODE(0x3) |))	\
	IOCON_PIO_HYS(DT_PROP(node_id, input_schmitt_enable)) |			\
	IOCON_PIO_INVERT(DT_PROP(node_id, nxp_invert)) |			\
	IOCON_PIO_OD(DT_PROP(node_id, drive_open_drain)) |			\
	IOCON_PIO_SMODE(DT_ENUM_IDX(node_id, nxp_digital_filter)) |		\
	IOCON_PIO_CLKDIV(DT_ENUM_IDX(node_id, nxp_filter_clock_div)) |		\
	IOCON_PIO_ADMODE(!DT_PROP(node_id, nxp_analog_mode)) |			\
	IOCON_PIO_FILTER(DT_PROP(node_id, nxp_disable_analog_filter)) |		\
	IOCON_PIO_I2CMODE(!DT_PROP(node_id, nxp_i2c_mode)) |			\
	IOCON_PIO_I2CMODE((DT_ENUM_IDX_OR(node_id, nxp_i2c_filter, 0) << 1)))

/* Mask for digital type pin configuration register */
#define Z_PINCTRL_IOCON_D_PIN_MASK (IOCON_PIO_FUNC_MASK |			\
	IOCON_PIO_MODE_MASK | IOCON_PIO_HYS_MASK | IOCON_PIO_INVERT_MASK |	\
	IOCON_PIO_OD_MASK | IOCON_PIO_SMODE_MASK | IOCON_PIO_CLKDIV_MASK)

/* Mask for analog type pin configuration register */
#define Z_PINCTRL_IOCON_A_PIN_MASK						\
	(Z_PINCTRL_IOCON_D_PIN_MASK | IOCON_PIO_ADMODE_MASK |			\
	IOCON_PIO_FILTER_MASK)

/* Mask for i2c type pin configuration register */
#define Z_PINCTRL_IOCON_I_PIN_MASK (IOCON_PIO_FUNC_MASK |			\
	IOCON_PIO_I2CMODE_MASK | IOCON_PIO_SMODE_MASK | IOCON_PIO_CLKDIV_MASK)

#define Z_PINCTRL_STATE_PIN_INIT(group, pin_prop, idx)				\
	DT_PROP_BY_IDX(group, pin_prop, idx) | Z_PINCTRL_IOCON_PINCFG(group),

/**
 * @brief Utility macro to initialize state pins contained in a given property.
 *
 * @param node_id Node identifier.
 * @param prop Property name describing state pins.
 */
#define Z_PINCTRL_STATE_PINS_INIT(node_id, prop)			       \
	{DT_FOREACH_CHILD_VARGS(DT_PHANDLE(node_id, prop),		       \
				DT_FOREACH_PROP_ELEM, pinmux,		       \
				Z_PINCTRL_STATE_PIN_INIT)}

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_SOC_ARM_NXP_LPC_11U6X_PINCTRL_SOC_H_ */
