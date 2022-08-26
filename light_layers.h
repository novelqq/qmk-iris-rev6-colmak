
#pragma once

/*

LED index mapping:

          (31)              (32)              (33)                                    (67)              (66)              (65)
┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
│0       │1       │2       │3       │4       │5       │                          │39      │38      │37      │36      │35      │34      │
├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
│11      │10      │9       │8       │7       │6       │                          │40      │41      │42      │43      │44      │45      │
├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
│12      │13      │14      │15      │16      │17      │                          │51      │50      │49      │48      │47      │46      │
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
│23      │22      │21      │20      │19      │18      │27      │        │61      │52      │53      │54      │55      │56      │57      │
└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                               │24      │25      │26      │                 │60      │59      │58      │
                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
          (30)              (29)              (28)                                    (62)              (63)              (64)

*/

const rgblight_segment_t PROGMEM COLEMAK_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left side
    {1, 5, HSV_WHITE},
    {6, 6, HSV_WHITE},
    {12, 6,HSV_WHITE},
    {18, 6,HSV_WHITE},
    {24, 1,HSV_CYAN},
    {25, 1,HSV_GREEN}, // TT(_NUM_SYM)
    {26, 2,HSV_WHITE},
    {28, 3,HSV_WHITE}, // underglow
    {31, 3,HSV_WHITE}, // underglow
    // right side
    {34, 6, HSV_WHITE},
    {40, 6, HSV_WHITE},
    {46, 6, HSV_WHITE},
    {52, 6, HSV_WHITE},
    {58, 1, HSV_WHITE},
    {59, 1, HSV_RED}, // TT(_NAV)
    {60, 2, HSV_WHITE},
    {62, 3, HSV_WHITE}, // underglow
    {65, 3, HSV_WHITE} // underglow
);

const rgblight_segment_t PROGMEM QWERTY_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left side
    {0, 6, 85, 0, 255},
    {6, 6, 85, 70, 255},
    {12, 6, 85, 150, 255},
    {18, 6, 85, 240, 255},
    {24, 1, 85, 255, 255},
    {25, 1, 169, 255, 255}, // TT(_NUM_SYM)
    {26, 2, 85, 255, 255},
    {28, 3, 85, 255, 255}, // underglow
    {31, 3, 85, 0, 255}, // underglow
    // right side
    {34, 6, 85, 0, 255},
    {40, 6, 85, 70, 255},
    {46, 6, 85, 150, 255},
    {52, 6, 85, 240, 255},
    {58, 1, 85, 255, 255},
    {59, 1, 201, 255, 255}, // TT(_NAV)
    {60, 2, 85, 255, 255},
    {62, 3, 85, 255, 255}, // underglow
    {65, 3, 85, 0, 255} // underglow
);

const rgblight_segment_t PROGMEM SYM_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left side
    {1, 5, HSV_AZURE},
    {6, 6, HSV_AZURE},
    {12, 6,HSV_AZURE},
    {18, 6,HSV_AZURE},
    {24, 1,HSV_AZURE},
    {25, 1,HSV_GREEN}, // TT(_NUM_SYM)
    {26, 2,HSV_AZURE},
    {28, 3,HSV_AZURE}, // underglow
    {31, 3,HSV_AZURE}, // underglow
    // right side
    {34, 6, HSV_AZURE},
    {40, 6, HSV_AZURE},
    {46, 6, HSV_AZURE},
    {52, 6, HSV_AZURE},
    {58, 1, HSV_AZURE},
    {59, 1, HSV_ORANGE}, // TT(_NAV)
    {60, 2, HSV_AZURE},
    {62, 3, HSV_WHITE}, // underglow
    {65, 3, HSV_WHITE} // underglow
);

const rgblight_segment_t PROGMEM NAV_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left side
    {1, 5, 	HSV_TEAL},
    {6, 6, 	HSV_TEAL},
    {12, 6,	HSV_TEAL},
    {18, 6,	HSV_TEAL},
    {24, 1,	HSV_TEAL},
    {25, 1,	HSV_TEAL}, // TT(_NUM_SYM)
    {26, 2,	HSV_TEAL},
    {28, 3,	HSV_TEAL}, // underglow
    {31, 3,	HSV_TEAL}, // underglow
    // right side
    {34, 6, 	HSV_TEAL},
    {40, 6, 	HSV_TEAL},
    {46, 6, 	HSV_TEAL},
    {52, 6, 	HSV_TEAL},
    {58, 1, 	HSV_TEAL},
    {59, 1, HSV_YELLOW}, // TT(_NAV)
    {60, 2, 	HSV_TEAL},
    {62, 3, HSV_WHITE}, // underglow
    {65, 3, HSV_WHITE} // underglow
);

const rgblight_segment_t PROGMEM MISC_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // // both sides
    // {0, 1, 0, 255, 255}, // RESET
    // {1, 4, 0, 0, 0},
    // {5, 1, 85, 0, 255}, // set QWERTY as default
    // {6, 2, 0, 0, 0},
    // {8, 1, 160, 150, 150}, // MUTE
    // {9, 3, 0, 0, 0},
    // {12, 1, 201, 255, 255}, // CAPS
    // {13, 1, 120, 255, 255}, // PLAY
    // {14, 1, 0, 255, 255}, // NEXT
    // {15, 1, 160, 255, 255}, // VOLUME_UP
    // {16, 1, 43, 255, 255}, // BRIGHTNESS_UP
    // {17, 2, 0, 0, 0},
    // {19, 1, 43, 200, 200}, // BRIGHTNESS_DOWN
    // {20, 1, 160, 220, 200}, // VOLUME_DOWN
    // {21, 1, 0, 220, 200}, // PREV
    // {22, 1, 120, 220, 200}, // STOP
    // {23, 2, 0, 0, 0},
    // {25, 1, 85, 255, 255}, // TO(DEFAULT)
    // {26, 2, 0, 0, 0},
    // {28, 6, 0, 255, 255}, // underglow
    // {34, 5, 0, 0, 0},
    // {39, 1, 127, 255, 255}, // set COLEMAK as default
    // {40, 19, 0, 0, 0},
    // {59, 1, 85, 255, 255}, // TO(DEFAULT)
    // {60, 2, 0, 0, 0},
    // {62, 6, 0, 255, 255} // underglow
        // left side
    {1, 5, 	HSV_CORAL},
    {6, 6, 	HSV_CORAL},
    {12, 6,	HSV_CORAL},
    {18, 6,	HSV_CORAL},
    {24, 1,	HSV_CORAL},
    {25, 1,	HSV_CORAL}, // TT(_NUM_SYM)
    {26, 2,	HSV_CORAL},
    {28, 3,	HSV_CORAL}, // underglow
    {31, 3,	HSV_CORAL}, // underglow
    // right side
    {34, 6, 	HSV_CORAL},
    {40, 6, 	HSV_CORAL},
    {46, 6, 	HSV_CORAL},
    {52, 6, 	HSV_CORAL},
    {58, 1, 	HSV_CORAL},
    {59, 1, HSV_GREEN}, // TT(_NAV)
    {60, 2, 	HSV_CORAL},
    {62, 3, HSV_WHITE}, // underglow
    {65, 3, HSV_WHITE} // underglow
);

const rgblight_segment_t* const PROGMEM MY_LIGHT_LAYERS[] = RGBLIGHT_LAYERS_LIST(
    COLEMAK_LIGHT_LAYER,
    QWERTY_LIGHT_LAYER,
    SYM_LIGHT_LAYER,
    NAV_LIGHT_LAYER,
    MISC_LIGHT_LAYER
);
