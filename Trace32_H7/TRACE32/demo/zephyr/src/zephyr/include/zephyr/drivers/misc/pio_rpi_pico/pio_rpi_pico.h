/*
 * Copyright (c) 2023 Tokita, Hiroshi <tokita.hiroshi@fujitsu.com>
 * Copyright (c) 2023 Yonatan Schachter
 * Copyright (c) 2023 Ionut Pavel <iocapa@iocapa.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_MISC_PIO_PICO_RPI_PIO_PICO_RPI_H_
#define ZEPHYR_DRIVERS_MISC_PIO_PICO_RPI_PIO_PICO_RPI_H_

#include <zephyr/devicetree/gpio.h>

#include <hardware/pio.h>

/**
 * @brief Utility macro to define a PIO program. The program is a list
 *        of 16 bit instructions, generated by the pioasm tool.
 *
 * @param name Name of the program.
 * @param wrap_target Wrap target as specified by the PIO program.
 * @param wrap Wrap source as specified by the PIO program.
 * @param ... Comma separated list of PIO instructions.
 */
#define RPI_PICO_PIO_DEFINE_PROGRAM(name, wrap_target, wrap, ...)	\
	static const uint32_t name ## _wrap_target = wrap_target;	\
	static const uint32_t name ## _wrap = wrap;			\
	static const uint16_t name ## _program_instructions[] = {	\
		__VA_ARGS__						\
	};								\
	static const struct pio_program name ## _program = {		\
		.instructions = name ## _program_instructions,		\
		.length = ARRAY_SIZE(name ## _program_instructions),	\
		.origin = -1,						\
	}

/**
 * @brief Utility macro to get the wrap target of a program.
 *
 * @param name Name of the program.
 */
#define RPI_PICO_PIO_GET_WRAP_TARGET(name) name ## _wrap_target

/**
 * @brief Utility macro to get the wrap source of a program.
 *
 * @param name Name of the program.
 */
#define RPI_PICO_PIO_GET_WRAP(name) name ## _wrap

/**
 * @brief Utility macro to get a pointer to a PIO program.
 *
 * @param name Name of the program.
 */
#define RPI_PICO_PIO_GET_PROGRAM(name) &name ## _program

/**
 * @brief Get a pin number from a pinctrl / group name and index
 *
 * Example devicetree fragment(s):
 *
 * @code{.dts}
 *	pinctrl {
 *		pio_child_default: pio_child_default {
 *			tx_gpio {
 *				pinmux = <PIO0_P0>, <PIO0_P2>;
 *			};
 *
 *			rx_gpio {
 *				pinmux = <PIO0_P1>;
 *				input-enable;
 *			};
 *		};
 *	};
 * @endcode
 *
 * @code{.dts}
 *	pio {
 *		status = "okay";
 *		c: child {
 *			pinctrl-0 = <&pio_child_default>;
 *			pinctrl-names = "default";
 *		};
 *	};
 * @endcode
 *
 * Example usage:
 *
 * @code{.c}
 *	DT_RPI_PICO_PIO_PIN_BY_NAME(node, default, 0, tx_gpio, 0) // 0
 *	DT_RPI_PICO_PIO_PIN_BY_NAME(node, default, 0, tx_gpio, 1) // 2
 *	DT_RPI_PICO_PIO_PIN_BY_NAME(node, default, 0, rx_gpio, 0) // 1
 * @endcode
 *
 * @param node_id node identifier
 * @param p_name pinctrl name
 * @param p_idx pinctrl index
 * @param g_name group name
 * @param g_idx group index
 * @return pin number
 */
#define DT_RPI_PICO_PIO_PIN_BY_NAME(node_id, p_name, p_idx, g_name, g_idx)			\
	RP2_GET_PIN_NUM(DT_PROP_BY_IDX(								\
		DT_CHILD(DT_PINCTRL_BY_NAME(node_id, p_name, p_idx), g_name), pinmux, g_idx))

/**
 * @brief Get a pin number from a pinctrl / group name and index
 *
 * @param inst instance number
 * @param p_name pinctrl name
 * @param p_idx pinctrl index
 * @param g_name group name
 * @param g_idx group index
 * @return pin number
 *
 * @see DT_RPI_PICO_PIO_PIN_BY_NAME
 */
#define DT_INST_RPI_PICO_PIO_PIN_BY_NAME(inst, p_name, p_idx, g_name, g_idx)			\
	DT_RPI_PICO_PIO_PIN_BY_NAME(DT_DRV_INST(inst), p_name, p_idx, g_name, g_idx)

/**
 * @brief Get the pin number of a pin by its name.
 *
 * @param inst instance number
 * @param name name of the pin (e.g. tx, rx, sck).
 */
#define DT_INST_PIO_PIN_BY_NAME(inst, name) \
	DT_PIO_PIN_BY_NAME(DT_DRV_INST(inst), name)

/**
 * Get PIO object
 *
 * @param dev Pointer to device structure for rpi_pio device instance
 * @return PIO object
 */
PIO pio_rpi_pico_get_pio(const struct device *dev);

/**
 * Allocate a state machine.
 *
 * @param dev Pointer to device structure for rpi_pio device instance
 * @param sm Pointer to store allocated state machine
 * @retval 0 on success
 * @retval -EBUSY if no state machines were available
 */
int pio_rpi_pico_allocate_sm(const struct device *dev, size_t *sm);

#endif /* ZEPHYR_DRIVERS_MISC_PIO_PICO_RPI_PIO_PICO_RPI_H_ */
