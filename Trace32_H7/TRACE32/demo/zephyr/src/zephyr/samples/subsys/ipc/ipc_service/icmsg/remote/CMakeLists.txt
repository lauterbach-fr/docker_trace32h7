#
# Copyright (c) 2022 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: Apache-2.0
#

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(ipc_service_remote)

target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../common)

target_sources(app PRIVATE src/main.c)
