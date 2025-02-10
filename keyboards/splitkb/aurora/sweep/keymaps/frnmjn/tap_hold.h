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
        case _T_E:
        case _COMM:
        case _DOT:
        case _SLSH:
        case _T_RB:
        case _T_SB:
        case _T_CB:
        case _T_PERC:
        case _T_PIPE:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}
