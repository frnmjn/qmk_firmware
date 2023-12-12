enum combos{
  C_TAB,
	C_ENTER,
	C_ESC,
	C_CTX,
  C_TERM,
  C_SEL_ALL,
  C_GOSYM,
  C_WIN_MAX,
  C_WIN_SX,
  C_WIN_DX,
  C_CLEAR,
  C_HISTORY,
  C_CW_TOGG,
  C_DIAMOND,
  C_HOMEROW,
  C_NEW_TAB,
	COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM c_tab[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM c_enter[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM c_esc[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM c_ctx[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM c_term[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM c_sel_all[] = { KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM c_gosym[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM c_win_dx[] = {KC_K, KC_L, TD_SCLN, COMBO_END};
const uint16_t PROGMEM c_win_sx[] = {KC_A, KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM c_win_max[] = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM c_clear[] = {KC_D, KC_L, COMBO_END};
const uint16_t PROGMEM c_history[] = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM c_cw_togg[] = {KC_A, TD_SCLN, COMBO_END};
const uint16_t PROGMEM c_diamond[] = {TD_COMM, TD_DOT, COMBO_END};
const uint16_t PROGMEM c_homerow[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM c_new_tab[] = {KC_R, KC_T, COMBO_END};

combo_t key_combos[] = {
  [C_TAB] = COMBO(c_tab, TAB),
	[C_ENTER] = COMBO(c_enter, ENT),
	[C_ESC] = COMBO(c_esc, ESC),
	[C_CTX] = COMBO_ACTION(c_ctx),
  [C_TERM] = COMBO_ACTION(c_term),
  [C_SEL_ALL] = COMBO_ACTION(c_sel_all),
  [C_WIN_MAX] = COMBO_ACTION(c_win_max),
  [C_WIN_DX] = COMBO_ACTION(c_win_dx),
  [C_WIN_SX] = COMBO_ACTION(c_win_sx),
  [C_GOSYM] = COMBO(c_gosym, GOSYM),
  [C_CLEAR] = COMBO_ACTION(c_clear),
  [C_HISTORY] = COMBO_ACTION(c_history),
  [C_CW_TOGG] = COMBO_ACTION(c_cw_togg),
  [C_DIAMOND] = COMBO_ACTION(c_diamond),
  [C_HOMEROW] = COMBO_ACTION(c_homerow),
  [C_NEW_TAB] = COMBO_ACTION(c_new_tab),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case C_CTX:
      if (pressed) {
		    SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_SPC)SS_UP(X_LCTL)SS_UP(X_SPC));
      }
      break;
    case C_TERM:
      if (pressed) {
		    SEND_STRING(SS_DOWN(X_LCMD)SS_DOWN(X_LALT)SS_TAP(X_T)SS_UP(X_LCMD)SS_UP(X_LALT));
      }
      break;
    case C_SEL_ALL:
      if (pressed) {
		    SEND_STRING(SS_LCMD("a"));
      }
      break;
    case C_WIN_MAX:
      if (pressed) {
		    SEND_STRING(SS_LCMD("m"));
      }
      break;
    case C_WIN_DX:
      if (pressed) {
		    SEND_STRING(SS_LCMD("r"));
      }
      break;
    case C_WIN_SX:
      if (pressed) {
		    SEND_STRING(SS_LCMD("l"));
      }
      break;
    case C_CLEAR:
      if (pressed) {
		    SEND_STRING(SS_LCMD("k"));
      }
      break;
    case C_HISTORY:
      if (pressed) {
		    SEND_STRING(SS_LCMD("y"));
      }
      break;
    case C_CW_TOGG:
      if (pressed) {
        caps_word_on();
      }
      break;
    case C_DIAMOND:
      if (pressed) {
		    SEND_STRING("<>" SS_TAP(X_LEFT));
      }
      break;
    case C_HOMEROW:
      if (pressed) {
		    SEND_STRING(SS_LCMD("h"));
      } 
      break;
    case C_NEW_TAB:
      if (pressed) {
		    SEND_STRING(SS_LCMD("t"));
      } 
      break;
  }
}
