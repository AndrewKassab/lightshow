#include "sequences.hpp"

/* Square and center trace */
void sequence_one(CRGB* leds, int delayTime, int thickness, CRGB colorOne, CRGB colorTwo){

  for (int i = 0; i <= 79; i++){

      if ( i == 1 ){
        leds[76] = CRGB::Black;
        leds[185] = CRGB::Black;
      } else if ( i == 2 ){
        leds[77] = CRGB::Black;
        leds[184] = CRGB::Black;
      } else if ( i == 3 ) {
        leds[78] = CRGB::Black;
        leds[183] = CRGB::Black;
      } else if ( i == 4 ) {
        leds[79] = CRGB::Black;
        leds[182] = CRGB::Black;
      }

      delay(delayTime);

      // left square
      leds[start+i] = colorOne;
      leds[start+i-thickness] = CRGB::Black;

      // right square
      leds[end-i] = colorOne;
      leds[end-i+thickness] = CRGB::Black;

      // middle 
      if ( i != 42){
        leds[middle_bottom_left_corner+i-thickness] = CRGB::Black;
        leds[middle_bottom_right_corner-i+thickness] = CRGB::Black;
      }
      if ( i == 79 ){
        leds[middle_bottom_left_corner+2] = CRGB::Black;
        leds[middle_bottom_right_corner-2] = CRGB::Black;
      } else {
        leds[middle_bottom_left_corner+i] = colorTwo;
        leds[middle_bottom_right_corner-i] = colorTwo;
      }
      
      // corners
      light_all_corners(leds, CRGB::White);        
      
      FastLED.show();
  }
}

/* Square Cycle */
void sequence_two(CRGB* leds, int delayTime, CRGB colorOne, CRGB colorTwo){
  LightSegment * leftSquareLeftInSeq = get_left_square_left(leds);
  LightSegment * leftSquareTopInSeq = get_left_square_top(leds);
  LightSegment * leftSquareRightInSeq = get_left_square_right(leds);
  LightSegment * leftSquareBottomInSeq = get_left_square_bottom(leds);
  LightSegment * rightSquareTopInSeq = get_right_square_top(leds);
  LightSegment * rightSquareRightInSeq = get_right_square_right(leds);
  LightSegment * rightSquareLeftInSeq = get_right_square_left(leds);
  LightSegment * rightSquareBottomInSeq = get_right_square_bottom(leds);

  FastLED.clear();
  leds[middle_top_left_corner] = CRGB::White;
  leds[middle_top_right_corner] = CRGB::White;
  leds[middle_bottom_left_corner] = CRGB::White;
  leds[middle_bottom_right_corner] = CRGB::White;
  leds[middle_top_middle] = CRGB::White;
  leftSquareLeftInSeq->setToColor(colorOne);
  rightSquareRightInSeq->setToColor(colorOne);
  FastLED.show();
  delay(delayTime);
  leftSquareLeftInSeq->turnOff();
  rightSquareRightInSeq->turnOff();
  leftSquareTopInSeq->setToColor(colorTwo);
  rightSquareTopInSeq->setToColor(colorTwo);
  FastLED.show();
  delay(delayTime);
  leftSquareTopInSeq->turnOff();
  rightSquareTopInSeq->turnOff();
  leftSquareRightInSeq->setToColor(colorOne);
  rightSquareLeftInSeq->setToColor(colorOne);
  FastLED.show();
  delay(delayTime);
  leftSquareRightInSeq->turnOff();
  rightSquareLeftInSeq->turnOff();
  leftSquareBottomInSeq->setToColor(colorTwo);
  rightSquareBottomInSeq->setToColor(colorTwo);
  FastLED.show();
  delay(delayTime);


  free(leftSquareLeftInSeq);
  free(leftSquareTopInSeq);
  free(leftSquareRightInSeq);
  free(leftSquareBottomInSeq);
  free(rightSquareTopInSeq);
  free(rightSquareRightInSeq);
  free(rightSquareLeftInSeq);
  free(rightSquareBottomInSeq);
}
