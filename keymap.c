/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _MEDIA,
  _NUMPAD
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

#define LOWER LT(_LOWER, KC_SPC)
#define RAISE LT(_RAISE, KC_SPC)
#define NUMPAD LT(_NUMPAD, KC_TAB)
#define RAISE_2 MO(_RAISE)

#define PRINT S(G(KC_4))
#define LOCK C(G(KC_Q))

// // Left-hand home row mods
// #define HOME_S LCTL_T(KC_S)
// #define HOME_D LALT_T(KC_D)
// #define HOME_F LGUI_T(KC_F)
//
// // Right-hand home row mods
// #define HOME_J RGUI_T(KC_J)
// #define HOME_K LALT_T(KC_K)
// #define HOME_L RCTL_T(KC_L)

// Disable Left-hand home row mods
#define HOME_S KC_S
#define HOME_D KC_D
#define HOME_F KC_F

// Disable Right-hand home row mods
#define HOME_J KC_J
#define HOME_K KC_K
#define HOME_L KC_L

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Num  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  | Rght |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
          KC_ESC,    KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
          KC_TAB,    KC_A,  HOME_S,  HOME_D, HOME_F,   KC_G,    KC_H,  HOME_J,  HOME_K,  HOME_L, KC_SCLN,  KC_ENT,
   OSM(MOD_LSFT),    KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
          _______, KC_LCTL, KC_LALT, KC_LGUI,  NUMPAD, LOWER,  RAISE, RAISE_2, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down |  Up  | Rght |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Shift |
 * |------+------+------+------+~-----+------+------+------+------+------+------+------|
 * | Lock |Print |      |      |      |             |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 *
 */
[_LOWER] = LAYOUT_planck_grid(
        KC_GRV ,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
        _______, _______, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_ENT,
  OSM(MOD_LSFT), _______, _______, _______, _______, _______, _______,  KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_RSFT,
        _______, _______, _______, _______, _______,  KC_SPC,  KC_SPC, _______, _______, _______, _______, _______
),


/* Raise
 * |-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   -  |   =  |   [  |  ]   |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   "  |   '  |  \   |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  >=  |  <<  |  >>  |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *
 */
[_RAISE] = LAYOUT_planck_grid(
        KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        _______, _______, _______, _______, _______, _______, _______, KC_MINS,   KC_EQL, KC_LBRC, KC_RBRC, KC_PIPE,
  OSM(MOD_LSFT), _______, _______, _______, _______, _______, _______, _______,  KC_DQUO, KC_QUOT, KC_BSLS, KC_RSFT,
        _______, _______, _______, _______, _______,  KC_SPC,  KC_SPC, _______,  KC_HOME, KC_PGDN, KC_PGUP, KC_END
),
/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   7  |   8  |   9  |   /  | BKsp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   *  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   0  |   ,  |   .  |   +  |      |
 * `-----------------------------------------------------------------------------------'
 *
 */
[_NUMPAD] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,   KC_9, KC_SLSH, KC_BSPC,
    _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,   KC_6, KC_ASTR, KC_ENT,
    _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,   KC_3, KC_MINS, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_0, KC_COMM, KC_DOT, KC_PLUS, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down |  Up  | Rght |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Shift |
 * |------+------+------+------+~-----+------+------+------+------+------+------+------|
 * | Lock |Print |      |      |      |             |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 *
 */
[_MEDIA] = LAYOUT_planck_grid(
       LOCK,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______,
    _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,
    _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______, _______, _______, _______,   PRINT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _MEDIA);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // switch (keycode) {
  //   case QWERTY:
  //     if (record->event.pressed) {
  //       print("mode just switched to qwerty and this is a huge string\n");
  //       set_single_persistent_default_layer(_QWERTY);
  //     }
  //     return false;
  //     break;
  // }
  return true;
}
