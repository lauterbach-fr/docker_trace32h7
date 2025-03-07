/*
 * Copyright (c) 2022, Carlo Caione <ccaione@baylibre.com>
 */

/**
 * @file
 *
 * @brief public S2RAM APIs.
 * @defgroup pm_s2ram S2RAM APIs
 * @ingroup subsys_pm
 * @{
 */

#ifndef ZEPHYR_INCLUDE_ARCH_COMMON_PM_S2RAM_H_
#define ZEPHYR_INCLUDE_ARCH_COMMON_PM_S2RAM_H_

#ifdef _ASMLANGUAGE
GTEXT(arch_pm_s2ram_suspend);
#else

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief System off function
 *
 * This function is passed as argument and called by @ref arch_pm_s2ram_suspend
 * to power the system off after the CPU context has been saved.
 *
 * This function never returns if the system is powered off. If the operation
 * cannot be performed a proper value is returned and the code must take care
 * of restoring the system in a fully operational state before returning.
 *
 * @retval none		The system is powered off.
 * @retval -EBUSY	The system is busy and cannot be powered off at this time.
 * @retval -errno	Other error codes.
 */
typedef int (*pm_s2ram_system_off_fn_t)(void);

/**
 * @brief Save CPU context on suspend
 *
 * This function is used on suspend-to-RAM (S2RAM) to save the CPU context in
 * (retained) RAM before powering the system off using the provided function.
 * This function is usually called from the PM subsystem / hooks.
 *
 * The CPU context is usually the minimum set of CPU registers which content
 * must be restored on resume to let the platform resume its execution from the
 * point it left at the time of suspension.
 *
 * @param system_off	Function to power off the system.
 *
 * @retval 0		The CPU context was successfully saved and restored.
 * @retval -EBUSY	The system is busy and cannot be suspended at this time.
 * @retval -errno	Negative errno code in case of failure.
 */
int arch_pm_s2ram_suspend(pm_s2ram_system_off_fn_t system_off);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* _ASMLANGUAGE */

#endif /* ZEPHYR_INCLUDE_ARCH_COMMON_PM_S2RAM_H_ */
