//Knocked about version of the Norman layout from the Minidox layouts folder. Uses RSTHD keymap.
//Possibly available to view on http://www.keyboard-layout-editor.com

#include QMK_KEYBOARD_H


extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layers {
    _RSTHD,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  RSTHD = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

//Tap Dance Declarations
enum {
  TD_COMM_QUES = 0,
  TD_DOT_EXLM,
  TD_SPC_ENT,
  TD_LBKTS,
  TD_RBKTS
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_COMM_QUES]  = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_QUES),
  [TD_DOT_EXLM]  = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_EXLM),
  [TD_SPC_ENT]  = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
  [TD_LBKTS]  = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LBRC),
  [TD_RBKTS]  = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_RBRC)
// Other declarations would go here, separated by commas, if you have them
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define DSK_LFT LGUI(LCTL(KC_LEFT))
#define DSK_RT  LGUI(LCTL(KC_RIGHT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_RSTHD] = LAYOUT( \

    KC_J,    KC_C,    KC_Y,    KC_F,  KC_K,                   KC_Z,  KC_L,   TD(TD_COMM_QUES),    KC_U,   KC_Q, \
    KC_R,    KC_S,    KC_T,    KC_H,  KC_D,                   KC_M,  KC_N,   KC_A,        KC_I ,  KC_O,   \
    LSFT_T(KC_SLSH), LCTL_T(KC_V), KC_G, LALT_T(KC_P), KC_B,    KC_X, RALT_T(KC_W), TD(TD_DOT_EXLM), RCTL_T(KC_SCLN), RSFT_T(KC_MINS), \
             OSM(MOD_LGUI), LT(_RAISE,  KC_BSPC), KC_E,      KC_SPC, LT(_LOWER, KC_QUOT),  KC_TAB   \
),

[_RAISE] = LAYOUT( \
  _______,   KC_AT,    KC_HASH, KC_DLR,  KC_PERC,       KC_PLUS,      KC_7,    KC_8,   KC_9,   KC_0,    \
  LSFT_T(KC_CIRC), LCTL_T(KC_AMPR),  KC_TILD, KC_PIPE, KC_BSLS,       KC_EQL,  KC_4,    KC_5,   KC_6, _______, \
  KC_CAPS,   OSM(MOD_LCTL),   KC_UNDS, LALT_T(KC_GRV),  KC_PDOT,      KC_ASTR, RALT_T(KC_1),     KC_2,   RCTL_T(KC_3), _______, \
                        _______, _______, _______,       KC_ENT,      MO(_ADJUST), _______                    \
),


[_LOWER] = LAYOUT( \
  KC_ESC,   KC_HOME, KC_UP,   KC_END,   KC_PGUP,     _______, _______, _______,  _______, _______,
  KC_VOLU,  KC_LEFT, KC_DOWN, KC_RIGHT, TD(TD_LBKTS),   TD(TD_RBKTS), _______, _______,  _______, _______, \
  KC_VOLD,  KC_MPRV, KC_MPLY, KC_MNXT,  KC_PGDN,     _______, _______, _______,  _______,  _______, \
                       _______, KC_DEL, KC_ESC,        _______,  _______,  _______                    \
),

[_ADJUST] =  LAYOUT( \
  CALTDEL,  _______,  _______, _______,  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  \
  _______, DSK_LFT,   TSKMGR,  DSK_RT,   _______,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  RESET,   _______, _______, _______,  _______,    KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15, \
                    _______, _______, KC_ESC,      _______, _______,  _______                    \
)

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
