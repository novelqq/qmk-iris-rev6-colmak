#include QMK_KEYBOARD_H

#include "light_layers.h"

enum my_layers {
    _COLEMAK,
    _QWERTY,
    _SYM,
    _NAV,
    _MISC
};

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    DEFAULT,
    CUT,
    COPY,
    PASTE,
    SELWORD,
    SELLINE,
    NEXTSEN,
};

#define TO_N_S TO(_SYM)
#define TO_NAV TO(_NAV)
#define TO_SYM TO(_SYM)
#define TO_MISC TO(_MISC)
#define OSL_SYM OSL(_SYM)
#define OSM_SFT OSM(MOD_LSFT)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRAVE,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQUAL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC, KC_A,     KC_R,   KC_S,    KC_T,    KC_D,                               KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    QWERTY,           COLEMAK, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSPC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, OSM_SFT, KC_SPC,                    KC_ENT,  OSL_SYM, KC_RGUI
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

    [_SYM] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______,KC_EXLM, KC_AT,  KC_HASH, KC_DOLLAR, KC_PERC,                           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_BSLS, KC_MINS, KC_LBRC, KC_LCBR, _______,                           _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_PIPE, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, KC_EQL,  _______, _______,         _______, _______, KC_PLUS, _______, _______, _______, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, DEFAULT, _______,                   NEXTSEN, TO_NAV, TO_SYM
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_NAV] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_WH_U, KC_HOME, KC_UP,   KC_END,  _______,                            _______, KC_WH_U, KC_WH_D, KC_PGUP, KC_PGDN, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_WH_D, KC_LEFT, KC_DOWN,KC_RIGHT, _______,                            _______, COPY,    PASTE,   SELLINE, SELWORD, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______,         _______, _______, CUT,     _______, _______, _______, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_BTN2, DEFAULT, KC_BTN1,                   _______, TO_MISC,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_MISC] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       _______,   _______, _______, _______, _______, QWERTY,                             COLEMAK, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, _______, _______, KC_MUTE, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_MPLY, KC_MNXT, KC_VOLU, BL_INC,  _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_MSTP, KC_MPRV, KC_VOLD, KC_BRID, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, DEFAULT, _______,                   _______, DEFAULT, _______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_QWERTY] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQUAL,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LCPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,           KC_ESC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, DEFAULT,  KC_ENT,                     KC_SPC, OSL_SYM,  KC_RGUI
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    )
};

void keyboard_post_init_user(void) {
    rgblight_layers = MY_LIGHT_LAYERS;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_COLEMAK, layer_state_cmp(state, _COLEMAK));
    rgblight_set_layer_state(_QWERTY, layer_state_cmp(state, _QWERTY));

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_SYM, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(_NAV, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(_MISC, layer_state_cmp(state, _MISC));

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
                layer_move(_COLEMAK);
            }
            return false;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
                layer_move(_QWERTY);
            }
            return false;
        case DEFAULT:
            if (record->event.pressed) {
                if (layer_state_cmp(default_layer_state, _COLEMAK)) {
                    layer_move(_COLEMAK);
                } else if (layer_state_cmp(default_layer_state, _QWERTY)) {
                    layer_move(_QWERTY);
                }
            }
            return false;
        case CUT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_X);
                unregister_code(KC_LCTL);
                unregister_code(KC_X);
            }
            return false;
        case COPY:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_C);
                unregister_code(KC_LCTL);
                unregister_code(KC_C);
            }
            return false;
        case PASTE:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_V);
                unregister_code(KC_LCTL);
                unregister_code(KC_V);
            }
            return false;
        case SELLINE:  // Selects the current line.
            if (record->event.pressed) {
              SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
            }
            return false;
        case SELWORD:  // Selects the current word under the cursor.
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL(SS_TAP(X_RGHT) SS_LSFT(SS_TAP(X_LEFT))));
            }
            return false;
        case NEXTSEN:  // Next sentence macro.
            if (record->event.pressed) {
              SEND_STRING(". ");
              add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
            }
            return false;
    }
    return true;
}
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_BTN4);
        } else {
            tap_code(KC_BTN5);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    }
    return false;
}

