/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

#include QMK_KEYBOARD_H
#include "keymap_italian_mac_ansi.h"
#include "sendstring_italian_mac_ansi.h"

#include "macros.h"
#include "combos.h"
#include "tap_dance.h"

enum layers{
    ZERO,
    ONE,
};

#define MO1   MO(ONE)
#define LT1   LT(ONE, KC_SPC)
#define LM1   LM(ONE, MOD_LCTL)
#define OSL1  OSL(ONE)

#define T_RB    TD(TD_RB)
#define T_HOME  TD(TD_HOME)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [ZERO] = LAYOUT_69_ansi(
        KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,      KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_Q,       KC_W,       KC_E,       KC_R,    KC_T,                 KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_A,       KC_S,       KC_D,       KC_F,    KC_G,                 KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_Z,       KC_X,       KC_C,       KC_V,    KC_B,       KC_NO,    KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_NO,    KC_NO,
        KC_NO,    KC_NO,      MO1,        LT1,                 KC_NO,      KC_NO,    LM1,      OSL1,    KC_NO,   KC_NO,   KC_NO),

    [ONE] = LAYOUT_69_ansi(
        KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,      KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,      KC_NO,      KC_NO,      SW_TAB,  KC_NO,                KC_NO,    IT_UNDS, IT_MINS, KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_1,       KC_2,       KC_3,       KC_4,    KC_5,                 KC_NO,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,     KC_NO,    KC_NO,
        KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,      KC_NO,    KC_NO,    T_RB,    KC_LCMD, KC_NO,   KC_NO,    KC_NO,    KC_NO,      
        KC_NO,    KC_NO,      KC_NO,      KC_SPC,              KC_NO,      KC_NO,    KC_BSPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO)
};
// clang-format on

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case IT_MINS:
        case IT_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
