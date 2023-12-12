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
        NO,   KC_Q,   KC_W,   T_E,    KC_R,   KC_T,           KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    NO,      NO,      NO,     NO,
        NO,   HR_1,   HR_2,   HR_3,   HR_4,   KC_G,           KC_H,   HR_7,   HR_8,   HR_9,    HR_10,   NO,      NO,      NO,
        NO,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   BT,     KC_N,   KC_M,   COMM,   DOT,     SLSH,    NO,      NO,
        NO,   NO,     GONUM,  GONOR,          NO,     NO,     BSPC,   _MEH,   NO,     NO,      NO
),

[NOR] = LAYOUT_69_ansi(
        NO,   NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,      NO,      NO,      NO,      NO,
        NO,   NO,     NO,     SW_TAB, SRC,    PGUP,           NO,     T_QT,   T_DQT,  T_PIPE,  NO,      NO,      NO,      NO,      NO,
        NO,   T_HOME, ALT,    CTL,    SFT,    PGDN,           _SX,    _DN,    _UP,    _DX,     END,     NO,      NO,      NO,
        NO,   UNDO,   CUT,    COPY,   PASTE,  REDO,   NO,     NO,     T_RB,   T_SB,   T_CB,    T_PERC,  NO,      NO,
        NO,   NO,     NO,     NO,             NO,     NO,     DEL,    NO,     NO,     NO,      NO
),

[NUM] = LAYOUT_69_ansi(
        NO,   NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,      NO,      NO,      NO,      NO,
        NO,   NO,     NO,     NO,     NO,     NO,             NO,     KC_7,   KC_8,   KC_9,    AST,     NO,      NO,      NO,      NO,
        NO,   CMD,    ALT,    CTL,    KC_0,   NO,             MINS,   KC_4,   KC_5,   KC_6,    PLUS,    NO,      NO,      NO,
        NO,   NO,     NO,     NO,     NO,     NO,     NO,     DOT,    KC_1,   KC_2,   KC_3,    SLSH,    NO,      NO,
        NO,   NO,     NO,     NO,             NO,     NO,     TRNS,   NO,     NO,     NO,      NO
),

};
// clang-format on

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case T_E:
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
    switch(keycode) {
        case HR_1:
        case HR_2:
        case HR_3:
        case HR_4:
        case HR_7:
        case HR_8:
        case HR_9:
        case HR_10:
        case COMM:
        case DOT:
        case CIRC:
        case ESC:
        case SLSH:
        case ENT:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case HR_10:
            register_code16((!shifted) ? SCLN : COLN);
            break;
        case COMM:
            register_code16((!shifted) ? COMM : IT_LABK);
            break;
        case DOT:
            register_code16((!shifted) ? DOT : IT_RABK);
            break;
        case CIRC:
            register_code16((!shifted) ? CIRC : DLR);
            break;
        case ESC:
            register_code16((!shifted) ? ESC : AMPR);
            break;
        case SLSH:
            register_code16((!shifted) ? SLSH : IT_QUES);
            break;
        case ENT:
            register_code16((!shifted) ? ENT : AST);
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case HR_10:
            unregister_code16((!shifted) ? SCLN : COLN);
            break;
        case COMM:
            unregister_code16((!shifted) ? COMM : IT_LABK);
            break;
        case DOT:
            unregister_code16((!shifted) ? DOT : IT_RABK);
            break;
        case CIRC:
            unregister_code16((!shifted) ? CIRC : DLR);
            break;
        case ESC:
            unregister_code16((!shifted) ? ESC : AMPR);
            break;
        case SLSH:
            unregister_code16((!shifted) ? SLSH : IT_QUES);
            break;
        case ENT:
            unregister_code16((!shifted) ? ENT : AST);
            break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}
 
