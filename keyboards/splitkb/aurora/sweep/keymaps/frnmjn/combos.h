// clang-format off
enum combos{
  C_TAB,
  C_ENTER,
  C_ESC,
  C_PIPE,
  C_CW_TOGG,
  C_DCOLN,
  C_HAPPY,
  C_SAD,
  C_AMPE,
  C_TILD,
  C_HASH,
  C_AT,
  C_REGEX,
  C_UNDS,
  C_BSLS,
  C_DQT,
  C_QUOT,
  C_MIX,
  C_NUM,
  C_RB,
  C_CB,
  C_SB,
  C_F5,
  C_F12,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM c_tab[]      = {_HR_6, _HR_7, COMBO_END};
const uint16_t PROGMEM c_enter[]    = {_HR_2, _HR_3, COMBO_END};
const uint16_t PROGMEM c_esc[]      = {_HR_6, _HR_7, _HR_8, COMBO_END};
const uint16_t PROGMEM c_pipe[]     = {KC_R, _HR_3, COMBO_END};
const uint16_t PROGMEM c_cw_togg[]  = {_HR_1, _HR_2, _HR_3, COMBO_END};
const uint16_t PROGMEM c_dcoln[]    = {_COMM, _DOT, COMBO_END};
const uint16_t PROGMEM c_mix[]      = {_HR_7, _HR_8, COMBO_END};
const uint16_t PROGMEM c_num[]      = {_HR_1, _HR_2, COMBO_END};
const uint16_t PROGMEM c_happy[]    = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM c_sad[]      = {KC_M, _COMM, _DOT, COMBO_END};
const uint16_t PROGMEM c_ampe[]     = {_T_E, KC_R, COMBO_END};
const uint16_t PROGMEM c_tild[]     = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM c_hash[]     = {_T_E, _HR_2, COMBO_END};
const uint16_t PROGMEM c_at[]       = {KC_W, _T_E, COMBO_END};
const uint16_t PROGMEM c_regex[]    = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_unds[]     = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM c_bsls[]     = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM c_dqt[]      = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM c_quot[]     = {KC_M, _COMM, COMBO_END};
const uint16_t PROGMEM c_rb[]       = {KC_U, _HR_6, COMBO_END};
const uint16_t PROGMEM c_cb[]       = {KC_I, _HR_7, COMBO_END};
const uint16_t PROGMEM c_sb[]       = {KC_O, _HR_8, COMBO_END};
const uint16_t PROGMEM c_f5[]       = {_HR_0, _HR_1, _HR_2, _HR_3, COMBO_END};
const uint16_t PROGMEM c_f12[]      = {_HR_6, _HR_7, _HR_8, _HR_9, COMBO_END};

combo_t key_combos[] = {
  [C_TAB]     = COMBO(c_tab, _TAB),
  [C_ENTER]   = COMBO(c_enter, _ENT),
  [C_ESC]     = COMBO(c_esc, _ESC),
  [C_PIPE]    = COMBO(c_pipe, _PIPE),
  [C_CW_TOGG] = COMBO_ACTION(c_cw_togg),
  [C_DCOLN]   = COMBO_ACTION(c_dcoln),
  [C_HAPPY]   = COMBO_ACTION(c_happy),
  [C_SAD]     = COMBO_ACTION(c_sad),
  [C_MIX]     = COMBO_ACTION(c_mix),
  [C_NUM]     = COMBO_ACTION(c_num),
  [C_AMPE]    = COMBO(c_ampe, _AMPR),
  [C_TILD]    = COMBO(c_tild, _TILD),
  [C_HASH]    = COMBO(c_hash, _HASH),
  [C_AT]      = COMBO(c_at, _AT),
  [C_REGEX]   = COMBO(c_regex, _CIRC),
  [C_UNDS]    = COMBO(c_unds, _UNDS),
  [C_BSLS]    = COMBO(c_bsls, _BSLS),
  [C_DQT]     = COMBO(c_dqt, _DQT),
  [C_QUOT]    = COMBO(c_quot, _QUOT),
  [C_RB]      = COMBO(c_rb, _LPRN),
  [C_CB]      = COMBO(c_cb, _LCBR),
  [C_SB]      = COMBO(c_sb, _LBRC),
  [C_F5]      = COMBO(c_f5, KC_F5),
  [C_F12]     = COMBO(c_f12, KC_F12),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case C_NUM:
            if (pressed) {
                layer_move(NUM);
            } else {
               layer_clear();
            }
            break;
    case C_MIX:
            if (pressed) {
                layer_move(MIX);
            } else {
               layer_clear();
            }
            break;
    case C_CW_TOGG:
      if (pressed) {
        caps_word_on();
      }
      break;
    case C_DCOLN:
      if (pressed) {
		    SEND_STRING("::");
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
// clang-format on
