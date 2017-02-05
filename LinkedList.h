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

    int trackSequence(Node* h);
    void updateSequenceSize(Node* h, int sequenceSize);
  public:
    LinkedList();
    LinkedList(Node* h);

    void insert(Data data);
    void print();
    void printSequence(Node* n);
    Node* findLongestSequence(Node* h);

    // Accessors
    int getSize();
    Node* getHead();
};

#endif
