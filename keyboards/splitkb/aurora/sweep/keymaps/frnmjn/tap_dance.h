// clang-format off
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
    TD_E,
    TD_3,
};

static td_tap_t td_e_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void e_finished(tap_dance_state_t *state, void *user_data) {
    td_e_state.state = cur_dance(state);
    switch (td_e_state.state) {
        case TD_SINGLE_TAP: SEND_STRING("e"); break;
        case TD_SINGLE_HOLD: SEND_STRING("E"); break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
            SEND_STRING("ee"); break;
        case TD_DOUBLE_HOLD:
            SEND_STRING(SS_TAP(X_LBRC)); break;
        default: break;
    }
}

static td_tap_t td_three_state = {
    .is_press_action = true, 
    .state = TD_NONE
};

void three_finished(tap_dance_state_t *state, void *user_data) {
    td_three_state.state = cur_dance(state);
    switch (td_three_state.state) {
        case TD_SINGLE_TAP:
            SEND_STRING("3"); 
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING(".");
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
        case TD_DOUBLE_SINGLE_TAP:
            SEND_STRING("33"); 
            break;
        case TD_TRIPLE_TAP:
        case TD_TRIPLE_HOLD:
            SEND_STRING("333"); 
            break; 
        default:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_E] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, e_finished, NULL),
    [TD_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, three_finished, NULL),
};
