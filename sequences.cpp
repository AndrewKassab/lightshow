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
void square_side_cycle(CRGB* leds, int delayTime, CRGB colorOne, CRGB colorTwo, CRGB colorThree, CRGB colorFour){
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
  leftSquareRightInSeq->setToColor(colorThree);
  rightSquareLeftInSeq->setToColor(colorThree);
  FastLED.show();
  delay(delayTime);
  leftSquareRightInSeq->turnOff();
  rightSquareLeftInSeq->turnOff();
  leftSquareBottomInSeq->setToColor(colorFour);
  rightSquareBottomInSeq->setToColor(colorFour);
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

void square_color_trace(CRGB * leds, int thickness, int delayTime, CRGB * colors, int numColors){
  leds[middle_top_left_corner] = CRGB::White;
  leds[middle_top_right_corner] = CRGB::White;
  leds[middle_bottom_left_corner] = CRGB::White;
  leds[middle_bottom_right_corner] = CRGB::White;
  leds[middle_top_middle] = CRGB::White;
  LightSegment * leftSquare = get_left_square(leds);
  LightSegment * rightSquare = get_right_square(leds);
  SegmentList squares = SegmentList(leftSquare);
  squares.add(rightSquare);
  boolean reverseTable[2] = {true, false};
  for ( int i = 0; i < numColors; i++ ){
    squares.traceAllAndRemain(thickness,delayTime,reverseTable, colors[i]);
  }
}

void up_down_trace(CRGB * leds, int thickness, int delayTime, CRGB colorOne, CRGB colorTwo){
  LightSegment * leftSquareLeft = get_left_square_left(leds);
  LightSegment * leftSquareRight = get_left_square_right(leds);
  LightSegment * rightSquareLeft = get_right_square_left(leds);
  LightSegment * rightSquareRight = get_right_square_right(leds);
  LightSegment * middleLeft = get_middle_left(leds);
  LightSegment * middleRight = get_middle_right(leds);
  SegmentList lights = SegmentList(leftSquareLeft);
  lights.add(leftSquareRight);
  lights.add(rightSquareLeft);
  lights.add(rightSquareRight);
  lights.add(middleLeft);
  lights.add(middleRight);
  boolean reverseTable[6] = {true, false, true, false, true, false};
  lights.traceAllDontRemain(thickness, delayTime,reverseTable, colorOne);
  reverseTable[0] = false;
  reverseTable[2] = false;
  reverseTable[4] = false;
  reverseTable[1] = true;
  reverseTable[3] = true;
  reverseTable[5] = true;
  lights.traceAllDontRemain(thickness, delayTime,reverseTable, colorTwo);
}
