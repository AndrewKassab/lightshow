#include "LinkedList.hpp"

LinkedList::LinkedList(LightSegment * head){
  Node * newNode = new Node(head);
  this->head = newNode;
}

void LinkedList::add(LightSegment * newSegment){
  Node * currentSegment = this->head;
  while (currentSegment->next){
    currentSegment = currentSegment->next;
  }
  currentSegment->next = new Node(newSegment);
}

void LinkedList::setAllToColor(int r, int g, int b){
  Node * currentSegment = this->head;
  while (currentSegment){
    currentSegment->segment->setToColor(r,g,b);
    currentSegment = currentSegment->next;
  }
}

void LinkedList::turnAllOff(){
  Node * currentSegment = this->head;
  while (currentSegment){
    currentSegment->segment->turnOff();
    currentSegment = currentSegment->next;
  }
}


void LinkedList::fadeAllIn(int delayTime){
  Node * currentSegmentNode = this->head;
  for (int i = 1; i <= 70; i++){
    currentSegmentNode = this->head;
    while (currentSegmentNode){
      LightSegment * segment = currentSegmentNode->segment;
      segment->setToColorNoUpdate((segment->r/70) * i, segment->g/70 * i, segment->b/70 * i);
      currentSegmentNode = currentSegmentNode->next;
    }
    FastLED.show();
    delay(delayTime);
  }
}
