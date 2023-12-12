enum custom_keycodes {
    CUT = SAFE_RANGE,
    COPY,
    PASTE,
    UNDO,
    REDO,
    SAVE,
    SW_TAB,
    FILE,
    TERM,
    RUN,
    HYPR,
    EXIT,
    HOME,
    END,
    QUIT,
};

bool is_ctl_tab_active = false;
uint16_t ctl_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case CUT:
        SEND_STRING(SS_LCMD("x"));
        return false;
        break;
      case COPY:
        SEND_STRING(SS_LCMD("c"));
        return false;
        break;
      case PASTE:
        SEND_STRING(SS_LCMD("v"));
        return false;
        break;
      case UNDO:
        SEND_STRING(SS_LCMD("z"));
        return false;
        break;
      case REDO:
        SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCMD)SS_TAP(X_Z)SS_UP(X_LCMD)SS_UP(X_LSFT));
        return false;
        break;
      case SAVE:
        SEND_STRING(SS_LCMD("s"));
        return false;
        break;
      case SW_TAB:
        if (!is_ctl_tab_active) {
          is_ctl_tab_active = true;
          register_code(KC_LCTL);
        }
        ctl_tab_timer = timer_read();
        register_code(KC_TAB);
        return false;
        break;
      case FILE:
        SEND_STRING(SS_DOWN(X_LCMD)SS_DOWN(X_LSFT)SS_TAP(X_R)SS_UP(X_LCMD)SS_UP(X_LSFT));
        return false;
        break;
      case RUN:
        SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_ENT)SS_UP(X_LCTL));
        return false;
        break;
      case HYPR:
        SEND_STRING(SS_DOWN(X_LCMD)SS_DOWN(X_LALT)SS_DOWN(X_LCTL)SS_DOWN(X_LSFT));
        return false;
        break;
      case EXIT:
        SEND_STRING(SS_TAP(X_ESC)":w");
        return false;
        break;
      case HOME:
        SEND_STRING(SS_DOWN(X_LCMD)SS_TAP(X_LEFT)SS_UP(X_LCMD));
        return false;
        break;
      case END:
        SEND_STRING(SS_DOWN(X_LCMD)SS_TAP(X_RIGHT)SS_UP(X_LCMD));
        return false;
        break;
      case QUIT:
        SEND_STRING(SS_LCMD("q"));
        return false;
        break;
    }
  } else {
    switch (keycode) {
      case SW_TAB:
        unregister_code(KC_TAB);
        return false;
        break;
      case HYPR:
        SEND_STRING(SS_UP(X_LCMD)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
        return false;
        break;
    }
  }
  return true;
};

void matrix_scan_user(void) {
  if (is_ctl_tab_active) {
    if (timer_elapsed(ctl_tab_timer) > 1000) {
      unregister_code(KC_LCTL);
      is_ctl_tab_active = false;
    }
  }
}
