// Copyright 2022 mjohns
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* layer config */
#define TAPPING_TOGGLE 1

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* tcpkump */
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the Serial implementation uses the PIO0 peripheral

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Home Row Mods
#define TAPPING_TERM 180
#define CHORDAL_HOLD
#define PERMISSIVE_HOLD
