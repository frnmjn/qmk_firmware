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
    TD_SB,
    TD_CB,
    TD_E,
    TD_QT,
    TD_DQT,
    TD_PIPE,
    TD_PERC,
};

static td_tap_t td_rb_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void rb_finished(tap_dance_state_t *state, void *user_data) {
    td_rb_state.state = cur_dance(state);
    switch (td_rb_state.state) {
        case TD_SINGLE_TAP: SEND_STRING("("); break;
        case TD_DOUBLE_TAP: SEND_STRING("()" SS_TAP(X_LEFT)); break;
        default: break;
    }
}

static td_tap_t td_sb_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void sb_finished(tap_dance_state_t *state, void *user_data) {
    td_sb_state.state = cur_dance(state);
    switch (td_sb_state.state) {
        case TD_SINGLE_TAP: SEND_STRING("["); break;
        case TD_DOUBLE_TAP: SEND_STRING("[]" SS_TAP(X_LEFT)); break;
        default: break;
    }
}

static td_tap_t td_cb_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void cb_finished(tap_dance_state_t *state, void *user_data) {
    td_cb_state.state = cur_dance(state);
    switch (td_cb_state.state) {
        case TD_SINGLE_TAP: SEND_STRING("{"); break;
        case TD_DOUBLE_TAP: SEND_STRING("{}" SS_TAP(X_LEFT)); break;
        default: break;
    }
}

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

static td_tap_t td_quot_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void quot_finished(tap_dance_state_t *state, void *user_data) {
    td_quot_state.state = cur_dance(state);
    switch (td_quot_state.state) {
        case TD_SINGLE_TAP: SEND_STRING("'"); break;
        case TD_SINGLE_HOLD:
            SEND_STRING("`"); break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
            SEND_STRING("''" SS_TAP(X_LEFT)); break;
        default: break;
    }
}

static td_tap_t td_dquot_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void dquot_finished(tap_dance_state_t *state, void *user_data) {
    td_dquot_state.state = cur_dance(state);
    switch (td_dquot_state.state) {
        case TD_SINGLE_TAP: SEND_STRING("\""); break;
        case TD_SINGLE_HOLD:
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_HOLD:
            SEND_STRING("\"\"" SS_TAP(X_LEFT)); break;
        default: break;
    }
}

static td_tap_t td_pipe_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void pipe_finished(tap_dance_state_t *state, void *user_data) {
    td_pipe_state.state = cur_dance(state);
    switch (td_pipe_state.state) {
        case TD_SINGLE_TAP: SEND_STRING("|"); break;
        case TD_SINGLE_HOLD:
            SEND_STRING("|>" SS_TAP(X_SPC)); break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_HOLD:
            SEND_STRING("||"); break;
        default: break;
    }
}

static td_tap_t td_perc_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void perc_finished(tap_dance_state_t *state, void *user_data) {
    td_perc_state.state = cur_dance(state);
    switch (td_perc_state.state) {
        case TD_SINGLE_TAP:
            SEND_STRING("%"); break;
        case TD_SINGLE_HOLD:
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_HOLD:
            SEND_STRING("%{}" SS_TAP(X_LEFT)); break;
        default: break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_RB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rb_finished, NULL),
    [TD_SB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sb_finished, NULL),
    [TD_CB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cb_finished, NULL),
    [TD_E] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, e_finished, NULL),
    [TD_QT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, quot_finished, NULL),
    [TD_DQT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dquot_finished, NULL),
    [TD_PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, pipe_finished, NULL),
    [TD_PERC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, perc_finished, NULL),
};
