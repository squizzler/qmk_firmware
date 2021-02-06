#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _RSTHD,
    _FUN,
    _UPPER
};

enum combo_events {
  TOP_L,
  TOP_R,
  MID_L,
  MID_R,
  BOT_L,
  BOT_R,
  HN_QUOT,
  FUN_TOP_L,
  FUN_TOP_R,
  FUN_MID_L,
  FUN_MID_R,
};

const uint16_t PROGMEM fk_combo[] = {KC_F, KC_K, COMBO_END};
const uint16_t PROGMEM zl_combo[] = {KC_Z, KC_L, COMBO_END};
const uint16_t PROGMEM hd_combo[] = {KC_H, KC_D, COMBO_END};
const uint16_t PROGMEM mn_combo[] = {KC_M, KC_N, COMBO_END};
const uint16_t PROGMEM pb_combo[] = {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM xw_combo[] = {KC_X, KC_W, COMBO_END};
const uint16_t PROGMEM hn_combo[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM fun_fk_combo[] = {KC_9, KC_PLUS, COMBO_END};
const uint16_t PROGMEM fun_zl_combo[] = {KC_PGUP, KC_HOME, COMBO_END};
const uint16_t PROGMEM fun_hd_combo[] = {KC_6, KC_EQL, COMBO_END};
const uint16_t PROGMEM fun_mn_combo[] = {KC_PGDN, KC_LEFT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [TOP_L] = COMBO(fk_combo, KC_EXLM),
  [TOP_R] = COMBO(zl_combo, KC_AT),
  [MID_L] = COMBO(hd_combo, KC_TAB),
  [MID_R] = COMBO_ACTION(mn_combo),
  [BOT_L] = COMBO(pb_combo, KC_HASH),
  [BOT_R] = COMBO(xw_combo, KC_AMPR),
  [HN_QUOT] = COMBO(hn_combo, KC_QUOT),
  [FUN_TOP_L] = COMBO_ACTION(fun_fk_combo),
  [FUN_TOP_R] = COMBO_ACTION(fun_zl_combo),
  [FUN_MID_L] = COMBO(fun_hd_combo, KC_LBRC),
  [FUN_MID_R] = COMBO(fun_mn_combo, KC_RBRC),
};

  void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
      case MID_R:
      if (pressed) {
        tap_code16(LALT(KC_3));
      }
      break;
      case FUN_TOP_L:
        if (pressed) {
          tap_code16(LALT(KC_2));
        }
        break;
      case FUN_TOP_R:
        if (pressed) {
          tap_code16(LALT(KC_4));
        }
        break;
    }
  }

// Defines for task manager and such
// For insertion in keymap
#define KILL LGUI(LALT(KC_ESC)) //Force quit controls
#define SCRCAP LCTL(LSFT(LGUI(KC_5))) //Screen capture controls
#define DSK_LFT LGUI(LCTL(KC_LEFT))
#define DSK_RT  LGUI(LCTL(KC_RIGHT))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_RSTHD] = LAYOUT(
    KC_J,    KC_C,    KC_Y,     KC_F, KC_K,              KC_Z,  KC_L,   KC_COMM,  KC_U,   KC_Q,
    KC_R,    KC_S,    KC_T,     KC_H, KC_D,              KC_M,  KC_N,   KC_A,     KC_I ,  KC_O,
    LCTL_T(KC_SLSH), LALT_T(KC_V), LGUI_T(KC_G), KC_P, KC_B,      KC_X,  KC_W, RGUI_T(KC_DOT), RALT_T(KC_SCLN),RCTL_T(KC_MINS),
          KC_LSPO, LT(_UPPER, KC_BSPC), KC_E,      KC_SPC, LT(_FUN, KC_ENT),  KC_RSPC
),
[_FUN] = LAYOUT(
  KC_BSLS, KC_7,    KC_8,   KC_9,  KC_PLUS,       KC_PGUP,  KC_HOME, KC_UP,   KC_END, KC_DLR,
  KC_PIPE, KC_4,    KC_5,   KC_6,    KC_EQL,      KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PERC,
  _______, LALT_T(KC_1), LGUI_T(KC_2), KC_3,KC_PAST,    _______, _______, _______, _______, _______,
                  _______, _______, KC_0,     _______, _______, _______
),
[_UPPER] = LAYOUT(
   KC_CIRC, KC_TILD, KC_VOLU, KC_BRMU, LSFT(KC_NUBS), KC_NUBS,  KC_F7, KC_F8, KC_F9, KC_F10,
   KC_ESC, KC_GRV,  KC_VOLD, KC_BRMD, DSK_LFT,        DSK_RT, KC_F4, KC_F5,  KC_F6, KC_F11,
   KC_MPRV, KC_MPLY, KC__MUTE, KC_MNXT, _______,      _______, KC_F1, KC_F2, KC_F3, KC_F12,
                      _______, _______, _______,      KC_DEL,  _______,  _______
),
};
