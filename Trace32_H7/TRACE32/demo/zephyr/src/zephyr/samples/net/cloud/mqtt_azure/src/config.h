/*
 * Copyright (c) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#define SERVER_ADDR		CONFIG_SAMPLE_CLOUD_AZURE_SERVER_ADDR
#define SERVER_PORT		CONFIG_SAMPLE_CLOUD_AZURE_SERVER_PORT

#if defined(CONFIG_SOCKS)
#define SOCKS5_PROXY_ADDR	CONFIG_SAMPLE_SOCKS_ADDR
#define SOCKS5_PROXY_PORT	CONFIG_SAMPLE_SOCKS_PORT
#endif

#define MQTT_CLIENTID		CONFIG_SAMPLE_CLOUD_AZURE_CLIENT_ID

#define APP_SLEEP_MSECS		8000

#define APP_MQTT_BUFFER_SIZE	1024

#endif /* __CONFIG_H__ */
