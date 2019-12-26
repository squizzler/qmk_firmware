#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _FORMS   0
#define _BAR     1
#define _STROKE  2
#define _BAR_STR 3
#define _VOWEL   5
#define _VOW_BAR 6

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))


enum custom_keycodes {
  FORMS = SAFE_RANGE,
  BAR,
  STROKE,
  BAR_STR,
  VOWEL,
  VOW_BAR,
};



//Code for the vowel layer tap functionnalaty

// tapdance keycodes
enum td_keycodes {
VOW_NOBAR,
VOW_WITHBAR,
C_UC,
W_UC,
O_UC,
E_UC,
A_UC,
B_UC,
U_UC,
G_UC,
X_UC,
D_UC,
V_UC,
Q_UC

 // Our example key: `LALT` when held, `(` when tapped. Add additional keycodes for each tapdance.
};

// define a type containing as many tapdance states as you need
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;

// create a global instance of the tapdance state type
static td_state_t td_state;

// declare your tapdance functions:

// function to determine the current tapdance state
int cur_dance (qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void vownob_finished (qk_tap_dance_state_t *state, void *user_data);
void vownob_reset (qk_tap_dance_state_t *state, void *user_data);

void vowwib_finished (qk_tap_dance_state_t *state, void *user_data);
void vowwib_reset (qk_tap_dance_state_t *state, void *user_data);



//In Layer declaration, add tap dance item in place of a key code



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Basic const
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |   ,  |   n  |   N  |      |           |      |   R  |   r  |   .  |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   k  |   f  |   s  |   p  |  (   |           |   )  |   m  |   t  |   j  |   l  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |   `  |Down  | Up   | Ctrl |           |  Alt | Left | Right|   '  |  ABC |
 * `----------------------------------'           `----------------------------------'
 *                  ,----------------------.    ,------,--------------.
 *                  |BKSP/GUI|STROKE|      |    |      |  BAR |Tab/GUI|
 *                  `---------------| VOW  |    |Spc   |------+-------.
 *                                  |      |    |      |
 *                                  `------'    `------'
 */
[_FORMS] = LAYOUT( \
  _______, KC_COMM, KC_N, KC_K, _______,      _______,    LSFT(KC_R),    KC_R,    KC_DOT,    _______,    \
  LSFT(KC_N), KC_F,  KC_S,    KC_P,    KC_LPRN,      KC_RPRN,  KC_M,    KC_T,    KC_J,    KC_L, \
  _______, KC_GRV,   KC_DOWN, KC_UP,  OSM(KC_LCTRL), OSM(KC_LALT), KC_LEFT, KC_RIGHT, KC_QUOT,  _______, \
           LGUI_T(KC_BSPC), MO(_STROKE), TD(VOW_NOBAR),    KC_SPC, MO(_BAR), LGUI_T(KC_TAB)              \
),
/* Const + bar
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   \  |   7  |   8  |   9  |   0  |           |   +  |   -  |   *  |      |   /  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |   4  |   5  |   6  |   [  |           |   ]  |   M  |   y  |   z  |      |
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
  KC_BSLS,    KC_P7,   KC_P8,   KC_P9,   KC_P0,      KC_PLUS, KC_MINS, KC_PAST,  _______, KC_PSLS,    \
  KC_EQL,    KC_P4,   KC_P5,   KC_P6,   KC_LBRC,    KC_RBRC, LSFT(KC_M), KC_Y,   KC_Z,    XXXXXXX, \
  _______,    KC_P1,   KC_P2,   KC_P3,   _______,    _______,    _______,    _______, _______,  _______, \
                    _______, _______, TD(VOW_WITHBAR),          _______, _______, _______                 \
),

/* Const + stroke
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |   ?  |   @  |   K  |      |           |      |      |      |   !  |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |  F   |   S  |   P  |   {  |           |   }  |   M  |   T  |   J  |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |  ``  |      |      |      |           |      |      |      |   "  |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,---------------------.    ,------,--------------.
 *                  |Ent/GUI|STROKE|      |    |      |BAR   |Ent/GUI|
 *                  `--------------| VOW  |    |Spc   |------+-------.
 *                                 |      |    |      |
 *                                 `------'    `------'
 */
[_STROKE] = LAYOUT( \
  _______,     KC_QUES, XXXXXXX,  LSFT(KC_K), _______,    _______, XXXXXXX, XXXXXXX,  KC_EXLM,  _______,    \
  XXXXXXX, LSFT(KC_F), LSFT(KC_S), LSFT(KC_P), KC_LCBR,    KC_RCBR,  XXXXXXX, LSFT(KC_T), LSFT(KC_J), XXXXXXX,  \
  _______, _______, _______, _______, _______,   _______, _______, _______,  _______,   _______, \
                _______, _______, _______,          KC_ENT, _______, _______  \
),

/* Const + stroke + bar
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |  #   |  €   |   %  |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   ^  |  &   |   ~  |  |   |   ⟨  |           |   ⟩  |      |   Y  |   Z  |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,---------------------.    ,------,--------------.
 *                  |Ent/GUI|STROKE|      |    |      |BAR   |Ent/GUI|
 *                  `--------------| VOW  |    |Spc   |------+-------.
 *                                 |      |    |      |
 *                                 `------'    `------'
 */
[_BAR_STR] = LAYOUT( \
  _______, KC_HASH, LALT(KC_3),KC_PERC,   _______,      _______, XXXXXXX, XXXXXXX, _______, _______,    \
  KC_CIRC, KC_AMPR, KC_TILD, KC_PIPE,   _______,      _______, XXXXXXX, LSFT(KC_Y), LSFT(KC_Z), XXXXXXX, \
  _______, _______, KC_UNDS, KC_GRV,    _______,      _______, _______, _______, _______, _______, \
                    _______, _______, _______,          _______, _______, _______                 \
),


/* Vowel
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |  L   |  W   |      |           |      |  c   |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |   x  |   e  |   a  |   <  |           |   >  |   b  |   u  |   g  |   o  |
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
  _______, _______, LSFT(KC_L), TD(W_UC), _______,   _______,  TD(C_UC), TD(O_UC),  _______, _______,    \
  XXXXXXX, TD(X_UC), TD(E_UC), TD(A_UC),  KC_LT,     KC_GT, TD(B_UC), TD(U_UC), TD(G_UC), XXXXXXX, \
  _______, _______, KC_PGUP, KC_PGDN, _______,       _______,    KC_HOME, KC_END, _______, _______, \
                    _______, _______, _______,       _______, _______, _______                 \
),

/* Vowel + bar
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F5  |  F6  |  F7  |  F8  |   ≤  |           |   ≥  |   v  |   q  |      |   d  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F9  |  F10 | F11  |  F12 |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,---------------------.    ,------,--------------.
 *                  |Ent/GUI|STROKE|      |    |      |BAR   |Ent/GUI|
 *                  `--------------| VOW  |    |Spc   |------+-------.
 *                                 |      |    |      |
 *                                 `------'    `------'
 */
[_VOW_BAR] = LAYOUT( \
  KC_F1,    KC_F2,  KC_F3,   KC_F4,   _______,      _______, XXXXXXX, TD(D_UC), _______, _______,    \
  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,      _______, TD(V_UC), TD(Q_UC), XXXXXXX, XXXXXXX, \
  KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,      _______, _______, _______, _______, _______, \
                    _______, _______, _______,          _______, _______, _______                 \
),
};


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


// determine the tapdance state to return
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) { return SINGLE_TAP; }
    else { return SINGLE_HOLD; }
  }
  if (state->count == 2) { return DOUBLE_SINGLE_TAP; }
  else { return 3; } // any number higher than the maximum state value you return above
}

// handle the possible states for each tapdance keycode you define:

void vownob_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(KC_H);
      break;
    case SINGLE_HOLD:
      layer_on(_VOWEL); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
      break;
    case DOUBLE_SINGLE_TAP: // allow nesting of 2 parens `((` within tapping term
      register_code (KC_RSFT);
      register_code (KC_H);
  }
}

void vownob_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_H);
      break;
    case SINGLE_HOLD:
      layer_off(_VOWEL); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
      break;
    case DOUBLE_SINGLE_TAP:
      unregister_code (KC_RSFT);
      unregister_code (KC_H);
    }
  }



      void vowwib_finished (qk_tap_dance_state_t *state, void *user_data) {
        td_state = cur_dance(state);
        switch (td_state) {
          case SINGLE_TAP:
            register_code16(KC_I);
            break;
          case SINGLE_HOLD:
            layer_on(_VOWEL); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
          case DOUBLE_SINGLE_TAP: // allow nesting of 2 parens `((` within tapping term
            register_code (KC_RSFT);
            register_code (KC_I);
        }
      }

      void vowwib_reset (qk_tap_dance_state_t *state, void *user_data) {
        switch (td_state) {
          case SINGLE_TAP:
            unregister_code16(KC_I);
            break;
          case SINGLE_HOLD:
            layer_off(_VOWEL); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
          case DOUBLE_SINGLE_TAP:
            unregister_code (KC_RSFT);
            unregister_code (KC_I);
  }
}

// define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
  [VOW_NOBAR]ACTION_TAP_DANCE_FN_ADVANCED(NULL, vownob_finished, vownob_reset),
  [VOW_WITHBAR]ACTION_TAP_DANCE_FN_ADVANCED(NULL, vowwib_finished, vowwib_reset),
  [C_UC]  = ACTION_TAP_DANCE_DOUBLE(KC_C, LSFT(KC_C)),
  [W_UC]  = ACTION_TAP_DANCE_DOUBLE(KC_W, LSFT(KC_W)),
  [O_UC]  = ACTION_TAP_DANCE_DOUBLE(KC_O, LSFT(KC_O)),
  [E_UC]  = ACTION_TAP_DANCE_DOUBLE(KC_E, LSFT(KC_E)),
  [A_UC]  = ACTION_TAP_DANCE_DOUBLE(KC_A, LSFT(KC_A)),
  [B_UC]  = ACTION_TAP_DANCE_DOUBLE(KC_B, LSFT(KC_B)),
  [U_UC]  = ACTION_TAP_DANCE_DOUBLE(KC_U, LSFT(KC_U)),
  [G_UC]  = ACTION_TAP_DANCE_DOUBLE(KC_G, LSFT(KC_G)),
  [X_UC]  = ACTION_TAP_DANCE_DOUBLE(KC_X, LSFT(KC_X)),
  [D_UC]  = ACTION_TAP_DANCE_DOUBLE(KC_D, LSFT(KC_D)),
  [V_UC]  = ACTION_TAP_DANCE_DOUBLE(KC_V, LSFT(KC_V)),
  [Q_UC]  = ACTION_TAP_DANCE_DOUBLE(KC_Q, LSFT(KC_Q))
};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _BAR, _STROKE, _BAR_STR);
  state = update_tri_layer_state(state, _VOWEL, _BAR, _VOW_BAR);
  return state;
}
