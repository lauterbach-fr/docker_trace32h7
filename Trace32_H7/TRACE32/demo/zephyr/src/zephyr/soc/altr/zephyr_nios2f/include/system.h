/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_gen2_0' in SOPC Builder design 'ghrd_10m50da'
 * SOPC Builder design path: ../../ghrd_10m50da.sopcinfo
 *
 * Generated: Tue Dec 05 14:41:17 SGT 2017
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00200820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1c
#define ALT_CPU_DCACHE_BYPASS_MASK 0x80000000
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x00400020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 1
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_DIVISION_ERROR_EXCEPTION
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1c
#define ALT_CPU_NAME "nios2_gen2_0"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00200820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1c
#define NIOS2_DCACHE_BYPASS_MASK 0x80000000
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x00400020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 1
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_DIVISION_ERROR_EXCEPTION
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1c
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_16550_UART
#define __ALTERA_AVALON_I2C
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SPI
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_GENERIC_QUAD_SPI_CONTROLLER2
#define __ALTERA_MSGDMA
#define __ALTERA_NIOS2_GEN2
#define __ALTERA_ONCHIP_FLASH


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "MAX 10"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x201000
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x201000
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x201000
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "ghrd_10m50da"


/*
 * a_16550_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_a_16550_uart_0 altera_16550_uart
#define A_16550_UART_0_BASE 0x100000
#define A_16550_UART_0_FIFO_DEPTH 64
#define A_16550_UART_0_FIFO_MODE 1
#define A_16550_UART_0_FIO_HWFC 0
#define A_16550_UART_0_FIO_SWFC 0
#define A_16550_UART_0_FREQ 50000000
#define A_16550_UART_0_IRQ 1
#define A_16550_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define A_16550_UART_0_NAME "/dev/a_16550_uart_0"
#define A_16550_UART_0_SPAN 512
#define A_16550_UART_0_TYPE "altera_16550_uart"


/*
 * ext_flash_avl_csr configuration
 *
 */

#define ALT_MODULE_CLASS_ext_flash_avl_csr altera_generic_quad_spi_controller2
#define EXT_FLASH_AVL_CSR_BASE 0x100240
#define EXT_FLASH_AVL_CSR_FLASH_TYPE "Micron512"
#define EXT_FLASH_AVL_CSR_IRQ 6
#define EXT_FLASH_AVL_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define EXT_FLASH_AVL_CSR_IS_EPCS 0
#define EXT_FLASH_AVL_CSR_NAME "/dev/ext_flash_avl_csr"
#define EXT_FLASH_AVL_CSR_NUMBER_OF_SECTORS 1024
#define EXT_FLASH_AVL_CSR_PAGE_SIZE 256
#define EXT_FLASH_AVL_CSR_SECTOR_SIZE 65536
#define EXT_FLASH_AVL_CSR_SPAN 64
#define EXT_FLASH_AVL_CSR_SUBSECTOR_SIZE 4096
#define EXT_FLASH_AVL_CSR_TYPE "altera_generic_quad_spi_controller2"


/*
 * ext_flash_avl_mem configuration
 *
 */

#define ALT_MODULE_CLASS_ext_flash_avl_mem altera_generic_quad_spi_controller2
#define EXT_FLASH_AVL_MEM_BASE 0x8000000
#define EXT_FLASH_AVL_MEM_FLASH_TYPE "Micron512"
#define EXT_FLASH_AVL_MEM_IRQ -1
#define EXT_FLASH_AVL_MEM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define EXT_FLASH_AVL_MEM_IS_EPCS 0
#define EXT_FLASH_AVL_MEM_NAME "/dev/ext_flash_avl_mem"
#define EXT_FLASH_AVL_MEM_NUMBER_OF_SECTORS 1024
#define EXT_FLASH_AVL_MEM_PAGE_SIZE 256
#define EXT_FLASH_AVL_MEM_SECTOR_SIZE 65536
#define EXT_FLASH_AVL_MEM_SPAN 67108864
#define EXT_FLASH_AVL_MEM_SUBSECTOR_SIZE 4096
#define EXT_FLASH_AVL_MEM_TYPE "altera_generic_quad_spi_controller2"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER_0
#define ALT_TIMESTAMP_CLK none


/*
 * i2c_0 configuration
 *
 */

#define ALT_MODULE_CLASS_i2c_0 altera_avalon_i2c
#define I2C_0_BASE 0x100200
#define I2C_0_FIFO_DEPTH 16
#define I2C_0_FREQ 50000000
#define I2C_0_IRQ 4
#define I2C_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define I2C_0_NAME "/dev/i2c_0"
#define I2C_0_SPAN 64
#define I2C_0_TYPE "altera_avalon_i2c"
#define I2C_0_USE_AV_ST 0


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x201000
#define JTAG_UART_0_IRQ 0
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * led configuration
 *
 */

#define ALT_MODULE_CLASS_led altera_avalon_pio
#define LED_BASE 0x1002e0
#define LED_BIT_CLEARING_EDGE_REGISTER 0
#define LED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED_CAPTURE 0
#define LED_DATA_WIDTH 4
#define LED_DO_TEST_BENCH_WIRING 0
#define LED_DRIVEN_SIM_VALUE 0
#define LED_EDGE_TYPE "NONE"
#define LED_FREQ 50000000
#define LED_HAS_IN 0
#define LED_HAS_OUT 1
#define LED_HAS_TRI 0
#define LED_IRQ -1
#define LED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED_IRQ_TYPE "NONE"
#define LED_NAME "/dev/led"
#define LED_RESET_VALUE 0
#define LED_SPAN 16
#define LED_TYPE "altera_avalon_pio"


/*
 * msgdma_0_csr configuration
 *
 */

#define ALT_MODULE_CLASS_msgdma_0_csr altera_msgdma
#define MSGDMA_0_CSR_BASE 0x1002c0
#define MSGDMA_0_CSR_BURST_ENABLE 1
#define MSGDMA_0_CSR_BURST_WRAPPING_SUPPORT 1
#define MSGDMA_0_CSR_CHANNEL_ENABLE 0
#define MSGDMA_0_CSR_CHANNEL_ENABLE_DERIVED 0
#define MSGDMA_0_CSR_CHANNEL_WIDTH 8
#define MSGDMA_0_CSR_DATA_FIFO_DEPTH 32
#define MSGDMA_0_CSR_DATA_WIDTH 32
#define MSGDMA_0_CSR_DESCRIPTOR_FIFO_DEPTH 128
#define MSGDMA_0_CSR_DMA_MODE 0
#define MSGDMA_0_CSR_ENHANCED_FEATURES 0
#define MSGDMA_0_CSR_ERROR_ENABLE 0
#define MSGDMA_0_CSR_ERROR_ENABLE_DERIVED 0
#define MSGDMA_0_CSR_ERROR_WIDTH 8
#define MSGDMA_0_CSR_IRQ 3
#define MSGDMA_0_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define MSGDMA_0_CSR_MAX_BURST_COUNT 2
#define MSGDMA_0_CSR_MAX_BYTE 1024
#define MSGDMA_0_CSR_MAX_STRIDE 1
#define MSGDMA_0_CSR_NAME "/dev/msgdma_0_csr"
#define MSGDMA_0_CSR_PACKET_ENABLE 0
#define MSGDMA_0_CSR_PACKET_ENABLE_DERIVED 0
#define MSGDMA_0_CSR_PREFETCHER_ENABLE 0
#define MSGDMA_0_CSR_PROGRAMMABLE_BURST_ENABLE 0
#define MSGDMA_0_CSR_RESPONSE_PORT 2
#define MSGDMA_0_CSR_SPAN 32
#define MSGDMA_0_CSR_STRIDE_ENABLE 0
#define MSGDMA_0_CSR_STRIDE_ENABLE_DERIVED 0
#define MSGDMA_0_CSR_TRANSFER_TYPE "Aligned Accesses"
#define MSGDMA_0_CSR_TYPE "altera_msgdma"


/*
 * msgdma_0_descriptor_slave configuration
 *
 */

#define ALT_MODULE_CLASS_msgdma_0_descriptor_slave altera_msgdma
#define MSGDMA_0_DESCRIPTOR_SLAVE_BASE 0x1002f0
#define MSGDMA_0_DESCRIPTOR_SLAVE_BURST_ENABLE 1
#define MSGDMA_0_DESCRIPTOR_SLAVE_BURST_WRAPPING_SUPPORT 1
#define MSGDMA_0_DESCRIPTOR_SLAVE_CHANNEL_ENABLE 0
#define MSGDMA_0_DESCRIPTOR_SLAVE_CHANNEL_ENABLE_DERIVED 0
#define MSGDMA_0_DESCRIPTOR_SLAVE_CHANNEL_WIDTH 8
#define MSGDMA_0_DESCRIPTOR_SLAVE_DATA_FIFO_DEPTH 32
#define MSGDMA_0_DESCRIPTOR_SLAVE_DATA_WIDTH 32
#define MSGDMA_0_DESCRIPTOR_SLAVE_DESCRIPTOR_FIFO_DEPTH 128
#define MSGDMA_0_DESCRIPTOR_SLAVE_DMA_MODE 0
#define MSGDMA_0_DESCRIPTOR_SLAVE_ENHANCED_FEATURES 0
#define MSGDMA_0_DESCRIPTOR_SLAVE_ERROR_ENABLE 0
#define MSGDMA_0_DESCRIPTOR_SLAVE_ERROR_ENABLE_DERIVED 0
#define MSGDMA_0_DESCRIPTOR_SLAVE_ERROR_WIDTH 8
#define MSGDMA_0_DESCRIPTOR_SLAVE_IRQ -1
#define MSGDMA_0_DESCRIPTOR_SLAVE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MSGDMA_0_DESCRIPTOR_SLAVE_MAX_BURST_COUNT 2
#define MSGDMA_0_DESCRIPTOR_SLAVE_MAX_BYTE 1024
#define MSGDMA_0_DESCRIPTOR_SLAVE_MAX_STRIDE 1
#define MSGDMA_0_DESCRIPTOR_SLAVE_NAME "/dev/msgdma_0_descriptor_slave"
#define MSGDMA_0_DESCRIPTOR_SLAVE_PACKET_ENABLE 0
#define MSGDMA_0_DESCRIPTOR_SLAVE_PACKET_ENABLE_DERIVED 0
#define MSGDMA_0_DESCRIPTOR_SLAVE_PREFETCHER_ENABLE 0
#define MSGDMA_0_DESCRIPTOR_SLAVE_PROGRAMMABLE_BURST_ENABLE 0
#define MSGDMA_0_DESCRIPTOR_SLAVE_RESPONSE_PORT 2
#define MSGDMA_0_DESCRIPTOR_SLAVE_SPAN 16
#define MSGDMA_0_DESCRIPTOR_SLAVE_STRIDE_ENABLE 0
#define MSGDMA_0_DESCRIPTOR_SLAVE_STRIDE_ENABLE_DERIVED 0
#define MSGDMA_0_DESCRIPTOR_SLAVE_TRANSFER_TYPE "Aligned Accesses"
#define MSGDMA_0_DESCRIPTOR_SLAVE_TYPE "altera_msgdma"


/*
 * onchip_flash_0_csr configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_flash_0_csr altera_onchip_flash
#define ONCHIP_FLASH_0_CSR_BASE 0x200000
#define ONCHIP_FLASH_0_CSR_BYTES_PER_PAGE 8192
#define ONCHIP_FLASH_0_CSR_IRQ -1
#define ONCHIP_FLASH_0_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_FLASH_0_CSR_NAME "/dev/onchip_flash_0_csr"
#define ONCHIP_FLASH_0_CSR_READ_ONLY_MODE 0
#define ONCHIP_FLASH_0_CSR_SECTOR1_ENABLED 1
#define ONCHIP_FLASH_0_CSR_SECTOR1_END_ADDR 0x7fff
#define ONCHIP_FLASH_0_CSR_SECTOR1_START_ADDR 0
#define ONCHIP_FLASH_0_CSR_SECTOR2_ENABLED 1
#define ONCHIP_FLASH_0_CSR_SECTOR2_END_ADDR 0xffff
#define ONCHIP_FLASH_0_CSR_SECTOR2_START_ADDR 0x8000
#define ONCHIP_FLASH_0_CSR_SECTOR3_ENABLED 1
#define ONCHIP_FLASH_0_CSR_SECTOR3_END_ADDR 0x6ffff
#define ONCHIP_FLASH_0_CSR_SECTOR3_START_ADDR 0x10000
#define ONCHIP_FLASH_0_CSR_SECTOR4_ENABLED 1
#define ONCHIP_FLASH_0_CSR_SECTOR4_END_ADDR 0xb7fff
#define ONCHIP_FLASH_0_CSR_SECTOR4_START_ADDR 0x70000
#define ONCHIP_FLASH_0_CSR_SECTOR5_ENABLED 0
#define ONCHIP_FLASH_0_CSR_SECTOR5_END_ADDR 0xffffffff
#define ONCHIP_FLASH_0_CSR_SECTOR5_START_ADDR 0xffffffff
#define ONCHIP_FLASH_0_CSR_SPAN 8
#define ONCHIP_FLASH_0_CSR_TYPE "altera_onchip_flash"


/*
 * onchip_flash_0_data configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_flash_0_data altera_onchip_flash
#define ONCHIP_FLASH_0_DATA_BASE 0x0
#define ONCHIP_FLASH_0_DATA_BYTES_PER_PAGE 8192
#define ONCHIP_FLASH_0_DATA_IRQ -1
#define ONCHIP_FLASH_0_DATA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_FLASH_0_DATA_NAME "/dev/onchip_flash_0_data"
#define ONCHIP_FLASH_0_DATA_READ_ONLY_MODE 0
#define ONCHIP_FLASH_0_DATA_SECTOR1_ENABLED 1
#define ONCHIP_FLASH_0_DATA_SECTOR1_END_ADDR 0x7fff
#define ONCHIP_FLASH_0_DATA_SECTOR1_START_ADDR 0
#define ONCHIP_FLASH_0_DATA_SECTOR2_ENABLED 1
#define ONCHIP_FLASH_0_DATA_SECTOR2_END_ADDR 0xffff
#define ONCHIP_FLASH_0_DATA_SECTOR2_START_ADDR 0x8000
#define ONCHIP_FLASH_0_DATA_SECTOR3_ENABLED 1
#define ONCHIP_FLASH_0_DATA_SECTOR3_END_ADDR 0x6ffff
#define ONCHIP_FLASH_0_DATA_SECTOR3_START_ADDR 0x10000
#define ONCHIP_FLASH_0_DATA_SECTOR4_ENABLED 1
#define ONCHIP_FLASH_0_DATA_SECTOR4_END_ADDR 0xb7fff
#define ONCHIP_FLASH_0_DATA_SECTOR4_START_ADDR 0x70000
#define ONCHIP_FLASH_0_DATA_SECTOR5_ENABLED 0
#define ONCHIP_FLASH_0_DATA_SECTOR5_END_ADDR 0xffffffff
#define ONCHIP_FLASH_0_DATA_SECTOR5_START_ADDR 0xffffffff
#define ONCHIP_FLASH_0_DATA_SPAN 753664
#define ONCHIP_FLASH_0_DATA_TYPE "altera_onchip_flash"


/*
 * onchip_memory2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_0 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_0_BASE 0x400000
#define ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_0_DUAL_PORT 0
#define ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE "ghrd_10m50da_onchip_memory2_0"
#define ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 0
#define ONCHIP_MEMORY2_0_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_0_IRQ -1
#define ONCHIP_MEMORY2_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_0_NAME "/dev/onchip_memory2_0"
#define ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_0_SIZE_VALUE 131072
#define ONCHIP_MEMORY2_0_SPAN 131072
#define ONCHIP_MEMORY2_0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_0_WRITABLE 1


/*
 * spi_0 configuration
 *
 */

#define ALT_MODULE_CLASS_spi_0 altera_avalon_spi
#define SPI_0_BASE 0x100280
#define SPI_0_CLOCKMULT 1
#define SPI_0_CLOCKPHASE 1
#define SPI_0_CLOCKPOLARITY 0
#define SPI_0_CLOCKUNITS "Hz"
#define SPI_0_DATABITS 8
#define SPI_0_DATAWIDTH 16
#define SPI_0_DELAYMULT "1.0E-9"
#define SPI_0_DELAYUNITS "ns"
#define SPI_0_EXTRADELAY 0
#define SPI_0_INSERT_SYNC 0
#define SPI_0_IRQ 5
#define SPI_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SPI_0_ISMASTER 1
#define SPI_0_LSBFIRST 0
#define SPI_0_NAME "/dev/spi_0"
#define SPI_0_NUMSLAVES 1
#define SPI_0_PREFIX "spi_"
#define SPI_0_SPAN 32
#define SPI_0_SYNC_REG_DEPTH 2
#define SPI_0_TARGETCLOCK 128000u
#define SPI_0_TARGETSSDELAY "0.0"
#define SPI_0_TYPE "altera_avalon_spi"


/*
 * sysid configuration
 *
 */

#define ALT_MODULE_CLASS_sysid altera_avalon_sysid_qsys
#define SYSID_BASE 0x100300
#define SYSID_ID 0
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/sysid"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1512455752
#define SYSID_TYPE "altera_avalon_sysid_qsys"


/*
 * timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0 altera_avalon_timer
#define TIMER_0_ALWAYS_RUN 0
#define TIMER_0_BASE 0x1002a0
#define TIMER_0_COUNTER_SIZE 32
#define TIMER_0_FIXED_PERIOD 0
#define TIMER_0_FREQ 50000000
#define TIMER_0_IRQ 2
#define TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_LOAD_VALUE 49999
#define TIMER_0_MULT 0.001
#define TIMER_0_NAME "/dev/timer_0"
#define TIMER_0_PERIOD 1
#define TIMER_0_PERIOD_UNITS "ms"
#define TIMER_0_RESET_OUTPUT 0
#define TIMER_0_SNAPSHOT 1
#define TIMER_0_SPAN 32
#define TIMER_0_TICKS_PER_SEC 1000
#define TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
