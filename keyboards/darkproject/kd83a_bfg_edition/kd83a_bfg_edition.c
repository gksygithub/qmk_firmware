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

#include "kd83a_bfg_edition.h"

#ifdef RGB_MATRIX_ENABLE

const aw_led g_aw_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |     R location
 *   |     |          G location
 *   |     |          |          B location
 *   |     |          |          | */
    //{0, CS1_SW4,   CS2_SW4,   CS3_SW4},   //   0, k00, Esc
    
    {0, CS1_SW1,   CS2_SW1,   CS3_SW1},   //   0, k00, Esc
    {0, CS1_SW2,   CS2_SW2,   CS3_SW2},   //   1, k10, F1
    {0, CS1_SW3,   CS2_SW3,   CS3_SW3},   //   2, k20, F2
    {0, CS1_SW4,   CS2_SW4,   CS3_SW4},   //   3, k30, F3
    {0, CS1_SW5,   CS2_SW5,   CS3_SW5},   //   4, k40, F4
    {0, CS1_SW6,   CS2_SW6,   CS3_SW6},   //   5, k50, F5
    {0, CS1_SW7,   CS2_SW7,   CS3_SW7},   //   6, k60, F6
    {0, CS1_SW8,   CS2_SW8,   CS3_SW8},   //   7, k70, F7
    {0, CS1_SW9,   CS2_SW9,   CS3_SW9},   //   8, k80, F8
    {0, CS1_SW10,  CS2_SW10,  CS3_SW10},  //   9, k90, F9
    {0, CS1_SW11,  CS2_SW11,  CS3_SW11},  //  10, ka0, F10
    {0, CS1_SW12,  CS2_SW12,  CS3_SW12},  //  11, kb0, F11
    {1, CS1_SW1,   CS2_SW1,   CS3_SW1},   //  12, kc0, F12
    {1, CS4_SW2,   CS5_SW2,   CS6_SW2},   //  13, kd0, Printscreen
    {1, CS4_SW5,   CS5_SW5,   CS6_SW5},   //  14, k56, Del
  
    {0, CS4_SW1,   CS5_SW1,   CS6_SW1},   //  15, k01, `
    {0, CS4_SW2,   CS5_SW2,   CS6_SW2},   //  16, k11, 1
    {0, CS4_SW3,   CS5_SW3,   CS6_SW3},   //  17, k21, 2
    {0, CS4_SW4,   CS5_SW4,   CS6_SW4},   //  18, k31, 3
    {0, CS4_SW5,   CS5_SW5,   CS6_SW5},   //  19, k41, 4
    {0, CS4_SW6,   CS5_SW6,   CS6_SW6},   //  20, k51, 5
    {0, CS4_SW7,   CS5_SW7,   CS6_SW7},   //  21, k61, 6
    {0, CS4_SW8,   CS5_SW8,   CS6_SW8},   //  22, k71, 7
    {0, CS4_SW9,   CS5_SW9,   CS6_SW9},   //  23, k81, 8
    {0, CS4_SW10,  CS5_SW10,  CS6_SW10},  //  24, k91, 9
    {0, CS4_SW11,  CS5_SW11,  CS6_SW11},  //  25, ka1, 0
    {0, CS4_SW12,  CS5_SW12,  CS6_SW12},  //  26, kb1, -
    {1, CS1_SW5,   CS2_SW5,   CS3_SW5},   //  27, kc1, =
    {1, CS1_SW7,   CS2_SW7,   CS3_SW7},   //  28, kd1, Backspace
    {1, CS1_SW2,   CS2_SW2,   CS3_SW2},   //  29, k16, Home

    {0, CS7_SW1,   CS8_SW1,   CS9_SW1},   //  30, k02, Tab
    {0, CS7_SW2,   CS8_SW2,   CS9_SW2},   //  31, k12, Q
    {0, CS7_SW3,   CS8_SW3,   CS9_SW3},   //  32, k22, W
    {0, CS7_SW4,   CS8_SW4,   CS9_SW4},   //  33, k32, E
    {0, CS7_SW5,   CS8_SW5,   CS9_SW5},   //  34, k42, R
    {0, CS7_SW6,   CS8_SW6,   CS9_SW6},   //  35, k52, T
    {0, CS7_SW7,   CS8_SW7,   CS9_SW7},   //  36, k62, Y
    {0, CS7_SW8,   CS8_SW8,   CS9_SW8},   //  37, k72, U
    {0, CS7_SW9,   CS8_SW9,   CS9_SW9},   //  38, k82, I
    {0, CS7_SW10,  CS8_SW10,  CS9_SW10},  //  39, k92, O
    {0, CS7_SW11,  CS8_SW11,  CS9_SW11},  //  40, ka2, P
    {0, CS7_SW12,  CS8_SW12,  CS9_SW12},  //  41, kb2, [
    {1, CS1_SW8,   CS2_SW8,   CS3_SW8},   //  42, kc2, ]
    {1, CS1_SW9,   CS2_SW9,   CS3_SW9},   //  43, kd3, "\\"
    {1, CS4_SW3,   CS5_SW3,   CS6_SW3},   //  44, k06, End
  
    {0, CS10_SW1,  CS11_SW1,  CS12_SW1},  //  45, k03, Caps Lock
    {0, CS10_SW2,  CS11_SW2,  CS12_SW2},  //  46, k13, A
    {0, CS10_SW3,  CS11_SW3,  CS12_SW3},  //  47, k23, S
    {0, CS10_SW4,  CS11_SW4,  CS12_SW4},  //  48, k33, D
    {0, CS10_SW5,  CS11_SW5,  CS12_SW5},  //  49, k43, F
    {0, CS10_SW6,  CS11_SW6,  CS12_SW6},  //  50, k53, G
    {0, CS10_SW7,  CS11_SW7,  CS12_SW7},  //  51, k63, H
    {0, CS10_SW8,  CS11_SW8,  CS12_SW8},  //  52, k73, J
    {0, CS10_SW9,  CS11_SW9,  CS12_SW9},  //  53, k83, K
    {0, CS10_SW10, CS11_SW10, CS12_SW10}, //  54, k93, L
    {0, CS10_SW11, CS11_SW11, CS12_SW11}, //  55, ka3, ;
    {0, CS10_SW12, CS11_SW12, CS12_SW12}, //  56, kb3, '
    {1, CS1_SW11,  CS2_SW11,  CS3_SW11},  //  57, kc3, Enter
    {1, CS4_SW4,   CS5_SW4,   CS6_SW4},   //  58, k26, PgUp
   
    {0, CS13_SW1,  CS14_SW1,  CS15_SW1},  //  59, k04, Shift_L
    {0, CS13_SW2,  CS14_SW2,  CS15_SW2},  //  60, k24, Z
    {0, CS13_SW3,  CS14_SW3,  CS15_SW3},  //  61, k34, X
    {0, CS13_SW4,  CS14_SW4,  CS15_SW4},  //  62, k44, C
    {0, CS13_SW5,  CS14_SW5,  CS15_SW5},  //  63, k54, V
    {0, CS13_SW6,  CS14_SW6,  CS15_SW6},  //  64, k64, B
    {0, CS13_SW7,  CS14_SW7,  CS15_SW7},  //  65, k74, N
    {0, CS13_SW8,  CS14_SW8,  CS15_SW8},  //  66, k84, M
    {0, CS13_SW9,  CS14_SW9,  CS15_SW9},  //  67, k94, ,
    {0, CS13_SW10, CS14_SW10, CS15_SW10}, //  68, ka4, .
    {0, CS13_SW11, CS14_SW11, CS15_SW11}, //  69, kb4, /
    {1, CS4_SW8,   CS5_SW8,   CS6_SW8},   //  70, kd4, Shift_R
    {1, CS4_SW9,   CS5_SW9,   CS6_SW9},   //  71, k17, Up
    {1, CS4_SW7,   CS5_SW7,   CS6_SW7},   //  72, k36, PgDn

    {0, CS16_SW1,  CS17_SW1,  CS18_SW1},  //  73, k05, Ctrl_L
    {0, CS16_SW2,  CS17_SW2,  CS18_SW2},  //  74, k15, Win_L
    {0, CS16_SW3,  CS17_SW3,  CS18_SW3},  //  75, k25, Alt_L
    {0, CS16_SW6,  CS17_SW6,  CS18_SW6},  //  76, k65, Space
    {0, CS16_SW9,  CS17_SW9,  CS18_SW9},  //  77, k95, Alt_R
    {0, CS16_SW10, CS17_SW10, CS18_SW10}, //  78, ka5, FN
    {0, CS16_SW12, CS17_SW12, CS18_SW12}, //  79, kc5, Ctrl_R
    {1, CS4_SW10,  CS5_SW10,  CS6_SW10},  //  80, k07, Left
    {1, CS4_SW11,  CS5_SW11,  CS6_SW11},  //  81, k27, Down
    {1, CS10_SW5,  CS11_SW5,  CS12_SW5},  //  82, k37, Right
   
    {1, CS10_SW10, CS11_SW10, CS12_SW10}, //  83, Z1
    {1, CS10_SW11, CS11_SW11, CS12_SW11}, //  84, Z2  
};

#define __ NO_LED
//#define RGB_LAYOUT LAYOUT

led_config_t g_led_config = {

{
    { 59, __, 14, 80, 79, 82, 73,  5},
    { 31, 30, 46,  0, 60, 58, 15, 16},
    { 32, 45, 47, __, 61, 72, 1 , 17},
    { 33,  3, 48, 4, 62, 71,   2, 18},
    { 34, 35, 49, 50, 63, 64, 20, 19},
    { 37, 36, 52, 51, 66, 65, 21, 22},
    { 38, 42, 53,  6, 67, 44, 27, 23},
    { 39,  7, 54, 81, 68, __,  8, 24},
    { 40, 41, 55, 56, __, 69, 26, 25},
    { 74, 70, 78, 75, 76, 77, __, 13},
    { __, 28, 43, 11, 57, 12,  9, 10},
    { 83, __, __, __, __, __, __, __},
    { __, __, __, __, __, __, 29, __},
    { 84, __, __, __, __, __, __, __} 
},
{
    // 1U = 12
    {    12,   0}, //   0, k00, Esc
    {    36,   0}, //   1, k10, F1
    {    48,   0}, //   2, k20, F2
    {    60,   0}, //   3, k30, F3
    {    72,   0}, //   4, k40, F4
    {    84,   0}, //   5, k50, F5
    {    96,   0}, //   6, k60, F6
    {   108,   0}, //   7, k70, F7
    {   120,   0}, //   8, k80, F8
    {   132,   0}, //   9, k90, F9
    {   144,   0}, //  10, ka0, F10
    {   156,   0}, //  11, kb0, F11
    {   168,   0}, //  12, kc0, F12
    {   180,   0}, //  13, kd0, Printscreen
    {   192,   0}, //  14, k56, Del

    {    12,  12}, //  15, k01, `
    {    24,  12}, //  16, k11, 1
    {    36,  12}, //  17, k21, 2
    {    48,  12}, //  18, k31, 3
    {    60,  12}, //  19, k41, 4
    {    72,  12}, //  20, k51, 5
    {    84,  12}, //  21, k61, 6
    {    96,  12}, //  22, k71, 7
    {   108,  12}, //  23, k81, 8
    {   120,  12}, //  24, k91, 9
    {   132,  12}, //  25, ka1, 0
    {   144,  12}, //  26, kb1, -
    {   156,  12}, //  27, kc1, =
    {   174,  12}, //  28, kd1, Backspace
    {   192,  12}, //  29, k16, Home

    {    15,  24}, //  30, k02, Tab
    {    30,  24}, //  31, k12, Q
    {    42,  24}, //  32, k22, W
    {    54,  24}, //  33, k32, E
    {    66,  24}, //  34, k42, R
    {    78,  24}, //  35, k52, T
    {    90,  24}, //  36, k62, Y
    {   102,  24}, //  37, k72, U
    {   114,  24}, //  38, k82, I
    {   126,  24}, //  39, k92, O
    {   138,  24}, //  40, ka2, P
    {   150,  24}, //  41, kb2, [
    {   162,  24}, //  42, kc2, ]
    {   177,  24}, //  43, kd3, "\\"
    {   192,  24}, //  44, k06, End

    {  16.5,  36}, //  45, k03, Caps Lock
    {    33,  36}, //  46, k13, A
    {    45,  36}, //  47, k23, S
    {    57,  36}, //  48, k33, D
    {    69,  36}, //  49, k43, F
    {    81,  36}, //  50, k53, G
    {    93,  36}, //  51, k63, H
    {   105,  36}, //  52, k73, J
    {   117,  36}, //  53, k83, K
    {   129,  36}, //  54, k93, L
    {   141,  36}, //  55, ka3, ;
    {   153,  36}, //  56, kb3, '
    { 172.5,  36}, //  57, kc3, Enter
    {   192,  36}, //  58, k26, PgUp

    {  19.5,  48}, //  59, k04, Shift_L
    {    39,  48}, //  60, k24, Z
    {    51,  48}, //  61, k34, X
    {    63,  48}, //  62, k44, C
    {    75,  48}, //  63, k54, V
    {    87,  48}, //  64, k64, B
    {    99,  48}, //  65, k74, N
    {   111,  48}, //  66, k84, M
    {   123,  48}, //  67, k94, ,
    {   135,  48}, //  68, ka4, .
    {   147,  48}, //  69, kb4, /
    { 163.5,  48}, //  70, kd4, Shift_R
    {   180,  48}, //  70, k17, Up
    {   192,  48}, //  72, k36, PgDn

    {  13.5,  60}, //  73, k05, Ctrl_L
    {  28.5,  60}, //  74, k15, Win_L
    {  43.5,  60}, //  75, k25, Alt_L
    {  88.5,  60}, //  76, k65, Space
    {   132,  60}, //  77, k95, Alt_R
    {   144,  60}, //  78, ka5, FN
    {   156,  60}, //  79, kc5, Ctrl_R
    {   168,  60}, //  80, k07, Left
    {   180,  60}, //  81, k27, Down
    {   192,  60}, //  82, k37, Right

    {     0,  18}, // 83, Z1
    {     0,  28}, // 84, Z2  
}, 
{
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4,
} 
};
#endif

#ifdef EEPROM_ENABLE

#include "spi_master.h"

void spi_init(void) {
    static bool is_initialised = false;
    if (!is_initialised) {
        is_initialised = true;

        // Try releasing special pins for a short time
        setPinInput(SPI_SCK_PIN);
        setPinInput(SPI_MOSI_PIN);
        setPinInput(SPI_MISO_PIN);

        chThdSleepMilliseconds(10);

        palSetPadMode(PAL_PORT(SPI_SCK_PIN), PAL_PAD(SPI_SCK_PIN), PAL_MODE_ALTERNATE(SPI_SCK_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL | PAL_OUTPUT_SPEED_HIGHEST | PAL_WB32_CURRENT_LEVEL3);
        palSetPadMode(PAL_PORT(SPI_MOSI_PIN), PAL_PAD(SPI_MOSI_PIN), PAL_MODE_ALTERNATE(SPI_MOSI_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL | PAL_OUTPUT_SPEED_HIGHEST);
        palSetPadMode(PAL_PORT(SPI_MISO_PIN), PAL_PAD(SPI_MISO_PIN), PAL_MODE_ALTERNATE(SPI_MISO_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL | PAL_OUTPUT_SPEED_HIGHEST);
    }
}

#endif

#ifdef ENCODER_ENABLE

bool encoder_update_kb(uint8_t index, bool clockwise) {

    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return true;
}
#endif

