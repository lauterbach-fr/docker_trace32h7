/*
 * Copyright (c) 2019 Derek Hageman <hageman@inthat.cloud>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_INTERRUPT_CONTROLLER_INTC_SAM0_EIC_PRIV_H_
#define ZEPHYR_DRIVERS_INTERRUPT_CONTROLLER_INTC_SAM0_EIC_PRIV_H_

#include <errno.h>
#include <zephyr/types.h>
#include <soc.h>

/*
 * Used in the ASF headers, but not always defined by them (looks like they
 * sometimes define __L instead).
 */
#ifndef _L
#define _L(i) i ## L
#endif

/*
 * Unfortunately the ASF headers define the EIC mappings somewhat painfully:
 * the macros have both the port letter and are only defined if that pin
 * has an EIC channel.  So we can't just use a macro expansion here, because
 * some of them might be undefined for a port and we can't test for another
 * macro definition inside a macro.
 */
static const uint8_t sam0_eic_channels[PORT_GROUPS][32] = {
#if PORT_GROUPS >= 1
{
#ifdef PIN_PA00A_EIC_EXTINT_NUM
	PIN_PA00A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA01A_EIC_EXTINT_NUM
	PIN_PA01A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA02A_EIC_EXTINT_NUM
	PIN_PA02A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA03A_EIC_EXTINT_NUM
	PIN_PA03A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA04A_EIC_EXTINT_NUM
	PIN_PA04A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA05A_EIC_EXTINT_NUM
	PIN_PA05A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA06A_EIC_EXTINT_NUM
	PIN_PA06A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA07A_EIC_EXTINT_NUM
	PIN_PA07A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA08A_EIC_EXTINT_NUM
	PIN_PA08A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA09A_EIC_EXTINT_NUM
	PIN_PA09A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA10A_EIC_EXTINT_NUM
	PIN_PA10A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA11A_EIC_EXTINT_NUM
	PIN_PA11A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA12A_EIC_EXTINT_NUM
	PIN_PA12A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA13A_EIC_EXTINT_NUM
	PIN_PA13A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA14A_EIC_EXTINT_NUM
	PIN_PA14A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA15A_EIC_EXTINT_NUM
	PIN_PA15A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA16A_EIC_EXTINT_NUM
	PIN_PA16A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA17A_EIC_EXTINT_NUM
	PIN_PA17A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA18A_EIC_EXTINT_NUM
	PIN_PA18A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA19A_EIC_EXTINT_NUM
	PIN_PA19A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA20A_EIC_EXTINT_NUM
	PIN_PA20A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA21A_EIC_EXTINT_NUM
	PIN_PA21A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA22A_EIC_EXTINT_NUM
	PIN_PA22A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA23A_EIC_EXTINT_NUM
	PIN_PA23A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA24A_EIC_EXTINT_NUM
	PIN_PA24A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA25A_EIC_EXTINT_NUM
	PIN_PA25A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA26A_EIC_EXTINT_NUM
	PIN_PA26A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA27A_EIC_EXTINT_NUM
	PIN_PA27A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA28A_EIC_EXTINT_NUM
	PIN_PA28A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA29A_EIC_EXTINT_NUM
	PIN_PA29A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA30A_EIC_EXTINT_NUM
	PIN_PA30A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PA31A_EIC_EXTINT_NUM
	PIN_PA31A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
},
#endif

#if PORT_GROUPS >= 2
{
#ifdef PIN_PB00A_EIC_EXTINT_NUM
	PIN_PB00A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB01A_EIC_EXTINT_NUM
	PIN_PB01A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB02A_EIC_EXTINT_NUM
	PIN_PB02A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB03A_EIC_EXTINT_NUM
	PIN_PB03A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB04A_EIC_EXTINT_NUM
	PIN_PB04A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB05A_EIC_EXTINT_NUM
	PIN_PB05A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB06A_EIC_EXTINT_NUM
	PIN_PB06A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB07A_EIC_EXTINT_NUM
	PIN_PB07A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB08A_EIC_EXTINT_NUM
	PIN_PB08A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB09A_EIC_EXTINT_NUM
	PIN_PB09A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB10A_EIC_EXTINT_NUM
	PIN_PB10A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB11A_EIC_EXTINT_NUM
	PIN_PB11A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB12A_EIC_EXTINT_NUM
	PIN_PB12A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB13A_EIC_EXTINT_NUM
	PIN_PB13A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB14A_EIC_EXTINT_NUM
	PIN_PB14A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB15A_EIC_EXTINT_NUM
	PIN_PB15A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB16A_EIC_EXTINT_NUM
	PIN_PB16A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB17A_EIC_EXTINT_NUM
	PIN_PB17A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB18A_EIC_EXTINT_NUM
	PIN_PB18A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB19A_EIC_EXTINT_NUM
	PIN_PB19A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB20A_EIC_EXTINT_NUM
	PIN_PB20A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB21A_EIC_EXTINT_NUM
	PIN_PB21A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB22A_EIC_EXTINT_NUM
	PIN_PB22A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB23A_EIC_EXTINT_NUM
	PIN_PB23A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB24A_EIC_EXTINT_NUM
	PIN_PB24A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB25A_EIC_EXTINT_NUM
	PIN_PB25A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB26A_EIC_EXTINT_NUM
	PIN_PB26A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB27A_EIC_EXTINT_NUM
	PIN_PB27A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB28A_EIC_EXTINT_NUM
	PIN_PB28A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB29A_EIC_EXTINT_NUM
	PIN_PB29A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB30A_EIC_EXTINT_NUM
	PIN_PB30A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PB31A_EIC_EXTINT_NUM
	PIN_PB31A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
},
#endif

#if PORT_GROUPS >= 3
{
#ifdef PIN_PC00A_EIC_EXTINT_NUM
	PIN_PC00A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC01A_EIC_EXTINT_NUM
	PIN_PC01A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC02A_EIC_EXTINT_NUM
	PIN_PC02A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC03A_EIC_EXTINT_NUM
	PIN_PC03A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC04A_EIC_EXTINT_NUM
	PIN_PC04A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC05A_EIC_EXTINT_NUM
	PIN_PC05A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC06A_EIC_EXTINT_NUM
	PIN_PC06A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC07A_EIC_EXTINT_NUM
	PIN_PC07A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC08A_EIC_EXTINT_NUM
	PIN_PC08A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC09A_EIC_EXTINT_NUM
	PIN_PC09A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC10A_EIC_EXTINT_NUM
	PIN_PC10A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC11A_EIC_EXTINT_NUM
	PIN_PC11A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC12A_EIC_EXTINT_NUM
	PIN_PC12A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC13A_EIC_EXTINT_NUM
	PIN_PC13A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC14A_EIC_EXTINT_NUM
	PIN_PC14A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC15A_EIC_EXTINT_NUM
	PIN_PC15A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC16A_EIC_EXTINT_NUM
	PIN_PC16A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC17A_EIC_EXTINT_NUM
	PIN_PC17A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC18A_EIC_EXTINT_NUM
	PIN_PC18A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC19A_EIC_EXTINT_NUM
	PIN_PC19A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC20A_EIC_EXTINT_NUM
	PIN_PC20A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC21A_EIC_EXTINT_NUM
	PIN_PC21A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC22A_EIC_EXTINT_NUM
	PIN_PC22A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC23A_EIC_EXTINT_NUM
	PIN_PC23A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC24A_EIC_EXTINT_NUM
	PIN_PC24A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC25A_EIC_EXTINT_NUM
	PIN_PC25A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC26A_EIC_EXTINT_NUM
	PIN_PC26A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC27A_EIC_EXTINT_NUM
	PIN_PC27A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC28A_EIC_EXTINT_NUM
	PIN_PC28A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC29A_EIC_EXTINT_NUM
	PIN_PC29A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC30A_EIC_EXTINT_NUM
	PIN_PC30A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PC31A_EIC_EXTINT_NUM
	PIN_PC31A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
},
#endif

#if PORT_GROUPS >= 4
{
#ifdef PIN_PD00A_EIC_EXTINT_NUM
	PIN_PD00A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD01A_EIC_EXTINT_NUM
	PIN_PD01A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD02A_EIC_EXTINT_NUM
	PIN_PD02A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD03A_EIC_EXTINT_NUM
	PIN_PD03A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD04A_EIC_EXTINT_NUM
	PIN_PD04A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD05A_EIC_EXTINT_NUM
	PIN_PD05A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD06A_EIC_EXTINT_NUM
	PIN_PD06A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD07A_EIC_EXTINT_NUM
	PIN_PD07A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD08A_EIC_EXTINT_NUM
	PIN_PD08A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD09A_EIC_EXTINT_NUM
	PIN_PD09A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD10A_EIC_EXTINT_NUM
	PIN_PD10A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD11A_EIC_EXTINT_NUM
	PIN_PD11A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD12A_EIC_EXTINT_NUM
	PIN_PD12A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD13A_EIC_EXTINT_NUM
	PIN_PD13A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD14A_EIC_EXTINT_NUM
	PIN_PD14A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD15A_EIC_EXTINT_NUM
	PIN_PD15A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD16A_EIC_EXTINT_NUM
	PIN_PD16A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD17A_EIC_EXTINT_NUM
	PIN_PD17A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD18A_EIC_EXTINT_NUM
	PIN_PD18A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD19A_EIC_EXTINT_NUM
	PIN_PD19A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD20A_EIC_EXTINT_NUM
	PIN_PD20A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD21A_EIC_EXTINT_NUM
	PIN_PD21A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD22A_EIC_EXTINT_NUM
	PIN_PD22A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD23A_EIC_EXTINT_NUM
	PIN_PD23A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD24A_EIC_EXTINT_NUM
	PIN_PD24A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD25A_EIC_EXTINT_NUM
	PIN_PD25A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD26A_EIC_EXTINT_NUM
	PIN_PD26A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD27A_EIC_EXTINT_NUM
	PIN_PD27A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD28A_EIC_EXTINT_NUM
	PIN_PD28A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD29A_EIC_EXTINT_NUM
	PIN_PD29A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD30A_EIC_EXTINT_NUM
	PIN_PD30A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
#ifdef PIN_PD31A_EIC_EXTINT_NUM
	PIN_PD31A_EIC_EXTINT_NUM,
#else
	0xFF,
#endif
},
#endif
};

static inline int sam0_eic_map_to_line(int port, int pin)
{
	uint8_t ch = sam0_eic_channels[port][pin];

	if (ch == 0xFF) {
		return -ENOTSUP;
	}
	return ch;
}

#endif /* ZEPHYR_DRIVERS_INTERRUPT_CONTROLLER_INTC_SAM0_EIC_PRIV_H_ */
