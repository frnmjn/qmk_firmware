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
        case _HR_9:
        case _COMM:
        case _DOT:
        case _CIRC:
        case _ESC:
        case _SLSH:
        case _ENT:
        case _MINS:
        case _UNDS:
        case _TAB:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case _HR_9:
            register_code16((!shifted) ? _SCLN : _COLN);
            break;
        case _COMM:
            register_code16((!shifted) ? _COMM : IT_LABK);
            break;
        case _DOT:
            register_code16((!shifted) ? _DOT : _IT_RABK);
            break;
        case _CIRC:
            register_code16((!shifted) ? _CIRC : _DLR);
            break;
        case _ESC:
            register_code16((!shifted) ? _ESC : _MEH);
            break;
        case _SLSH:
            register_code16((!shifted) ? _SLSH : IT_QUES);
            break;
        case _ENT:
            register_code16((!shifted) ? _ENT : _NUM);
            break;
        case _MINS:
            if (!shifted)
                register_code16(_MINS);
            else {
                register_code16(IT_LABK);
                register_code16(_MINS);
            }
            break;
        case _UNDS:
            if (!shifted)
                register_code16(_UNDS);
            else {
                register_code16(_MINS);
                register_code16(IT_RABK);
            }
            break;
        case _TAB:
            if (!shifted)
                register_code16(_TAB);
            else {
                register_code16(_CMD);
                register_code16(_SFT);
                register_code16(KC_A);
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
        case _HR_9:
            unregister_code16((!shifted) ? _SCLN : _COLN);
            break;
        case _COMM:
            unregister_code16((!shifted) ? _COMM : IT_LABK);
            break;
        case _DOT:
            unregister_code16((!shifted) ? _DOT : IT_RABK);
            break;
        case _CIRC:
            unregister_code16((!shifted) ? _CIRC : _DLR);
            break;
        case _ESC:
            unregister_code16((!shifted) ? _ESC : _AMPR);
            break;
        case _SLSH:
            unregister_code16((!shifted) ? _SLSH : IT_QUES);
            break;
        case _ENT:
            unregister_code16((!shifted) ? _ENT : _ASTR);
            break;
        case _MINS:
            if (!shifted)
                unregister_code16(_MINS);
            else {
                unregister_code16(IT_LABK);
                unregister_code16(_MINS);
            }
            break;
        case _UNDS:
            if (!shifted)
                unregister_code16(_UNDS);
            else {
                unregister_code16(_MINS);
                unregister_code16(IT_RABK);
            }
            break;
        case _TAB:
            if (!shifted)
                unregister_code16(_TAB);
            else {
                unregister_code16(_CMD);
                unregister_code16(_SFT);
                unregister_code16(KC_A);
            }
            break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}
