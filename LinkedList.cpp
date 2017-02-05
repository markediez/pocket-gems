#include "LinkedList.h"

LinkedList::LinkedList() {
  size = 0;
  head = NULL;
}

/**
* Insert a new node in the list in ascending GPA order
* head = head of the list
* data = data for new node
* @return curent head of the list
*/
void LinkedList::insert(Data data) {
  size++;

  // Insert a new node with the given data
  if (head == NULL) {
    head = new Node(data);
  } else {
    Node* currNode = head;
    Node* prevNode = NULL;
    Node* newNode = new Node(data);

    // Place node in proper spot
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
    } // end while
  } // end else
}

/**
* Finds the longest sequence such that gpa is increasing while sat scores are decreasing
* @return - head of the longest sequence
*/
Node* LinkedList::findLongestSequence(Node* h) {
  Node* longestHead = h;
  int longestSize = 0;
  int currSize = 0;
  int possibleLength = size;
  while(h->next != NULL) {
    currSize = trackSequence(h);

    // Update longestSize and longestHead when a longer sequence is found
    if (currSize > longestSize) {
      longestSize = currSize;
      longestHead = h;
    }

    if (possibleLength > longestSize) {
      h = h->next;
      possibleLength--;
    } else {
      // We can't find a longer sequence if the possible length is <= current sequence
      break;
    }
  }

  return longestHead;
}

/**
* Finds the sequence of ASC gpa and DESC sat for a given head
* h = head of list / sublist
* @return sequenceSize from h
*/
int LinkedList::trackSequence(Node *h) {
  Node* tail = h;
  Node* currNode = h->next;

  int sequenceSize = 1;
  while(currNode->next != NULL) {
    if(currNode->data.sat < tail->data.sat) {
      tail->nextSequence = currNode;
      tail = currNode;
      sequenceSize += currNode->sequenceSize;
    }

    if (currNode->nextSequence == NULL) {
      currNode = currNode->next;
    } else {
      // No need to find the sequence from here again
      break;
    }
  }

  updateSequenceSize(h, sequenceSize);
  return sequenceSize;
}

/**
* Updates the sequence size of each node in the sequence starting at h
* h = start of sequence
* sequenceSize = size of sequence from h
*/
void LinkedList::updateSequenceSize(Node* h, int sequenceSize) {
  while(h->nextSequence != NULL) {
    h->sequenceSize = sequenceSize;
    h = h->nextSequence;
    sequenceSize--;

    if (h->sequenceSize == sequenceSize) {
      // No need to update from here
      break;
    }
  }
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
