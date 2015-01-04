/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
    LANG_KEY,
};

/*
 * Fn action definition
 * Plus meaningful names for function (FN) macros, they should be used without the KC_ prefix.
 */
static const uint16_t PROGMEM fn_actions[] = {
    // TEENSY programming
    #define KC_TEEN                              KC_FN0
    [0] =   ACTION_FUNCTION(TEENSY_KEY),

    // switch on layer 1
    #define KC_PL1                               KC_FN1
    [1] =   ACTION_LAYER_TOGGLE(2),

    // momentary layer 1
    #define KC_ML1                               KC_FN2
    [2] =   ACTION_LAYER_MOMENTARY(2),

    // switch language
    #define KC_LANG                              KC_FN3
    //[3] =   ACTION_MODS_KEY(MOD_LGUI, KC_SPC),
    [3] =   ACTION_FUNCTION(LANG_KEY),

    // switch on layer 2
    #define KC_PL2                               KC_FN4
    [4] =   ACTION_LAYER_TOGGLE(3),

    // reset layering, switch off all layers, only the default remains active
    #define KC_L0                                KC_FN5
    [5] =   ACTION_LAYER_CLEAR(ON_RELEASE),
};





static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Keymap: Layer 0. Same as Kinesis, but functions assigned to the additional keys of Ergodox.
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   `    |   1  |   2  |   3  |   4  |   5  | +L1  |           | +L2  |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  Tab   |   Q  |   W  |   E  |   R  |   T  | ~L1  |           | ~L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | CapsLk |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------| Lang |           | Esc  |------+------+------+------+------+--------|
     * |  LShf  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |  RShf  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | LGui |   =  | \Int |  Lft | Rght |                                       |  Up  |  Dn  |  [   |  ]   | RGui |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | LCtl | LAlt |       | RAlt | RCtl |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | Home |       | PgUp |      |      |
     *                                 | BkSp |  Del |------|       |------| Enter| Space|
     *                                 |      |      |  End |       | PgDn |      |      |
     *                                 `--------------------'       `--------------------'
     *
     ****************************************************************************************************
     *
     * Keymap: Layer 1. Make English input consistent with Hungarian Z-Y placement
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |   Z  |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |   Y  |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     *
     *
     *
     ****************************************************************************************************
     *
     *
     *
     * Keymap: Layer 2
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |  F1  |  F2  |  F3  |  F4  |  F5  | =L0  |           | =L0  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |  F11 |  F12 |  F13 |  F14 |  F15 |      |           |      |  F16 |  F17 |  F18 |  F19 |  F20 |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |  F21 |  F22 |  F23 |  F24 |  Ins |------|           |------|      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  LShf  |      |      |      |      |      |      |           |      |      | PrtSc| ScrLk| Pause|      |  RShf  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | LGui |      |      |      |      |                                       |      |      |      |      | RGui |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | LCtl | LAlt |       | RAlt | RCtl |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     *
     *
     *
     ****************************************************************************************************
     *
     *
     *
     * Keymap: Layer 3
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | Teensy |      |      |      |      |      | =L0  |           | =L0  |      | NumLk|   =  |   /  |   *  |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   -  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   +  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  | Enter|        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |      |   .  | Enter|      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |   0  |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     *
     *
     *
     ****************************************************************************************************
     *
     *
     * Keymap: Empty, to copy
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     *
     *
     *
     */

    KEYMAP(  // Layer 0
        // left hand
        GRV ,1   ,2   ,3   ,4   ,5   ,PL1 ,
        TAB ,Q   ,W   ,E   ,R   ,T   ,ML1 ,
        CAPS,A   ,S   ,D   ,F   ,G   ,
        LSFT,Z   ,X   ,C   ,V   ,B   ,LANG,
        LGUI,EQL ,NUBS,LEFT,RGHT,
                                      LCTL,LALT,
                                           HOME,
                                 BSPC,DEL ,END ,
        // right hand
             PL2 ,6   ,7   ,8   ,9   ,0   ,MINS,
             ML1 ,Y   ,U   ,I   ,O   ,P   ,BSLS,
                  H   ,J   ,K   ,L   ,SCLN,QUOT,
             ESC ,N   ,M   ,COMM,DOT ,SLSH,RSFT,
                       UP  ,DOWN,LBRC,RBRC,RGUI,
        RALT,RCTL,
        PGUP,
        PGDN,ENT ,SPC
    ),

    KEYMAP(  // Layer1:
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,Y   ,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,Z   ,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer2
        // left hand
        NO  ,F1  ,F2  ,F3  ,F4  ,F5  ,L0  ,
        NO  ,F11 ,F12 ,F13 ,F14 ,F15 ,TRNS,
        NO  ,F21 ,F22 ,F23 ,F24 ,INS ,
        TRNS,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        TRNS,NO  ,NO  ,NO  ,NO  ,
                                      TRNS,TRNS,
                                           NO  ,
                                 NO  ,NO  ,NO  ,
        // right hand
             L0  ,F6  ,F7  ,F8  ,F9  ,F10 ,NO  ,
             TRNS,F16 ,F17 ,F18 ,F19 ,F20 ,NO  ,
                  NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
             NO  ,TEEN,PSCR,SLCK,PAUS,NO  ,TRNS,
                       NO  ,NO  ,NO  ,NO  ,TRNS,
        TRNS,TRNS,
        NO  ,
        NO  ,NO  ,NO
    ),

    KEYMAP(  // Layer3
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,L0  ,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             L0  ,TRNS,NLCK,PEQL,PSLS,PAST,TRNS,
             TRNS,TRNS,P7  ,P8  ,P9  ,PMNS,TRNS,
                  TRNS,P4  ,P5  ,P6  ,PPLS,TRNS,
             TRNS,TRNS,P1  ,P2  ,P3  ,PENT,TRNS,
                       TRNS,TRNS,PDOT,PENT,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,P0
    ),

/*
    // templates to copy from

    KEYMAP(  // LayerN: transparent on edges + hard-defined thumb keys, all others are empty
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,TRNS,TRNS,LALT,LGUI,
                                      TRNS,TRNS,
                                           TRNS,
                                 LCTL,LSFT,TRNS,
        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                       RGUI,RALT,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,RSFT,RCTL
    ),
    KEYMAP(  // LayerN: fully transparent
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
    KEYMAP(  // LayerN: fully empty
        // left hand
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,NO  ,NO  ,NO  ,
                                      NO  ,NO  ,
                                           NO  ,
                                 NO  ,NO  ,NO  ,
        // right hand
             NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
             NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
                  NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
             NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
                       NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,
        NO  ,
        NO  ,NO  ,NO
    ),
*/

};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // print("action_function called\n");
    // print("id  = "); phex(id); print("\n");
    // print("opt = "); phex(opt); print("\n");

    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(50);
        bootloader_jump(); // should not return
        print("not supported.\n");
    } else if (id == LANG_KEY) {
        // toggle layer 1
        if (record->event.pressed) {
            layer_invert(1);
            //print("layer_state: "); phex(layer_state); print("\n");
            // layer 1 is the second lowest bit?
            //if (layer_state & (1<<1))
            //    ergodox_board_led_on();
            //else
            //    ergodox_board_led_off();
        }

        // send LGUI + SPACE
        if (record->event.pressed) {
            add_weak_mods(MOD_BIT(KC_LGUI));
            send_keyboard_report();
            register_code(KC_SPACE);
        } else {
            unregister_code(KC_SPACE);
            del_weak_mods(MOD_BIT(KC_LGUI));
            send_keyboard_report();
        }
    }
}


