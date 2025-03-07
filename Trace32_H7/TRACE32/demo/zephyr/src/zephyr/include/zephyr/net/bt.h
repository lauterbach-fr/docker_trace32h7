/*
 * Copyright (c) 2017 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Bluetooth L2 stack public header
 */

#ifndef ZEPHYR_INCLUDE_NET_BT_H_
#define ZEPHYR_INCLUDE_NET_BT_H_

#include <zephyr/net/net_mgmt.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Management part definitions */

#define _NET_BT_LAYER	NET_MGMT_LAYER_L2
#define _NET_BT_CODE	0x155
#define _NET_BT_BASE	(NET_MGMT_IFACE_BIT |			\
			 NET_MGMT_LAYER(_NET_BT_LAYER) |	\
			 NET_MGMT_LAYER_CODE(_NET_BT_CODE))
#define _NET_BT_EVENT	(_NET_BT_BASE | NET_MGMT_EVENT_BIT)

enum net_request_bt_cmd {
	NET_REQUEST_BT_CMD_ADVERTISE = 1,
	NET_REQUEST_BT_CMD_CONNECT,
	NET_REQUEST_BT_CMD_SCAN,
	NET_REQUEST_BT_CMD_DISCONNECT,
};

#define NET_REQUEST_BT_ADVERTISE				\
	(_NET_BT_BASE | NET_REQUEST_BT_CMD_ADVERTISE)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_BT_ADVERTISE);

#define NET_REQUEST_BT_CONNECT					\
	(_NET_BT_BASE | NET_REQUEST_BT_CMD_CONNECT)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_BT_CONNECT);

#define NET_REQUEST_BT_SCAN					\
	(_NET_BT_BASE | NET_REQUEST_BT_CMD_SCAN)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_BT_SCAN);

enum net_event_bt_cmd {
	NET_EVENT_BT_CMD_SCAN_RESULT = 1,
};

#define NET_EVENT_BT_SCAN_RESULT				\
	(_NET_BT_EVENT | NET_EVENT_BT_CMD_SCAN_RESULT)

#define NET_REQUEST_BT_DISCONNECT				\
	(_NET_BT_BASE | NET_REQUEST_BT_CMD_DISCONNECT)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_BT_DISCONNECT);

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_NET_BT_H_ */
