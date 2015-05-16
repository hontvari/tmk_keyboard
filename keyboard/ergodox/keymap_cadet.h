/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
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
    [3] =   ACTION_MODS_ONESHOT(MOD_RALT),

    // switch on layer 2
    #define KC_PL2                               KC_FN4
    [4] =   ACTION_LAYER_TOGGLE(3),

    // reset layering, switch off all layers, only the default remains active
    #define KC_L0                                KC_FN5
    [5] =   ACTION_LAYER_CLEAR(ON_RELEASE),

};





static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Legend:
     *   Symbol in drawing | USB keycode | Description
     *   Frnt              | RALT        | Front or Greek on Space Cadet, Level3 Shift in ISO standard, AltGr on PC
     *   Top               | LANG2       | Top on Space Cadet, Level 5 Shift
     *   LMet, RMet        | LALT        | Meta on Space Cadet, Alt on PC
     *   LSup, RSup        | LGUI        | Super on Space Cadet, UNIX, Windows on Windows, Gui key in USB specification
     *   LHyp, RHyp        | RGUI        | Hyper on Space Cadet, UNIX
     *   COMP              | MENU        | Compose key on Sun, UNIX
     *   +                 | PPLS        | Keypad +
     *   (                 | KP_LPAREN   | Keypad (
     *   )                 | KP_RPAREN   | Keypad )
     *   :                 | KP_COLON    | Keypad colon
     *   {                 |             | non-standard key
     *   }                 |             | non-standard key
     ****************************************************************************************************
     *
     * Layer 0: Alphanumeric
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   `    |   1  |   2  |   3  |   4  |   5  |  [   |           |   ]  |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  Tab   |   Q  |   W  |   E  |   R  |   T  | Frnt |           | Frnt |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | CapsLk |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |  J   |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------| LSFT |           | LSFT |------+------+------+------+------+--------|
     * |  RGHT  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   UP   |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | LEFT | LSFT |  LSup |  LMet | LCTL |                                     | RCTL | RMet | RSup | RSFT | DOWN |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |  ESC |  ~L3 |       |   =  |  ~L2 |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | Home |       | PgUp |      |      |
     *                                 | BkSp |  Del |------|       |------| Enter| Space|
     *                                 |      |      |  End |       | PgDn |      |      |
     *                                 `--------------------'       `--------------------'
     *
     ****************************************************************************************************
     *
     * Keymap: Layer 1. NONE
     *
     ****************************************************************************************************
     *
     *
     *
     * Keymap: Layer 2 Function
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |  F16 |  F17 |  F18 |  F19 |  F20 | =L0  |           | =L0  |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |  F6  |  F7  |  F8  |  F9  |  F10 |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  LShf  |  F11 |  F12 |  F13 |  F14 |  F15 |      |           |      |Teensy| PrtSc| ScrLk| Pause|  Ins |  RShf  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | LGui |  F21 |  F22 |  F23 |  F24 |                                       |      |      |      |      | RGui |
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
     * |        |      |      |      |      |      | =L0  |           | =L0  |      | NumLk|   =  |   /  |   *  |        |
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

    KEYMAP(  // Layer 0: ALPHANUMERIC
        // left hand
        GRV ,1   ,2   ,3   ,4   ,5   ,PL1 ,
        TAB ,Q   ,W   ,E   ,R   ,T   ,ML1 ,
        CAPS,A   ,S   ,D   ,F   ,G   ,
        LSFT,Z   ,X   ,C   ,V   ,B   ,LANG,
        LGUI,EQL ,ESC ,LEFT,RGHT,
                                      LCTL,LALT,
                                           HOME,
                                 BSPC,DEL ,END ,
        // right hand
             PL2 ,6   ,7   ,8   ,9   ,0   ,MINS,
             ML1 ,Y   ,U   ,I   ,O   ,P   ,BSLS,
                  H   ,J   ,K   ,L   ,SCLN,QUOT,
             LANG,N   ,M   ,COMM,DOT ,SLSH,RSFT,
                       UP  ,DOWN,LBRC,RBRC,RGUI,
        LALT,RCTL,
        PGUP,
        PGDN,ENT ,SPC
    ),

    KEYMAP(  // Layer1: NOT USED
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

    KEYMAP(  // Layer2: FUNCTION
        // left hand
        NO  ,F16 ,F17 ,F18 ,F19 ,F20  ,L0  ,
        NO  ,F6  ,F7  ,F8  ,F9  ,F10 ,TRNS,
        NO  ,F1  ,F2  ,F3  ,F4  ,F5  ,
        TRNS,F11 ,F12 ,F13 ,F14  ,F15 ,NO  ,
        TRNS,F21 ,F22 ,F23 ,F24 ,
                                      TRNS,TRNS,
                                           NO  ,
                                 NO  ,NO  ,NO  ,
        // right hand
             L0  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
             TRNS,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
                  NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
             NO  ,TEEN,PSCR,SLCK,PAUS,INS ,TRNS,
                       NO  ,NO  ,NO  ,NO  ,TRNS,
        TRNS,TRNS,
        NO  ,
        NO  ,NO  ,NO
    ),

    KEYMAP(  // Layer3: NUMPAD
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
    }
}


