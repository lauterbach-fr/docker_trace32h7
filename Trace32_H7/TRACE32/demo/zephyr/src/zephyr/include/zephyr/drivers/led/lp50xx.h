/*
 * Copyright (c) 2020 Seagate Technology LLC
 * Copyright (c) 2022 Grinn
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#ifndef ZEPHYR_INCLUDE_DRIVERS_LED_LP50XX_H_
#define ZEPHYR_INCLUDE_DRIVERS_LED_LP50XX_H_

#define LP50XX_COLORS_PER_LED	3

#define LP5009_MAX_LEDS		3
#define LP5012_MAX_LEDS		4
#define LP5018_MAX_LEDS		6
#define LP5024_MAX_LEDS		8
#define LP5030_MAX_LEDS		10
#define LP5036_MAX_LEDS		12

/*
 * LED channels mapping.
 */

/* Bank channels */
#define LP50XX_BANK_CHAN_BASE		0
#define LP50XX_BANK_BRIGHT_CHAN		LP50XX_BANK_CHAN_BASE
#define LP50XX_BANK_COL1_CHAN(led)	(LP50XX_BANK_CHAN_BASE + 1)
#define LP50XX_BANK_COL2_CHAN(led)	(LP50XX_BANK_CHAN_BASE + 2)
#define LP50XX_BANK_COL3_CHAN(led)	(LP50XX_BANK_CHAN_BASE + 3)

/* LED brightness channels. */
#define LP50XX_LED_BRIGHT_CHAN_BASE	4
#define LP50XX_LED_BRIGHT_CHAN(led)	(LP50XX_LED_BRIGHT_CHAN_BASE + led)

/*
 * LED color channels.
 *
 * Each channel definition is compatible with the following chips:
 *   - LP5012_XXX => LP5009 / LP5012
 *   - LP5024_XXX => LP5018 / LP5024
 *   - LP5036_XXX => LP5030 / LP5036
 */
#define LP5012_LED_COL_CHAN_BASE	8
#define LP5012_LED_COL1_CHAN(led) \
	(LP5012_LED_COL_CHAN_BASE + led * LP50XX_COLORS_PER_LED)
#define LP5012_LED_COL2_CHAN(led) \
	(LP5012_LED_COL_CHAN_BASE + led * LP50XX_COLORS_PER_LED + 1)
#define LP5012_LED_COL3_CHAN(led) \
	(LP5012_LED_COL_CHAN_BASE + led * LP50XX_COLORS_PER_LED + 2)

#define LP5024_LED_COL_CHAN_BASE	12
#define LP5024_LED_COL1_CHAN(led) \
	(LP5024_LED_COL_CHAN_BASE + led * LP50XX_COLORS_PER_LED)
#define LP5024_LED_COL2_CHAN(led) \
	(LP5024_LED_COL_CHAN_BASE + led * LP50XX_COLORS_PER_LED + 1)
#define LP5024_LED_COL3_CHAN(led) \
	(LP5024_LED_COL_CHAN_BASE + led * LP50XX_COLORS_PER_LED + 2)

#define LP5036_LED_COL_CHAN_BASE	16
#define LP5036_LED_COL1_CHAN(led) \
	(LP5036_LED_COL_CHAN_BASE + led * LP50XX_COLORS_PER_LED)
#define LP5036_LED_COL2_CHAN(led) \
	(LP5036_LED_COL_CHAN_BASE + led * LP50XX_COLORS_PER_LED + 1)
#define LP5036_LED_COL3_CHAN(led) \
	(LP5036_LED_COL_CHAN_BASE + led * LP50XX_COLORS_PER_LED + 2)

#endif /* ZEPHYR_INCLUDE_DRIVERS_LED_LP50XX_H_ */
