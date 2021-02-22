#include "satan.h"

// Easier-to-read layout
#define _______ KC_TRNS

enum unicode_names {
  POO,
  SNEK,
  IRONY,
  EGGP,
  FLEX,
  TACO,
  BRTO
};

const uint32_t PROGMEM unicode_map[] = {
  [POO] = 0x1F4A9, // 💩 poo
  [SNEK] = 0x1F40D, // 🐍 snake
  [IRONY] = 0x2E2E,  // ⸮ irony
  [EGGP] = 0x1F346, // 🍆 eggplant
  [FLEX] = 0x1F4AA, // 💪 flex
  [TACO] = 0x1F32E, // 🌮 taco
  [BRTO] = 0x1F32F, // 🌯 Burrito
};

#define C_MTCE MT(MOD_LCTL, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Base layout is basic 60% QWERTY with a few changes
  // * capslock is escape/control mod_tap combo
  // * Backspace is split into backspace+delete
  // * Left shift is split into layer_up+shift
  // * Right shift is split into shift+layer_up
  // * Enter is split into two keys, but both keys are enter
  LAYOUT_all(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    C_MTCE,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_ENT,
    MO(1),   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, TO(1),
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, TO(1),   KC_RCTL),

  // Second layer
  // * Function keys on number keys
  // * WASD are mouse direction
  // * Space is mouse button1
  // * alt keys are mouse button 2
  // * hjkl are arrows to vim standard
  // * +/- are volume up/down
  // * Backspace/delete are home/end
  LAYOUT_all(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_VOLD, KC_VOLU, KC_HOME, KC_END,
    _______, _______, KC_MS_U, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    TO(0),   KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, _______,
    _______, MO(2),   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_BTN2,                            KC_BTN1,                            KC_BTN2, _______, TO(0),   _______),

  // Unicode/emoji layer
  // Access this by hitting both halfs of left shift plus the letter
  LAYOUT_all(
    _______, _______, _______, _______, KC_END,  _______, KC_HOME, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______,
    _______, _______, _______, X(EGGP), _______, X(TACO), _______, _______, X(IRONY), _______, X(POO), _______, _______, _______,
    _______, _______, X(SNEK), _______, X(FLEX), _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, X(BRTO), _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                            _______,                            _______, _______, _______, _______),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  return MACRO_NONE;
}

void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
};

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_NUM_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    DDRB |= (1 << 2); PORTB &= ~(1 << 2);
  } else {
    DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_COMPOSE)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_KANA)) {

  } else {

  }

}
