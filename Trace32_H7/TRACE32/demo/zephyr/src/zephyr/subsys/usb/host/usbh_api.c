/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <errno.h>
#include <zephyr/sys/util.h>
#include "usbh_internal.h"

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(uhs_api, CONFIG_USBH_LOG_LEVEL);

int usbh_init(struct usbh_contex *uhs_ctx)
{
	int ret;

	k_mutex_lock(&uhs_ctx->mutex, K_FOREVER);

	if (!device_is_ready(uhs_ctx->dev)) {
		LOG_ERR("USB host controller is not ready");
		ret = -ENODEV;
		goto init_exit;
	}

	if (uhc_is_initialized(uhs_ctx->dev)) {
		LOG_WRN("USB host controller is already initialized");
		ret = -EALREADY;
		goto init_exit;
	}

	ret = usbh_init_device_intl(uhs_ctx);

init_exit:
	k_mutex_unlock(&uhs_ctx->mutex);
	return ret;
}

int usbh_enable(struct usbh_contex *uhs_ctx)
{
	int ret;

	k_mutex_lock(&uhs_ctx->mutex, K_FOREVER);

	if (!uhc_is_initialized(uhs_ctx->dev)) {
		LOG_WRN("USB host controller is not initialized");
		ret = -EPERM;
		goto enable_exit;
	}

	if (uhc_is_enabled(uhs_ctx->dev)) {
		LOG_WRN("USB host controller is already enabled");
		ret = -EALREADY;
		goto enable_exit;
	}

	ret = uhc_enable(uhs_ctx->dev);
	if (ret != 0) {
		LOG_ERR("Failed to enable controller");
		goto enable_exit;
	}

enable_exit:
	k_mutex_unlock(&uhs_ctx->mutex);
	return ret;
}

int usbh_disable(struct usbh_contex *uhs_ctx)
{
	int ret;

	if (!uhc_is_enabled(uhs_ctx->dev)) {
		LOG_WRN("USB host controller is already disabled");
		return 0;
	}

	k_mutex_lock(&uhs_ctx->mutex, K_FOREVER);

	ret = uhc_disable(uhs_ctx->dev);
	if (ret) {
		LOG_ERR("Failed to disable USB controller");
	}

	k_mutex_unlock(&uhs_ctx->mutex);

	return 0;
}

int usbh_shutdown(struct usbh_contex *const uhs_ctx)
{
	int ret;

	k_mutex_lock(&uhs_ctx->mutex, K_FOREVER);

	ret = uhc_shutdown(uhs_ctx->dev);
	if (ret) {
		LOG_ERR("Failed to shutdown USB device");
	}

	k_mutex_unlock(&uhs_ctx->mutex);

	return ret;
}
