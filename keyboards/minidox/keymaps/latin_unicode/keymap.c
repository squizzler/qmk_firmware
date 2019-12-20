//Knocked about version of the Norman layout from the Minidox layouts folder. Uses RSTHD keymap.
//Possibly available to view on http://www.keyboard-layout-editor.com

#include QMK_KEYBOARD_H


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


enum unicode_names {
  COMA,
  QUEST,
  FULST,
  EXCLA,
  LTBRK,
  RTBRK,
  MORTHN,
  LESTHN,
  CIRCUM,
  SECT,
  PLUMIN,
};

const uint32_t PROGMEM unicode_map[] = {
  [COMA]  = 0x002C,  // ,
  [QUEST] = 0x003F,
  [FULST] = 0x002E,
  [EXCLA] = 0x0021,
  [LTBRK] = 0x0028,
  [RTBRK] = 0x0029,
  [MORTHN]= 0x003C,
  [LESTHN]= 0x003E,
  [CIRCUM]= 0x005E,
  [SECT]  = 0X00A7,
  [PLUMIN]= 0X00B1,
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_RSTHD] = LAYOUT( \
  KC_J,        KC_C,        KC_Y,        KC_F,       KC_K,      KC_Z,  KC_L,        XP(COMA, QUEST),     KC_U,        KC_Q, \
  KC_R,    KC_S,    KC_T,    KC_H,        KC_D,     KC_M,   KC_N,        KC_A,        KC_I ,        KC_O,   \
  LSFT_T(KC_SLSH), KC_V,    KC_G,    KC_P, KC_B,  KC_X,  KC_W,        XP(FULST, EXCLA),      KC_SCLN,      RSFT_T(KC_MINS), \
               OSM(MOD_LGUI), LT(_RAISE,  KC_BSPC),   KC_E,     KC_SPC, LT(_LOWER, KC_TAB), KC_LALT    \
),

[_RAISE] = LAYOUT( \
  KC_CLR,    KC_AT,    KC_HASH, KC_DLR,  KC_PERC,       KC_PLUS,  KC_7,    KC_8,   KC_9,   KC_0,    \
X(CIRCUM),   KC_AMPR,  KC_TILD, KC_PIPE, KC_BSLS,      KC_MINS,  KC_4,    KC_5,   KC_6, KC_EQL, \
  XP(SECT, PLUMIN), _______, KC_UNDS, KC_GRV,  KC_PDOT,       KC_ASTR, KC_1,     KC_2,   KC_3, _______, \
                        _______, _______, _______,       KC_ENT,   MO(_ADJUST), TO(LOWER)                    \
),


[_LOWER] = LAYOUT( \
  KC_PSCR,   KC_HOME, KC_UP, KC_END,     _______,       KC_LBRC, XP(LTBRK, MORTHN), _______, XP(RTBRK, LESTHN), KC_RBRC,    
  SFT_T(KC_VOLU),  KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGUP,KC_BRMU, _______, _______,  _______, KC_RSFT, \
  KC_VOLD,  KC_MPRV, KC_MPLY, KC_MNXT,  KC_PGDN,       KC_BRMD, _______, _______,  _______,  _______, \
                       _______, KC_DEL, KC_ESC ,        _______,  _______,  TO(ADJUST)                    \
),

[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10, \
  _______, DSK_LFT, _______, DSK_RT,  _______,      TSKMGR,  CALTDEL,  _______, KC_F11,   KC_F12, \
  RESET,   _______, _______, _______, _______,      _______, _______,  _______, _______,  _______, \
                    _______, _______, _______,      _______, _______,  TO(RSTHD)                    \
)

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);

  void eeconfig_init_user(void) {
      set_unicode_input_mode(UC_LNX);
  }