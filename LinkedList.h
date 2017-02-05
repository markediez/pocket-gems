#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>
#include "Node.h"
#include "Data.h"

using namespace std;

class LinkedList {
  private:
    int size;
    Node* head;

  public:
    LinkedList() {
      size = 0;
      head = NULL;
    }

    void insert(Data data);
    void print();

    // Accessors
    int getSize();
    Node* getHead();
};

#endif
