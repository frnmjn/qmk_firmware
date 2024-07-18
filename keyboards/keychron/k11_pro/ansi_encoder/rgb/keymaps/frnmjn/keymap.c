#include QMK_KEYBOARD_H

#include "keymap_italian_mac_ansi.h"
#include "sendstring_italian_mac_ansi.h"
#include "alias.h"
#include "tap_dance.h"
#include "combo.h"
#include "macro.h"


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[INS] = LAYOUT_69_ansi(
        NO,   NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,      NO,      NO,      NO,      NO,
        NO,   KC_Q,   KC_W,   TD_E,   KC_R,   KC_T,           KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    NO,      NO,      NO,     NO,
        NO,   HR_1,   HR_2,   HR_3,   HR_4,   KC_G,           KC_H,   HR_7,   HR_8,   HR_9,    HR_10,   NO,      NO,      NO,
        NO,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   BT,     KC_N,   KC_M,   TD_COMM,TD_DOT,  TD_SLSH, NO,      NO,
        NO,   NO,     GONUM,  GONOR,          NO,     NO,     BSPC,   HYPR,   NO,     NO,      NO
),

[NOR] = LAYOUT_69_ansi(
        NO,   NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,      NO,      NO,      NO,      NO,
        NO,   QUIT,   EXIT,   SW_TAB, SRC,    NO,             TD_QT,  UNDS,   TD_DQT, AMPR,    TD_PIPE,    NO,      NO,      NO,      NO,
        NO,   HOME,   TD_S,   TD_D,   TD_F,   RUN,            _SX,    _DN,    _UP,    _DN,     END,     NO,      NO,      NO,
        NO,   UNDO,   CUT,    TD_C,   PASTE,  REDO,   NO,     EXLM,   TD_RB,  TD_SB,  TD_CB,   PERC,    NO,      NO,
        NO,   NO,     NO,     NO,             NO,     NO,     DEL,    NO,     NO,     NO,      NO
),

[SYM] = LAYOUT_69_ansi(
        NO,   NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,      NO,      NO,      NO,      NO,
        NO,   NO,     NO,     NO,     NO,     NO,             NO,     NO,     NO,     NO,      NO,      NO,      NO,      NO,      NO,
        NO,   NO,     NO,     NO,     NO,     NO,             CIRC,   AT,     HASH,   TILD,    DLR,    NO,      NO,      NO,
        NO,   NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,      NO,      NO,      NO,
        NO,   NO,     NO,     SPC,            NO,     NO,     TRNS,   NO,     NO,     NO,      NO
),

[NUM] = LAYOUT_69_ansi(
        NO,   NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,      NO,      NO,      NO,      NO,
        NO,   NO,     NO,     NO,     NO,     NO,             PLUS,   KC_7,   KC_8,   KC_9,    SLS,     NO,      NO,      NO,      NO,
        NO,   CMD,    NO,     CTL,    KC_0,   NO,             MINS,   KC_4,   KC_5,   KC_6,    EQL,     NO,      NO,      NO,
        NO,   NO,     NO,     NO,     NO,     NO,     NO,     AST,    KC_1,   KC_2,   KC_3,    DOT,     NO,      NO,
        NO,   NO,     NO,     NO,             NO,     NO,     TRNS,   NO,     NO,     NO,      NO
),

};
// clang-format on

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case TD_E:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case UNDS:
        case MINS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    return true;
}
 
bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
   return true;
}
