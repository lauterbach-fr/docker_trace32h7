# Copyright (c) 2023 Intel Corporation
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(cdns_nand)

target_sources(app PRIVATE src/main.c)
