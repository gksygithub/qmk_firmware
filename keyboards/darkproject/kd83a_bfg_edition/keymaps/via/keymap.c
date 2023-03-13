/* Copyright 2022 GSKY <gskyGit@gsky.com.tw>
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


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
enum my_keycodes {
    KC_MC = SAFE_RANGE,
    KC_LPAD,
    KC_SIRI,
    KC_DND,
    KC_SPOT,
    KC_EJ,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
    switch (keycode) {

        case KC_MC:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
              
                //add_weak_mods(MOD_BIT(KC_1));
                //tap_code16(KC_1);
                //rgblight_step();
            } else {
                host_consumer_send(0);
                //rgblight_step();
            }
            return false; /* Skip all further processing of this key */

        case KC_LPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
               // rgblight_step_reverse();
            } else {
                host_consumer_send(0);
               //rgblight_step_reverse();
            }
            return false; /* Skip all further processing of this key */

        case KC_SIRI: 
            if (record->event.pressed) {

               host_consumer_send(0xCF);
               // rgblight_step_reverse();
            } else {
                host_consumer_send(0);
               //rgblight_step_reverse();
            }
            return false; /* Skip all further processing of this key */

        case KC_DND:
            if (record->event.pressed) {
               // host_consumer_send(0x2A0);
               host_system_send(0x9B);
               // rgblight_step_reverse();
            } else {
               host_system_send(0);
               //rgblight_step_reverse();
            }
            return false; /* Skip all further processing of this key */

        case KC_SPOT:
            if (record->event.pressed) {
               host_consumer_send(0x221);
               // rgblight_step_reverse();
            } else {
                host_consumer_send(0);
               //rgblight_step_reverse();
            }
            return false; /* Skip all further processing of this key */ 

        case KC_EJ:
            if (record->event.pressed) {
               host_consumer_send(0x0B8);
               // rgblight_step_reverse();
            } else {
                host_consumer_send(0);
               //rgblight_step_reverse();
            }
            return false; /* Skip all further processing of this key */
        

        
        default:
            return true; /* Process all other keycodes normally */
    }
};

void housekeeping_task_user(void) {
    writePin(C15, keymap_config.no_gui);
};

void keyboard_pre_init_user(void) {

    setPinInputLow(C15);
    writePin(C15, false);
    setPinInputLow(C0);
    writePin(C0, false);
};

enum custom_layers {
    Win,
    Mac,
    Winfn,
    Macfn,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
[Win] = LAYOUT(
  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL, 
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME, 
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_END,    
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGUP,    
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_PGDN,    
  KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(Winfn),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[Mac] = LAYOUT(
  KC_ESC,   KC_BRID,  KC_BRIU,  KC_MC,    KC_SIRI,  KC_F5,    KC_F6,    KC_MRWD,  KC_MPLY,  KC_MFFD,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_PSCR,  KC_DEL,   
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME, 
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_END,    
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGUP,    
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_PGDN,    
  KC_LCTL,  KC_LALT,  KC_LGUI,                      KC_SPC,                                 KC_RALT,  MO(Macfn),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[Winfn] = LAYOUT(
  KC_ESC,   KC_MYCM,  KC_MAIL,  KC_WSCH,  KC_WHOM,  KC_CALC,  KC_MSEL,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_PSCR,  RGB_MOD,  
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  RGB_HUI, 
  KC_TAB,   KC_Q,     TO(Win),  KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_END,    
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGUP,    
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     TO(Mac),  KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            RGB_VAI,  KC_PGDN,    
  KC_LCTL,  GUI_TOG,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(Winfn),KC_RCTL,  RGB_SPD,  RGB_VAD,  RGB_SPI),

[Macfn] = LAYOUT(
  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  RGB_MOD, 
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  RGB_HUI, 
  KC_TAB,   KC_Q,     TO(Win),  KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_END,    
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGUP,    
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     TO(Mac),  KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            RGB_VAI,  KC_PGDN,    
  KC_LCTL,  KC_LALT,  KC_LGUI,                      KC_SPC,                                 KC_RALT,  MO(Winfn),KC_RCTL,  RGB_SPD,  RGB_VAD,  RGB_SPI),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [Win] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
        [Mac] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
        [Winfn] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)  },
        [Macfn] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
};
#endif

void led_init_ports(void) {
  setPinOutput(C0);
  setPinOutput(C14);
  setPinOutput(C15);
};


layer_state_t layer_state_set_user(layer_state_t state) {

    writePin(C0, layer_state_cmp(state, 1));

    return state;

};
