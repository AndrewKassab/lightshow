#ifndef LIGHTSHOW
#define LIGHTSHOW 

#include <FastLED.h> 

#define NUM_LEDS 262

#define left_top_right_corner 20
#define left_top_left_corner 40
#define left_bottom_left_corner 60
#define left_bottom_right_corner 80

#define middle_bottom_left_corner 92
#define middle_top_left_corner 111
#define middle_top_middle 131
#define middle_top_right_corner 151
#define middle_bottom_right_corner 170

#define right_bottom_left_corner 181
#define right_bottom_right_corner 201
#define right_top_right_corner 221
#define right_top_left_corner 241

#define start 1
#define end 260

void set_to_color(CRGB leds[], int startIndex, int endIndex, int r, int g, int b);

void turn_off(CRGB leds[], int startIndex, int endIndex);

#endif
