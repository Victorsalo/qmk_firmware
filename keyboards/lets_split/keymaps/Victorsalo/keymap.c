#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Bksp |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Adjust| GUI  | Alt  |Lower | Tab  |Space |Raise | VolDn| VolUp| Pl/Ps| Next |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12 ( \
  KC_BSPC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SE_ARNG, \
  KC_ESC,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    SE_ODIA, SE_ADIA, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    SE_COMM, SE_DOT,  SE_MINS, KC_ENT , \
  KC_LCTL,  ADJUST, KC_LGUI, KC_LALT, LOWER,  KC_TAB,  KC_SPC,  RAISE,   KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT  \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Bksp |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Adjust| GUI  | Alt  |Lower |    Space    |Raise | VolDn| VolUp| Pl/Ps| Next |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  KC_BSPC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    SE_SCLN, KC_BSPC, \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    SE_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    SE_COMM, SE_DOT,  SE_SLSH, KC_ENT , \
  KC_LCTL,  ADJUST, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT  \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Bksp |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Adjust| GUI  | Alt  |Lower |    Space    |Raise | VolDn| VolUp| Pl/Ps| Next |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_BSPC,  SE_QUOT, SE_COMM, SE_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    SE_SLSH, \
  KC_LSFT, SE_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
  KC_LCTL, ADJUST, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Del  |   \  |   *  |   (  |   )  |      |      |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   <  |   +  |   {  |   }  |   "  |      |   4  |   5  |   6  |   -  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   -  |   =  |   [  |   ]  |   '  |      |   1  |   2  |   3  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Alt  |      |      |Space |   0  |   ,  |   .  | Enter|      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_DEL,SE_BSLS, SE_ASTR, SE_LPRN, SE_RPRN, _______, _______, KC_7,    KC_8,    KC_9,    SE_ASTR, _______, \
  _______,  SE_LABK, SE_PLUS, SE_LCBR, SE_RCBR, SE_DQUO, _______, KC_4,    KC_5,    KC_6,    SE_MINS, SE_SLSH, \
  _______, SE_MINS, SE_EQL,  SE_LBRC, SE_RBRC, SE_QUOT, _______, KC_1,    KC_2,    KC_3,    SE_PLUS, _______, \
  _______, _______, _______, KC_LALT, _______, _______,  KC_SPC, KC_0, SE_COMM,    SE_DOT,  KC_ENT,  _______  \
),

/* Raise: featuring vim-style hjkl arrow keys
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  `   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  | Left | Down |  Up  |Right |      |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 | Home | PgDn | PgUp | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  SE_TILD, SE_EXLM, SE_AT,   SE_HASH, SE_DLR,  SE_PERC, SE_CIRC, SE_AMPR, SE_ASTR, SE_LPRN, SE_RPRN, KC_GRAVE,  \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, SE_PIPE, \
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, \
  _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |QWERTY|Colemk|Dvorak|      | Prev | Pl/Ps| Next |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Mute | VolDn| VolUp|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |BRTUP |BRTDWN|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |SYSREQ|      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______,  QWERTY,  COLEMAK, DVORAK,  _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_DEL,  \
  _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_BRIGHTNESS_UP, KC_BRIGHTNESS_DOWN, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SYSREQ, _______  \
)


};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
  }
  return true;
}
