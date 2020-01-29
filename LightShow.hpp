#ifndef LIGHTSHOW
#define LIGHTSHOW 

#include <FastLED.h> 
#include "LightSegment.hpp"
#include "SegmentList.hpp"

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

// TODO: Remove this function and all traces
void set_to_color(CRGB leds[], int startIndex, int endIndex, CRGB color);

// TODO: Remove this function and all traces
void set_one_to_color(CRGB leds[], int index, CRGB color); 

// TODO: Remove this function and all traces
void turn_off(CRGB leds[], int startIndex, int endIndex);

// TODO: Remove this function and all traces
void turn_one_off(CRGB leds[], int index);

void turn_all_off(CRGB leds[]);

void light_all_corners(CRGB leds[], CRGB color);

void turn_off_all_corners(CRGB leds[]);

void default_setup(CRGB leds[]);

void trace_outwards_evenly(CRGB leds[], int startIndex, int lengthOut, int thickness, int delayTime, CRGB color);

// construct new LightSegments that are typically used
LightSegment * get_left_square(CRGB* leds);
LightSegment * get_left_square_left(CRGB* leds);
LightSegment * get_left_square_right(CRGB* leds);
LightSegment * get_left_square_top(CRGB* leds);
LightSegment * get_left_square_bottom(CRGB* leds);

LightSegment * get_right_square(CRGB* leds);
LightSegment * get_right_square_left(CRGB* leds);
LightSegment * get_right_square_right(CRGB* leds);
LightSegment * get_right_square_top(CRGB* leds);
LightSegment * get_right_square_bottom(CRGB* leds);

LightSegment * get_middle_arch(CRGB* leds);
LightSegment * get_middle_top(CRGB* leds);
LightSegment * get_middle_left(CRGB* leds);
LightSegment * get_middle_right(CRGB* leds);
LightSegment * get_middle_top_left(CRGB* leds);
LightSegment * get_middle_top_right(CRGB* leds);

LightSegment * get_left_bridge(CRGB* leds);
LightSegment * get_right_bridge(CRGB* leds);
LightSegment * get_left_bridge_no_slant(CRGB* leds);
LightSegment * get_right_bridge_no_slant(CRGB* leds);

LightSegment * get_all_lights(CRGB* leds);

LightSegment * get_start_left_bridge_to_middle_top_left(CRGB* leds);
LightSegment * get_middle_top_right_to_right_bridge_end(CRGB* leds);

LightSegment * get_left_square_left_center_with_offset(CRGB* leds, int offset);
LightSegment * get_left_square_top_center_with_offset(CRGB* leds, int offset);
LightSegment * get_left_square_right_center_with_offset(CRGB* leds, int offset);
LightSegment * get_left_square_bottom_center_with_offset(CRGB* leds, int offset);

LightSegment * get_right_square_left_center_with_offset(CRGB* leds, int offset);
LightSegment * get_right_square_top_center_with_offset(CRGB* leds, int offset);
LightSegment * get_right_square_right_center_with_offset(CRGB* leds, int offset);
LightSegment * get_right_square_bottom_center_with_offset(CRGB* leds, int offset);

LightSegment * get_middle_left_center_with_offset(CRGB* leds, int offset);
LightSegment * get_middle_right_center_with_offset(CRGB* leds, int offset);

LightSegment * get_middle_top_center_with_offset(CRGB* leds, int offset);
LightSegment * get_middle_top_left_center_with_offset(CRGB* leds, int offset);
LightSegment * get_middle_top_right_center_with_offset(CRGB* leds, int offset);

#endif
