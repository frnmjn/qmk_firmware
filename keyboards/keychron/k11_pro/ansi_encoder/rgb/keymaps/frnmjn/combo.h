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

const uint16_t PROGMEM c_tab[] = {HR_8, HR_9, COMBO_END};
const uint16_t PROGMEM c_enter[] = {HR_3, HR_4, COMBO_END};
const uint16_t PROGMEM c_esc[] = {HR_7, HR_8, COMBO_END};
const uint16_t PROGMEM c_eql[] = {HR_2, HR_3, COMBO_END};
const uint16_t PROGMEM c_cw_togg[] = {HR_1, HR_10, COMBO_END};
const uint16_t PROGMEM c_diamond[] = {COMM, DOT, COMBO_END};
const uint16_t PROGMEM c_happy[] = {HR_7, HR_8, HR_9, COMBO_END};
const uint16_t PROGMEM c_sad[] = {HR_2, HR_3, HR_4, COMBO_END};
const uint16_t PROGMEM c_exlm[] = {T_E, KC_R, COMBO_END};
const uint16_t PROGMEM c_tild[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM c_hash[] = {KC_M, COMM, COMBO_END};
const uint16_t PROGMEM c_at[] = {KC_W, T_E, COMBO_END};
const uint16_t PROGMEM c_regex[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_unds[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM c_bsls[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM c_mins[] = {KC_U, KC_I, COMBO_END};

combo_t key_combos[] = {
  [C_TAB] = COMBO(c_tab, TAB),
	[C_ENTER] = COMBO(c_enter, ENT),
	[C_ESC] = COMBO(c_esc, ESC),
  [C_EQL] = COMBO(c_eql, EQL),
  [C_CW_TOGG] = COMBO_ACTION(c_cw_togg),
  [C_DIAMOND] = COMBO_ACTION(c_diamond),
  [C_HAPPY] = COMBO_ACTION(c_happy),
  [C_SAD] = COMBO_ACTION(c_sad),
  [C_EXLM] = COMBO_ACTION(c_exlm),
  [C_TILD] = COMBO_ACTION(c_tild),
  [C_HASH] = COMBO_ACTION(c_hash),
  [C_AT] = COMBO_ACTION(c_at),
  [C_REGEX] = COMBO(c_regex, CIRC),
  [C_UNDS] = COMBO(c_unds, UNDS),
  [C_BSLS] = COMBO(c_bsls, BSLS),
  [C_MINS] = COMBO(c_mins, MINS),
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

