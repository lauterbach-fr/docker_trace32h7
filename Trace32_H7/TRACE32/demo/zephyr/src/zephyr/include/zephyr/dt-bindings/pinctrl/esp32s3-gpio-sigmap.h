/*
 * Copyright (c) 2022 Espressif Systems (Shanghai) Co., Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_PINCTRL_ESP32S3_GPIO_SIGMAP_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_PINCTRL_ESP32S3_GPIO_SIGMAP_H_

#define ESP_NOSIG                         ESP_SIG_INVAL

#define ESP_SPIQ_IN                   0
#define ESP_SPIQ_OUT                  0
#define ESP_SPID_IN                   1
#define ESP_SPID_OUT                  1
#define ESP_SPIHD_IN                  2
#define ESP_SPIHD_OUT                 2
#define ESP_SPIWP_IN                  3
#define ESP_SPIWP_OUT                 3
#define ESP_SPICLK_OUT                4
#define ESP_SPICS0_OUT                5
#define ESP_SPICS1_OUT                6
#define ESP_SPID4_IN                  7
#define ESP_SPID4_OUT                 7
#define ESP_SPID5_IN                  8
#define ESP_SPID5_OUT                 8
#define ESP_SPID6_IN                  9
#define ESP_SPID6_OUT                 9
#define ESP_SPID7_IN                  10
#define ESP_SPID7_OUT                 10
#define ESP_SPIDQS_IN                 11
#define ESP_SPIDQS_OUT                11
#define ESP_U0RXD_IN                  12
#define ESP_U0TXD_OUT                 12
#define ESP_U0CTS_IN                  13
#define ESP_U0RTS_OUT                 13
#define ESP_U0DSR_IN                  14
#define ESP_U0DTR_OUT                 14
#define ESP_U1RXD_IN                  15
#define ESP_U1TXD_OUT                 15
#define ESP_U1CTS_IN                  16
#define ESP_U1RTS_OUT                 16
#define ESP_U1DSR_IN                  17
#define ESP_U1DTR_OUT                 17
#define ESP_U2RXD_IN                  18
#define ESP_U2TXD_OUT                 18
#define ESP_U2CTS_IN                  19
#define ESP_U2RTS_OUT                 19
#define ESP_U2DSR_IN                  20
#define ESP_U2DTR_OUT                 20
#define ESP_I2S1_MCLK_IN              21
#define ESP_I2S1_MCLK_OUT             21
#define ESP_I2S0O_BCK_IN              22
#define ESP_I2S0O_BCK_OUT             22
#define ESP_I2S0_MCLK_IN              23
#define ESP_I2S0_MCLK_OUT             23
#define ESP_I2S0O_WS_IN               24
#define ESP_I2S0O_WS_OUT              24
#define ESP_I2S0I_SD_IN               25
#define ESP_I2S0O_SD_OUT              25
#define ESP_I2S0I_BCK_IN              26
#define ESP_I2S0I_BCK_OUT             26
#define ESP_I2S0I_WS_IN               27
#define ESP_I2S0I_WS_OUT              27
#define ESP_I2S1O_BCK_IN              28
#define ESP_I2S1O_BCK_OUT             28
#define ESP_I2S1O_WS_IN               29
#define ESP_I2S1O_WS_OUT              29
#define ESP_I2S1I_SD_IN               30
#define ESP_I2S1O_SD_OUT              30
#define ESP_I2S1I_BCK_IN              31
#define ESP_I2S1I_BCK_OUT             31
#define ESP_I2S1I_WS_IN               32
#define ESP_I2S1I_WS_OUT              32
#define ESP_PCNT_SIG_CH0_IN0          33
#define ESP_GPIO_WLAN_PRIO            33
#define ESP_PCNT_SIG_CH1_IN0          34
#define ESP_GPIO_WLAN_ACTIVE          34
#define ESP_PCNT_CTRL_CH0_IN0         35
#define ESP_BB_DIAG0                  35
#define ESP_PCNT_CTRL_CH1_IN0         36
#define ESP_BB_DIAG1                  36
#define ESP_PCNT_SIG_CH0_IN1          37
#define ESP_BB_DIAG2                  37
#define ESP_PCNT_SIG_CH1_IN1          38
#define ESP_BB_DIAG3                  38
#define ESP_PCNT_CTRL_CH0_IN1         39
#define ESP_BB_DIAG4                  39
#define ESP_PCNT_CTRL_CH1_IN1         40
#define ESP_BB_DIAG5                  40
#define ESP_PCNT_SIG_CH0_IN2          41
#define ESP_BB_DIAG6                  41
#define ESP_PCNT_SIG_CH1_IN2          42
#define ESP_BB_DIAG7                  42
#define ESP_PCNT_CTRL_CH0_IN2         43
#define ESP_BB_DIAG8                  43
#define ESP_PCNT_CTRL_CH1_IN2         44
#define ESP_BB_DIAG9                  44
#define ESP_PCNT_SIG_CH0_IN3          45
#define ESP_BB_DIAG10                 45
#define ESP_PCNT_SIG_CH1_IN3          46
#define ESP_BB_DIAG11                 46
#define ESP_PCNT_CTRL_CH0_IN3         47
#define ESP_BB_DIAG12                 47
#define ESP_PCNT_CTRL_CH1_IN3         48
#define ESP_BB_DIAG13                 48
#define ESP_GPIO_BT_ACTIVE            49
#define ESP_BB_DIAG14                 49
#define ESP_GPIO_BT_PRIORITY          50
#define ESP_BB_DIAG15                 50
#define ESP_I2S0I_SD1_IN              51
#define ESP_BB_DIAG16                 51
#define ESP_I2S0I_SD2_IN              52
#define ESP_BB_DIAG17                 52
#define ESP_I2S0I_SD3_IN              53
#define ESP_BB_DIAG18                 53
#define ESP_CORE1_GPIO_IN7            54
#define ESP_CORE1_GPIO_OUT7           54
#define ESP_USB_EXTPHY_VP             55
#define ESP_USB_EXTPHY_OEN            55
#define ESP_USB_EXTPHY_VM             56
#define ESP_USB_EXTPHY_SPEED          56
#define ESP_USB_EXTPHY_RCV            57
#define ESP_USB_EXTPHY_VPO            57
#define ESP_USB_OTG_IDDIG_IN          58
#define ESP_USB_EXTPHY_VMO            58
#define ESP_USB_OTG_AVALID_IN         59
#define ESP_USB_EXTPHY_SUSPND         59
#define ESP_USB_SRP_BVALID_IN         60
#define ESP_USB_OTG_IDPULLUP          60
#define ESP_USB_OTG_VBUSVALID_IN      61
#define ESP_USB_OTG_DPPULLDOWN        61
#define ESP_USB_SRP_SESSEND_IN        62
#define ESP_USB_OTG_DMPULLDOWN        62
#define ESP_USB_OTG_DRVVBUS           63
#define ESP_USB_SRP_CHRGVBUS          64
#define ESP_USB_SRP_DISCHRGVBUS       65
#define ESP_SPI3_CLK_IN               66
#define ESP_SPI3_CLK_OUT              66
#define ESP_SPI3_Q_IN                 67
#define ESP_SPI3_Q_OUT                67
#define ESP_SPI3_D_IN                 68
#define ESP_SPI3_D_OUT                68
#define ESP_SPI3_HD_IN                69
#define ESP_SPI3_HD_OUT               69
#define ESP_SPI3_WP_IN                70
#define ESP_SPI3_WP_OUT               70
#define ESP_SPI3_CS0_IN               71
#define ESP_SPI3_CS0_OUT              71
#define ESP_SPI3_CS1_OUT              72
#define ESP_EXT_ADC_START             73
#define ESP_LEDC_LS_SIG_OUT0          73
#define ESP_LEDC_LS_SIG_OUT1          74
#define ESP_LEDC_LS_SIG_OUT2          75
#define ESP_LEDC_LS_SIG_OUT3          76
#define ESP_LEDC_LS_SIG_OUT4          77
#define ESP_LEDC_LS_SIG_OUT5          78
#define ESP_LEDC_LS_SIG_OUT6          79
#define ESP_LEDC_LS_SIG_OUT7          80
#define ESP_RMT_SIG_IN0               81
#define ESP_RMT_SIG_OUT0              81
#define ESP_RMT_SIG_IN1               82
#define ESP_RMT_SIG_OUT1              82
#define ESP_RMT_SIG_IN2               83
#define ESP_RMT_SIG_OUT2              83
#define ESP_RMT_SIG_IN3               84
#define ESP_RMT_SIG_OUT3              84
#define ESP_USB_JTAG_TCK              85
#define ESP_USB_JTAG_TMS              86
#define ESP_USB_JTAG_TDI              87
#define ESP_USB_JTAG_TDO              88
#define ESP_I2CEXT0_SCL_IN            89
#define ESP_I2CEXT0_SCL_OUT           89
#define ESP_I2CEXT0_SDA_IN            90
#define ESP_I2CEXT0_SDA_OUT           90
#define ESP_I2CEXT1_SCL_IN            91
#define ESP_I2CEXT1_SCL_OUT           91
#define ESP_I2CEXT1_SDA_IN            92
#define ESP_I2CEXT1_SDA_OUT           92
#define ESP_GPIO_SD0_OUT              93
#define ESP_GPIO_SD1_OUT              94
#define ESP_GPIO_SD2_OUT              95
#define ESP_GPIO_SD3_OUT              96
#define ESP_GPIO_SD4_OUT              97
#define ESP_GPIO_SD5_OUT              98
#define ESP_GPIO_SD6_OUT              99
#define ESP_GPIO_SD7_OUT              100
#define ESP_FSPICLK_IN                101
#define ESP_FSPICLK_OUT               101
#define ESP_FSPIQ_IN                  102
#define ESP_FSPIQ_OUT                 102
#define ESP_FSPID_IN                  103
#define ESP_FSPID_OUT                 103
#define ESP_FSPIHD_IN                 104
#define ESP_FSPIHD_OUT                104
#define ESP_FSPIWP_IN                 105
#define ESP_FSPIWP_OUT                105
#define ESP_FSPIIO4_IN                106
#define ESP_FSPIIO4_OUT               106
#define ESP_FSPIIO5_IN                107
#define ESP_FSPIIO5_OUT               107
#define ESP_FSPIIO6_IN                108
#define ESP_FSPIIO6_OUT               108
#define ESP_FSPIIO7_IN                109
#define ESP_FSPIIO7_OUT               109
#define ESP_FSPICS0_IN                110
#define ESP_FSPICS0_OUT               110
#define ESP_FSPICS1_OUT               111
#define ESP_FSPICS2_OUT               112
#define ESP_FSPICS3_OUT               113
#define ESP_FSPICS4_OUT               114
#define ESP_FSPICS5_OUT               115
#define ESP_TWAI_RX                   116
#define ESP_TWAI_TX                   116
#define ESP_TWAI_BUS_OFF_ON           117
#define ESP_TWAI_CLKOUT               118
#define ESP_SUBSPICLK_OUT             119
#define ESP_SUBSPIQ_IN                120
#define ESP_SUBSPIQ_OUT               120
#define ESP_SUBSPID_IN                121
#define ESP_SUBSPID_OUT               121
#define ESP_SUBSPIHD_IN               122
#define ESP_SUBSPIHD_OUT              122
#define ESP_SUBSPIWP_IN               123
#define ESP_SUBSPIWP_OUT              123
#define ESP_SUBSPICS0_OUT             124
#define ESP_SUBSPICS1_OUT             125
#define ESP_FSPIDQS_OUT               126
#define ESP_SPI3_CS2_OUT              127
#define ESP_I2S0O_SD1_OUT             128
#define ESP_CORE1_GPIO_IN0            129
#define ESP_CORE1_GPIO_OUT0           129
#define ESP_CORE1_GPIO_IN1            130
#define ESP_CORE1_GPIO_OUT1           130
#define ESP_CORE1_GPIO_IN2            131
#define ESP_CORE1_GPIO_OUT2           131
#define ESP_LCD_CS                    132
#define ESP_CAM_DATA_IN0              133
#define ESP_LCD_DATA_OUT0             133
#define ESP_CAM_DATA_IN1              134
#define ESP_LCD_DATA_OUT1             134
#define ESP_CAM_DATA_IN2              135
#define ESP_LCD_DATA_OUT2             135
#define ESP_CAM_DATA_IN3              136
#define ESP_LCD_DATA_OUT3             136
#define ESP_CAM_DATA_IN4              137
#define ESP_LCD_DATA_OUT4             137
#define ESP_CAM_DATA_IN5              138
#define ESP_LCD_DATA_OUT5             138
#define ESP_CAM_DATA_IN6              139
#define ESP_LCD_DATA_OUT6             139
#define ESP_CAM_DATA_IN7              140
#define ESP_LCD_DATA_OUT7             140
#define ESP_CAM_DATA_IN8              141
#define ESP_LCD_DATA_OUT8             141
#define ESP_CAM_DATA_IN9              142
#define ESP_LCD_DATA_OUT9             142
#define ESP_CAM_DATA_IN10             143
#define ESP_LCD_DATA_OUT10            143
#define ESP_CAM_DATA_IN11             144
#define ESP_LCD_DATA_OUT11            144
#define ESP_CAM_DATA_IN12             145
#define ESP_LCD_DATA_OUT12            145
#define ESP_CAM_DATA_IN13             146
#define ESP_LCD_DATA_OUT13            146
#define ESP_CAM_DATA_IN14             147
#define ESP_LCD_DATA_OUT14            147
#define ESP_CAM_DATA_IN15             148
#define ESP_LCD_DATA_OUT15            148
#define ESP_CAM_PCLK                  149
#define ESP_CAM_CLK                   149
#define ESP_CAM_H_ENABLE              150
#define ESP_LCD_H_ENABLE              150
#define ESP_CAM_H_SYNC                151
#define ESP_LCD_H_SYNC                151
#define ESP_CAM_V_SYNC                152
#define ESP_LCD_V_SYNC                152
#define ESP_LCD_DC                    153
#define ESP_LCD_PCLK                  154
#define ESP_SUBSPID4_IN               155
#define ESP_SUBSPID4_OUT              155
#define ESP_SUBSPID5_IN               156
#define ESP_SUBSPID5_OUT              156
#define ESP_SUBSPID6_IN               157
#define ESP_SUBSPID6_OUT              157
#define ESP_SUBSPID7_IN               158
#define ESP_SUBSPID7_OUT              158
#define ESP_SUBSPIDQS_IN              159
#define ESP_SUBSPIDQS_OUT             159
#define ESP_PWM0_SYNC0_IN             160
#define ESP_PWM0_OUT0A                160
#define ESP_PWM0_SYNC1_IN             161
#define ESP_PWM0_OUT0B                161
#define ESP_PWM0_SYNC2_IN             162
#define ESP_PWM0_OUT1A                162
#define ESP_PWM0_F0_IN                163
#define ESP_PWM0_OUT1B                163
#define ESP_PWM0_F1_IN                164
#define ESP_PWM0_OUT2A                164
#define ESP_PWM0_F2_IN                165
#define ESP_PWM0_OUT2B                165
#define ESP_PWM0_CAP0_IN              166
#define ESP_PWM1_OUT0A                166
#define ESP_PWM0_CAP1_IN              167
#define ESP_PWM1_OUT0B                167
#define ESP_PWM0_CAP2_IN              168
#define ESP_PWM1_OUT1A                168
#define ESP_PWM1_SYNC0_IN             169
#define ESP_PWM1_OUT1B                169
#define ESP_PWM1_SYNC1_IN             170
#define ESP_PWM1_OUT2A                170
#define ESP_PWM1_SYNC2_IN             171
#define ESP_PWM1_OUT2B                171
#define ESP_PWM1_F0_IN                172
#define ESP_SDHOST_CCLK_OUT_1         172
#define ESP_PWM1_F1_IN                173
#define ESP_SDHOST_CCLK_OUT_2         173
#define ESP_PWM1_F2_IN                174
#define ESP_SDHOST_RST_N_1            174
#define ESP_PWM1_CAP0_IN              175
#define ESP_SDHOST_RST_N_2            175
#define ESP_PWM1_CAP1_IN              176
#define ESP_SDHOST_CCMD_OD_PULLUP_EN_N176
#define ESP_PWM1_CAP2_IN              177
#define ESP_SDIO_TOHOST_INT_OUT       177
#define ESP_SDHOST_CCMD_IN_1          178
#define ESP_SDHOST_CCMD_OUT_1         178
#define ESP_SDHOST_CCMD_IN_2          179
#define ESP_SDHOST_CCMD_OUT_2         179
#define ESP_SDHOST_CDATA_IN_10        180
#define ESP_SDHOST_CDATA_OUT_10       180
#define ESP_SDHOST_CDATA_IN_11        181
#define ESP_SDHOST_CDATA_OUT_11       181
#define ESP_SDHOST_CDATA_IN_12        182
#define ESP_SDHOST_CDATA_OUT_12       182
#define ESP_SDHOST_CDATA_IN_13        183
#define ESP_SDHOST_CDATA_OUT_13       183
#define ESP_SDHOST_CDATA_IN_14        184
#define ESP_SDHOST_CDATA_OUT_14       184
#define ESP_SDHOST_CDATA_IN_15        185
#define ESP_SDHOST_CDATA_OUT_15       185
#define ESP_SDHOST_CDATA_IN_16        186
#define ESP_SDHOST_CDATA_OUT_16       186
#define ESP_SDHOST_CDATA_IN_17        187
#define ESP_SDHOST_CDATA_OUT_17       187
#define ESP_PCMFSYNC_IN               188
#define ESP_BT_AUDIO0_IRQ             188
#define ESP_PCMCLK_IN                 189
#define ESP_BT_AUDIO1_IRQ             189
#define ESP_PCMDIN                    190
#define ESP_BT_AUDIO2_IRQ             190
#define ESP_RW_WAKEUP_REQ             191
#define ESP_BLE_AUDIO0_IRQ            191
#define ESP_SDHOST_DATA_STROBE_1      192
#define ESP_BLE_AUDIO1_IRQ            192
#define ESP_SDHOST_DATA_STROBE_2      193
#define ESP_BLE_AUDIO2_IRQ            193
#define ESP_SDHOST_CARD_DETECT_N_1    194
#define ESP_PCMFSYNC_OUT              194
#define ESP_SDHOST_CARD_DETECT_N_2    195
#define ESP_PCMCLK_OUT                195
#define ESP_SDHOST_CARD_WRITE_PRT_1   196
#define ESP_PCMDOUT                   196
#define ESP_SDHOST_CARD_WRITE_PRT_2   197
#define ESP_BLE_AUDIO_SYNC0_P         197
#define ESP_SDHOST_CARD_INT_N_1       198
#define ESP_BLE_AUDIO_SYNC1_P         198
#define ESP_SDHOST_CARD_INT_N_2       199
#define ESP_BLE_AUDIO_SYNC2_P         199
#define ESP_ANT_SEL0                  200
#define ESP_ANT_SEL1                  201
#define ESP_ANT_SEL2                  202
#define ESP_ANT_SEL3                  203
#define ESP_ANT_SEL4                  204
#define ESP_ANT_SEL5                  205
#define ESP_ANT_SEL6                  206
#define ESP_ANT_SEL7                  207
#define ESP_SIG_IN_FUNC_208           208
#define ESP_SIG_IN_FUNC208            208
#define ESP_SIG_IN_FUNC_209           209
#define ESP_SIG_IN_FUNC209            209
#define ESP_SIG_IN_FUNC_210           210
#define ESP_SIG_IN_FUNC210            210
#define ESP_SIG_IN_FUNC_211           211
#define ESP_SIG_IN_FUNC211            211
#define ESP_SIG_IN_FUNC_212           212
#define ESP_SIG_IN_FUNC212            212
#define ESP_SDHOST_CDATA_IN_20        213
#define ESP_SDHOST_CDATA_OUT_20       213
#define ESP_SDHOST_CDATA_IN_21        214
#define ESP_SDHOST_CDATA_OUT_21       214
#define ESP_SDHOST_CDATA_IN_22        215
#define ESP_SDHOST_CDATA_OUT_22       215
#define ESP_SDHOST_CDATA_IN_23        216
#define ESP_SDHOST_CDATA_OUT_23       216
#define ESP_SDHOST_CDATA_IN_24        217
#define ESP_SDHOST_CDATA_OUT_24       217
#define ESP_SDHOST_CDATA_IN_25        218
#define ESP_SDHOST_CDATA_OUT_25       218
#define ESP_SDHOST_CDATA_IN_26        219
#define ESP_SDHOST_CDATA_OUT_26       219
#define ESP_SDHOST_CDATA_IN_27        220
#define ESP_SDHOST_CDATA_OUT_27       220
#define ESP_PRO_ALONEGPIO_IN0         221
#define ESP_PRO_ALONEGPIO_OUT0        221
#define ESP_PRO_ALONEGPIO_IN1         222
#define ESP_PRO_ALONEGPIO_OUT1        222
#define ESP_PRO_ALONEGPIO_IN2         223
#define ESP_PRO_ALONEGPIO_OUT2        223
#define ESP_PRO_ALONEGPIO_IN3         224
#define ESP_PRO_ALONEGPIO_OUT3        224
#define ESP_PRO_ALONEGPIO_IN4         225
#define ESP_PRO_ALONEGPIO_OUT4        225
#define ESP_PRO_ALONEGPIO_IN5         226
#define ESP_PRO_ALONEGPIO_OUT5        226
#define ESP_PRO_ALONEGPIO_IN6         227
#define ESP_PRO_ALONEGPIO_OUT6        227
#define ESP_PRO_ALONEGPIO_IN7         228
#define ESP_PRO_ALONEGPIO_OUT7        228
#define ESP_SYNCERR                   229
#define ESP_SYNCFOUND_FLAG            230
#define ESP_EVT_CNTL_IMMEDIATE_ABORT  231
#define ESP_LINKLBL                   232
#define ESP_DATA_EN                   233
#define ESP_DATA                      234
#define ESP_PKT_TX_ON                 235
#define ESP_PKT_RX_ON                 236
#define ESP_RW_TX_ON                  237
#define ESP_RW_RX_ON                  238
#define ESP_EVT_REQ_P                 239
#define ESP_EVT_STOP_P                240
#define ESP_BT_MODE_ON                241
#define ESP_GPIO_LC_DIAG0             242
#define ESP_GPIO_LC_DIAG1             243
#define ESP_GPIO_LC_DIAG2             244
#define ESP_CH                    245
#define ESP_RX_WINDOW                 246
#define ESP_UPDATE_RX                 247
#define ESP_RX_STATUS                 248
#define ESP_CLK_GPIO                  249
#define ESP_NBT_BLE                   250
#define ESP_USB_JTAG_TDO_BRIDGE       251
#define ESP_USB_JTAG_TRST             251
#define ESP_CORE1_GPIO_IN3            252
#define ESP_CORE1_GPIO_OUT3           252
#define ESP_CORE1_GPIO_IN4            253
#define ESP_CORE1_GPIO_OUT4           253
#define ESP_CORE1_GPIO_IN5            254
#define ESP_CORE1_GPIO_OUT5           254
#define ESP_CORE1_GPIO_IN6            255
#define ESP_CORE1_GPIO_OUT6           255
#define ESP_SIG_GPIO_OUT              256
#define ESP_GPIO_MAP_DATE             0x1907040

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_PINCTRL_ESP32S3_GPIO_SIGMAP_H_ */
