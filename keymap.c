// Copyright 2022 Ignacy Radliński (@radlinskii)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "light_layers.h"

enum my_layers {
    _COLEMAK,
    _QWERTY,
    _NUM_SYM,
    _NAV,
    _MOUSE,
    _MEDIA_MISC,
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
    SNIP,
    FLIP
};

#define LALT_KA LALT_T(KC_A)
#define LCTL_KS LCTL_T(KC_S)
#define LGUI_KD LGUI_T(KC_D)
#define LSFT_KF LSFT_T(KC_F)
#define RSFT_KJ RSFT_T(KC_J)
#define RGUI_KK RGUI_T(KC_K)
#define RCTL_KL RCTL_T(KC_L)
#define RA_SCLN RALT_T(KC_SCLN)

#define LALT_K1 LALT_T(KC_1)
#define LCTL_K2 LCTL_T(KC_2)
#define LGUI_K3 LGUI_T(KC_3)
#define LSFT_K4 LSFT_T(KC_4)
#define RSFT_K7 RSFT_T(KC_7)
#define RGUI_K8 RGUI_T(KC_8)
#define RCTL_K9 RCTL_T(KC_9)
#define RALT_K0 RALT_T(KC_0)

#define LCTL_KR LCTL_T(KC_R)
#define LGUI_KS LGUI_T(KC_S)
#define LSFT_KT LSFT_T(KC_T)
#define RSFT_KN RSFT_T(KC_N)
#define RGUI_KE RGUI_T(KC_E)
#define RCTL_KI RCTL_T(KC_I)
#define LGUI_BS LGUI_T(KC_BSPC)
#define RALT_TB RALT_T(KC_TAB)

#define TT_N_S TT(_NUM_SYM)
#define TT_NAV TT(_NAV)
#define TO_QWRT TO(_QWERTY)
#define TO_N_S TO(_NUM_SYM)
#define TO_NAV TO(_NAV)
#define TO_MOUSE TO(_MOUSE)
#define TO_M_M TO(_MEDIA_MISC)

bool sft_encoder = true;
bool is_ctl_tab_active = false;
uint16_t ctl_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRAVE,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQUAL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC, KC_A,     KC_R,   KC_S,    KC_T,    KC_D,                               KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY,           FLIP,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINUS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, TT_N_S,  KC_SPC,                     KC_ENT, TT_NAV,  KC_RGUI
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

    [_NUM_SYM] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       _______,  S(KC_1), S(KC_2),S(KC_3), S(KC_4), S(KC_5),                            S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_GRAVE),
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       S(KC_TAB),S(KC_Q), S(KC_W), S(KC_F), S(KC_P),S(KC_G),                           S(KC_J), S(KC_L), S(KC_U), S(KC_Y), S(KC_SCLN), S(KC_EQUAL),
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, S(KC_A), S(KC_R), S(KC_S), S(KC_T), S(KC_D),                            S(KC_H), S(KC_N), S(KC_E), S(KC_I), S(KC_O), S(KC_QUOT),
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______, S(KC_Z), S(KC_X), S(KC_C),  S(KC_V), S(KC_B),_______,           _______,S(KC_K), S(KC_M), S(KC_COMM), S(KC_DOT), S(KC_SLSH), S(KC_MINUS),
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, DEFAULT, _______,                   NEXTSEN, TO_NAV,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_NAV] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, KC_LBRC,                            KC_RBRC, KC_WH_U, KC_UP,   KC_WH_D, KC_HOME, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, KC_LCBR,                            KC_RCBR, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, SNIP,            _______, CUT,     COPY,    PASTE,   SELLINE, SELWORD, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, TO_N_S, _______,                   KC_BTN1, DEFAULT, KC_BTN2
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_MOUSE] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, _______, _______, _______, _______, _______,                            _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                           KC_WH_R, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_L,  TO_M_M,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, DEFAULT, _______,                   KC_BTN1, TO_NAV,  KC_BTN2
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_MEDIA_MISC] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       RESET,   _______, _______, _______, _______, QWERTY,                             COLEMAK, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, _______, _______, KC_MUTE, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_CAPS, KC_MPLY, KC_MNXT, KC_VOLU, BL_INC,  _______,                            _______, _______, _______, _______, _______, _______,
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
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LCTL, LALT_KA, LCTL_KS, LGUI_KD, LSFT_KF, KC_G,                               KC_H,    RSFT_KJ, RGUI_KK, RCTL_KL, RA_SCLN, KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,           KC_ESC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LGUI_BS, TT_N_S,  KC_ENT,                     KC_SPC, TT_NAV,  RALT_TB
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
    rgblight_set_layer_state(_NUM_SYM, layer_state_cmp(state, _NUM_SYM));
    rgblight_set_layer_state(_NAV, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(_MOUSE, layer_state_cmp(state, _MOUSE));
    rgblight_set_layer_state(_MEDIA_MISC, layer_state_cmp(state, _MEDIA_MISC));

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
        case SNIP:
            if (record->event.pressed) {
              register_code(KC_LGUI);
              register_code(KC_LSFT);
              register_code(KC_S);
              unregister_code(KC_LGUI);
              unregister_code(KC_LSFT);
              unregister_code(KC_S);
            }
            return false;
        case FLIP:
            if (record->event.pressed) {
                sft_encoder = !sft_encoder;
            }
            return false;
    }
    return true;
}
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (!is_ctl_tab_active) {
          is_ctl_tab_active = true;
          register_code(KC_LCTL);
        }
        if (clockwise) {
          ctl_tab_timer = timer_read();
          tap_code16(KC_TAB);
        } else {
          ctl_tab_timer = timer_read();
          tap_code16(S(KC_TAB));
        }
}
    else if (index == 1) {
        if (clockwise) {
            if (sft_encoder) {
                tap_code16(S(KC_RIGHT));
            }
            else {
                tap_code16(KC_RIGHT);
            }
        } else {
            if (sft_encoder) {
                tap_code16(S(KC_LEFT));
            }
            else {
                tap_code16(KC_LEFT);
            }
        }
    }
    return false;
}

void matrix_scan_user(void) {
  if (is_ctl_tab_active) {
    if (timer_elapsed(ctl_tab_timer) > 1250) {
      unregister_code(KC_LCTL);
      is_ctl_tab_active = false;
    }
  }
}