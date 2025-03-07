/*
 * Copyright (c) 2022 Emerson Electric Co.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief USB Hub Class device API header
 */

#ifndef ZEPHYR_INCLUDE_USB_CLASS_USB_HUB_H_
#define ZEPHYR_INCLUDE_USB_CLASS_USB_HUB_H_

/** USB Hub Class Feature Selectors defined in spec. Table 11-17 */
#define USB_HCFS_C_HUB_LOCAL_POWER	0x00
#define USB_HCFS_C_HUB_OVER_CURRENT	0x01
#define USB_HCFS_PORT_CONNECTION	0x00
#define USB_HCFS_PORT_ENABLE		0x01
#define USB_HCFS_PORT_SUSPEND		0x02
#define USB_HCFS_PORT_OVER_CURRENT	0x03
#define USB_HCFS_PORT_RESET		0x04
#define USB_HCFS_PORT_POWER		0x08
#define USB_HCFS_PORT_LOW_SPEED		0x09
#define USB_HCFS_C_PORT_CONNECTION	0x10
#define USB_HCFS_C_PORT_ENABLE		0x11
#define USB_HCFS_C_PORT_SUSPEND		0x12
#define USB_HCFS_C_PORT_OVER_CURRENT	0x13
#define USB_HCFS_C_PORT_RESET		0x14
#define USB_HCFS_PORT_TEST		0x15
#define USB_HCFS_PORT_INDICATOR		0x16

/** USB Hub Class Request Codes defined in spec. Table 11-16 */
#define USB_HCREQ_GET_STATUS		0x00
#define USB_HCREQ_CLEAR_FEATURE		0x01
#define USB_HCREQ_SET_FEATURE		0x03
#define USB_HCREQ_GET_DESCRIPTOR	0x06
#define USB_HCREQ_SET_DESCRIPTOR	0x07
#define USB_HCREQ_CLEAR_TT_BUFFER	0x08
#define USB_HCREQ_RESET_TT		0x09
#define USB_HCREQ_GET_TT_STATE		0x0A
#define USB_HCREQ_STOP_TT		0x0B

#endif /* ZEPHYR_INCLUDE_USB_CLASS_USB_HUB_H_ */
