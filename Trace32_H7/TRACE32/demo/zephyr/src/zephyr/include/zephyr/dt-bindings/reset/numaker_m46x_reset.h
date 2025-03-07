/*
 * Copyright (c) 2023 Nuvoton Technology Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_RESET_NUMAKER_M46X_RESET_H
#define ZEPHYR_INCLUDE_DT_BINDINGS_RESET_NUMAKER_M46X_RESET_H

/* Beginning of M460 BSP sys_reg.h reset module copy */

#define NUMAKER_SYS_IPRST0_PDMA0RST_Pos (2)

#define NUMAKER_SYS_IPRST0_EBIRST_Pos (3)

#define NUMAKER_SYS_IPRST0_EMAC0RST_Pos (5)

#define NUMAKER_SYS_IPRST0_SDH0RST_Pos (6)

#define NUMAKER_SYS_IPRST0_CRCRST_Pos (7)

#define NUMAKER_SYS_IPRST0_CCAPRST_Pos (8)

#define NUMAKER_SYS_IPRST0_HSUSBDRST_Pos (10)

#define NUMAKER_SYS_IPRST0_HBIRST_Pos (11)

#define NUMAKER_SYS_IPRST0_CRPTRST_Pos (12)

#define NUMAKER_SYS_IPRST0_KSRST_Pos (13)

#define NUMAKER_SYS_IPRST0_SPIMRST_Pos (14)

#define NUMAKER_SYS_IPRST0_HSUSBHRST_Pos (16)

#define NUMAKER_SYS_IPRST0_SDH1RST_Pos (17)

#define NUMAKER_SYS_IPRST0_PDMA1RST_Pos (18)

#define NUMAKER_SYS_IPRST0_CANFD0RST_Pos (20)

#define NUMAKER_SYS_IPRST0_CANFD1RST_Pos (21)

#define NUMAKER_SYS_IPRST0_CANFD2RST_Pos (22)

#define NUMAKER_SYS_IPRST0_CANFD3RST_Pos (23)

#define NUMAKER_SYS_IPRST0_BMCRST_Pos (28)

#define NUMAKER_SYS_IPRST1_GPIORST_Pos (1)

#define NUMAKER_SYS_IPRST1_TMR0RST_Pos (2)

#define NUMAKER_SYS_IPRST1_TMR1RST_Pos (3)

#define NUMAKER_SYS_IPRST1_TMR2RST_Pos (4)

#define NUMAKER_SYS_IPRST1_TMR3RST_Pos (5)

#define NUMAKER_SYS_IPRST1_ACMP01RST_Pos (7)

#define NUMAKER_SYS_IPRST1_I2C0RST_Pos (8)

#define NUMAKER_SYS_IPRST1_I2C1RST_Pos (9)

#define NUMAKER_SYS_IPRST1_I2C2RST_Pos (10)

#define NUMAKER_SYS_IPRST1_I2C3RST_Pos (11)

#define NUMAKER_SYS_IPRST1_QSPI0RST_Pos (12)

#define NUMAKER_SYS_IPRST1_SPI0RST_Pos (13)

#define NUMAKER_SYS_IPRST1_SPI1RST_Pos (14)

#define NUMAKER_SYS_IPRST1_SPI2RST_Pos (15)

#define NUMAKER_SYS_IPRST1_UART0RST_Pos (16)

#define NUMAKER_SYS_IPRST1_UART1RST_Pos (17)

#define NUMAKER_SYS_IPRST1_UART2RST_Pos (18)

#define NUMAKER_SYS_IPRST1_UART3RST_Pos (19)

#define NUMAKER_SYS_IPRST1_UART4RST_Pos (20)

#define NUMAKER_SYS_IPRST1_UART5RST_Pos (21)

#define NUMAKER_SYS_IPRST1_UART6RST_Pos (22)

#define NUMAKER_SYS_IPRST1_UART7RST_Pos (23)

#define NUMAKER_SYS_IPRST1_OTGRST_Pos (26)

#define NUMAKER_SYS_IPRST1_USBDRST_Pos (27)

#define NUMAKER_SYS_IPRST1_EADC0RST_Pos (28)

#define NUMAKER_SYS_IPRST1_I2S0RST_Pos (29)

#define NUMAKER_SYS_IPRST1_HSOTGRST_Pos (30)

#define NUMAKER_SYS_IPRST1_TRNGRST_Pos (31)

#define NUMAKER_SYS_IPRST2_SC0RST_Pos (0)

#define NUMAKER_SYS_IPRST2_SC1RST_Pos (1)

#define NUMAKER_SYS_IPRST2_SC2RST_Pos (2)

#define NUMAKER_SYS_IPRST2_I2C4RST_Pos (3)

#define NUMAKER_SYS_IPRST2_QSPI1RST_Pos (4)

#define NUMAKER_SYS_IPRST2_SPI3RST_Pos (6)

#define NUMAKER_SYS_IPRST2_SPI4RST_Pos (7)

#define NUMAKER_SYS_IPRST2_USCI0RST_Pos (8)

#define NUMAKER_SYS_IPRST2_PSIORST_Pos (10)

#define NUMAKER_SYS_IPRST2_DACRST_Pos (12)

#define NUMAKER_SYS_IPRST2_ECAP2RST_Pos (13)

#define NUMAKER_SYS_IPRST2_ECAP3RST_Pos (14)

#define NUMAKER_SYS_IPRST2_EPWM0RST_Pos (16)

#define NUMAKER_SYS_IPRST2_EPWM1RST_Pos (17)

#define NUMAKER_SYS_IPRST2_BPWM0RST_Pos (18)

#define NUMAKER_SYS_IPRST2_BPWM1RST_Pos (19)

#define NUMAKER_SYS_IPRST2_EQEI2RST_Pos (20)

#define NUMAKER_SYS_IPRST2_EQEI3RST_Pos (21)

#define NUMAKER_SYS_IPRST2_EQEI0RST_Pos (22)

#define NUMAKER_SYS_IPRST2_EQEI1RST_Pos (23)

#define NUMAKER_SYS_IPRST2_ECAP0RST_Pos (26)

#define NUMAKER_SYS_IPRST2_ECAP1RST_Pos (27)

#define NUMAKER_SYS_IPRST2_I2S1RST_Pos (29)

#define NUMAKER_SYS_IPRST2_EADC1RST_Pos (31)

#define NUMAKER_SYS_IPRST3_KPIRST_Pos (0)

#define NUMAKER_SYS_IPRST3_EADC2RST_Pos (6)

#define NUMAKER_SYS_IPRST3_ACMP23RST_Pos (7)

#define NUMAKER_SYS_IPRST3_SPI5RST_Pos (8)

#define NUMAKER_SYS_IPRST3_SPI6RST_Pos (9)

#define NUMAKER_SYS_IPRST3_SPI7RST_Pos (10)

#define NUMAKER_SYS_IPRST3_SPI8RST_Pos (11)

#define NUMAKER_SYS_IPRST3_SPI9RST_Pos (12)

#define NUMAKER_SYS_IPRST3_SPI10RST_Pos (13)

#define NUMAKER_SYS_IPRST3_UART8RST_Pos (16)

#define NUMAKER_SYS_IPRST3_UART9RST_Pos (17)

/* End of M460 BSP sys_reg.h reset module copy */

/* Beginning of M460 BSP sys.h reset module copy */

/*---------------------------------------------------------------------
 *  Module Reset Control Resister constant definitions.
 *---------------------------------------------------------------------
 */
#define NUMAKER_PDMA0_RST  ((0UL << 24) | NUMAKER_SYS_IPRST0_PDMA0RST_Pos)
#define NUMAKER_EBI_RST	   ((0UL << 24) | NUMAKER_SYS_IPRST0_EBIRST_Pos)
#define NUMAKER_EMAC0_RST  ((0UL << 24) | NUMAKER_SYS_IPRST0_EMAC0RST_Pos)
#define NUMAKER_SDH0_RST   ((0UL << 24) | NUMAKER_SYS_IPRST0_SDH0RST_Pos)
#define NUMAKER_CRC_RST	   ((0UL << 24) | NUMAKER_SYS_IPRST0_CRCRST_Pos)
#define NUMAKER_CCAP_RST   ((0UL << 24) | NUMAKER_SYS_IPRST0_CCAPRST_Pos)
#define NUMAKER_HSUSBD_RST ((0UL << 24) | NUMAKER_SYS_IPRST0_HSUSBDRST_Pos)
#define NUMAKER_HBI_RST	   ((0UL << 24) | NUMAKER_SYS_IPRST0_HBIRST_Pos)
#define NUMAKER_CRPT_RST   ((0UL << 24) | NUMAKER_SYS_IPRST0_CRPTRST_Pos)
#define NUMAKER_KS_RST	   ((0UL << 24) | NUMAKER_SYS_IPRST0_KSRST_Pos)
#define NUMAKER_SPIM_RST   ((0UL << 24) | NUMAKER_SYS_IPRST0_SPIMRST_Pos)
#define NUMAKER_HSUSBH_RST ((0UL << 24) | NUMAKER_SYS_IPRST0_HSUSBHRST_Pos)
#define NUMAKER_SDH1_RST   ((0UL << 24) | NUMAKER_SYS_IPRST0_SDH1RST_Pos)
#define NUMAKER_PDMA1_RST  ((0UL << 24) | NUMAKER_SYS_IPRST0_PDMA1RST_Pos)
#define NUMAKER_CANFD0_RST ((0UL << 24) | NUMAKER_SYS_IPRST0_CANFD0RST_Pos)
#define NUMAKER_CANFD1_RST ((0UL << 24) | NUMAKER_SYS_IPRST0_CANFD1RST_Pos)
#define NUMAKER_CANFD2_RST ((0UL << 24) | NUMAKER_SYS_IPRST0_CANFD2RST_Pos)
#define NUMAKER_CANFD3_RST ((0UL << 24) | NUMAKER_SYS_IPRST0_CANFD3RST_Pos)

#define NUMAKER_GPIO_RST   ((4UL << 24) | NUMAKER_SYS_IPRST1_GPIORST_Pos)
#define NUMAKER_TMR0_RST   ((4UL << 24) | NUMAKER_SYS_IPRST1_TMR0RST_Pos)
#define NUMAKER_TMR1_RST   ((4UL << 24) | NUMAKER_SYS_IPRST1_TMR1RST_Pos)
#define NUMAKER_TMR2_RST   ((4UL << 24) | NUMAKER_SYS_IPRST1_TMR2RST_Pos)
#define NUMAKER_TMR3_RST   ((4UL << 24) | NUMAKER_SYS_IPRST1_TMR3RST_Pos)
#define NUMAKER_ACMP01_RST ((4UL << 24) | NUMAKER_SYS_IPRST1_ACMP01RST_Pos)
#define NUMAKER_I2C0_RST   ((4UL << 24) | NUMAKER_SYS_IPRST1_I2C0RST_Pos)
#define NUMAKER_I2C1_RST   ((4UL << 24) | NUMAKER_SYS_IPRST1_I2C1RST_Pos)
#define NUMAKER_I2C2_RST   ((4UL << 24) | NUMAKER_SYS_IPRST1_I2C2RST_Pos)
#define NUMAKER_I2C3_RST   ((4UL << 24) | NUMAKER_SYS_IPRST1_I2C3RST_Pos)
#define NUMAKER_QSPI0_RST  ((4UL << 24) | NUMAKER_SYS_IPRST1_QSPI0RST_Pos)
#define NUMAKER_SPI0_RST   ((4UL << 24) | NUMAKER_SYS_IPRST1_SPI0RST_Pos)
#define NUMAKER_SPI1_RST   ((4UL << 24) | NUMAKER_SYS_IPRST1_SPI1RST_Pos)
#define NUMAKER_SPI2_RST   ((4UL << 24) | NUMAKER_SYS_IPRST1_SPI2RST_Pos)
#define NUMAKER_UART0_RST  ((4UL << 24) | NUMAKER_SYS_IPRST1_UART0RST_Pos)
#define NUMAKER_UART1_RST  ((4UL << 24) | NUMAKER_SYS_IPRST1_UART1RST_Pos)
#define NUMAKER_UART2_RST  ((4UL << 24) | NUMAKER_SYS_IPRST1_UART2RST_Pos)
#define NUMAKER_UART3_RST  ((4UL << 24) | NUMAKER_SYS_IPRST1_UART3RST_Pos)
#define NUMAKER_UART4_RST  ((4UL << 24) | NUMAKER_SYS_IPRST1_UART4RST_Pos)
#define NUMAKER_UART5_RST  ((4UL << 24) | NUMAKER_SYS_IPRST1_UART5RST_Pos)
#define NUMAKER_UART6_RST  ((4UL << 24) | NUMAKER_SYS_IPRST1_UART6RST_Pos)
#define NUMAKER_UART7_RST  ((4UL << 24) | NUMAKER_SYS_IPRST1_UART7RST_Pos)
#define NUMAKER_OTG_RST	   ((4UL << 24) | NUMAKER_SYS_IPRST1_OTGRST_Pos)
#define NUMAKER_USBD_RST   ((4UL << 24) | NUMAKER_SYS_IPRST1_USBDRST_Pos)
#define NUMAKER_EADC0_RST  ((4UL << 24) | NUMAKER_SYS_IPRST1_EADC0RST_Pos)
#define NUMAKER_I2S0_RST   ((4UL << 24) | NUMAKER_SYS_IPRST1_I2S0RST_Pos)
#define NUMAKER_HSOTG_RST  ((4UL << 24) | NUMAKER_SYS_IPRST1_HSOTGRST_Pos)
#define NUMAKER_TRNG_RST   ((4UL << 24) | NUMAKER_SYS_IPRST1_TRNGRST_Pos)

#define NUMAKER_SC0_RST	  ((8UL << 24) | NUMAKER_SYS_IPRST2_SC0RST_Pos)
#define NUMAKER_SC1_RST	  ((8UL << 24) | NUMAKER_SYS_IPRST2_SC1RST_Pos)
#define NUMAKER_SC2_RST	  ((8UL << 24) | NUMAKER_SYS_IPRST2_SC2RST_Pos)
#define NUMAKER_I2C4_RST  ((8UL << 24) | NUMAKER_SYS_IPRST2_I2C4RST_Pos)
#define NUMAKER_QSPI1_RST ((8UL << 24) | NUMAKER_SYS_IPRST2_QSPI1RST_Pos)
#define NUMAKER_SPI3_RST  ((8UL << 24) | NUMAKER_SYS_IPRST2_SPI3RST_Pos)
#define NUMAKER_SPI4_RST  ((8UL << 24) | NUMAKER_SYS_IPRST2_SPI4RST_Pos)
#define NUMAKER_USCI0_RST ((8UL << 24) | NUMAKER_SYS_IPRST2_USCI0RST_Pos)
#define NUMAKER_PSIO_RST  ((8UL << 24) | NUMAKER_SYS_IPRST2_PSIORST_Pos)
#define NUMAKER_DAC_RST	  ((8UL << 24) | NUMAKER_SYS_IPRST2_DACRST_Pos)
#define NUMAKER_EPWM0_RST ((8UL << 24) | NUMAKER_SYS_IPRST2_EPWM0RST_Pos)
#define NUMAKER_EPWM1_RST ((8UL << 24) | NUMAKER_SYS_IPRST2_EPWM1RST_Pos)
#define NUMAKER_BPWM0_RST ((8UL << 24) | NUMAKER_SYS_IPRST2_BPWM0RST_Pos)
#define NUMAKER_BPWM1_RST ((8UL << 24) | NUMAKER_SYS_IPRST2_BPWM1RST_Pos)
#define NUMAKER_EQEI0_RST ((8UL << 24) | NUMAKER_SYS_IPRST2_EQEI0RST_Pos)
#define NUMAKER_EQEI1_RST ((8UL << 24) | NUMAKER_SYS_IPRST2_EQEI1RST_Pos)
#define NUMAKER_EQEI2_RST ((8UL << 24) | NUMAKER_SYS_IPRST2_EQEI2RST_Pos)
#define NUMAKER_EQEI3_RST ((8UL << 24) | NUMAKER_SYS_IPRST2_EQEI3RST_Pos)
#define NUMAKER_ECAP0_RST ((8UL << 24) | NUMAKER_SYS_IPRST2_ECAP0RST_Pos)
#define NUMAKER_ECAP1_RST ((8UL << 24) | NUMAKER_SYS_IPRST2_ECAP1RST_Pos)
#define NUMAKER_ECAP2_RST ((8UL << 24) | NUMAKER_SYS_IPRST2_ECAP2RST_Pos)
#define NUMAKER_ECAP3_RST ((8UL << 24) | NUMAKER_SYS_IPRST2_ECAP3RST_Pos)
#define NUMAKER_I2S1_RST  ((8UL << 24) | NUMAKER_SYS_IPRST2_I2S1RST_Pos)
#define NUMAKER_EADC1_RST ((8UL << 24) | NUMAKER_SYS_IPRST2_EADC1RST_Pos)

#define NUMAKER_KPI_RST	   ((0x18UL << 24) | NUMAKER_SYS_IPRST3_KPIRST_Pos)
#define NUMAKER_EADC2_RST  ((0x18UL << 24) | NUMAKER_SYS_IPRST3_EADC2RST_Pos)
#define NUMAKER_ACMP23_RST ((0x18UL << 24) | NUMAKER_SYS_IPRST3_ACMP23RST_Pos)
#define NUMAKER_SPI5_RST   ((0x18UL << 24) | NUMAKER_SYS_IPRST3_SPI5RST_Pos)
#define NUMAKER_SPI6_RST   ((0x18UL << 24) | NUMAKER_SYS_IPRST3_SPI6RST_Pos)
#define NUMAKER_SPI7_RST   ((0x18UL << 24) | NUMAKER_SYS_IPRST3_SPI7RST_Pos)
#define NUMAKER_SPI8_RST   ((0x18UL << 24) | NUMAKER_SYS_IPRST3_SPI8RST_Pos)
#define NUMAKER_SPI9_RST   ((0x18UL << 24) | NUMAKER_SYS_IPRST3_SPI9RST_Pos)
#define NUMAKER_SPI10_RST  ((0x18UL << 24) | NUMAKER_SYS_IPRST3_SPI10RST_Pos)
#define NUMAKER_UART8_RST  ((0x18UL << 24) | NUMAKER_SYS_IPRST3_UART8RST_Pos)
#define NUMAKER_UART9_RST  ((0x18UL << 24) | NUMAKER_SYS_IPRST3_UART9RST_Pos)

/* End of M460 BSP sys.h reset module copy */

#endif
