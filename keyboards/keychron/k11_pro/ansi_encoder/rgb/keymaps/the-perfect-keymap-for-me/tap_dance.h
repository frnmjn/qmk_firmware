typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}
  
enum {
    TD_RB,
};

static td_tap_t td_rb_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void rb_finished(tap_dance_state_t *state, void *user_data) {
    td_rb_state.state = cur_dance(state);
    switch (td_rb_state.state) {
        case TD_SINGLE_TAP: SEND_STRING("("); break;
        case TD_SINGLE_HOLD: SEND_STRING(")"); break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_HOLD:
            SEND_STRING("()" SS_TAP(X_LEFT)); break;
        default: break;
    }
}

tap_dance_action_t tap_dance_actions[] = {

}; 
