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
    K00, K01, K02, K03, K04,                               K0B,           K0E, K0F, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C,      K1E, K1F, \
    K20,      K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D,      K3F, \
         K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B,      K4D, K4E, K4F, \
    K50, K51,      K53,           K56,                K5A, K5B, K5C, K5D, K5E, K5F  \
) { \
   {K00, K01, K02, K03, K04, ___, ___, ___, ___, ___, ___, K0B, ___, ___, K0E, K0F}, \
   {K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, ___, K1E, K1F}, \
   {K20, ___, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F}, \
   {K30, ___, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, ___, K3F}, \
   {___, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, ___, K4D, K4E, K4F}, \
   {K50, K51, ___, K53, ___, ___, K56, ___, ___, ___, K5A, K5B, K5C, K5D, K5E, K5F} \
}
