enum custom_keycodes {
    SW_TAB = SAFE_RANGE,
};

bool is_cmd_tab_active = false;
uint16_t cmd_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case SW_TAB:
        if (!is_cmd_tab_active) {
          is_cmd_tab_active = true;
          register_code(KC_LCMD);
        }
        cmd_tab_timer = timer_read();
        register_code(KC_TAB);
        break;
    }
  } else {
    switch (keycode) {
      case SW_TAB:
        unregister_code(KC_TAB);
        break;
    }
  }
  return true;
};

void matrix_scan_user(void) {
  if (is_cmd_tab_active) {
    if (timer_elapsed(cmd_tab_timer) > 1000) {
      unregister_code(KC_LCMD);
      is_cmd_tab_active = false;
    }
  }
}
