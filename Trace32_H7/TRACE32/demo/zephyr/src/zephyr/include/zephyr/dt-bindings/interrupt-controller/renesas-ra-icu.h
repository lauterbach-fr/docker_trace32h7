/*
 * Copyright (c) 2023 TOKITA Hiroshi <tokita.hiroshi@fujitsu.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DT_BINDINGS_INTERRUPT_CONTROLLER_RENESAS_RA_ICU_H_
#define ZEPHYR_DT_BINDINGS_INTERRUPT_CONTROLLER_RENESAS_RA_ICU_H_

#define RA_ICU_IRQ_UNSPECIFIED (-1)

#define RA_ICU_PORT_IRQ0       (1 << 8)
#define RA_ICU_PORT_IRQ1       (2 << 8)
#define RA_ICU_PORT_IRQ2       (3 << 8)
#define RA_ICU_PORT_IRQ3       (4 << 8)
#define RA_ICU_PORT_IRQ4       (5 << 8)
#define RA_ICU_PORT_IRQ5       (6 << 8)
#define RA_ICU_PORT_IRQ6       (7 << 8)
#define RA_ICU_PORT_IRQ7       (8 << 8)
#define RA_ICU_PORT_IRQ8       (9 << 8)
#define RA_ICU_PORT_IRQ9       (10 << 8)
#define RA_ICU_PORT_IRQ10      (11 << 8)
#define RA_ICU_PORT_IRQ11      (12 << 8)
#define RA_ICU_PORT_IRQ12      (13 << 8)
#define RA_ICU_PORT_IRQ14      (15 << 8)
#define RA_ICU_PORT_IRQ15      (16 << 8)
#define RA_ICU_DMAC0_INT       (17 << 8)
#define RA_ICU_DMAC1_INT       (18 << 8)
#define RA_ICU_DMAC2_INT       (19 << 8)
#define RA_ICU_DMAC3_INT       (20 << 8)
#define RA_ICU_DTC_COMPLETE    (21 << 8)
#define RA_ICU_ICU_SNZCANCEL   (23 << 8)
#define RA_ICU_FCU_FRDYI       (24 << 8)
#define RA_ICU_LVD_LVD1        (25 << 8)
#define RA_ICU_LVD_LVD2        (26 << 8)
#define RA_ICU_VBATT_LVD       (27 << 8)
#define RA_ICU_MOSC_STOP       (28 << 8)
#define RA_ICU_SYSTEM_SNZREQ   (29 << 8)
#define RA_ICU_AGT0_AGTI       (30 << 8)
#define RA_ICU_AGT0_AGTCMAI    (31 << 8)
#define RA_ICU_AGT0_AGTCMBI    (32 << 8)
#define RA_ICU_AGT1_AGTI       (33 << 8)
#define RA_ICU_AGT1_AGTCMAI    (34 << 8)
#define RA_ICU_AGT1_AGTCMBI    (35 << 8)
#define RA_ICU_IWDT_NMIUNDF    (36 << 8)
#define RA_ICU_WDT_NMIUNDF     (37 << 8)
#define RA_ICU_RTC_ALM         (38 << 8)
#define RA_ICU_RTC_PRD         (39 << 8)
#define RA_ICU_RTC_CUP         (40 << 8)
#define RA_ICU_ADC140_ADI      (41 << 8)
#define RA_ICU_ADC140_GBADI    (42 << 8)
#define RA_ICU_ADC140_CMPAI    (43 << 8)
#define RA_ICU_ADC140_CMPBI    (44 << 8)
#define RA_ICU_ADC140_WCMPM    (45 << 8)
#define RA_ICU_ADC140_WCMPUM   (46 << 8)
#define RA_ICU_ACMP_LP0        (47 << 8)
#define RA_ICU_ACMP_LP1        (48 << 8)
#define RA_ICU_USBFS_D0FIFO    (49 << 8)
#define RA_ICU_USBFS_D1FIFO    (50 << 8)
#define RA_ICU_USBFS_USBI      (51 << 8)
#define RA_ICU_USBFS_USBR      (52 << 8)
#define RA_ICU_IIC0_RXI        (53 << 8)
#define RA_ICU_IIC0_TXI        (54 << 8)
#define RA_ICU_IIC0_TEI        (55 << 8)
#define RA_ICU_IIC0_EEI        (56 << 8)
#define RA_ICU_IIC0_WUI        (57 << 8)
#define RA_ICU_IIC1_RXI        (58 << 8)
#define RA_ICU_IIC1_TXI        (59 << 8)
#define RA_ICU_IIC1_TEI        (60 << 8)
#define RA_ICU_IIC1_EEI        (61 << 8)
#define RA_ICU_SSIE0_SSITXI    (62 << 8)
#define RA_ICU_SSIE0_SSIRXI    (63 << 8)

#define RA_ICU_SSIE0_SSIF      (65 << 8)
#define RA_ICU_CTSU_CTSUWR     (66 << 8)
#define RA_ICU_CTSU_CTSURD     (67 << 8)
#define RA_ICU_CTSU_CTSUFN     (68 << 8)
#define RA_ICU_KEY_INTKR       (69 << 8)
#define RA_ICU_DOC_DOPCI       (70 << 8)
#define RA_ICU_CAC_FERRI       (71 << 8)
#define RA_ICU_CAC_MENDI       (72 << 8)
#define RA_ICU_CAC_OVFI        (73 << 8)
#define RA_ICU_CAN0_ERS        (74 << 8)
#define RA_ICU_CAN0_RXF        (75 << 8)
#define RA_ICU_CAN0_TXF        (76 << 8)
#define RA_ICU_CAN0_RXM        (77 << 8)
#define RA_ICU_CAN0_TXM        (78 << 8)
#define RA_ICU_IOPORT_GROUP1   (70 << 8)
#define RA_ICU_IOPORT_GROUP2   (80 << 8)
#define RA_ICU_IOPORT_GROUP3   (81 << 8)
#define RA_ICU_IOPORT_GROUP4   (82 << 8)
#define RA_ICU_ELC_SWEVT0      (83 << 8)
#define RA_ICU_ELC_SWEVT1      (84 << 8)
#define RA_ICU_POEG_GROUP0     (85 << 8)
#define RA_ICU_POEG_GROUP1     (86 << 8)
#define RA_ICU_GPT0_CCMPA      (87 << 8)
#define RA_ICU_GPT0_CCMPB      (88 << 8)
#define RA_ICU_GPT0_CMPC       (89 << 8)
#define RA_ICU_GPT0_CMPD       (90 << 8)
#define RA_ICU_GPT0_CMPE       (91 << 8)
#define RA_ICU_GPT0_CMPF       (92 << 8)
#define RA_ICU_GPT0_OVF        (93 << 8)
#define RA_ICU_GPT0_UDF        (94 << 8)
#define RA_ICU_GPT1_CCMPA      (95 << 8)
#define RA_ICU_GPT1_CCMPB      (96 << 8)
#define RA_ICU_GPT1_CMPC       (97 << 8)
#define RA_ICU_GPT1_CMPD       (98 << 8)
#define RA_ICU_GPT1_CMPE       (99 << 8)
#define RA_ICU_GPT1_CMPF       (100 << 8)
#define RA_ICU_GPT1_OVF        (101 << 8)
#define RA_ICU_GPT1_UDF        (102 << 8)
#define RA_ICU_GPT2_CCMPA      (103 << 8)
#define RA_ICU_GPT2_CCMPB      (104 << 8)
#define RA_ICU_GPT2_CMPC       (105 << 8)
#define RA_ICU_GPT2_CMPD       (106 << 8)
#define RA_ICU_GPT2_CMPE       (107 << 8)
#define RA_ICU_GPT2_CMPF       (108 << 8)
#define RA_ICU_GPT2_OVF        (109 << 8)
#define RA_ICU_GPT2_UDF        (110 << 8)
#define RA_ICU_GPT3_CCMPA      (111 << 8)
#define RA_ICU_GPT3_CCMPB      (112 << 8)
#define RA_ICU_GPT3_CMPC       (113 << 8)
#define RA_ICU_GPT3_CMPD       (114 << 8)
#define RA_ICU_GPT3_CMPE       (115 << 8)
#define RA_ICU_GPT3_CMPF       (116 << 8)
#define RA_ICU_GPT3_OVF        (117 << 8)
#define RA_ICU_GPT3_UDF        (118 << 8)
#define RA_ICU_GPT4_CCMPA      (119 << 8)
#define RA_ICU_GPT4_CCMPB      (120 << 8)
#define RA_ICU_GPT4_CMPC       (121 << 8)
#define RA_ICU_GPT4_CMPD       (122 << 8)
#define RA_ICU_GPT4_CMPE       (123 << 8)
#define RA_ICU_GPT4_CMPF       (124 << 8)
#define RA_ICU_GPT4_OVF        (125 << 8)
#define RA_ICU_GPT4_UDF        (126 << 8)
#define RA_ICU_GPT5_CCMPA      (127 << 8)
#define RA_ICU_GPT5_CCMPB      (128 << 8)
#define RA_ICU_GPT5_CMPC       (129 << 8)
#define RA_ICU_GPT5_CMPD       (130 << 8)
#define RA_ICU_GPT5_CMPE       (131 << 8)
#define RA_ICU_GPT5_CMPF       (132 << 8)
#define RA_ICU_GPT5_OVF        (133 << 8)
#define RA_ICU_GPT5_UDF        (134 << 8)
#define RA_ICU_GPT6_CCMPA      (135 << 8)
#define RA_ICU_GPT6_CCMPB      (136 << 8)
#define RA_ICU_GPT6_CMPC       (137 << 8)
#define RA_ICU_GPT6_CMPD       (138 << 8)
#define RA_ICU_GPT6_CMPE       (139 << 8)
#define RA_ICU_GPT6_CMPF       (140 << 8)
#define RA_ICU_GPT6_OVF        (141 << 8)
#define RA_ICU_GPT6_UDF        (142 << 8)
#define RA_ICU_GPT7_CCMPA      (143 << 8)
#define RA_ICU_GPT7_CCMPB      (144 << 8)
#define RA_ICU_GPT7_CMPC       (145 << 8)
#define RA_ICU_GPT7_CMPD       (146 << 8)
#define RA_ICU_GPT7_CMPE       (147 << 8)
#define RA_ICU_GPT7_CMPF       (148 << 8)
#define RA_ICU_GPT7_OVF        (149 << 8)
#define RA_ICU_GPT7_UDF        (150 << 8)
#define RA_ICU_GPT_UVWEDGE     (151 << 8)
#define RA_ICU_SCI0_RXI        (152 << 8)
#define RA_ICU_SCI0_TXI        (153 << 8)
#define RA_ICU_SCI0_TEI        (154 << 8)
#define RA_ICU_SCI0_ERI        (155 << 8)
#define RA_ICU_SCI0_AM         (156 << 8)
#define RA_ICU_SCI0_RXI_OR_ERI (157 << 8)
#define RA_ICU_SCI1_RXI        (158 << 8)
#define RA_ICU_SCI1_TXI        (159 << 8)
#define RA_ICU_SCI1_TEI        (160 << 8)
#define RA_ICU_SCI1_ERI        (161 << 8)
#define RA_ICU_SCI1_AM         (162 << 8)
#define RA_ICU_SCI2_RXI        (163 << 8)
#define RA_ICU_SCI2_TXI        (164 << 8)
#define RA_ICU_SCI2_TEI        (165 << 8)
#define RA_ICU_SCI2_ERI        (166 << 8)
#define RA_ICU_SCI2_AM         (167 << 8)
#define RA_ICU_SCI9_RXI        (168 << 8)
#define RA_ICU_SCI9_TXI        (169 << 8)
#define RA_ICU_SCI9_TEI        (170 << 8)
#define RA_ICU_SCI9_ERI        (171 << 8)
#define RA_ICU_SCI9_AM         (172 << 8)
#define RA_ICU_SPI0_SPRI       (173 << 8)
#define RA_ICU_SPI0_SPTI       (174 << 8)
#define RA_ICU_SPI0_SPII       (175 << 8)
#define RA_ICU_SPI0_SPEI       (176 << 8)
#define RA_ICU_SPI0_SPTEND     (177 << 8)
#define RA_ICU_SPI1_SPRI       (178 << 8)
#define RA_ICU_SPI1_SPTI       (179 << 8)
#define RA_ICU_SPI1_SPII       (180 << 8)
#define RA_ICU_SPI1_SPEI       (181 << 8)
#define RA_ICU_SPI1_SPTEND     (182 << 8)

#endif /* ZEPHYR_DT_BINDINGS_INTERRUPT_CONTROLLER_RENESAS_RA_ICU_H_ */
