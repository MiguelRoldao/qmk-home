/* Copyright 2022 James White <jamesmnw@gmail.com>
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
#pragma once

#define LAYOUT_Swoopiest( \
    l01, l02, l03, l04, l05,              r05, r04, r03, r02, r01, \
    l06, l07, l08, l09, l10,              r10, r09, r08, r07, r06, \
    l12, l13, l14, l15, l16,              r16, r15, r14, r13, r12, \
                        l11, l17,    r17, r11,                     \
              l18, l19, l20, l21,    r21, r20, r19, r18            \
) { \
    {   l01,   l02,   l03,   l04,   l05, KC_NO }, \
    {   l06,   l07,   l08,   l09,   l10,   l11 }, \
    {   l12,   l13,   l14,   l15,   l16,   l17 }, \
    { KC_NO, KC_NO,   l18,   l19,   l20,   l21 }, \
\
    {   r01,   r02,   r03,   r04,   r05, KC_NO }, \
    {   r06,   r07,   r08,   r09,   r10,   r11 }, \
    {   r12,   r13,   r14,   r15,   r16,   r17 }, \
    { KC_NO, KC_NO,   r18,   r19,   r20,   r21 }, \
}

//    { KC_NO,   r05,   r04,   r03,   r02,   r01 },
//    {   r11,   r10,   r09,   r08,   r07,   r06 },
//    {   r17,   r16,   r15,   r14,   r13,   r12 },
//    {   r21,   r20,   r19,   r18, KC_NO, KC_NO },

