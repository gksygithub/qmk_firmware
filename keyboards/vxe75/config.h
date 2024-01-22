// Copyright 2024 WESTBERRY
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* SPI */
#define SPI_DRIVER SPIDQ
#define SPI_SCK_PIN A5
#define SPI_MOSI_PIN A7
#define SPI_MISO_PIN A6

/* Flash */
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN B14

/* LED */
#define LED_PIN_ON_STATE 0
#define LED_SCROLL_LOCK_PIN C0
#define LED_WIN_LOCK_PIN C1
#define LED_CAPS_LOCK_PIN C2
#define LED_NUM_LOCK_PIN C3

/* RGB Driver */
#define DRIVER_1_CS A15
#define DRIVER_2_CS B15
#define DRIVER_1_EN C4
#define DRIVER_2_EN C4