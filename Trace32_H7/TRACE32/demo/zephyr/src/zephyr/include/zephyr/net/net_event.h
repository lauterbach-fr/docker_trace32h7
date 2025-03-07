/*
 * Copyright (c) 2016 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Network Events code public header
 */

#ifndef ZEPHYR_INCLUDE_NET_NET_EVENT_H_
#define ZEPHYR_INCLUDE_NET_NET_EVENT_H_

#include <zephyr/net/net_ip.h>
#include <zephyr/net/hostname.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup net_mgmt
 * @{
 */

/** @cond INTERNAL_HIDDEN */

/* Network Interface events */
#define _NET_IF_LAYER		NET_MGMT_LAYER_L2
#define _NET_IF_CORE_CODE	0x001
#define _NET_EVENT_IF_BASE	(NET_MGMT_EVENT_BIT |			\
				 NET_MGMT_IFACE_BIT |			\
				 NET_MGMT_LAYER(_NET_IF_LAYER) |	\
				 NET_MGMT_LAYER_CODE(_NET_IF_CORE_CODE))

enum net_event_if_cmd {
	NET_EVENT_IF_CMD_DOWN = 1,
	NET_EVENT_IF_CMD_UP,
	NET_EVENT_IF_CMD_ADMIN_DOWN,
	NET_EVENT_IF_CMD_ADMIN_UP,
};

#define NET_EVENT_IF_DOWN				\
	(_NET_EVENT_IF_BASE | NET_EVENT_IF_CMD_DOWN)

#define NET_EVENT_IF_UP					\
	(_NET_EVENT_IF_BASE | NET_EVENT_IF_CMD_UP)

#define NET_EVENT_IF_ADMIN_DOWN				\
	(_NET_EVENT_IF_BASE | NET_EVENT_IF_CMD_ADMIN_DOWN)

#define NET_EVENT_IF_ADMIN_UP				\
	(_NET_EVENT_IF_BASE | NET_EVENT_IF_CMD_ADMIN_UP)

/* IPv6 Events */
#define _NET_IPV6_LAYER		NET_MGMT_LAYER_L3
#define _NET_IPV6_CORE_CODE	0x060
#define _NET_EVENT_IPV6_BASE	(NET_MGMT_EVENT_BIT |			\
				 NET_MGMT_IFACE_BIT |			\
				 NET_MGMT_LAYER(_NET_IPV6_LAYER) |	\
				 NET_MGMT_LAYER_CODE(_NET_IPV6_CORE_CODE))

enum net_event_ipv6_cmd {
	NET_EVENT_IPV6_CMD_ADDR_ADD	= 1,
	NET_EVENT_IPV6_CMD_ADDR_DEL,
	NET_EVENT_IPV6_CMD_MADDR_ADD,
	NET_EVENT_IPV6_CMD_MADDR_DEL,
	NET_EVENT_IPV6_CMD_PREFIX_ADD,
	NET_EVENT_IPV6_CMD_PREFIX_DEL,
	NET_EVENT_IPV6_CMD_MCAST_JOIN,
	NET_EVENT_IPV6_CMD_MCAST_LEAVE,
	NET_EVENT_IPV6_CMD_ROUTER_ADD,
	NET_EVENT_IPV6_CMD_ROUTER_DEL,
	NET_EVENT_IPV6_CMD_ROUTE_ADD,
	NET_EVENT_IPV6_CMD_ROUTE_DEL,
	NET_EVENT_IPV6_CMD_DAD_SUCCEED,
	NET_EVENT_IPV6_CMD_DAD_FAILED,
	NET_EVENT_IPV6_CMD_NBR_ADD,
	NET_EVENT_IPV6_CMD_NBR_DEL,
	NET_EVENT_IPV6_CMD_DHCP_START,
	NET_EVENT_IPV6_CMD_DHCP_BOUND,
	NET_EVENT_IPV6_CMD_DHCP_STOP,
};

#define NET_EVENT_IPV6_ADDR_ADD					\
	(_NET_EVENT_IPV6_BASE | NET_EVENT_IPV6_CMD_ADDR_ADD)

#define NET_EVENT_IPV6_ADDR_DEL					\
	(_NET_EVENT_IPV6_BASE |	NET_EVENT_IPV6_CMD_ADDR_DEL)

#define NET_EVENT_IPV6_MADDR_ADD				\
	(_NET_EVENT_IPV6_BASE |	NET_EVENT_IPV6_CMD_MADDR_ADD)

#define NET_EVENT_IPV6_MADDR_DEL				\
	(_NET_EVENT_IPV6_BASE | NET_EVENT_IPV6_CMD_MADDR_DEL)

#define NET_EVENT_IPV6_PREFIX_ADD				\
	(_NET_EVENT_IPV6_BASE |	NET_EVENT_IPV6_CMD_PREFIX_ADD)

#define NET_EVENT_IPV6_PREFIX_DEL				\
	(_NET_EVENT_IPV6_BASE |	NET_EVENT_IPV6_CMD_PREFIX_DEL)

#define NET_EVENT_IPV6_MCAST_JOIN				\
	(_NET_EVENT_IPV6_BASE |	NET_EVENT_IPV6_CMD_MCAST_JOIN)

#define NET_EVENT_IPV6_MCAST_LEAVE				\
	(_NET_EVENT_IPV6_BASE |	NET_EVENT_IPV6_CMD_MCAST_LEAVE)

#define NET_EVENT_IPV6_ROUTER_ADD				\
	(_NET_EVENT_IPV6_BASE | NET_EVENT_IPV6_CMD_ROUTER_ADD)

#define NET_EVENT_IPV6_ROUTER_DEL				\
	(_NET_EVENT_IPV6_BASE | NET_EVENT_IPV6_CMD_ROUTER_DEL)

#define NET_EVENT_IPV6_ROUTE_ADD				\
	(_NET_EVENT_IPV6_BASE | NET_EVENT_IPV6_CMD_ROUTE_ADD)

#define NET_EVENT_IPV6_ROUTE_DEL				\
	(_NET_EVENT_IPV6_BASE | NET_EVENT_IPV6_CMD_ROUTE_DEL)

#define NET_EVENT_IPV6_DAD_SUCCEED				\
	(_NET_EVENT_IPV6_BASE | NET_EVENT_IPV6_CMD_DAD_SUCCEED)

#define NET_EVENT_IPV6_DAD_FAILED				\
	(_NET_EVENT_IPV6_BASE | NET_EVENT_IPV6_CMD_DAD_FAILED)

#define NET_EVENT_IPV6_NBR_ADD					\
	(_NET_EVENT_IPV6_BASE | NET_EVENT_IPV6_CMD_NBR_ADD)

#define NET_EVENT_IPV6_NBR_DEL					\
	(_NET_EVENT_IPV6_BASE | NET_EVENT_IPV6_CMD_NBR_DEL)

#define NET_EVENT_IPV6_DHCP_START				\
	(_NET_EVENT_IPV6_BASE |	NET_EVENT_IPV6_CMD_DHCP_START)

#define NET_EVENT_IPV6_DHCP_BOUND				\
	(_NET_EVENT_IPV6_BASE |	NET_EVENT_IPV6_CMD_DHCP_BOUND)

#define NET_EVENT_IPV6_DHCP_STOP				\
	(_NET_EVENT_IPV6_BASE |	NET_EVENT_IPV6_CMD_DHCP_STOP)

/* IPv4 Events*/
#define _NET_IPV4_LAYER		NET_MGMT_LAYER_L3
#define _NET_IPV4_CORE_CODE	0x004
#define _NET_EVENT_IPV4_BASE	(NET_MGMT_EVENT_BIT |			\
				 NET_MGMT_IFACE_BIT |			\
				 NET_MGMT_LAYER(_NET_IPV4_LAYER) |	\
				 NET_MGMT_LAYER_CODE(_NET_IPV4_CORE_CODE))

enum net_event_ipv4_cmd {
	NET_EVENT_IPV4_CMD_ADDR_ADD	= 1,
	NET_EVENT_IPV4_CMD_ADDR_DEL,
	NET_EVENT_IPV4_CMD_MADDR_ADD,
	NET_EVENT_IPV4_CMD_MADDR_DEL,
	NET_EVENT_IPV4_CMD_ROUTER_ADD,
	NET_EVENT_IPV4_CMD_ROUTER_DEL,
	NET_EVENT_IPV4_CMD_DHCP_START,
	NET_EVENT_IPV4_CMD_DHCP_BOUND,
	NET_EVENT_IPV4_CMD_DHCP_STOP,
	NET_EVENT_IPV4_CMD_MCAST_JOIN,
	NET_EVENT_IPV4_CMD_MCAST_LEAVE,
};

#define NET_EVENT_IPV4_ADDR_ADD					\
	(_NET_EVENT_IPV4_BASE | NET_EVENT_IPV4_CMD_ADDR_ADD)

#define NET_EVENT_IPV4_ADDR_DEL					\
	(_NET_EVENT_IPV4_BASE |	NET_EVENT_IPV4_CMD_ADDR_DEL)

#define NET_EVENT_IPV4_MADDR_ADD				\
	(_NET_EVENT_IPV4_BASE |	NET_EVENT_IPV4_CMD_MADDR_ADD)

#define NET_EVENT_IPV4_MADDR_DEL				\
	(_NET_EVENT_IPV4_BASE | NET_EVENT_IPV4_CMD_MADDR_DEL)

#define NET_EVENT_IPV4_ROUTER_ADD				\
	(_NET_EVENT_IPV4_BASE |	NET_EVENT_IPV4_CMD_ROUTER_ADD)

#define NET_EVENT_IPV4_ROUTER_DEL				\
	(_NET_EVENT_IPV4_BASE |	NET_EVENT_IPV4_CMD_ROUTER_DEL)

#define NET_EVENT_IPV4_DHCP_START				\
	(_NET_EVENT_IPV4_BASE |	NET_EVENT_IPV4_CMD_DHCP_START)

#define NET_EVENT_IPV4_DHCP_BOUND				\
	(_NET_EVENT_IPV4_BASE |	NET_EVENT_IPV4_CMD_DHCP_BOUND)

#define NET_EVENT_IPV4_DHCP_STOP				\
	(_NET_EVENT_IPV4_BASE |	NET_EVENT_IPV4_CMD_DHCP_STOP)

#define NET_EVENT_IPV4_MCAST_JOIN				\
	(_NET_EVENT_IPV4_BASE |	NET_EVENT_IPV4_CMD_MCAST_JOIN)

#define NET_EVENT_IPV4_MCAST_LEAVE				\
	(_NET_EVENT_IPV4_BASE |	NET_EVENT_IPV4_CMD_MCAST_LEAVE)


/* L4 network events */
#define _NET_L4_LAYER		NET_MGMT_LAYER_L4
#define _NET_L4_CORE_CODE	0x114
#define _NET_EVENT_L4_BASE	(NET_MGMT_EVENT_BIT |			\
				 NET_MGMT_IFACE_BIT |			\
				 NET_MGMT_LAYER(_NET_L4_LAYER) |	\
				 NET_MGMT_LAYER_CODE(_NET_L4_CORE_CODE))

enum net_event_l4_cmd {
	NET_EVENT_L4_CMD_CONNECTED = 1,
	NET_EVENT_L4_CMD_DISCONNECTED,
	NET_EVENT_L4_CMD_DNS_SERVER_ADD,
	NET_EVENT_L4_CMD_DNS_SERVER_DEL,
	NET_EVENT_L4_CMD_HOSTNAME_CHANGED,
	NET_EVENT_L4_CMD_CAPTURE_STARTED,
	NET_EVENT_L4_CMD_CAPTURE_STOPPED,
};

#define NET_EVENT_L4_CONNECTED				\
	(_NET_EVENT_L4_BASE | NET_EVENT_L4_CMD_CONNECTED)

#define NET_EVENT_L4_DISCONNECTED			\
	(_NET_EVENT_L4_BASE | NET_EVENT_L4_CMD_DISCONNECTED)

#define NET_EVENT_DNS_SERVER_ADD			\
	(_NET_EVENT_L4_BASE | NET_EVENT_L4_CMD_DNS_SERVER_ADD)

#define NET_EVENT_DNS_SERVER_DEL			\
	(_NET_EVENT_L4_BASE | NET_EVENT_L4_CMD_DNS_SERVER_DEL)

#define NET_EVENT_HOSTNAME_CHANGED			\
	(_NET_EVENT_L4_BASE | NET_EVENT_L4_CMD_HOSTNAME_CHANGED)

#define NET_EVENT_CAPTURE_STARTED			\
	(_NET_EVENT_L4_BASE | NET_EVENT_L4_CMD_CAPTURE_STARTED)

#define NET_EVENT_CAPTURE_STOPPED			\
	(_NET_EVENT_L4_BASE | NET_EVENT_L4_CMD_CAPTURE_STOPPED)

/** @endcond */

/**
 * @brief Network Management event information structure
 * Used to pass information on network events like
 *   NET_EVENT_IPV6_ADDR_ADD,
 *   NET_EVENT_IPV6_ADDR_DEL,
 *   NET_EVENT_IPV6_MADDR_ADD and
 *   NET_EVENT_IPV6_MADDR_DEL
 * when CONFIG_NET_MGMT_EVENT_INFO enabled and event generator pass the
 * information.
 */
struct net_event_ipv6_addr {
	struct in6_addr addr;
};

/**
 * @brief Network Management event information structure
 * Used to pass information on network events like
 *   NET_EVENT_IPV6_NBR_ADD and
 *   NET_EVENT_IPV6_NBR_DEL
 * when CONFIG_NET_MGMT_EVENT_INFO enabled and event generator pass the
 * information.
 * @note: idx will be '-1' in case of NET_EVENT_IPV6_NBR_DEL event.
 */
struct net_event_ipv6_nbr {
	struct in6_addr addr;
	int idx; /* NBR index*/
};

/**
 * @brief Network Management event information structure
 * Used to pass information on network events like
 *   NET_EVENT_IPV6_ROUTE_ADD and
 *   NET_EVENT_IPV6_ROUTE_DEL
 * when CONFIG_NET_MGMT_EVENT_INFO enabled and event generator pass the
 * information.
 */
struct net_event_ipv6_route {
	struct in6_addr nexthop;
	struct in6_addr addr; /* addr/prefix */
	uint8_t prefix_len;
};

/**
 * @brief Network Management event information structure
 * Used to pass information on network events like
 *   NET_EVENT_IPV6_PREFIX_ADD and
 *   NET_EVENT_IPV6_PREFIX_DEL
 * when CONFIG_NET_MGMT_EVENT_INFO is enabled and event generator pass the
 * information.
 */
struct net_event_ipv6_prefix {
	struct in6_addr addr; /* prefix */
	uint8_t len;
	uint32_t lifetime;
};

/**
 * @brief Network Management event information structure
 * Used to pass information on NET_EVENT_HOSTNAME_CHANGED event when
 * CONFIG_NET_MGMT_EVENT_INFO is enabled and event generator pass the
 * information.
 */
struct net_event_l4_hostname {
	char hostname[NET_HOSTNAME_SIZE];
};

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* ZEPHYR_INCLUDE_NET_NET_EVENT_H_ */
