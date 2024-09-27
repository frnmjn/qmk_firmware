enum combos{
	C_BSPC,
  C_CW_TOGG,
  C_HAPPY,
  C_SAD,
	COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM c_esc[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM c_cw_togg[] = {KC_A, KC_SCLN, COMBO_END};
const uint16_t PROGMEM c_happy[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM c_sad[] = {KC_S, KC_D, KC_F, COMBO_END};

combo_t key_combos[] = {
  [C_BSPC] = COMBO(c_esc, KC_BSPC),
  [C_CW_TOGG] = COMBO_ACTION(c_cw_togg),
  [C_HAPPY] = COMBO_ACTION(c_happy),
  [C_SAD] = COMBO_ACTION(c_sad),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case C_CW_TOGG:
      if (pressed) {
        caps_word_on();
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
  }
}

