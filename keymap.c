#include QMK_KEYBOARD_H
#include <stdio.h>

extern keymap_config_t keymap_config;

extern uint8_t is_master;

#define NAV_LT LT(_NAV, KC_ENT)
#define NUMS_LT LT(_NUMS, KC_TAB)
#define HOME_A GUI_T(KC_A)
#define HOME_R ALT_T(KC_R)
#define HOME_S CTL_T(KC_S)
#define HOME_T SFT_T(KC_T)
#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_I RALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _COLEMAK_DH,
  _NUMS,
  _FN,
  _NAV,
  _ADJUST,
  _QWERTY,
};

// Custom keycodes for layer keys
// Dual function escape with left command
enum custom_keycodes {
  COLEMAK_DH = SAFE_RANGE,
  NUMS,
  FN,
  NAV,
  ADJUST,
  QWERTY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     ADJUST,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,                         KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, NUMS_LT, KC_SPC,     KC_BSPC, NAV_LT,  XXXXXXX
                                      //|--------------------------|  |--------------------------|
  ),

  [_NUMS] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_DLR,  KC_PLUS, KC_LPRN, KC_RPRN, KC_AT,                        KC_BSLS, KC_MINS, KC_EQL,  XXXXXXX, KC_PAST, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_EXLM, KC_HASH, XXXXXXX, KC_QUOT, KC_GRV,                       KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, XXXXXXX, XXXXXXX,    KC_DEL,  KC_ESC, XXXXXXX
                                      //|--------------------------|  |--------------------------|
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_F11,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F12,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, FN,      XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //|--------------------------|  |--------------------------|
  ),

  [_FN] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, RGB_VAD,                      RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //|--------------------------|  |--------------------------|
  ),

  [_QWERTY] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     ADJUST,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, NUMS_LT, KC_SPC,     KC_BSPC, NAV_LT,  XXXXXXX
                                      //|--------------------------|  |--------------------------|
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,  \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUI, RGB_SAI, RGB_SPI, RGB_VAI, RGB_MOD,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUD, RGB_SAD, RGB_SPD, RGB_VAD, RGB_RMOD,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //|--------------------------|  |--------------------------|
  ),
};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NUMS_LT:
      return false;
    default:
      return true;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case HOME_A:
    case HOME_R:
    case HOME_I:
    case HOME_O:
      return TAPPING_TERM + 50;\
    default:
      return TAPPING_TERM;
  }
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  // TODO:
};

void rgb_matrix_indicators_user(void) {
  #ifdef RGB_MATRIX_ENABLE
  switch (biton32(layer_state)) {
    case _NUMS:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        rgb_matrix_set_color(i, 155, 89, 182);
      }
      break;

    case _NAV:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        rgb_matrix_set_color(i, 52, 152, 219);
      }
      break;

    default:
      if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
          // CAPS LOCK is ON
          rgb_matrix_set_color(i, 231, 76, 60);
        }
      }
      break;
  }
  #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NUMS:
      if (record->event.pressed) {
        layer_on(_NUMS);
      } else {
        layer_off(_NUMS);
      }
      return false;

    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
      } else {
        layer_off(_NAV);
      }
      return false;

    case ADJUST:
      if (record -> event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
  }
  return true;
}

void suspend_power_down_user(void) {
  #ifdef OLED_DRIVER_ENABLE
  oled_off();
  #endif

  #ifdef RGB_MATRIX_ENABLE
  rgb_matrix_set_suspend_state(true);
  #endif
}

void suspend_wakeup_init_user(void) {
  #ifdef OLED_DRIVER_ENABLE
  oled_on();
  #endif

  #ifdef RGB_MATRIX_ENABLE
  rgb_matrix_set_suspend_state(false);
  #endif
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

void render_space(void) {
  oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
  static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
  static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
  static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
  static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

  static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
  static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
  static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
  static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

  // fillers between the modifier icons bleed into the icon frames
  static const char PROGMEM off_off_1[] = {0xc5, 0};
  static const char PROGMEM off_off_2[] = {0xc6, 0};
  static const char PROGMEM on_off_1[] = {0xc7, 0};
  static const char PROGMEM on_off_2[] = {0xc8, 0};
  static const char PROGMEM off_on_1[] = {0xc9, 0};
  static const char PROGMEM off_on_2[] = {0xca, 0};
  static const char PROGMEM on_on_1[] = {0xcb, 0};
  static const char PROGMEM on_on_2[] = {0xcc, 0};

  if (modifiers & MOD_MASK_GUI) {
    oled_write_P(gui_on_1, false);
  } else {
    oled_write_P(gui_off_1, false);
  }

  if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
    oled_write_P(on_on_1, false);
  } else if (modifiers & MOD_MASK_GUI) {
    oled_write_P(on_off_1, false);
  } else if (modifiers & MOD_MASK_ALT) {
    oled_write_P(off_on_1, false);
  } else {
    oled_write_P(off_off_1, false);
  }

  if (modifiers & MOD_MASK_ALT) {
    oled_write_P(alt_on_1, false);
  } else {
    oled_write_P(alt_off_1, false);
  }

  if (modifiers & MOD_MASK_GUI) {
    oled_write_P(gui_on_2, false);
  } else {
    oled_write_P(gui_off_2, false);
  }

  if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
    oled_write_P(on_on_2, false);
  } else if (modifiers & MOD_MASK_GUI) {
    oled_write_P(on_off_2, false);
  } else if (modifiers & MOD_MASK_ALT) {
    oled_write_P(off_on_2, false);
  } else {
    oled_write_P(off_off_2, false);
  }

  if (modifiers & MOD_MASK_ALT) {
    oled_write_P(alt_on_2, false);
  } else {
    oled_write_P(alt_off_2, false);
  }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
  static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
  static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
  static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
  static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

  static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
  static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
  static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
  static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

  // fillers between the modifier icons bleed into the icon frames
  static const char PROGMEM off_off_1[] = {0xc5, 0};
  static const char PROGMEM off_off_2[] = {0xc6, 0};
  static const char PROGMEM on_off_1[] = {0xc7, 0};
  static const char PROGMEM on_off_2[] = {0xc8, 0};
  static const char PROGMEM off_on_1[] = {0xc9, 0};
  static const char PROGMEM off_on_2[] = {0xca, 0};
  static const char PROGMEM on_on_1[] = {0xcb, 0};
  static const char PROGMEM on_on_2[] = {0xcc, 0};

  if (modifiers & MOD_MASK_CTRL) {
    oled_write_P(ctrl_on_1, false);
  } else {
    oled_write_P(ctrl_off_1, false);
  }

  if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
    oled_write_P(on_on_1, false);
  } else if (modifiers & MOD_MASK_CTRL) {
    oled_write_P(on_off_1, false);
  } else if (modifiers & MOD_MASK_SHIFT) {
    oled_write_P(off_on_1, false);
  } else {
    oled_write_P(off_off_1, false);
  }

  if (modifiers & MOD_MASK_SHIFT) {
    oled_write_P(shift_on_1, false);
  } else {
    oled_write_P(shift_off_1, false);
  }

  if (modifiers & MOD_MASK_CTRL) {
    oled_write_P(ctrl_on_2, false);
  } else {
    oled_write_P(ctrl_off_2, false);
  }

  if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
    oled_write_P(on_on_2, false);
  } else if (modifiers & MOD_MASK_CTRL) {
    oled_write_P(on_off_2, false);
  } else if (modifiers & MOD_MASK_SHIFT) {
    oled_write_P(off_on_2, false);
  } else {
    oled_write_P(off_off_2, false);
  }

  if (modifiers & MOD_MASK_SHIFT) {
    oled_write_P(shift_on_2, false);
  } else {
    oled_write_P(shift_off_2, false);
  }
}

void render_logo(void) {
  static const char PROGMEM corne_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0
  };
  oled_write_P(corne_logo, false);
  oled_write_P(PSTR("corne"), false);
}

void render_layer_state(void) {
  static const char PROGMEM default_layer[] = {
    0x20, 0x94, 0x95, 0x96, 0x20,
    0x20, 0xb4, 0xb5, 0xb6, 0x20,
    0x20, 0xd4, 0xd5, 0xd6, 0x20, 0
  };
  static const char PROGMEM nums_layer[] = {
    0x20, 0x97, 0x98, 0x99, 0x20,
    0x20, 0xb7, 0xb8, 0xb9, 0x20,
    0x20, 0xd7, 0xd8, 0xd9, 0x20, 0
  };
  static const char PROGMEM nav_layer[] = {
    0x20, 0x9a, 0x9b, 0x9c, 0x20,
    0x20, 0xba, 0xbb, 0xbc, 0x20,
    0x20, 0xda, 0xdb, 0xdc, 0x20, 0
  };
  static const char PROGMEM adjust_layer[] = {
    0x20, 0x9d, 0x9e, 0x9f, 0x20,
    0x20, 0xbd, 0xbe, 0xbf, 0x20,
    0x20, 0xdd, 0xde, 0xdf, 0x20, 0
  };

  if (layer_state_is(_ADJUST)) {
    oled_write_P(adjust_layer, false);
  } else if (layer_state_is(_NAV)) {
    oled_write_P(nav_layer, false);
  } else if (layer_state_is(_NUMS)) {
    oled_write_P(nums_layer, false);
  } else {
    oled_write_P(default_layer, false);
  }
}

void render_status_main(void) {
  render_logo();
  render_space();
  render_layer_state();
  render_space();
  render_mod_status_gui_alt(get_mods() | get_oneshot_mods());
  render_mod_status_ctrl_shift(get_mods() | get_oneshot_mods());
}

void render_status_secondary(void) {
  render_logo();
  render_space();
  render_layer_state();
  render_space();
  render_mod_status_gui_alt(get_mods() | get_oneshot_mods());
  render_mod_status_ctrl_shift(get_mods() | get_oneshot_mods());
}

void oled_task_user(void) {
  if (is_master) {
    render_status_main();
  } else {
    render_status_secondary();
  }
}
#endif
