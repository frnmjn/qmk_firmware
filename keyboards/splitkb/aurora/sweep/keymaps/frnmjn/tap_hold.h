bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    return true;
};

void housekeeping_task_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    switch (tap_hold_keycode) {
        case _NOR:
            return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _HR_0:
        case _HR_9:
        case _CMD:
        case _DOT:
        case _SLSH:
            return TAPPING_TERM + 50;
        case _LPRN:
        case _LBRC:
        case _LCBR:
        case _UNDS:
        case _ESC:
        case _AT:
        case _AMPR:
        case _BSLS:
        case _CIRC:
            return TAPPING_TERM - 100;
        default:
            return TAPPING_TERM;
    }
}
