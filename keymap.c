#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

#ifdef OLED_DRIVER_ENABLE
static uint32_t oled_timer = 0;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _QWERTY,
  _ADJUST,
};

// Custom keycodes for layer keys
// Dual function escape with left command
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     ADJUST,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX,\
  //---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,\
  //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, XXXXXXX, KC_SPC,     KC_BSPC, KC_ENT,  XXXXXXX
                                      //|--------------------------|  |--------------------------|
  ),

  [_ADJUST] = LAYOUT(
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

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
  RGB_current_mode = rgblight_config.mode;
  #endif
}

void rgb_matrix_indicators_user(void) {
  #ifdef RGB_MATRIX_ENABLE
  switch (biton32(layer_state)) {
    default:
      if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
          rgb_matrix_set_color(i, 255, 200, 0);
        }
      }
      break;
  }
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
//   oled_write_P(PSTR("corne by  GuisR"), false);
}

void render_layer_state(void) {
  static const char PROGMEM default_layer[] = {
    0x20, 0x94, 0x95, 0x96, 0x20,
    0x20, 0xb4, 0xb5, 0xb6, 0x20,
    0x20, 0xd4, 0xd5, 0xd6, 0x20, 0
  };
  static const char PROGMEM adjust_layer[] = {
    0x20, 0x9d, 0x9e, 0x9f, 0x20,
    0x20, 0xbd, 0xbe, 0xbf, 0x20,
    0x20, 0xdd, 0xde, 0xdf, 0x20, 0
  };

  if (layer_state_is(_ADJUST)) {
    oled_write_P(adjust_layer, false);
  } else {
    oled_write_P(default_layer, false);
  }
}

void render_status_main(void) {
  render_logo();
//   render_space();
//   render_layer_state();
//   render_space();
//   render_mod_status_gui_alt(get_mods() | get_oneshot_mods());
//   render_mod_status_ctrl_shift(get_mods() | get_oneshot_mods());
}

void render_status_secondary(void) {
  render_logo();
//   render_space();
//   render_layer_state();
//   render_space();
//   render_mod_status_gui_alt(get_mods() | get_oneshot_mods());
//   render_mod_status_ctrl_shift(get_mods() | get_oneshot_mods());
}

void oled_task_user(void) {
  #ifndef SPLIT_KEYBOARD
  oled_on();
  #endif

  if (is_master) {
    render_status_main(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_status_secondary();
  }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record -> event.pressed) {
    #ifdef OLED_DRIVER_ENABLE
    oled_timer = timer_read32();
    #endif
  }

  switch (keycode) {
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

#ifdef RGB_MATRIX_ENABLE
void suspend_power_down_user(void) {
  rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
  rgb_matrix_set_suspend_state(false);
}
#endif
