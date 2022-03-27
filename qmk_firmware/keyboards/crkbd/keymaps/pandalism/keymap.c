/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <keymap_uk.h>
#include <stdio.h>

enum crkbd_layers {
  _BASE,
  _MOUSE,
  _SYMB,
  _NUMPD,
  _NAV,
  _BRCKT,
  _FUNC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------.                    ,----------------------------------------------------------------------------.
       KC_NO,       KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                   KC_J,   KC_L,           KC_U,           KC_Y,           KC_QUOT,        KC_NO, 
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
       KC_NO,       LGUI_T(KC_A),   LALT_T(KC_R),   LCTL_T(KC_S),   LSFT_T(KC_T),   KC_G,                   KC_M,   RSFT_T(KC_N),   RCTL_T(KC_E),   RALT_T(KC_I),   RGUI_T(KC_O),   KC_NO,
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
       KC_NO,       KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                   KC_K,   KC_H,           KC_COMM,        KC_DOT,         KC_SLSH,        KC_NO, 
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
                                    LT(1,KC_ESC),   LT(2,KC_TAB),   LT(3,KC_SPC),                           LT(4,KC_ENT),           LT(5,KC_BSPC),  LT(6,KC_DEL)
                                    //`---------------------------------------------'                      `------------------------------------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
  // Mouse
  //,-----------------------------------------------------------------------------------.                    ,----------------------------------------------------------------------------.
       KC_NO,       KC_PSCR,        KC_NO,          KC_NO,          KC_NO,          KC_NO,                  KC_NO,  KC_WH_U,        KC_MS_U,        KC_WH_D,        KC_NO,          KC_NO, 
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
       KC_NO,       KC_LGUI,        KC_LALT,        KC_LCTL,        KC_LSFT,        KC_CAPS,                KC_WH_L, KC_MS_L,       KC_MS_D,        KC_MS_R,        KC_WH_R,        KC_NO, 
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
       KC_NO,       KC_SLCK,        KC_NO,          KC_NO,          KC_NO,          KC_NO,                  KC_NO,  KC_ACL0,        KC_ACL1,        KC_ACL2,        KC_NO,          KC_NO, 
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
                                    LT(1,KC_ESC),   KC_NO,          KC_NO,                                  KC_BTN1,                KC_BTN2,        KC_BTN3
                                    //`---------------------------------------------'                      `------------------------------------------------------'                       
  ),

  [_SYMB] = LAYOUT_split_3x6_3(
  // Symbols
  //,-----------------------------------------------------------------------------------.                    ,----------------------------------------------------------------------------.
       KC_NO,       KC_PSCR,        KC_NO,          KC_NO,          KC_NO,          KC_NO,                  KC_QUES, KC_PERC,       KC_QUOT,        KC_GRV,         KC_CIRC,        KC_NO,
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
       KC_NO,       KC_LGUI,        KC_LALT,        KC_LCTL,        KC_LSFT,        KC_CAPS,                KC_EXLM, KC_AMPR,       UK_PIPE,        UK_TILD,        UK_COLN,        KC_NO, 
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
       KC_NO,       KC_SLCK,        KC_NO,          KC_NO,          KC_NO,          KC_NO,                  KC_NUHS, UK_DQUO,         UK_PND,        KC_DLR,         UK_EURO,        KC_NO, 
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
                                    KC_NO,          LT(2,KC_TAB),   KC_NO,                                  KC_ENT,                 KC_BSPC,        KC_DEL
                                    //`---------------------------------------------'                      `------------------------------------------------------'
  ),

  [_NUMPD] = LAYOUT_split_3x6_3(
  // NUMPAD
  //,-----------------------------------------------------------------------------------.                    ,----------------------------------------------------------------------------.
      KC_NO,        RGB_TOG,        RGB_MOD,        RGB_RMOD,       KC_NO,          RGB_VAI,                KC_PSLS, KC_7,          KC_8,           KC_9,           KC_MINS,        KC_NO,
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------| 
       KC_NO,       KC_LGUI,        KC_LALT,        KC_LCTL,        KC_LSFT,        RGB_VAD,                KC_PAST, KC_4,          KC_5,           KC_6,           KC_EQL,         KC_NO,
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
       KC_NO,       RGB_HUI,        RGB_HUD,        RGB_SAI,        RGB_SAD,        KC_NO,                  KC_EQL, KC_1,          KC_2,           KC_3,           KC_PENT,        KC_NO,
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
                                    KC_NO,          KC_NO,          LT(3,KC_SPC),                           KC_PENT,                KC_0,          KC_TAB
                                    //`---------------------------------------------'                      `------------------------------------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  // NAV
  //,-----------------------------------------------------------------------------------.                    ,----------------------------------------------------------------------------.
       KC_NO,       KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         LCTL(KC_Y),                KC_MPLY, KC_MNXT,       KC_MPRV,        KC_NO,          KC_PSCR,        KC_NO, 
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
       KC_NO,       KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RGHT,        LCTL(KC_Z),                KC_CAPS, KC_RSFT,       KC_RCTL,        KC_RALT,        KC_RGUI,        KC_NO,
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
       KC_NO,       KC_CALC,        KC_MYCM,        KC_INS,         KC_PAUS,        KC_NO,                  KC_VOLU, KC_VOLD,       KC_MUTE,        KC_NO,          KC_SLCK,        KC_NO,
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
                                    LCTL(KC_X),         LCTL(KC_C),        LCTL(KC_V),                                LT(4,KC_ENT),           KC_NO,          KC_NO
                                    //`---------------------------------------------'                      `------------------------------------------------------'
  ),

  [_BRCKT] = LAYOUT_split_3x6_3(
  // Brackets
  //,-----------------------------------------------------------------------------------.                    ,----------------------------------------------------------------------------.
       KC_NO,       KC_GT,          KC_RBRC,        KC_RCBR,        KC_RPRN,        UK_MINS,                KC_NO,   KC_NO,         KC_NO,          KC_NO,          KC_PSCR,        KC_NO, 
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
       KC_NO,       KC_LT,          KC_LBRC,        KC_LCBR,        KC_LPRN,        UK_UNDS,                KC_CAPS, KC_RSFT,       KC_RCTL,        KC_RALT,        KC_RGUI,        KC_NO, 
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
       KC_NO,       UK_BSLS,          KC_SLSH,        KC_SCLN,        KC_COLN,      UK_DQUO,                  KC_NO,   KC_NO,         KC_NO,          KC_NO,          KC_SLCK,        KC_NO, 
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
                                    KC_ESC,         KC_TAB,         KC_SPC,                                 KC_NO,   LT(5,KC_BSPC),                 KC_NO
                                    //`---------------------------------------------'                      `------------------------------------------------------'
  ),


  [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------.                    ,----------------------------------------------------------------------------.
       KC_NO,       KC_PSCR,        KC_NO,          KC_NO,          KC_NO,          KC_NO,                  KC_PSCR, KC_F7,         KC_F8,          KC_F9,          KC_F12,         KC_NO, 
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
       KC_NO,       KC_LGUI,        KC_LALT,        KC_LCTL,        KC_LSFT,        KC_CAPS,                KC_CAPS, KC_F4,         KC_F5,          KC_F6,          KC_F11,         KC_NO, 
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
       KC_NO,       KC_SLCK,        KC_NO,          KC_NO,          KC_NO,          KC_NO,                  KC_SLCK, KC_F1,         KC_F2,          KC_F3,          KC_F10,         KC_NO, 
  //|------------+----------------+---------------+---------------+--------------+--------|               |--------+--------------+--------------+---------------+---------------+--------|
                                    KC_ESC,         KC_TAB,         KC_SPC,                                 KC_NO,                  KC_NO, LT(6,KC_DEL)
                                    //`---------------------------------------------'                      `------------------------------------------------------'
  )
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}


void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (biton32(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case _MOUSE:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        case _SYMB:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case _NUMPD:
            oled_write_ln_P(PSTR("Numpad"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Nav"), false);
            break;  
        case _BRCKT:
            oled_write_ln_P(PSTR("Bracket"), false);
            break;
        case _FUNC:
            oled_write_ln_P(PSTR("Func"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
