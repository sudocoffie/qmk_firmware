/* Copyright 2018 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef TYPEWRITER_H
#define TYPEWRITER_H

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K10, K11, K12, K13, K14, K15, \
        K16, K17, K18, K19, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K30, \
        K31,      K32, K33, K34, K35, K36, K37, K38, K39, K40, K41, K42, K43, K44, \
        K45, K46, K47, K48, K49, K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, \
                            K60,                K61 \
) \
{ \
    { K00,   K01,   K02,   K03,   K04, K05,   K06,   K07,   K08,   K09, K10,   K11,   K12,   K13,   K14,   K15 }, \
    { KC_NO, K16,   K17,   K18,   K19,   K20, K21,   K22,   K23,   K24, K25,   K26,   K27,   K28,   K29,   K30 }, \
    { KC_NO, K31,   KC_NO, K32,   K33,   K34,   K35, K36,   K37,   K38, K39,   K40,   K41,   K42,   K43,   K44 }, \
    { KC_NO, K45,   K46,   K47,   K48,   K49, K50,   K51,   K52,   K53, K54,   K55,   K56,   K57,   K58,   K59 }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, K60, KC_NO, KC_NO, KC_NO, KC_NO, K61, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
}
#endif
