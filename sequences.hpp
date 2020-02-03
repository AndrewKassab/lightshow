#include "LightShow.hpp"

void sequence_one(CRGB* leds, int delayTime, int thickness, CRGB colorOne, CRGB colorTwo);
void square_side_cycle(CRGB* leds, int delayTime, CRGB colorOne, CRGB colorTwo, CRGB colorThree, CRGB colorFour);
void square_color_trace(CRGB * leds, int delayTime, int thickness, CRGB * colors, int numColors);
void up_down_trace(CRGB * leds, int thickness, int delayTime, CRGB colorOne, CRGB colorTwo);
void left_right_trace(CRGB * leds, int thickness, int delayTime, CRGB colorOne, CRGB colorTwo);
void sides_to_middle(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo, CRGB colorThree);
void trace_squares_and_middle(CRGB * leds, int delayTime, int thickness, CRGB color);
void trace_squares_corners_and_middle(CRGB * leds, int delayTime, int thickness, CRGB color);
void top_to_bottom(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo);
void trace_upwards(CRGB * leds, int thickness, int delayTime, CRGB color);
void trace_downwards(CRGB * leds, int thickness, int delayTime, CRGB color);
void trace_to_center(CRGB * leds, int thickness, int delayTime, CRGB color);
void corners_Cycle(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo);