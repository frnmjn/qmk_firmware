// clang-format off
enum combos{
  C_TAB,
  C_ENTER,
  C_ESC,
  C_EQL,
  C_CW_TOGG,
  C_DIAMOND,
  C_HAPPY,
  C_SAD,
  C_EXLM,
  C_TILD,
  C_HASH,
  C_AT,
  C_REGEX,
  C_UNDS,
  C_BSLS,
  C_MINS,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM c_tab[]      = {_HR_7, _HR_8, COMBO_END};
const uint16_t PROGMEM c_enter[]    = {_HR_2, _HR_3, COMBO_END};
const uint16_t PROGMEM c_esc[]      = {_HR_6, _HR_7, COMBO_END};
const uint16_t PROGMEM c_eql[]      = {_HR_1, _HR_2, COMBO_END};
const uint16_t PROGMEM c_cw_togg[]  = {_HR_3, _HR_6, COMBO_END};
const uint16_t PROGMEM c_diamond[]  = {_COMM, _DOT, COMBO_END};
const uint16_t PROGMEM c_happy[]    = {_HR_6, _HR_7, _HR_8, COMBO_END};
const uint16_t PROGMEM c_sad[]      = {_HR_1, _HR_2, _HR_3, COMBO_END};
const uint16_t PROGMEM c_exlm[]     = {_T_E, KC_R, COMBO_END};
const uint16_t PROGMEM c_tild[]     = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM c_hash[]     = {KC_M, _COMM, COMBO_END};
const uint16_t PROGMEM c_at[]       = {KC_W, _T_E, COMBO_END};
const uint16_t PROGMEM c_regex[]    = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_unds[]     = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM c_bsls[]     = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM c_mins[]     = {KC_U, KC_I, COMBO_END};

combo_t key_combos[] = {
  [C_TAB] = COMBO(c_tab, _TAB),
  [C_ENTER] = COMBO(c_enter, _ENT),
  [C_ESC] = COMBO(c_esc, _ESC),
  [C_EQL] = COMBO(c_eql, _EQL),
  [C_CW_TOGG] = COMBO_ACTION(c_cw_togg),
  [C_DIAMOND] = COMBO_ACTION(c_diamond),
  [C_HAPPY] = COMBO_ACTION(c_happy),
  [C_SAD] = COMBO_ACTION(c_sad),
  [C_EXLM] = COMBO_ACTION(c_exlm),
  [C_TILD] = COMBO_ACTION(c_tild),
  [C_HASH] = COMBO_ACTION(c_hash),
  [C_AT] = COMBO_ACTION(c_at),
  [C_REGEX] = COMBO(c_regex, _CIRC),
  [C_UNDS] = COMBO(c_unds, _UNDS),
  [C_BSLS] = COMBO(c_bsls, _BSLS),
  [C_MINS] = COMBO(c_mins, _MINS),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
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
    case C_HAPPY:
      if (pressed) {
		    SEND_STRING(":-)");
      }
      break;
    case C_SAD:
      if (pressed) {
		    SEND_STRING(":-(");
      }
      break;
    case C_EXLM:
      if (pressed) {
		    SEND_STRING("!");
      }
      break;
    case C_TILD:
      if (pressed) {
		    SEND_STRING("~");
      }
      break;
    case C_HASH:
      if (pressed) {
		    SEND_STRING("#");
      }
      break;
    case C_AT:
      if (pressed) {
		    SEND_STRING("@");
      }
      break;
  }
}
// clang-format on
