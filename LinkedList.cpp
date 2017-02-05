#include "LinkedList.h"

/**
* Insert a new node in the list in ascending GPA order
* head = head of the list
* data = data for new node
* @return curent head of the list
*/
void LinkedList::insert(Data data) {
  size++;

  if (head == NULL) {
    head = new Node(data);
  } else {
    Node* currNode = head;
    Node* prevNode = NULL;
    Node* newNode = new Node(data);

    bool spotFound = false;
    while(!spotFound) {
      if(currNode->data.gpa > newNode->data.gpa) {
        // Insert new node in between 2 other nodes
        if(prevNode == NULL) {
          // A new head
          head = newNode;
          newNode->next = currNode;
        } else {
          prevNode->next = newNode;
          newNode->next = currNode;
        }

        spotFound = true;
      } else if (currNode->next == NULL) {
        // Insert new node at the end
        currNode->next = newNode;
        spotFound = true;
      } else {
        // Spot not found, keep going
        prevNode = currNode;
        currNode = currNode->next;
      }
    }
  }
}

/**
* Finds the longest sequence such that gpa is increasing while sat scores are decreasing
* @return - head of the longest sequence
*/
Node* LinkedList::findLongestSequence() {
  Node* h;
  
  return h;
}

/**
* Prints the list
* head = head of the list
*/
void LinkedList::print() {
  Node* currNode = head;
  while(currNode != nullptr) {
    cout << "(" << currNode->data.gpa << "," << currNode->data.sat << ")" << endl;
    currNode = currNode->next;
  }
}

/**
* Prints the list
* head = head of the list
*/
void LinkedList::printSequence(Node *n) {
  Node* currNode = n;
  while(currNode != nullptr) {
    cout << "(" << currNode->data.gpa << "," << currNode->data.sat << ")" << endl;
    currNode = currNode->nextSequence;
  }
}

// Accessors
int LinkedList::getSize() { return size; }
Node* LinkedList::getHead() { return head; }
