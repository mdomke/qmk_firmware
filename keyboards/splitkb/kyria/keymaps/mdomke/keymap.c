/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
  LAY_QWERTY = 0,
  LAY_NAV,
  LAY_SYM,
  LAY_NUM,
  LAY_ADJUST,
  LAY_FKEYS,
};

// Aliases for readability
#define SYM       MO(LAY_SYM)
#define NAV       MO(LAY_NAV)
#define NUM       MO(LAY_NUM)
#define ADJUST    MO(LAY_ADJUST)
#define FKEYS     MO(LAY_FKEYS)

#define LSFT_A    MT(MOD_LSFT, KC_A)
#define RSFT_SCLN MT(MOD_RSFT, KC_SCLN)
#define ALT_ENT   MT(MOD_LALT, KC_ENT)
#define ALT_EQL   MT(MOD_RALT,KC_EQL)
#define LCTL_SPC  MT(MOD_LCTL, KC_SPC)
#define RCTL_SPC  MT(MOD_RCTL, KC_SPC)
#define HYPR_ESC  LCAG_T(KC_ESC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTZ
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | Bspc   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Hyp/Esc| ⇧/A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ⇧/; :| ' "    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Nav    |   Z  |   X  |   C  |   V  |   B  | FKs  |CapsLk|  |Adjust| Lead |   N  |   M  | ,  < | . >  | /  ? |   - _  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                               | LGUI | Enter| Space| Num  |  | Sym  | Space|   =  | RGUI |
 *                               |      |  Alt | Ctrl |      |  |      | Ctrl |  Alt |      |
 *                               `---------------------------'  `----------------------------
 */
    [LAY_QWERTY] = LAYOUT(
     KC_TAB  , KC_Q  ,  KC_W   , KC_E   , KC_R   , KC_T   ,                                       KC_Y   , KC_U   , KC_I   , KC_O  , KC_P     , KC_BSPC  ,
     HYPR_ESC, LSFT_A,  KC_S   , KC_D   , KC_F   , KC_G   ,                                       KC_H   , KC_J   , KC_K   , KC_L  , RSFT_SCLN, KC_QUOTE,
     NAV     , KC_Z  ,  KC_X   , KC_C   , KC_V   , KC_B   , FKEYS    , KC_CAPS, ADJUST, KC_LEAD , KC_N   , KC_M   , KC_COMM, KC_DOT, KC_SLSH  , KC_MINS  ,
                                KC_MUTE, KC_LGUI, ALT_ENT, LCTL_SPC , NUM    , SYM   , RCTL_SPC, ALT_EQL, KC_RGUI, KC_APP
    ),

/*
 *
 * ,-------------------------------------------.                             ,-------------------------------------------.
 * |        |      |      |      |      |      |                             |      | PgDn | PgUp |      |      | Delete |
 * |--------+------+------+------+------+------|                             |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                             |   ←  |   ↓  |   ↑  |   →  |      |        |
 * |--------+------+------+------+------+------+-------------. ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      | |      |      | Insrt| Home | End  |      |      | PrtSc  |
 * `----------------------+------+------+------+------+------| |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      | |      |      |      |      |      |
 *                        |      |      |      |      |      | |      |      |      |      |      |
 *                        `----------------------------------' `----------------------------------'
 *
 */
   [LAY_NAV] = LAYOUT(
   _______,  _______, _______, _______, _______, _______,                                    _______ , KC_PGDN, KC_PGUP, _______, _______, KC_DEL ,
   _______,  _______, _______, _______, _______, _______,                                    KC_LEFT , KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
   _______,  _______, _______, _______, _______, _______, _______, KC_SLCK, _______, _______,KC_INS  , KC_HOME, KC_END,  _______, _______, KC_PSCR,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),
/*
 * Lower Layer: Numpad, Media
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      | VolUp|      |      |                              | /    | 7 &  | 8 *  | 9 (  | -    |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next |      |                              | *    | 4 $  | 5 %  | 6 ^  | .    | =      |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      | VolDn| Pause|      |      |      |  |      |      | 0 )  | 1 !  | 2 @  | 3 #  | +    |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LAY_NUM] = LAYOUT(
      _______, _______, _______, KC_VOLU, _______ , _______,                                     KC_PSLS, KC_7,    KC_8,    KC_9, KC_PMNS , _______,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT , _______,                                     KC_PAST, KC_4,    KC_5,    KC_6, KC_PDOT , KC_PEQL,
      _______, _______, _______, KC_VOLD, KC_PAUSE, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3, KC_PPLS , _______,
                                 _______, _______ , _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Raise Layer: Symbols
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |  ~   |  {   |  }   |      |                              |      |      |  €   |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  %   |  @   |  (   |  )   |  `   |                              |   #  |  =   |  +   |  :   |  !   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  $   |  ^   |  [   |  ]   |  |   |      |      |  |      |      |   &  |  *   |  -   |  /   |  \   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LAY_SYM] = LAYOUT(
      _______, _______, KC_TILD, KC_LCBR, KC_RCBR, _______,                                     _______, _______, ALGR(KC_5),_______,_______,_______,
      _______, KC_PERC, KC_DLR , KC_LPRN, KC_RPRN, KC_GRV ,                                     KC_HASH, KC_EQL,  KC_PLUS, KC_COLN,  KC_EXLM,_______,
      _______, KC_CIRC, KC_AT  , KC_LBRC, KC_RBRC, KC_PIPE, _______, _______, _______, _______, KC_AMPR, KC_ASTR, KC_MINS, KC_SLSH,  KC_BSLS,_______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


/*
 * Adjust Layer

 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | SAI  | HUI  | VAI  | TOG  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LAY_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, RGB_SAI, RGB_HUI, RGB_VAI, RGB_TOG,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Function Keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      | F7   | F8   | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      | F4   | F5   | F6   | F11  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      | F1   | F2   | F3   | F12  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LAY_FKEYS] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("       Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case LAY_QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case LAY_NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case LAY_SYM:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
          case LAY_NUM:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case LAY_ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case LAY_FKEYS:
            oled_write_P(PSTR("Function\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    return false;
}
#endif

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_A) {
          SEND_STRING(SS_LGUI(SS_LCTL("q")));
        }

        SEQ_ONE_KEY(KC_S) {
          SEND_STRING(SS_LGUI(SS_LSFT("4")));
        }
        
        SEQ_TWO_KEYS(KC_C, KC_B) { // Code block
            SEND_STRING("```" SS_LSFT("\n\n") "``` " SS_TAP(X_UP));
        }
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_A:
        case RSFT_SCLN:
            return 160;
        default:
            return TAPPING_TERM;
    }
}
