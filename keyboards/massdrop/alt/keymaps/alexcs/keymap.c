#include QMK_KEYBOARD_H

enum alt_keycodes {
    L_BRI = SAFE_RANGE, //LED Brightness Increase
    L_BRD,              //LED Brightness Decrease
    L_EDG_I,            //LED Edge Brightness Increase
    L_EDG_D,            //LED Edge Brightness Decrease
    L_EDG_M,            //LED Edge lighting mode
    L_PTN,              //LED Pattern Select Next
    L_PTP,              //LED Pattern Select Previous
    L_PSI,              //LED Pattern Speed Increase
    L_PSD,              //LED Pattern Speed Decrease
    L_T_MD,             //LED Toggle Mode
    L_T_ONF,            //LED Toggle On / Off
    L_ON,               //LED On
    L_OFF,              //LED Off
    L_T_BR,             //LED Toggle Breath Effect
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction and effect
    U_T_AGCR,           //USB Toggle Automatic GCR control
    DBG_TOG,            //DEBUG Toggle On / Off
    DBG_MTRX,           //DEBUG Toggle Matrix Prints
    DBG_KBD,            //DEBUG Toggle Keyboard Prints
    DBG_MOU,            //DEBUG Toggle Mouse Prints
    DBG_FAC,            //DEBUG Factory light testing (All on white)
    MD_BOOT             //Restart into bootloader after hold timeout
};

enum tapdance_keycodes {
    TD_ESCP = 0, // Single tap for Esc, double for CAPS
};

//Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
        [TD_ESCP] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
    TD(TD_ESCP), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
        L_T_BR,  L_PSD,   L_BRI,   L_PSI,   L_EDG_I, _______, _______, _______, U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END,  \
        L_T_PTD, L_PTP,   L_BRD,   L_PTN,   L_EDG_D, _______, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, \
        _______, L_T_MD,  L_T_ONF, _______, L_EDG_M, MD_BOOT, NK_TOGG, _______, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        _______, _______, _______,                            DBG_FAC,                            _______, _______,   L_PTP, KC_PGDN, L_PTN    \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    [RGB] = LAYOUT(
        GRV:   0,  1,         2,         3,      4,      5,      6,      7,      8,         9,        0: 10,     MINS: 11,   EQL: 12,   BSPC: 13,  DEL: 14,
        TAB:  15,  Q: 16,     W: 17,     E: 18,  R: 19,  T: 20,  Y: 21,  U: 22,  I: 23,     O: 24,    P: 25,     LBRC: 26,   RBRC: 27,  BSLC: 28,  HOME: 29,
        CAPS: 30,  A: 31,     S: 32,     D: 33,  F: 34,  G: 35,  H: 36,  J: 37,  K: 38,     L: 39,    SCLN: 40,  QUOT: 41,              ENTR: 42,  PGUP: 43,
        LSFT: 44,  Z: 45,     X: 46,     C: 47,  V: 48,  B: 49,  N: 50,  M: 51,  COMM: 52,  DOT: 53,  SLSH: 54,  RSFT: 55,              UP: 56,    PGDN: 57,
        LCTL: 58,  LGUI: 59,  LALT: 60,                SPC: 61,                             RALT: 62,  Fn: 63,             LEFT:  64,   DOWN: 65,  RGHT: 66,
    ),
    [MATRIX] = LAYOUT(
        0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,
        15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
        30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42     ,  43,
        44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55     ,  56,  57,
        58,  59,  60,            61,                 62,  63,        64,  65,  66
    ),
    */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;
    static uint8_t scroll_effect = 0;

    switch (keycode) {
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_EDG_M:
            if (record->event.pressed) {
                led_edge_mode++;
                if (led_edge_mode > LED_EDGE_MODE_MAX) {
                    led_edge_mode = LED_EDGE_MODE_ALL;
                }
            }
            return false;
        case L_EDG_I:
            if (record->event.pressed) {
                led_edge_brightness += 0.1;
                if (led_edge_brightness > 1) { led_edge_brightness = 1; }
            }
            return false;
        case L_EDG_D:
            if (record->event.pressed) {
                led_edge_brightness -= 0.1;
                if (led_edge_brightness < 0) { led_edge_brightness = 0; }
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                I2C3733_Control_Set(!I2C3733_Control_Get());
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                I2C3733_Control_Set(1);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                I2C3733_Control_Set(0);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                scroll_effect++;
                if (scroll_effect == 1) {               //Patterns with scroll move horizontal (Right to left)
                    led_animation_direction = 1;
                    led_animation_orientation = 0;
                    led_animation_circular = 0;
                } else if (scroll_effect == 2) {        //Patterns with scroll move vertical (Top to bottom)
                    led_animation_direction = 1;
                    led_animation_orientation = 1;
                    led_animation_circular = 0;
                } else if (scroll_effect == 3) {        //Patterns with scroll move vertical (Bottom to top)
                    led_animation_direction = 0;
                    led_animation_orientation = 1;
                    led_animation_circular = 0;
                } else if (scroll_effect == 4) {        //Patterns with scroll explode from center
                    led_animation_direction = 0;
                    led_animation_orientation = 0;
                    led_animation_circular = 1;
                } else if (scroll_effect == 5) {        //Patterns with scroll implode on center
                    led_animation_direction = 1;
                    led_animation_orientation = 0;
                    led_animation_circular = 1;
                } else {                                //Patterns with scroll move horizontal (Left to right)
                    scroll_effect = 0;
                    led_animation_direction = 0;
                    led_animation_orientation = 0;
                    led_animation_circular = 0;
                }
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_FAC:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                led_lighting_mode = LED_MODE_NORMAL;
                led_edge_brightness = 1;
                led_edge_mode = LED_EDGE_MODE_ALL;
                led_animation_breathing = 0;
                led_animation_id = 7; //led_programs.c led_setups leds_white index
                gcr_desired = LED_GCR_MAX;
                I2C3733_Control_Set(1);
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= BOOTKEY_HOLD_MS) {
                    reset_keyboard();
                }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

led_instruction_t led_instructions[] = {
    //LEDs are normally inactive, no processing is performed on them
    //Flags are used in matching criteria for an LED to be active and indicate how to color it
    //Flags can be found in tmk_core/protocol/arm_atsam/led_matrix.h (prefixed with LED_FLAG_)
    //LED IDs can be found in config_led.h in the keyboard's directory
    //Examples are below
    
    //All LEDs use the user's selected pattern (this is the factory default)
    { .flags = LED_FLAG_USE_ROTATE_PATTERN },

    //Specific LEDs use the user's selected pattern while all others are off
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id0 = 0xFFFFFFFF, .id1 = 0xAAAAAAAA, .id2 = 0x55555555, .id3 = 0x11111111 },

    //Specific LEDs use specified RGB values while all others are off
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0xFF, .id1 = 0x00FF, .id2 = 0x0000FF00, .id3 = 0xFF000000, .r = 75, .g = 150, .b = 225 },
    
    //All LEDs use the user's selected pattern
    //On layer 1, all key LEDs (except the top row which keeps active pattern) are red while all edge LEDs are green
    //When layer 1 is active, key LEDs use red    (id0  32 -  16: 1111 1111 1111 1111 1000 0000 0000 0000 = 0xFFFF8000) (except top row 15 - 1)
    //When layer 1 is active, key LEDs use red    (id1  64 -  33: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //When layer 1 is active, key LEDs use red    (id2  67 -  65: 0000 0000 0000 0000 0000 0000 0000 0111 = 0x00000007)
    //When layer 1 is active, edge LEDs use green (id2  95 -  68: 1111 1111 1111 1111 1111 1111 1111 1000 = 0xFFFFFFF8)
    //When layer 1 is active, edge LEDs use green (id3 105 -  96: 0000 0000 0000 0000 0000 0011 1111 1111 = 0x000003FF)
    // { .flags = LED_FLAG_USE_ROTATE_PATTERN },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 0xFFFF8000, .id1 = 0xFFFFFFFF, .id2 = 0x00000007, .r = 255, .layer = 1 },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id2 = 0xFFFFFFF8, .id3 = 0x000003FF, .g = 127, .layer = 1 },

    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 0x11702001, .id1 = 0xDCF887F8, .id2 = 0xFFFFFFFF, .g = 63, .layer = 1 },

    //All key LEDs use red while edge LEDs use the active pattern
    //All key LEDs use red     (id0  32 -   1: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //All key LEDs use red     (id1  64 -  33: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //All key LEDs use red     (id2  67 -  65: 0000 0000 0000 0000 0000 0000 0000 0111 = 0x00000007)
    //Edge uses active pattern (id2  95 -  68: 1111 1111 1111 1111 1111 1111 1111 1000 = 0xFFFFFFF8)
    //Edge uses active pattern (id3 105 -  96: 0000 0000 0000 0000 0000 0011 1111 1111 = 0x000003FF)
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0xFFFFFFFF, .id1 = 0xFFFFFFFF, .id2 = 0x00000007, .r = 255 },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN , .id2 = 0xFFFFFFF8, .id3 = 0x000003FF },

    //end must be set to 1 to indicate end of instruction set
    { .end = 1 }
};
