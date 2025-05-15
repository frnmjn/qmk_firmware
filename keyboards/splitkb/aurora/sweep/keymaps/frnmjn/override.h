const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t alt_left            = ko_make_basic(MOD_MASK_ALT, KC_LEFT, KC_DEL);
// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &delete_key_override,
    &alt_left,

};
