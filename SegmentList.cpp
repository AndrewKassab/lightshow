#include "SegmentList.hpp"

SegmentList::SegmentList(LightSegment * head){
  SegmentNode * newSegmentNode = new SegmentNode(head);
  this->head = newSegmentNode;
  this->size = 1;
}

SegmentList::~SegmentList(){
  SegmentNode * currentSegment = this->head;
  while (currentSegment->next){
    SegmentNode * previousSegment = currentSegment;
    currentSegment = currentSegment->next;
    free(previousSegment);
  }
  free(currentSegment);
}

int SegmentList::getLongestSegmentSize(){
  SegmentNode * currentNode = this->head;
  int largestSize = 0;
  while (currentNode){
    LightSegment * currSegment = currentNode->segment;
    if (currSegment->size > largestSize){
      largestSize = currSegment->size;
    }
    currentNode = currentNode->next;
  }
  return largestSize;
}

void SegmentList::add(LightSegment * newSegment){
  SegmentNode * currentSegment = this->head;
  while (currentSegment->next){
    currentSegment = currentSegment->next;
  }
  currentSegment->next = new SegmentNode(newSegment);
  this->size++;
}

void SegmentList::setAllToColor(CRGB color){
  SegmentNode * currentSegment = this->head;
  while (currentSegment){
    currentSegment->segment->setToColor(color);
    currentSegment = currentSegment->next;
  }
}
void SegmentList::turnAllOff(){
  SegmentNode * currentSegment = this->head;
  while (currentSegment){
    currentSegment->segment->turnOff();
    currentSegment = currentSegment->next;
  }
}

void SegmentList::fadeAllIn(int delayTime, CRGB color){
  CRGB * currLeds;
  SegmentNode * currentSegmentSegmentNode = this->head;
  for (int i = 0; i <= 255; i = i + 2){
    currentSegmentSegmentNode = this->head;
    while (currentSegmentSegmentNode){
      LightSegment * segment = currentSegmentSegmentNode->segment;
      currLeds = segment->leds; 
      int currLedsSize = segment->size;
      for (int j = 0; j <= currLedsSize; j++){
          currLeds[j] = color;
          currLeds[j].maximizeBrightness(i);
      }
      currentSegmentSegmentNode = currentSegmentSegmentNode->next;
    }
    FastLED.show();
    delay(delayTime);
  }
}

void SegmentList::fadeAllDown(int delayTime){
  CRGB * currLeds;
  SegmentNode * currentSegmentSegmentNode = this->head;
  for (int i = 255; i >= 210; i--){
    currentSegmentSegmentNode = this->head;
    while (currentSegmentSegmentNode){
      LightSegment * segment = currentSegmentSegmentNode->segment;
      currLeds = segment->leds; 
      int currLedsSize = segment->size;
      for (int j = 0; j <= currLedsSize; j++){
        currLeds[j].nscale8(i);
      }
      currentSegmentSegmentNode = currentSegmentSegmentNode->next;
    }
    FastLED.show();
    delay(delayTime);
  }
}

// each segment must be equal in length
void SegmentList::traceAllAndRemain(int thickness, int delayTime, boolean * reverse, CRGB color){

  int largestSize = this->getLongestSegmentSize();

  for (int i = 0; i <= largestSize; i++){
    SegmentNode * currentSegment = this->head;
    int segIndex = 0;
    while (currentSegment){
      LightSegment * segment = currentSegment->segment;
      if (reverse[segIndex]){
          segment->leds[segment->size-i] = color;
      } else {
          segment->leds[i] = color;
      }
      currentSegment = currentSegment->next; 
      segIndex++;
    }
    FastLED.show();
    delay(delayTime);
  }
}

void SegmentList::traceAllDontRemain(int thickness, int delayTime, boolean * reverse, CRGB color){

  int largestSize = this->getLongestSegmentSize();

  for (int i = 0; i <= largestSize + thickness; i++){
    SegmentNode * currentSegment = this->head;
    int segIndex = 0;
    while (currentSegment){
      LightSegment * segment = currentSegment->segment;
      if (reverse[segIndex]){
          if (segment->size-i >= 0 && i < largestSize){
            segment->leds[segment->size-i] = color;
          }
      } else {
          if (i <= segment->size && i < largestSize){
            segment->leds[i] = color;
          }
      }
      if (reverse[segIndex] && i >= thickness){
        segment->leds[segment->size-i+thickness] = CRGB::Black;
      } else if ( i >= thickness ) {
        segment->leds[i-thickness] = CRGB::Black;
      }
      currentSegment = currentSegment->next; 
      segIndex++;
    }
    FastLED.show();
    delay(delayTime);
  }

}

void SegmentList::traceAllKeepEnd(int thickness, int delayTime, boolean * reverse, CRGB color){

  int largestSize = this->getLongestSegmentSize();

  for (int i = 0; i <= largestSize; i++){
    SegmentNode * currentSegment = this->head;
    int segIndex = 0;
    while (currentSegment){
      LightSegment * segment = currentSegment->segment;
      if (reverse[segIndex]){
          if (segment->size-i >= 0 ){
            segment->leds[segment->size-i] = color;
          }
      } else {
          if (i <= segment->size ){
            segment->leds[i] = color;
          }
      }
      if (reverse[segIndex] && i >= thickness){
        segment->leds[segment->size-i+thickness] = CRGB::Black;
      } else if ( i >= thickness ) {
        segment->leds[i-thickness] = CRGB::Black;
      }
      currentSegment = currentSegment->next; 
      segIndex++;
    }
    FastLED.show();
    delay(delayTime);
  }

}
