#ifndef NODE
#define NODE 

#include "LightSegment.hpp"

class SegmentNode{
  public: 
    LightSegment * segment;
    SegmentNode * next;
    SegmentNode(LightSegment* segment);
};

#endif
