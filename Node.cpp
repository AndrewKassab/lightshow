#include "Node.hpp"

Node::Node(LightSegment * segment){
  this->segment = segment;
  this->next = NULL;
}