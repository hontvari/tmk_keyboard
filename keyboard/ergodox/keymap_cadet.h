/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
    LEFT_PARENTHESIS,
    RIGHT_PARENTHESIS,
};

/*
 * Fn action definition
 * Plus meaningful names for function (FN) macros, they should be used without the KC_ prefix.
 */
static const uint16_t PROGMEM fn_actions[] = {
    // TEENSY programming
    #define KC_TEEN                              KC_FN0
    [0] =   ACTION_FUNCTION(TEENSY_KEY),

    // opening parenthesis
    #define KC_LPAR                              KC_FN6
    [6] =   ACTION_FUNCTION(LEFT_PARENTHESIS),

    // closing parenthesis
    #define KC_RPAR                              KC_FN7
    [7] =   ACTION_FUNCTION(RIGHT_PARENTHESIS),

    // momentary layer 1
    #define KC_XML1                              KC_FN8
    [8] =   ACTION_LAYER_MOMENTARY(1),

    // momentary layer 2
    #define KC_XML2                              KC_FN9
    [9] =   ACTION_LAYER_MOMENTARY(2),

    // momentary layer 3
    #define KC_XML3                              KC_FN10
    [10] =   ACTION_LAYER_MOMENTARY(3),

    // momentary layer 4
    #define KC_XML4                              KC_FN11
    [11] =   ACTION_LAYER_MOMENTARY(4),

    // momentary layer 5
    #define KC_XML5                              KC_FN12
    [12] =   ACTION_LAYER_MOMENTARY(5),

    // left brace (numpad braces does not work on Linux (evdev?))
    #define KC_LCBR                              KC_FN13
    [13] =   ACTION_MODS_KEY(MOD_LSFT, KC_LBRACKET),

    // right braces (numpad braces does not work on Linux (evdev?))
    #define KC_RCBR                              KC_FN14
    [14] =   ACTION_MODS_KEY(MOD_LSFT, KC_RBRACKET),

    // colon (numpad colon does not work on Linux (evdev?))
    #define KC_COLN                              KC_FN15
    [15] =   ACTION_MODS_KEY(MOD_LSFT, KC_SCOLON),

    // double quote
    #define KC_DQUO                              KC_FN16
    [16] =   ACTION_MODS_KEY(MOD_LSFT, KC_QUOT),
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
         *
         * Layer 0: Alphanumeric
         *
         * ,--------------------------------------------------.           ,--------------------------------------------------.
         * |   `    |   1  |   2  |   3  |   4  |   5  |   [  |           |   ]  |   6  |   7  |   8  |   9  |   0  |   -    |
         * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
         * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  CUT |           | PASTE|   Y  |   U  |   I  |   O  |   P  |   \    |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * | CapsLk |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
         * |--------+------+------+------+------+------| COPY |           | UNDO |------+------+------+------+------+--------|
         * |   Esc  |  Z   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   :    |
         * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
         *   |      |  =   |   +  |  (  |   )   |                                       |  ENT |   "  |   {  |   }  | COMP |
         *   `----------------------------------'                                       `----------------------------------'
         *                                        ,-------------.       ,-------------.
         *                                        |      |      |       |      |      |
         *                                 ,------|------|------|       |------+------+------.
         *                                 |      |      |      |       |      |      |      |
         *                                 |  ~L1 |  ~L2 |------|       |------|  ~L4 |  SPC |
         *                                 |      |      |  ~L3 |       |  ~L5 |      |      |
         *                                 `--------------------'       `--------------------'
         *
         ****************************************************************************************************
         *
         * Layer 1: Modifiers left, navigation keys right
         *
         * ,--------------------------------------------------.           ,--------------------------------------------------.
         * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
         * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
         * |        |      |      |      |      |      |      |           |      | Home | PgDn | PgUp |  End |      |  PrtSc |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * |        |(LShf)|  Top | AltGr| LShf |      |------|           |------| Left | Down |  Up  | Rght |      |  ScrLk |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * |        | LHyp | LGui | LAlt | LCtl |      |      |           |      |      | BSPC |  DEL |      | Ins  |  Pause |
         * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
         *   |      |(LShf)|(LShf)|(LShf)|(LShf)|                                       |  ENT |      |      |      |      |
         *   `----------------------------------'                                       `----------------------------------'
         *                                        ,-------------.       ,-------------.
         *                                        |      |      |       |      |      |
         *                                 ,------|------|------|       |------+------+------.
         *                                 |      |      |      |       |      |      |      |
         *                                 |  ~L1 |  ~L2 |------|       |------|  ~L4 |  SPC |
         *                                 |      |      |  ~L3 |       |  ~L5 |      |      |
         *                                 `--------------------'       `--------------------'
         *
         *
         *
         ****************************************************************************************************
         *
         * Layer 2: Modifiers left, alphanum right
         *
         * ,--------------------------------------------------.           ,--------------------------------------------------.
         * |        |      |      |      |      |      |      |           | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
         * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
         * |        |      |      |      |      |      |      |           | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * |        |(LShf)|  Top | AltGr| LShf |      |------|           |------| TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
         * |--------+------+------+------+------+------|      |           | TRNS |------+------+------+------+------+--------|
         * |        | LHyp | LGui | LAlt | LCtl |      |      |           |      | TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
         * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
         *   |      |(LShf)|(LShf)|(LShf)|(LShf)|                                       | TRNS | TRNS | TRNS | TRNS | TRNS |
         *   `----------------------------------'                                       `----------------------------------'
         *                                        ,-------------.       ,-------------.
         *                                        |      |      |       | TRNS | TRNS |
         *                                 ,------|------|------|       |------+------+------.
         *                                 |      |      |      |       | TRNS |      |      |
         *                                 |  ~L1 |  ~L2 |------|       |------|  ~L4 |  SPC |
         *                                 |      |      |  ~L3 |       |  ~L5 |      |      |
         *                                 `--------------------'       `--------------------'
         *
         *
         *
         ****************************************************************************************************
         *
         *
         *
         * Layer 3. Numpad (It should be extended with more mathematical sign, there is KP parantheses, hex digit, etc.)
         *
         * ,--------------------------------------------------.           ,--------------------------------------------------.
         * | Teensy |      |      |      |      |      |      |           |      |      | NumLk|   =  |   /  |   *  |        |
         * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
         * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   -  |        |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * |        |(LShf)| Top* | AltGr| LShf |      |------|           |------|      |   4  |   5  |   6  |   +  |        |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * |        | LHyp | LGui | LAlt | LCtl |      |      |           |      |      |   1  |   2  |   3  | Enter|        |
         * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
         *   |      |(LShf)|(LShf)|(LShf)|(LShf)|                                       |      |      |   .  | Enter|      |
         *   `----------------------------------'                                       `----------------------------------'
         *                                        ,-------------.       ,-------------.
         *                                        |      |      |       |      |      |
         *                                 ,------|------|------|       |------+------+------.
         *                                 |      |      |      |       |      |      |      |
         *                                 |  ~L1 |  ~L2 |------|       |------|  ~L4 |   0  |
         *                                 |      |      | ~L3  |       |  ~L5 |      |      |
         *                                 `--------------------'       `--------------------'
         *
         *
         *
         ****************************************************************************************************
         *
         *
         * Layer4: Alphanum left, modifiers right
         *
         * ,--------------------------------------------------.           ,--------------------------------------------------.
         * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |           |      |      |      |      |      |      |        |
         * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
         * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |           |      |      |      |      |      |      |        |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS |------|           |------|      | RShf | AltGr|  Top |(RShf)|        |
         * |--------+------+------+------+------+------| TRNS |           |      |------+------+------+------+------+--------|
         * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS |      |           |      |      | RCtl | LAlt | RGui | RHyp |        |
         * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
         *   | TRNS | TRNS | TRNS | TRNS | TRNS |                                       |(RShf)|(RShf)|(RShf)|(RShf)|      |
         *   `----------------------------------'                                       `----------------------------------'
         *                                        ,-------------.       ,-------------.
         *                                        | TRNS | TRNS |       |      |      |
         *                                 ,------|------|------|       |------+------+------.
         *                                 |      |      | TRNS |       |      |      |      |
         *                                 |  ~L1 |  ~L2 |------|       |------|  ~L4 |  SPC |
         *                                 |      |      | ~L3  |       |  ~L5 |      |      |
         *                                 `--------------------'       `--------------------'
         *
         *
         *
         ****************************************************************************************************
         *
         * Layer 5. Function keys left, modifiers right
         *
         * ,--------------------------------------------------.           ,--------------------------------------------------.
         * |        |  F16 |  F17 |  F18 |  F19 |  F20 |      |           |      |      |      |      |      |      |        |
         * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
         * |        |  F6  |  F7  |  F8  |  F9  |  F10 |      |           |      |      |      |      |      |      |        |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * |        |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|      | RShf | AltGr|  Top |(RShf)|        |
         * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
         * |        |  F11 |  F12 |  F13 |  F14 |  F15 |      |           |      |      | RCtl | LAlt | RGui | RHyp |        |
         * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
         *   |      |  F21 |  F22 |  F23 |  F24 |                                       |(RShf)|(RShf)|(RShf)|(RShf)|      |
         *   `----------------------------------'                                       `----------------------------------'
         *                                        ,-------------.       ,-------------.
         *                                        |      |      |       |      |      |
         *                                 ,------|------|------|       |------+------+------.
         *                                 |      |      |      |       |      |      |      |
         *                                 |  ~L1 |  ~L2 |------|       |------|  ~L4 |  SPC |
         *                                 |      |      | ~L3  |       |  ~L5 |      |      |
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
        GRV ,1   ,2   ,3   ,4   ,5   ,LBRC,
        TAB ,Q   ,W   ,E   ,R   ,T   ,CUT ,
        CAPS,A   ,S   ,D   ,F   ,G   ,
        ESC ,Z   ,X   ,C   ,V   ,B   ,COPY,
        NO  ,EQL ,PPLS,LPAR,RPAR,
                                      NO  ,NO  ,
                                           NO  ,
                                 XML1,XML2,XML3,
        // right hand
             RBRC,6   ,7   ,8   ,9   ,0   ,MINS,
             PASTE,Y   ,U   ,I   ,O   ,P   ,BSLS,
                  H   ,J   ,K   ,L   ,SCLN,QUOT,
             UNDO,N   ,M   ,COMM,DOT ,SLSH,COLN,
                       ENT ,DQUO,LCBR,RCBR,MENU,
        NO  ,NO  ,
        NO  ,
        XML5,XML4,SPC
    ),

    KEYMAP(  // Layer1: Modifiers left, navigation keys right
        // left hand
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,LSFT,LANG2,RALT,LSFT,NO  ,
        NO  ,RGUI,LGUI,LALT,LCTL,NO  ,NO  ,
        NO  ,LSFT,LSFT,LSFT,LSFT,
                                      NO  ,NO  ,
                                           NO  ,
                                 XML1,XML2,XML3,
        // right hand
             NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
             NO  ,HOME,PGDN,PGUP,END ,NO  ,PSCR,
                  LEFT,DOWN,UP  ,RGHT,NO  ,SLCK,
             NO  ,NO  ,BSPC,DEL ,NO  ,INS ,PAUS,
                       ENT ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,
        NO  ,
        XML5,XML4,SPC
    ),

    KEYMAP(  // Layer 2: Modifiers left, alphanumeric right
        // left hand
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,LSFT,LANG2,RALT,LSFT,NO  ,
        NO  ,RGUI,LGUI,LALT,LCTL,NO  ,NO  ,
        NO  ,LSFT,LSFT,LSFT,LSFT,
                                      NO  ,NO  ,
                                           NO  ,
                                 XML1,XML2,XML3,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        XML5,XML4,SPC
    ),

    KEYMAP(  // Layer3: NUMPAD
        // left hand
        TEEN,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,LSFT,LANG2,RALT,LSFT,NO  ,
        NO  ,RGUI,LGUI,LALT,LCTL,NO  ,NO  ,
        NO  ,LSFT,LSFT,LSFT,LSFT,
                                      NO  ,NO  ,
                                           NO  ,
                                 XML1,XML2,XML3,
        // right hand
             NO  ,NO  ,NLCK,PEQL,PSLS,PAST,NO  ,
             NO  ,NO  ,P7  ,P8  ,P9  ,PMNS,NO  ,
                  NO  ,P4  ,P5  ,P6  ,PPLS,NO  ,
             NO  ,NO  ,P1  ,P2  ,P3  ,PENT,NO  ,
                       NO  ,NO  ,PDOT,PENT,NO  ,
        NO  ,NO  ,
        NO  ,
        XML5,XML4,P0
    ),

    KEYMAP(  // Layer 4: Alphanumeric left, modifiers right
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 XML1,XML2,XML3,
        // right hand
             NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
             NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
                  NO  ,RSFT,RALT,LANG2,LSFT,NO  ,
             NO  ,NO  ,RCTL,LALT,LGUI,RGUI,NO  ,
                       RSFT,RSFT,RSFT,RSFT,NO  ,
        NO  ,NO  ,
        NO  ,
        XML5,XML4,SPC
    ),

    KEYMAP(  // Layer5: Function left, modifiers right
        // left hand
        NO  ,F16 ,F17 ,F18 ,F19 ,F20 ,NO  ,
        NO  ,F6  ,F7  ,F8  ,F9  ,F10 ,NO  ,
        NO  ,F1  ,F2  ,F3  ,F4  ,F5  ,
        NO  ,F11 ,F12 ,F13 ,F14 ,F15 ,NO  ,
        NO  ,F21 ,F22 ,F23 ,F24 ,
                                      NO  ,NO  ,
                                           NO  ,
                                 XML1,XML2,XML3,
        // right hand
             NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
             NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
                  NO  ,RSFT,RALT,LANG2,LSFT,NO  ,
             NO  ,NO  ,RCTL,LALT,LGUI,RGUI,NO  ,
                       RSFT,RSFT,RSFT,RSFT,NO  ,
        NO  ,NO  ,
        NO  ,
        XML5,XML4,SPC
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
    } else if (id == LEFT_PARENTHESIS) {
        if (record->event.pressed) {
            add_key(0xB6);
            send_keyboard_report();
        } else {
            del_key(0xB6);
            send_keyboard_report();
        }
    } else if (id == RIGHT_PARENTHESIS) {
        if (record->event.pressed) {
            add_key(0xB7);
            send_keyboard_report();
        } else {
            del_key(0xB7);
            send_keyboard_report();
        }
    }
}


