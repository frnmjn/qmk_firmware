enum combos{
  C_TAB,
	C_ENTER,
	C_ESC,
  C_GOSYM,
  C_CW_TOGG,
  C_DIAMOND,
	COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM c_tab[] = {HR_8, HR_9, COMBO_END};
const uint16_t PROGMEM c_enter[] = {HR_3, HR_4, COMBO_END};
const uint16_t PROGMEM c_esc[] = {HR_7, HR_8, COMBO_END};
const uint16_t PROGMEM c_gosym[] = {HR_2, HR_3, COMBO_END};
const uint16_t PROGMEM c_cw_togg[] = {HR_1, HR_10, COMBO_END};
const uint16_t PROGMEM c_diamond[] = {TD_COMM, TD_DOT, COMBO_END};

combo_t key_combos[] = {
  [C_TAB] = COMBO(c_tab, TAB),
	[C_ENTER] = COMBO(c_enter, ENT),
	[C_ESC] = COMBO(c_esc, ESC),
  [C_GOSYM] = COMBO(c_gosym, GOSYM),
  [C_CW_TOGG] = COMBO_ACTION(c_cw_togg),
  [C_DIAMOND] = COMBO_ACTION(c_diamond),
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
  }
}
