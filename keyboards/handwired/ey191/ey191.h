// Copyright 2022 Juan Rivera (@c0qu1)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

#define ___ KC_NO

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT_ansi65x( \
    K01, K02, K03, K04, K05,                               K0C,           K0F, K0G, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,      K1F, K1G, \
    K21,      K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, K2G, \
    K31,      K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E,      K3G, \
         K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C,      K4E, K4F, K4G, \
    K51, K52,      K54,           K57,                K5B, K5C, K5D, K5E, K5F, K5G  \
) { \
   {K01, K02, K03, K04, K05, ___, ___, ___, ___, ___, ___, K0C, ___, ___, K0F, K0G}, \
   {K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, ___, K1F, K1G}, \
   {K21, ___, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, K2G}, \
   {K31, ___, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, ___, K3G}, \
   {___, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, ___, K4E, K4F, K4G}, \
   {K51, K52, ___, K54, ___, ___, K57, ___, ___, ___, K5B, K5C, K5D, K5E, K5F, K5G } \
}
