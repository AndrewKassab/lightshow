#ifndef LIGHTSHOW
#define LIGHTSHOW 

#include <FastLED.h> 
#include "LightSegment.hpp"
#include "LinkedList.hpp"

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

LightSegment * leftSquare;
LightSegment * leftSquareLeft;
LightSegment * leftSquareTop;
LightSegment * leftSquareRight;
LightSegment * leftSquareBottom;
LightSegment * rightSquare;
LightSegment * rightSquareTop;
LightSegment * rightSquareRight;
LightSegment * rightSquareLeft;
LightSegment * rightSquareBottom;
LightSegment * middleTop; 
LightSegment * middleLeft;
LightSegment * middleRight;
LightSegment * middleTopLeft;
LightSegment * middleTopRight;
LightSegment * rightBridge;
LightSegment * leftBridge;
LightSegment * allLights;
LightSegment * startLeftBridgeToMiddleTopLeft;
LightSegment * middleTopRightToRightBridgeEnd;

void set_to_color(CRGB leds[], int startIndex, int endIndex, int r, int g, int b);

void set_one_to_color(CRGB leds[], int index, int r, int g, int b);

void turn_off(CRGB leds[], int startIndex, int endIndex);

void turn_one_off(CRGB leds[], int index);

void turn_all_off(CRGB leds[]);

void countdown(CRGB leds[]);

void light_all_corners(CRGB leds[], int r, int g, int b);

void turn_off_all_corners(CRGB leds[]);

void default_setup(CRGB leds[]);

void set_left_square_left(CRGB leds[], int r, int g, int b);

void set_left_square_right(CRGB leds[], int r, int g, int b);

void set_left_square_bottom(CRGB leds[], int r, int g, int b);

void set_left_square_top(CRGB leds[], int r, int g, int b);

void set_right_square_left(CRGB leds[], int r, int g, int b);

void set_right_square_right(CRGB leds[], int r, int g, int b);

void set_right_square_bottom(CRGB leds[], int r, int g, int b);

void set_right_square_top(CRGB leds[], int r, int g, int b);

void set_middle_left(CRGB leds[], int r, int g, int b);

void set_middle_top_left(CRGB leds[], int r, int g, int b);

void set_middle_top_right(CRGB leds[], int r, int g, int b);

void set_middle_middle(CRGB leds[], int r, int g, int b);

void set_left_bridge(CRGB leds[], int r, int g, int b);

void set_right_bridge(CRGB leds[], int r, int g, int b);

void single_trace(CRGB leds[], int startIndex, int endIndex, int thickness, int delayTime, int r, int g, int b);

void trace_outwards_evenly(CRGB leds[], int startIndex, int lengthOut, int thickness, int delayTime, int r, int g, int b);

// construct new LightSegments that are typically used
void get_left_square(CRGB* leds);
void get_left_square_left(CRGB* leds);
void get_left_square_right(CRGB* leds);
void get_left_square_top(CRGB* leds);
void get_left_square_bottom(CRGB* leds);

void get_right_square(CRGB* leds);
void get_right_square_left(CRGB* leds);
void get_right_square_right(CRGB* leds);
void get_right_square_top(CRGB* leds);
void get_right_square_bottom(CRGB* leds);

void get_middle_arch(CRGB* leds);
void get_middle_top(CRGB* leds);
void get_middle_left(CRGB* leds);
void get_middle_right(CRGB* leds);
void get_middle_top_left(CRGB* leds);
void get_middle_top_right(CRGB* leds);

void get_left_bridge(CRGB* leds);
void get_right_bridge(CRGB* leds);
void get_left_bridge_no_slant(CRGB* leds);
void get_right_bridge_no_slant(CRGB* leds);

void get_all_lights(CRGB* leds);

void get_start_left_bridge_to_middle_top_left(CRGB* leds);
void get_middle_top_right_to_right_bridge_end(CRGB* leds);

void get_left_square_left_center_with_thickness(CRGB* leds, int thickness);
void get_left_square_top_center_with_thickness(CRGB* leds, int thickness);
void get_left_square_right_center_with_thickness(CRGB* leds, int thickness);
void get_left_square_bottom_center_with_thickness(CRGB* leds, int thickness);

#endif
