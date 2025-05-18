bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case _HR_0:
        case _HR_1:
        case _HR_2:
        case _HR_3:
        case _HR_6:
        case _HR_7:
        case _HR_8:
        case _HR_9:
        case KC_A ... KC_Z:
        case _T_E:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case _BSPC:
        case _DEL:
        case _UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _HR_0:
        case _HR_1:
        case _HR_2:
        case _HR_3:
        case _HR_6:
        case _HR_7:
        case _HR_8:
        case _HR_9:
        case _COMM:
        case _DOT:
        case _CIRC:
        case _ESC:
        case _SLSH:
        case _ENT:
        case _MINS:
        case _UNDS:
        case _TILD:
        case _AT:
        case _TAB:
        case _AMPR:
        case _PIPE:
        case _BSLS:
        case _DQT:
        case _QUOT:
        case _LCBR:
        case _LBRC:
        case _LPRN:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case _DQT:
            if (!shifted) {
                SEND_STRING("\"");
            } else {
                SEND_STRING("\"\"" SS_TAP(X_LEFT));
            }
            break;
        case _QUOT:
            if (!shifted) {
                SEND_STRING("'");
            } else {
                SEND_STRING("''" SS_TAP(X_LEFT));
            }
            break;
        case _LCBR:
            if (!shifted) {
                SEND_STRING("{");
            } else {
                SEND_STRING("}");
            }
            break;
        case _LBRC:
            if (!shifted) {
                SEND_STRING("[");
            } else {
                SEND_STRING("]");
            }
            break;
        case _LPRN:
            if (!shifted) {
                SEND_STRING("(");
            } else {
                SEND_STRING(")");
            }
            break;
        case _TILD:
            if (!shifted) {
                SEND_STRING("~");
            } else {
                SEND_STRING(SS_TAP(X_ESC) ":wq" SS_TAP(X_ENT));
            }
            break;
        case _AT:
            if (!shifted) {
                SEND_STRING("@");
            } else {
                SEND_STRING("!");
            }
            break;
        case _AMPR:
            if (!shifted) {
                SEND_STRING("&");
            } else {
                SEND_STRING("*");
            }
            break;
        case _BSLS:
            if (!shifted) {
                SEND_STRING("\\");
            } else {
                SEND_STRING("%");
            }
            break;
        case _PIPE:
            if (!shifted) {
                SEND_STRING("|");
            } else {
                SEND_STRING("||" SS_TAP(X_LEFT));
            }
            break;
        case _HR_9:
            if (!shifted) {
                SEND_STRING(";");
            } else {
                SEND_STRING(":");
            }
            break;
        case _COMM:
            if (!shifted) {
                SEND_STRING(",");
            } else {
                SEND_STRING("<");
            }
            break;
        case _DOT:
            if (!shifted) {
                SEND_STRING(".");
            } else {
                SEND_STRING(">");
            }
            break;
        case _CIRC:
            if (!shifted) {
                SEND_STRING("^");
            } else {
                SEND_STRING("$");
            }
            break;
        case _ESC:
            if (!shifted) {
                SEND_STRING(SS_TAP(X_ESC));
            } else {
                SEND_STRING(SS_TAP(X_TAB));
            }
            break;
        case _SLSH:
            if (!shifted) {
                SEND_STRING("/");
            } else {
                SEND_STRING("?");
            }
            break;
        case _ENT:
            if (!shifted) {
                SEND_STRING(SS_TAP(X_ENT));
            } else {
                SEND_STRING("=");
            }
            break;
        case _UNDS:
            if (!shifted) {
                SEND_STRING("_");
            } else {
                SEND_STRING("-");
            }
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
    switch (keycode) {
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}
