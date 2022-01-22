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
#include <stdio.h>
char wpm_str[10];

#define SH_SLSH RSFT_T(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // MacOS Base
    [0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
           KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,                            KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_BSPC,
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           MO(1),     KC_A,       KC_R,       KC_S,       KC_T,       KC_G,                            KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_QUOT,
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_LGUI,      KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,                            KC_K,       KC_H,       KC_COMM,    KC_DOT,     SH_SLSH,    KC_ENT,
        //|-----------+-----------+-----------+-----------+-----------+-----------+------|      |------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                           MO(2),    MO(8), OSM(MOD_LSFT),     KC_SPC, MO(10),    KC_RCTL
		    							               //`-------------------------------'      `-------------------------------'
    ),
    // MacOS Nav
    [1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
           KC_TAB,     KC_TRNS,    KC_TRNS,    LCTL(KC_E), KC_TRNS,    KC_TRNS,                         MEH(KC_K), LCTL(KC_U), KC_UP,     LAG(KC_I),   LCTL(KC_P), LALT(KC_BSPC),
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_TRNS,    LCTL(KC_A), KC_LALT,    KC_LGUI,    MEH(KC_V),  KC_TRNS,                         LGUI(KC_Z), KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_MINS,    KC_GRV,
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_TRNS,    KC_TRNS,    KC_TRNS,    LCTL(KC_C), KC_TRNS,    KC_TRNS,                         LCA(KC_B),  LCTL(KC_N), RCS(KC_BSLS),KC_EXLM,KC_TRNS,  KC_ESC,
        //|-----------+-----------+-----------+-----------+-----------+-----------+------|      |------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                           KC_TRNS,    KC_TRNS,    KC_TRNS,      LGUI(KC_SPC), LCTL(KC_SLSH), KC_TRNS
		    							               //`-------------------------------'      `-------------------------------'
    ),
    [2] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
           KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                         MEH(KC_J),  MEH(KC_L),  MEH(KC_U),  MEH(KC_Y),  MEH(KC_SCLN),KC_DELETE,
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_VOLD,    KC_VOLU,    KC_MUTE,                         MEH(KC_M),  MEH(KC_N),  MEH(KC_E),  MEH(KC_I),  MEH(KC_O),  MEH(KC_QUOT),
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_TRNS,    KC_TRNS,    KC_TRNS,    DF(3),      DF(6),      KC_TRNS,                         LCA(KC_B),       LCA(KC_N),       RCS(KC_BSLS),MEH(KC_BSLS),     SH_SLSH,    KC_ENT,
        //|-----------+-----------+-----------+-----------+-----------+-----------+------|      |------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                           KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS, KC_RALT
		    							               //`-------------------------------'      `-------------------------------'
    ),
    // Windows
    [3] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
           KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,                            KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_BSPC,
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           MO(4),      KC_A,       KC_R,       KC_S,       KC_T,       KC_G,                            KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_QUOT,
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_LCTL,      KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,                            KC_K,       KC_H,       KC_COMM,    KC_DOT,     SH_SLSH,    KC_ENT,
        //|-----------+-----------+-----------+-----------+-----------+-----------+------|      |------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                           MO(5),    MO(9), OSM(MOD_LSFT),     KC_SPC,  MO(10),   KC_RALT
		    							               //`-------------------------------'      `-------------------------------'
    ),
    // Windows Nav
    [4] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_END,     KC_TRNS,    KC_TRNS,                         KC_TRNS,    KC_TRNS,    KC_UP,      KC_TRNS,    KC_TRNS,    LCTL(KC_BSPC),
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_TRNS,    KC_HOME,    KC_LCTL,    KC_LALT,    KC_TRNS,    KC_TRNS,                         LCTL(KC_Z), KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_MINS,    KC_GRV,
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                         KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_EXLM,    KC_TRNS,    KC_ESC,
        //|-----------+-----------+-----------+-----------+-----------+-----------+------|      |------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                           KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_RGUI,KC_TRNS,   KC_TRNS
		    							               //`-------------------------------'      `-------------------------------'
    ),
    [5] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
           KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                         KC_TRNS,    LAG(KC_U),  LAG(KC_I),  LAG(KC_O),  KC_TRNS,    KC_TRNS,
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_VOLD,    KC_VOLU,    KC_MUTE,                         LAG(KC_H),  LAG(KC_J),  LAG(KC_K),  LAG(KC_L),  LAG(KC_P),  KC_TRNS,
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_TRNS,    KC_TRNS,    KC_TRNS,    DF(0),      DF(6),      KC_TRNS,                         KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        //|-----------+-----------+-----------+-----------+-----------+-----------+------|      |------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                           KC_TRNS,    KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS
		    							               //`-------------------------------'      `-------------------------------'
    ),
    // GAMING
    [6] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
	       KC_TAB, 	   KC_Q, 	   KC_W, 	   KC_E, 	   KC_R, 	   KC_T, 							KC_Y,       KC_U, 	    KC_I, 	    KC_O, 	    KC_P, 	    KC_TRNS,
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
        LT(7, KC_ESC), KC_A, 	   KC_S, 	   KC_D,       KC_F, 	   KC_G, 	    					KC_H, 	    KC_J, 	    KC_K, 	    KC_L,       KC_SCLN,    KC_TRNS,
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
	       KC_LSFT,    KC_Z, 	   KC_X, 	   KC_C,       KC_V, 	   KC_B,    					    KC_N, 	    KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_TRNS,
        //|-----------+-----------+-----------+-----------+-----------+-----------+------|      |------+-----------+-----------+-----------+-----------+-----------+-----------|
	    									               KC_LCTL,    KC_SPC,  KC_LALT, 	     KC_TRNS, KC_TRNS, DF(3)
		    							               //`-------------------------------'      `-------------------------------'
    ),
    // GAMING (Funcs)
    [7] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
	       KC_TRNS,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,    					    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
	       KC_TRNS,    KC_F1, 	   KC_F2, 	   KC_F3,      KC_F4, 	   KC_TRNS, 	    				KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
	    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
	       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    				        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        //|-----------+-----------+-----------+-----------+-----------+-----------+------|      |------+-----------+-----------+-----------+-----------+-----------+-----------|
	    									               KC_TRNS,    KC_TRNS,  KC_TRNS, 	     KC_TRNS, KC_TRNS,  KC_TRNS
		    							               //`-------------------------------'      `-------------------------------'
    ),
    // SYMBOLS / Shortcuts (MacOS)KC_EQL, KC_GT
    [8] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
           LGUI(KC_TAB), LGUI(KC_Q), LGUI(KC_W), LGUI(KC_F), LGUI(KC_P), LGUI(KC_B),                    KC_AMPR,    KC_LBRC,     KC_LCBR,    KC_RCBR,    KC_RBRC, LGUI(KC_BSPC),
        //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_TRNS,  LGUI(KC_A),  LGUI(KC_R),  LGUI(KC_S),  LGUI(KC_T),  LGUI(KC_G),                    KC_DLR,    KC_EQL,     KC_LPRN,    KC_RPRN,    KC_GT,      KC_GRV,
        //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_TRNS,  LGUI(KC_Z),  LGUI(KC_X),  LGUI(KC_C),  LGUI(KC_D),  LGUI(KC_V),                    KC_CIRC,   KC_PIPE,    KC_ASTR,    KC_EXLM,    KC_BSLS, LGUI(KC_SLSH),
        //|-----------+-----------+-----------+-----------+-----------+-----------+------|      |------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                           KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS,  KC_TRNS
		    							               //`-------------------------------'      `-------------------------------'
    ),
    // SYMBOLS / Shortcuts (Windows)
    [9] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
           LCTL(KC_TAB), LCTL(KC_Q), LCTL(KC_W), LCTL(KC_F), LCTL(KC_P), LCTL(KC_B),                    KC_AMPR,    KC_LBRC,     KC_LCBR,    KC_RCBR,    KC_RBRC, LCTL(KC_BSPC),
        //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_TRNS,    LCTL(KC_A), LCTL(KC_R), LCTL(KC_S), LCTL(KC_T), LCTL(KC_G),                      KC_DLR,    KC_EQL,     KC_LPRN,    KC_RPRN,    KC_GT,      KC_GRV,
        //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_TRNS,    LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_D), LCTL(KC_V),                      KC_CIRC,   KC_PIPE,    KC_ASTR,    KC_EXLM,    KC_BSLS, LCTL(KC_SLSH),
        //|-----------+-----------+-----------+-----------+-----------+-----------+------|      |------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                           KC_TRNS,    KC_TRNS,   KC_TRNS,       KC_TRNS, KC_TRNS,  KC_TRNS
		    							               //`-------------------------------'      `-------------------------------'
    ),
    // NUMBERS
    [10] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
           KC_TILDE,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                         KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_PLUS,    KC_COLN,    KC_BSPC,
        //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_COMM,    KC_4,       KC_3,       KC_2,       KC_1,       KC_5,                            KC_6,       KC_0,       KC_9,       KC_8,       KC_7,       KC_DOT,
        //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                         KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        //|-----------+-----------+-----------+-----------+-----------+-----------+------|      |------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                           KC_TRNS,    KC_TRNS,   KC_TRNS,      KC_TRNS, KC_TRNS,   KC_TRNS
		    							               //`-------------------------------'      `-------------------------------'
    )
};

#define L_MAC 0
#define L_WINDOWS 3
#define L_GAMING 6

#ifdef OLED_ENABLE
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//   if (!is_keyboard_master()) {
//     return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
//   }
//   return rotation;
// }


void oled_render_layer_state(void) {
    oled_write_P(PSTR("OS: "), false);
    switch (get_highest_layer(default_layer_state)) {
        case L_MAC:
            oled_write_ln_P(PSTR("Mac"), false);
            break;
        case L_WINDOWS:
            oled_write_ln_P(PSTR("Windows"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Gaming"), false);
    }

}

void oled_render_mod_state(void) {
  oled_advance_page(true);
  oled_write_P(PSTR("Oneshot: "), false);
  if (get_oneshot_mods() & MOD_MASK_SHIFT) {
    oled_write_ln_P(PSTR("SHIFT"), false);
  }
  if (get_oneshot_mods() & MOD_MASK_CTRL) {
    oled_write_ln_P(PSTR("CTRL "), false);
  }
  if (get_oneshot_mods() & MOD_MASK_ALT) {
    oled_write_ln_P(PSTR("ALT  "), false);
  }
  if (get_oneshot_mods() & MOD_MASK_GUI) {
    oled_write_ln_P(PSTR("GUI  "), false);
  }
  if (!get_oneshot_mods()) {
    oled_write_ln_P(PSTR("off  "), false);
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
    oled_write_P(PSTR("\n"), false);
    char name = ' ';
        if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
            (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k:%2d %c",
            record->event.key.row, record->event.key.col,
            keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

static void render_logo(void) {
  static const char PROGMEM my_logo[] = {
// 'Pichu-Eyes', 128x32px
0x00, 0x01, 0x01, 0x01, 0x03, 0x02, 0x06, 0x04, 0x0c, 0x08, 0x18, 0x10, 0x30, 0x20, 0x60, 0x40,
0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0,
0x78, 0x0e, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfc,
0x78, 0x30, 0x60, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x30, 0x60, 0xe0, 0x20,
0x20, 0x60, 0x60, 0x60, 0x60, 0x70, 0x58, 0x46, 0xc3, 0xc1, 0xc0, 0xc0, 0x80, 0xc0, 0xc0, 0x60,
0x40, 0xc0, 0x80, 0x00, 0x1e, 0xfe, 0x04, 0x0c, 0x18, 0x10, 0x30, 0x60, 0x40, 0xc0, 0x80, 0x80,
0x00, 0x00, 0x01, 0x01, 0x03, 0x06, 0x04, 0x0c, 0x18, 0x10, 0x30, 0x60, 0x40, 0xc0, 0xfe, 0x07,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff,
0xf8, 0xf0, 0x70, 0x78, 0x18, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xf8, 0x8c, 0x84, 0x86, 0x86, 0xc6, 0xff, 0xff, 0xff, 0xff,
0xff, 0xfe, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xfc,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xc0, 0x00, 0x01, 0x03, 0x02, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x03, 0x02, 0x06, 0x0c, 0x08, 0x18, 0x30, 0x20, 0x60, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x01, 0x03,
0x02, 0x06, 0x0e, 0x1a, 0x32, 0x62, 0xc2, 0x84, 0x08, 0x30, 0xc0, 0x00, 0x00, 0x01, 0x01, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
0x0f, 0x87, 0x81, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xfe, 0x0f,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x0f, 0xfc, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x06, 0x0c,
0x08, 0x18, 0x30, 0x60, 0x40, 0xc0, 0x80, 0xff, 0x00, 0x80, 0x40, 0x1e, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0c, 0x04, 0x06, 0x02, 0x02, 0x03, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x02, 0x02, 0x06, 0x04, 0x0c, 0x18, 0x10, 0x30, 0x60,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x04, 0x00, 0x01,
0x80, 0xc0, 0x40, 0x20, 0x20, 0x30, 0x20, 0x20, 0x20, 0x21, 0x22, 0x3c, 0x3e, 0x23, 0x60, 0x60,
0x60, 0x40, 0x40, 0x40, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  oled_write_raw_P(my_logo, sizeof(my_logo));
}


bool cancel_all_oneshots(void) {
      bool queue = true;

  if (get_oneshot_mods() && !has_oneshot_mods_timed_out()) {
    clear_oneshot_mods();
    queue = false;
  }

  if (get_oneshot_locked_mods()) {
    clear_oneshot_mods();
    clear_oneshot_locked_mods();
    unregister_mods(get_mods());
    queue = false;
  }

  return queue;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool queue = true;

  switch (keycode) {
    case 21762:
    if (record->event.pressed) {
        if (get_oneshot_mods()) {
            queue = cancel_all_oneshots();
        }
        break;
    }
  }

  if (record->event.pressed) {
    set_keylog(keycode, record);
  }

  return queue;
}


void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
        oled_render_mod_state();
    } else {
        render_logo();
    }
}

#endif // OLED_ENABLE

const uint16_t PROGMEM grv_combo[] = {KC_M, KC_N, COMBO_END};
const uint16_t PROGMEM exclamation_combo[] = {KC_DOT, KC_COMM, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(grv_combo, KC_GRV),
    COMBO(exclamation_combo, KC_EXLM), // keycodes with modifiers are possible too!
};
