
#include QMK_KEYBOARD_H
#include "alias.h"
#include "tap_dance.h"
//#include "combo.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_69_ansi(
		    BASE_ESC,        BASE_1,        BASE_2,        BASE_3,        BASE_4,        BASE_5,        BASE_6,        BASE_7,        BASE_8,        BASE_9,        BASE_0,     BASE_MINS,      BASE_EQL,       BASE_NO,       BASE_BT,
		     BASE_NO,        BASE_Q,        BASE_W,        BASE_E,        BASE_R,        BASE_T,        BASE_Y,        BASE_U,        BASE_I,        BASE_O,        BASE_P,     BASE_LBRC,     BASE_RBRC,     BASE_BSLS,     BASE_DTUP,
		    BASE_TAB,        BASE_A,        BASE_S,        BASE_D,        BASE_F,        BASE_G,        BASE_H,        BASE_J,        BASE_K,        BASE_L,     BASE_SCLN,     BASE_QUOT,       BASE_NO,   BASE_DTDOWN,
		    BASE_SFT,        BASE_Z,        BASE_X,        BASE_C,        BASE_V,        BASE_B,       BASE_NO,        BASE_N,        BASE_M,     BASE_COMM,      BASE_DOT,     BASE_SLSH,      BASE_SFT,       BASE_UP,
		    BASE_CTL,      BASE_GUI,      BASE_ALT,   BASE_SPCNAV,       BASE_NO,       BASE_NO,     BASE_BSPC,       BASE_NO,     BASE_LEFT,     BASE_DOWN,    BASE_RIGHT
),
[NAV] = LAYOUT_69_ansi(
		      NAV_NO,        NAV_F1,        NAV_F2,        NAV_F3,        NAV_F4,        NAV_F5,        NAV_F6,        NAV_F7,        NAV_F8,        NAV_F9,        NAV_F9,       NAV_F10,       NAV_F11,       NAV_F12,        NAV_NO,
		      NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_UP,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,
		      NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,      NAV_HOME,      NAV_LEFT,      NAV_DOWN,     NAV_RIGHT,       NAV_END,        NAV_NO,        NAV_NO,        NAV_NO,
		      NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,
		      NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO,       NAV_DEL,        NAV_NO,        NAV_NO,        NAV_NO,        NAV_NO
),

};
// clang-format on

//const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
  
//};
