#include "LightShow.hpp"

void sequence_one(CRGB* leds, int delayTime, int thickness, CRGB colorOne, CRGB colorTwo);
void square_side_cycle(CRGB* leds, int delayTime, CRGB colorOne, CRGB colorTwo, CRGB colorThree, CRGB colorFour);
void square_color_trace(CRGB * leds, int delayTime, int thickness, CRGB * colors, int numColors);
void up_down_trace(CRGB * leds, int thickness, int delayTime, CRGB colorOne, CRGB colorTwo);