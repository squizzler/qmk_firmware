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

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define DSK_LFT LGUI(LCTL(KC_LEFT))
#define DSK_RT  LGUI(LCTL(KC_RIGHT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_RSTHD] = LAYOUT( \
<<<<<<< Local Changes
    KC_J,   KC_C,    KC_Y,   KC_F,   KC_K,            KC_Z,  KC_L,    KC_COMMA,    KC_U,   KC_Q, \
    KC_R,    KC_S,    KC_T,    KC_H,        KC_D,     KC_M,   KC_N,        KC_A,        KC_I ,        KC_O,   \
    LCTRL_T(KC_SLSH), KC_V,    KC_G,    KC_P, KC_B,  KC_X,  KC_W,        KC_DOT,      OSM(MOD_RSFT),      RCTRL_T(KC_QUOT), \
     OSM(MOD_LGUI), LT(_RAISE,  KC_BSPC),   KC_E,     KC_SPC, LT(_LOWER, KC_TAB), OSM(MOD_RALT)    \
=======
<<<<<<< Updated upstream
    KC_J,        KC_C,        KC_Y,        KC_F,       KC_K,      KC_Z,  KC_L,        KC_COMMA,     KC_U,        KC_Q, \
    SFT_T(KC_R), CTL_T(KC_S), ALT_T(KC_T), GUI_T(KC_H), KC_D,     KC_M,  GUI_T(KC_N), ALT_T(KC_A), CTL_T(KC_I), SFT_T(KC_O),\
    KC_SCLN,     KC_V,        KC_G,        KC_P,        KC_B,     KC_X,  KC_W,        KC_DOT,      KC_QUOT,      KC_SLSH, \
             KC_CAPS,         KC_BSPC,        LT(_RAISE, KC_E),     LT(_LOWER, KC_SPC), KC_TAB, TG(RAISE)    \
=======
    LCTRL_T(KC_J),   KC_C,    KC_Y,   KC_F,   KC_K,        KC_Z,  KC_L,    KC_COMMA,    KC_U,   RCTRL_T(KC_Q), \
    KC_R,    KC_S,    KC_T,    KC_H,        KC_D,         KC_M,   KC_N,        KC_A,        KC_I ,        KC_O,   \
    LSFT_T(KC_GRAVE), KC_V,    KC_G,    KC_P, LSFT_T(KC_B),         KC_X,  KC_W,        KC_DOT,      KC_SCLN,      RSFT_T(KC_QUOT), \
             OSM(MOD_LGUI), LT(_RAISE,  KC_BSPC),   KC_E,     KC_SPC, LT(_LOWER, KC_TAB), OSM(MOD_RALT)    \
>>>>>>> Stashed changes
>>>>>>> External Changes
),

[_RAISE] = LAYOUT( \
  KC_ESC,    KC_AT,    KC_HASH, KC_DLR,  KC_PERC,       KC_PLUS,  KC_7,    KC_8,   KC_9,   KC_0,    \
  KC_CIRCUMFLEX,   KC_AMPR,  KC_TILD, KC_PIPE, KC_BSLS,  KC_MINS,  KC_4,    KC_5,   KC_6, KC_EQL, \
  _______,   _______,   KC_UNDS, KC_GRV,  KC_PDOT,       KC_ASTR, KC_1,     KC_2,   KC_3, _______, \
                        _______, _______, _______,       KC_ENT,   MO(_ADJUST), _______                    \
),


[_LOWER] = LAYOUT( \
  KC_ESC,   KC_HOME, KC_UP, KC_END,     _______,       KC_LBRC, KC_LPRN,  KC_QUES, KC_RPRN, KC_RBRC,    \
  SFT_T(KC_VOLU),  KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGUP,KC_BRMU, _______, _______,  _______, KC_RSFT, \
  KC_VOLD,  KC_MPRV, KC_MPLY, KC_MNXT,  KC_PGDN,       KC_BRMD, _______, KC_EXLM,  _______,  _______, \
                       _______, KC_DEL, KC_ESC,        _______,  _______,  _______                    \
),

[_ADJUST] =  LAYOUT( \
  KC_ESC,  _______,  _______, _______,  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  \
  _______, _______,  _______, TSKMGR,  CALTDEL,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  RESET,   _______, _______, _______,  _______,    KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15, \
                    _______, _______, KC_ESC,      _______, _______,  _______                    \
)

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
