/** @file
 @brief 6lowpan private header

 This is not to be included by the application.
 */

/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

/* 6lopan dispatches */
#define NET_6LO_DISPATCH_IPV6		0x41 /* 01000001 */
#define NET_6LO_DISPATCH_BROADCAST	0x50 /* 01010000 */
#define NET_6LO_DISPATCH_IPHC		0x60 /* 01100000 */
#define NET_6LO_DISPATCH_MESH		0x80 /* 10xxxxxx */
#define NET_6LO_DISPATCH_FRAG1		0xC0 /* 11000xxx */
#define NET_6LO_DISPATCH_FRAGN		0xE0 /* 11100xxx */

#define NET_6LO_DISPATCH_IPHC_MASK	0xE0
/**
  * TF (Traffic class and Flow label)
  * 00:  ECN + DSCP + 4-bit Pad + Flow Label (4 bytes)
  * 01:  ECN + 2-bit Pad + Flow Label (3 bytes), DSCP is elided.
  * 10:  ECN + DSCP (1 byte), Flow Label is elided.
  * 11:  Traffic Class and Flow Label are elided.
  */
#define NET_6LO_IPHC_TF_POS		11
#define NET_6LO_IPHC_TF_MASK		(0x03 << NET_6LO_IPHC_TF_POS)
#define NET_6LO_IPHC_TF_00		(0x00 << NET_6LO_IPHC_TF_POS)
#define NET_6LO_IPHC_TF_01		(0x01 << NET_6LO_IPHC_TF_POS)
#define NET_6LO_IPHC_TF_10		(0x02 << NET_6LO_IPHC_TF_POS)
#define NET_6LO_IPHC_TF_11		(0x03 << NET_6LO_IPHC_TF_POS)

/* NH (next header) */
#define NET_6LO_IPHC_NH_POS		10
#define NET_6LO_IPHC_NH_MASK	(0x01 << NET_6LO_IPHC_NH_POS)
#define NET_6LO_IPHC_NH_0		(0x00 << NET_6LO_IPHC_NH_POS)
#define NET_6LO_IPHC_NH_1		(0x01 << NET_6LO_IPHC_NH_POS)

/* HLIM (Hop Limit) */
#define NET_6LO_IPHC_HLIM_POS		8
#define NET_6LO_IPHC_HLIM_MASK		(0x03 << NET_6LO_IPHC_HLIM_POS)
#define NET_6LO_IPHC_HLIM		(0x00 << NET_6LO_IPHC_HLIM_POS) /* 00 */
#define NET_6LO_IPHC_HLIM1		(0x01 << NET_6LO_IPHC_HLIM_POS) /* 01 */
#define NET_6LO_IPHC_HLIM64		(0x02 << NET_6LO_IPHC_HLIM_POS) /* 10 */
#define NET_6LO_IPHC_HLIM255		(0x03 << NET_6LO_IPHC_HLIM_POS) /* 11 */

/* CID (Context Identifier Extension) */
#define NET_6LO_IPHC_CID_POS		7
#define NET_6LO_IPHC_CID_MASK		(0x01 << NET_6LO_IPHC_CID_POS)
#define NET_6LO_IPHC_CID_0		(0x00 << NET_6LO_IPHC_CID_POS)
#define NET_6LO_IPHC_CID_1		(0x01 << NET_6LO_IPHC_CID_POS)

/* SAC (Source Address Compression) */
#define NET_6LO_IPHC_SAC_POS		6
#define NET_6LO_IPHC_SAC_MASK		(0x01 << NET_6LO_IPHC_SAC_POS)
#define NET_6LO_IPHC_SAC_0		(0x00 << NET_6LO_IPHC_SAC_POS)
#define NET_6LO_IPHC_SAC_1		(0x01 << NET_6LO_IPHC_SAC_POS)

/* SAM (Source Address Mode) */
#define NET_6LO_IPHC_SAM_POS		4
#define NET_6LO_IPHC_SAM_MASK		(0x03 << NET_6LO_IPHC_SAM_POS)
#define NET_6LO_IPHC_SAM_00		(0x00 << NET_6LO_IPHC_SAM_POS)
#define NET_6LO_IPHC_SAM_01		(0x01 << NET_6LO_IPHC_SAM_POS)
#define NET_6LO_IPHC_SAM_10		(0x02 << NET_6LO_IPHC_SAM_POS)
#define NET_6LO_IPHC_SAM_11		(0x03 << NET_6LO_IPHC_SAM_POS)

#define NET_6LO_IPHC_SA_MASK		(NET_6LO_IPHC_SAC_MASK | \
					 NET_6LO_IPHC_SAM_MASK)

/* M (Multicast compression) */
#define NET_6LO_IPHC_M_POS		3
#define NET_6LO_IPHC_M_MASK		(0x01 << NET_6LO_IPHC_M_POS)
#define NET_6LO_IPHC_M_0		(0x00 << NET_6LO_IPHC_M_POS)
#define NET_6LO_IPHC_M_1		(0x01 << NET_6LO_IPHC_M_POS)

/* DAC (Destination Address Compression) */
#define NET_6LO_IPHC_DAC_POS		2
#define NET_6LO_IPHC_DAC_MASK		(0x01 << NET_6LO_IPHC_DAC_POS)
#define NET_6LO_IPHC_DAC_0		(0x00 << NET_6LO_IPHC_DAC_POS)
#define NET_6LO_IPHC_DAC_1		(0x01 << NET_6LO_IPHC_DAC_POS)

/* DAM (Destination Address Mode) */
#define NET_6LO_IPHC_DAM_POS		0
#define NET_6LO_IPHC_DAM_MASK		(0x03 << NET_6LO_IPHC_DAM_POS)
#define NET_6LO_IPHC_DAM_00		(0x00 << NET_6LO_IPHC_DAM_POS)
#define NET_6LO_IPHC_DAM_01		(0x01 << NET_6LO_IPHC_DAM_POS)
#define NET_6LO_IPHC_DAM_10		(0x02 << NET_6LO_IPHC_DAM_POS)
#define NET_6LO_IPHC_DAM_11		(0x03 << NET_6LO_IPHC_DAM_POS)

#define NET_6LO_IPHC_DA_MASK		(NET_6LO_IPHC_DAC_MASK | \
					 NET_6LO_IPHC_DAM_MASK | \
					 NET_6LO_IPHC_M_MASK)

/* Next Header UDP */
#define NET_6LO_NHC_UDP_BARE		0xF0

#define NET_6LO_NHC_UDP_CHKSUM_0	0x00
#define NET_6LO_NHC_UDP_CHKSUM_1	0x08

#define NET_6LO_NHC_UDP_PORT_MASK 0x03
#define NET_6LO_NHC_UDP_PORT_00		0x00
#define NET_6LO_NHC_UDP_PORT_01		0x01
#define NET_6LO_NHC_UDP_PORT_10		0x02
#define NET_6LO_NHC_UDP_PORT_11		0x03
#define NET_6LO_NHC_UDP_CHECKSUM	0x04
#define NET_6LO_NHC_UDP_8_BIT_PORT	0xF0
#define NET_6LO_NHC_UDP_4_BIT_PORT	0xF0B

#define NET_6LO_FRAG1_HDR_LEN		4
#define NET_6LO_FRAGN_HDR_LEN		5

#define NET_6LO_FRAG_DATAGRAM_SIZE_LEN		2
#define NET_6LO_FRAG_DATAGRAM_OFFSET_LEN	2

/* Timeout when getting net_buf in RX path. In RX, we must not wait forever as
 * that can cause the stack to deadlock. This can happen if RX side is flooding
 * incoming data and we cannot get process the packet in 6lo side.
 */
#define NET_6LO_RX_PKT_TIMEOUT K_MSEC(100) /* in ms */
