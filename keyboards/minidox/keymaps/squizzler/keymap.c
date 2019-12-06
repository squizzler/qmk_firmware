#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _FORMS   0
#define _BAR     1
#define _STROKE  2
#define _STR_BAR 3
#define _VOWEL   5
#define _VOW_BAR 6
#define _RSTHD   8
#define _ADJUST  16



// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Basic const
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   `  |   ,  |   n  |   N  |      |           |      |   l  |   R  |   .  |  '   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   k  |   r  |   s  |   p  |  (   |           |   )  |   m  |   t  |   j  |   f  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |Down  | Up   | Ctrl |           |  Alt | Left | Right|      |  ABC |
 * `----------------------------------'           `----------------------------------'
 *                  ,----------------------.    ,------,--------------.
 *                  |BKSP/GUI|STROKE|      |    |      |  BAR |Tab/GUI|
 *                  `---------------| VOW  |    |Spc   |------+-------.
 *                                  |      |    |      |
 *                                  `------'    `------'
 */
[_FORMS] = LAYOUT( \
  KC_GESC, KC_COMM, KC_N, LSFT(KC_N), _______,      _______,    KC_L,    LSFT(KC_R),    KC_DOT,    KC_QUOT,    \
  KC_K,    KC_R,    KC_S,    KC_P,    KC_LPRN,      KC_RPRN  KC_M,    KC_T,    KC_J,    KC_F, \
  _______, KC_SCLN   KC_DOWN, KC_UP,  OSM(KC_LCTRL), OSM(KC_LALT), KC_LEFT, KC_RIGHT, KC_QUOT,  KC_SLSH, \
                    LGUI_T(KC_BKSP), OSL(_STROKE), LT( _VOWEL, KC_H),    KC_SPC, OSL(_BAR), RGUI(TAB)              \
),
/* Const + bar
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   \  |   7  |   8  |   9  |   0  |           |   *  |   +  |   -  |      |   /  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |   4  |   5  |   6  |   [  |           |   ]  |   M  |   y  |   z  |   =  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |   1  |   2  |   3  |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,---------------------.    ,------,--------------.
 *                  |Ent/GUI|STROKE|   h  |    |      |BAR   |Ent/GUI|
 *                  `--------------|      |    |Spc   |------+-------.
 *                                 | VOW  |    |      |
 *                                 `------'    `------'
 */
[_BAR] = LAYOUT( \
  KC_BSLS,    KC_P7,   KC_P8,   KC_P9,   KC_P0,      KC_PAST,  KC_PPLS, KC_PMNS,    _______,    KC_PSLS,    \
  _______,    KC_P4,   KC_P5,   KC_P6,   KC_LBRC,    KC_RBRC, LSFT(KC_M),    KC_Y,    KC_Z,    KC_EQL, \
  _______,    KC_P1,   KC_P2,   KC_P3,   _______,    _______,    _______,    _______, _______,  _______, \
                    KC_LCTL, LOWER, KC_SPC,          KC_BSPC, RAISE, OSM(MOD_LSFT)                 \
),

/* Const + stroke
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  ``  |   ?  |   @  |   R  |      |           |      |      |   &  |   !  |  "   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   K  |      |   S  |   P  |   {  |           |   }  |   M  |   T  |   J  |   F  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,---------------------.    ,------,--------------.
 *                  |Ent/GUI|STROKE|      |    |      |BAR   |Ent/GUI|
 *                  `--------------| VOW  |    |Spc   |------+-------.
 *                                 |      |    |      |
 *                                 `------'    `------'
 */
[_STROKE] = LAYOUT( \
  _______,     KC_QUES, KC_E,       LSFT(KC_M), _______,    _______, _______, KC_AMPR,  KC_EXLM,  _______,    \
  LSFT(KC_K),  _______,  LSFT(KC_S), LSFT(KC_P), KC_LCBR,    KC_RCBR,  LSFT(KC_M), LSFT(KC_T),  LSFT(KC_J), LSFT(KC_F),\
  _______, _______, _______, _______, _______,   _______, _______, _______,  _______,   _______, \
                LGUI_T(KC_ENT), LT(BAR, KC_ESC), LT(VOWEL, KC_BSPC),    CTL_T(KC_SPC), LT(_LOWER, KC_TAB), ALT_T(KC_ENT)  \
),

/* Const + stroke + bar
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F5  |  F6  |  F7  |  F8  |   ⟨  |           |   ⟩  |      |   Y  |   Z  |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F9  |  F10 | F11  |  F12 |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,---------------------.    ,------,--------------.
 *                  |Ent/GUI|STROKE|      |    |      |BAR   |Ent/GUI|
 *                  `--------------| VOW  |    |Spc   |------+-------.
 *                                 |      |    |      |
 *                                 `------'    `------'
 */
[_STR_BAR] = LAYOUT( \
  KC_F1,    KC_F2,  KC_F3,   KC_F4,   _______,      _______, _______, _______, _______, _______,    \
  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,      _______, _______, LSFT(KC_Y), LSFT(KC_Z), _______, \
  KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,      _______, _______, _______, _______, _______, \
                    KC_LCTL, LOWER, KC_SPC,         KC_BSPC, RAISE, OSM(MOD_LSFT)                 \
),


/* Vowel
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |   L  |      |           |      |      |   c  |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   w  |   o  |   e  |   a  |   <  |           |   >  |   b  |   u  |   g  |   x  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      | PgDn | PgUp |      |           |      | Home |  End |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,---------------------.    ,------,--------------.
 *                  |Ent/GUI|STROKE|      |    |      |BAR   |Ent/GUI|
 *                  `--------------| VOW  |    |Spc   |------+-------.
 *                                 |      |    |      |
 *                                 `------'    `------'
 */
[_VOWEL] = LAYOUT( \
  _______, _______, _______, LSFT(KC_L), _______,   _______, _______, KC_C,    _______, _______,    \
  KC_W,    KC_O,    KC_E,    KC_A,    KC_LT,        KC_GT,   KC_B,    KC_U,    KC_G,    KC_X, \
  _______, _______,    PG_UP, PG_DN, _______,       _______,    KC_HOME, KC_END, _______, _______, \
                    KC_LCTL, LOWER, KC_SPC,         KC_BSPC, RAISE, OSM(MOD_LSFT)                 \
),

/* Vowel + bar
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |   d  |      |      |   ≤  |           |   ≥  |   v  |   q  |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,---------------------.    ,------,--------------.
 *                  |Ent/GUI|STROKE|      |    |      |BAR   |Ent/GUI|
 *                  `--------------| VOW  |    |Spc   |------+-------.
 *                                 |      |    |      |
 *                                 `------'    `------'
 */
[_VOWEL_BAR] = LAYOUT( \
  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,    \
  _______,    KC_D, _______, _______, _______,      _______,    KC_V,    KC_Q, _______, _______, \
  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, \
                    KC_LCTL, LOWER, KC_SPC,         KC_BSPC, RAISE, OSM(MOD_LSFT)                 \
),
};

//That'a all folks! Additional keymaps included for confirming all useful keys and functions are taken into the new layouts.

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab | Left | Down |  Up  | Right|           |      |   -  |   =  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Ctrl|   `  |  GUI |  Alt |      |           |      |      |      |   \  |   '  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 *
[_RAISE] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
  KC_TAB,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,      _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, \
  KC_LCTL, KC_GRV,  KC_LGUI, KC_LALT, _______,      _______, _______, _______, KC_BSLS,  KC_QUOT, \
                    _______, _______, _______,      _______, _______, _______                    \
),

 * Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc |      |      |      |      |           |      |   _  |   +  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Caps|   ~  |      |      |      |           |      |      |      |   |  |   "  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|  Del |
 *                  `-------------|      |    | Enter|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 *
[_LOWER] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
  KC_ESC,  _______, _______, _______, _______,      _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, \
  KC_CAPS, KC_TILD, _______, _______, _______,      _______, _______, _______, KC_PIPE,  KC_DQT, \
                    _______, _______, _______,      KC_ENT,  _______, KC_DEL                    \
),

 * Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |      |      |           |      |      |      |Taskmg|caltde|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 *
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  KC_F11,  KC_F12,  _______, _______, _______,      _______, _______, _______, TSKMGR, CALTDEL, \
  RESET,   _______, _______, _______, _______,      _______, _______, _______, _______,  _______, \
                    _______, _______, _______,      _______,  _______, _______                    \
)
 */

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
//Tri_layer 

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    }
  return true;
}