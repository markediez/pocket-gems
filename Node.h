#ifndef _NODE_H
#define _NODE_H

#include "Data.h"

struct Node {
  Data data;
  Node* next;

  // Should point to the closest node with > gpa and < sat
  Node* nextSequence;

  Node(Data _data);
};

#endif
