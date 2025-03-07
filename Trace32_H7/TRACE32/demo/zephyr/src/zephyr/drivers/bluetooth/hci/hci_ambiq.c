/*
 * Copyright (c) 2023 Ambiq Micro Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @brief Ambiq SPI based Bluetooth HCI driver.
 */

#define DT_DRV_COMPAT ambiq_bt_hci_spi

#include <zephyr/init.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/bluetooth/hci_driver.h>
#include <zephyr/bluetooth/hci.h>

#define LOG_LEVEL CONFIG_BT_HCI_DRIVER_LOG_LEVEL
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(bt_hci_driver);

#include "apollox_blue.h"

#define HCI_SPI_NODE DT_COMPAT_GET_ANY_STATUS_OKAY(ambiq_bt_hci_spi)
#define SPI_DEV_NODE DT_BUS(HCI_SPI_NODE)

#define HCI_CMD 0x01
#define HCI_ACL 0x02
#define HCI_SCO 0x03
#define HCI_EVT 0x04

/* Offset of special item */
#define PACKET_TYPE         0
#define PACKET_TYPE_SIZE    1
#define EVT_HEADER_TYPE     0
#define EVT_HEADER_EVENT    1
#define EVT_HEADER_SIZE     2
#define EVT_VENDOR_CODE_LSB 3
#define EVT_VENDOR_CODE_MSB 4
#define CMD_OGF             1
#define CMD_OCF             2

#define EVT_OK      0
#define EVT_DISCARD 1
#define EVT_NOP     2

/* Max SPI buffer length for transceive operations.
 * The maximum TX packet number is 512 bytes data + 12 bytes header.
 * The maximum RX packet number is 255 bytes data + 3 header.
 */
#define SPI_MAX_TX_MSG_LEN 524
#define SPI_MAX_RX_MSG_LEN 258

static uint8_t __noinit rxmsg[SPI_MAX_RX_MSG_LEN];
static const struct device *spi_dev = DEVICE_DT_GET(SPI_DEV_NODE);
static struct spi_config spi_cfg = {
	.operation = SPI_OP_MODE_MASTER | SPI_TRANSFER_MSB | SPI_MODE_CPOL | SPI_MODE_CPHA |
		     SPI_WORD_SET(8),
};
static K_KERNEL_STACK_DEFINE(spi_rx_stack, CONFIG_BT_DRV_RX_STACK_SIZE);
static struct k_thread spi_rx_thread_data;

static struct spi_buf spi_tx_buf;
static struct spi_buf spi_rx_buf;
static const struct spi_buf_set spi_tx = {.buffers = &spi_tx_buf, .count = 1};
static const struct spi_buf_set spi_rx = {.buffers = &spi_rx_buf, .count = 1};

static K_SEM_DEFINE(sem_irq, 0, 1);
static K_SEM_DEFINE(sem_spi_available, 1, 1);

void bt_packet_irq_isr(const struct device *unused1, struct gpio_callback *unused2,
		       uint32_t unused3)
{
	k_sem_give(&sem_irq);
}

static inline int bt_spi_transceive(void *tx, uint32_t tx_len, void *rx, uint32_t rx_len)
{
	spi_tx_buf.buf = tx;
	spi_tx_buf.len = (size_t)tx_len;
	spi_rx_buf.buf = rx;
	spi_rx_buf.len = (size_t)rx_len;
	return spi_transceive(spi_dev, &spi_cfg, &spi_tx, &spi_rx);
}

static int spi_send_packet(uint8_t *data, uint16_t len)
{
	int ret;

	/* Wait for SPI bus to be available */
	k_sem_take(&sem_spi_available, K_FOREVER);

	/* Send the SPI packet to controller */
	ret = bt_apollo_spi_send(data, len, bt_spi_transceive);

	/* Free the SPI bus */
	k_sem_give(&sem_spi_available);

	return ret;
}

static int spi_receive_packet(uint8_t *data, uint16_t *len)
{
	int ret;

	/* Wait for SPI bus to be available */
	k_sem_take(&sem_spi_available, K_FOREVER);

	/* Receive the SPI packet from controller */
	ret = bt_apollo_spi_rcv(data, len, bt_spi_transceive);

	/* Free the SPI bus */
	k_sem_give(&sem_spi_available);

	return ret;
}

static int hci_event_filter(const uint8_t *evt_data)
{
	uint8_t evt_type = evt_data[0];

	switch (evt_type) {
	case BT_HCI_EVT_LE_META_EVENT: {
		uint8_t subevt_type = evt_data[sizeof(struct bt_hci_evt_hdr)];

		switch (subevt_type) {
		case BT_HCI_EVT_LE_ADVERTISING_REPORT:
			return EVT_DISCARD;
		default:
			return EVT_OK;
		}
	}
	case BT_HCI_EVT_CMD_COMPLETE: {
		uint16_t opcode = (uint16_t)(evt_data[3] + (evt_data[4] << 8));

		switch (opcode) {
		case BT_OP_NOP:
			return EVT_NOP;
		default:
			return EVT_OK;
		}
	}
	default:
		return EVT_OK;
	}
}

static struct net_buf *bt_hci_evt_recv(uint8_t *data, size_t len)
{
	int evt_filter;
	bool discardable = false;
	struct bt_hci_evt_hdr hdr = {0};
	struct net_buf *buf;
	size_t buf_tailroom;

	if (len < sizeof(hdr)) {
		LOG_ERR("Not enough data for event header");
		return NULL;
	}

	evt_filter = hci_event_filter(data);
	if (evt_filter == EVT_NOP) {
		/* The controller sends NOP event when wakes up based on
		 * hardware specific requirement, do not post this event to
		 * host stack.
		 */
		return NULL;
	} else if (evt_filter == EVT_DISCARD) {
		discardable = true;
	}

	memcpy((void *)&hdr, data, sizeof(hdr));
	data += sizeof(hdr);
	len -= sizeof(hdr);

	if (len != hdr.len) {
		LOG_ERR("Event payload length is not correct");
		return NULL;
	}

	buf = bt_buf_get_evt(hdr.evt, discardable, K_NO_WAIT);
	if (!buf) {
		if (discardable) {
			LOG_DBG("Discardable buffer pool full, ignoring event");
		} else {
			LOG_ERR("No available event buffers!");
		}
		return buf;
	}

	net_buf_add_mem(buf, &hdr, sizeof(hdr));

	buf_tailroom = net_buf_tailroom(buf);
	if (buf_tailroom < len) {
		LOG_ERR("Not enough space in buffer %zu/%zu", len, buf_tailroom);
		net_buf_unref(buf);
		return NULL;
	}

	net_buf_add_mem(buf, data, len);

	return buf;
}

static struct net_buf *bt_hci_acl_recv(uint8_t *data, size_t len)
{
	struct bt_hci_acl_hdr hdr = {0};
	struct net_buf *buf;
	size_t buf_tailroom;

	if (len < sizeof(hdr)) {
		LOG_ERR("Not enough data for ACL header");
		return NULL;
	}

	buf = bt_buf_get_rx(BT_BUF_ACL_IN, K_NO_WAIT);
	if (buf) {
		memcpy((void *)&hdr, data, sizeof(hdr));
		data += sizeof(hdr);
		len -= sizeof(hdr);
	} else {
		LOG_ERR("No available ACL buffers!");
		return NULL;
	}

	if (len != sys_le16_to_cpu(hdr.len)) {
		LOG_ERR("ACL payload length is not correct");
		net_buf_unref(buf);
		return NULL;
	}

	net_buf_add_mem(buf, &hdr, sizeof(hdr));
	buf_tailroom = net_buf_tailroom(buf);
	if (buf_tailroom < len) {
		LOG_ERR("Not enough space in buffer %zu/%zu", len, buf_tailroom);
		net_buf_unref(buf);
		return NULL;
	}

	net_buf_add_mem(buf, data, len);

	return buf;
}

static void bt_spi_rx_thread(void *p1, void *p2, void *p3)
{
	ARG_UNUSED(p1);
	ARG_UNUSED(p2);
	ARG_UNUSED(p3);

	struct net_buf *buf;
	int ret;
	uint16_t len = 0;

	while (true) {
		/* Wait for controller interrupt */
		k_sem_take(&sem_irq, K_FOREVER);

		do {
			/* Recevive the HCI packet via SPI */
			ret = spi_receive_packet(&rxmsg[0], &len);
			if (ret) {
				break;
			}

			/* Check if needs to handle the vendor specific events which are
			 * incompatible with the standard Bluetooth HCI format.
			 */
			if (bt_apollo_vnd_rcv_ongoing(&rxmsg[0], len)) {
				break;
			}

			switch (rxmsg[PACKET_TYPE]) {
			case HCI_EVT:
				buf = bt_hci_evt_recv(&rxmsg[PACKET_TYPE + PACKET_TYPE_SIZE],
						      (len - PACKET_TYPE_SIZE));
				break;
			case HCI_ACL:
				buf = bt_hci_acl_recv(&rxmsg[PACKET_TYPE + PACKET_TYPE_SIZE],
						      (len - PACKET_TYPE_SIZE));
				break;
			default:
				buf = NULL;
				LOG_WRN("Unknown BT buf type %d", rxmsg[PACKET_TYPE]);
				break;
			}

			/* Post the RX message to host stack to process */
			if (buf) {
				bt_recv(buf);
			}
		} while (0);
	}
}

static int bt_hci_send(struct net_buf *buf)
{
	int ret = 0;

	/* Buffer needs an additional byte for type */
	if (buf->len >= SPI_MAX_TX_MSG_LEN) {
		LOG_ERR("Message too long");
		return -EINVAL;
	}

	switch (bt_buf_get_type(buf)) {
	case BT_BUF_ACL_OUT:
		net_buf_push_u8(buf, HCI_ACL);
		break;
	case BT_BUF_CMD:
		net_buf_push_u8(buf, HCI_CMD);
		break;
	default:
		LOG_ERR("Unsupported type");
		net_buf_unref(buf);
		return -EINVAL;
	}

	/* Send the SPI packet */
	ret = spi_send_packet(buf->data, buf->len);

	net_buf_unref(buf);

	return ret;
}

static int bt_hci_open(void)
{
	int ret;

	ret = bt_hci_transport_setup(spi_dev);
	if (ret) {
		return ret;
	}

	/* Start RX thread */
	k_thread_create(&spi_rx_thread_data, spi_rx_stack, K_KERNEL_STACK_SIZEOF(spi_rx_stack),
			(k_thread_entry_t)bt_spi_rx_thread, NULL, NULL, NULL,
			K_PRIO_COOP(CONFIG_BT_DRIVER_RX_HIGH_PRIO), 0, K_NO_WAIT);

	ret = bt_apollo_controller_init(spi_send_packet);

	return ret;
}

static int bt_spi_setup(const struct bt_hci_setup_params *params)
{
	ARG_UNUSED(params);

	int ret;

	ret = bt_apollo_vnd_setup();

	return ret;
}

static const struct bt_hci_driver drv = {
	.name = "ambiq hci",
	.bus = BT_HCI_DRIVER_BUS_SPI,
	.open = bt_hci_open,
	.send = bt_hci_send,
	.setup = bt_spi_setup,
};

static int bt_hci_init(void)
{
	int ret;

	if (!device_is_ready(spi_dev)) {
		LOG_ERR("SPI device not ready");
		return -ENODEV;
	}

	ret = bt_apollo_dev_init();
	if (ret) {
		return ret;
	}

	bt_hci_driver_register(&drv);

	LOG_DBG("BT HCI initialized");

	return 0;
}

SYS_INIT(bt_hci_init, POST_KERNEL, CONFIG_BT_HCI_INIT_PRIORITY);
