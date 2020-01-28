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

void SegmentList::add(LightSegment * newSegment){
  SegmentNode * currentSegment = this->head;
  while (currentSegment->next){
    currentSegment = currentSegment->next;
  }
  currentSegment->next = new SegmentNode(newSegment);
  this->size++;
}

void SegmentList::setAllToColor(Color color){
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

void SegmentList::fadeAllIn(int delayTime){
  SegmentNode * currentSegmentSegmentNode = this->head;
  for (int i = 1; i <= 70; i++){
    currentSegmentSegmentNode = this->head;
    while (currentSegmentSegmentNode){
      LightSegment * segment = currentSegmentSegmentNode->segment;
      Color newColor = { (segment->r/70) * i, (segment->g/70) * i, (segment->b/70) * i };
      segment->setToColorNoUpdate(newColor);
      currentSegmentSegmentNode = currentSegmentSegmentNode->next;
    }
    FastLED.show();
    delay(delayTime);
  }
}

void SegmentList::fadeAllDown(int delayTime){
  SegmentNode * currentSegmentSegmentNode;
  for (int i = 1; i <= 70; i++){
    currentSegmentSegmentNode = this->head;
    while (currentSegmentSegmentNode){
      LightSegment * segment = currentSegmentSegmentNode->segment;
      Color newColor = { segment->r - ((segment->r/70) * i), segment->g - ((segment->g/70) * i), segment->b - ((segment->b/70) * i)};
      segment->setToColorNoUpdate(newColor);
      currentSegmentSegmentNode = currentSegmentSegmentNode->next;
    }
    FastLED.show();
    delay(delayTime);
  }  
  turnAllOff();
}

// each segment must be equal in length
void SegmentList::traceAll(int thickness, int delayTime, boolean * reverse){
  for (int i = 0; i < this->head->segment->endIndex - this->head->segment->startIndex - thickness + 2; i++){
    SegmentNode * currentSegment = this->head;
    int segIndex = 0;
    while (currentSegment){
      LightSegment * segment = currentSegment->segment;
      for (int j = 0; j < thickness; j++){
        if (reverse[segIndex]){
            segment->leds[segment->endIndex-i-j] = CRGB(segment->r,segment->g,segment->b);
        } else {
            segment->leds[segment->startIndex+i+j] = CRGB(segment->r,segment->g,segment->b);
        }
      }
      currentSegment = currentSegment->next; 
      segIndex++;
    }
    FastLED.show();
    delay(delayTime);
  }
}
