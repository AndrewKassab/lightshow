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