// There is a hypothesis floating around that SAT score is a strong indicator of GPA. Your task is to provide the strongest counter example for this hypothesis. Given a data set of (sat, gpa) for the final year of a group of students, devise an algorithm to construct the longest sequence of (sati, gpai) of students with progressively better SAT scores, and progressively worse gpa’s, i.e. sat1 < sat2 < … < satk and gpa1 > gpa2 > … > gpak ( Assume SAT scores and gpa’s are unique )
// Please submit your code as a file in the language of your choice. Please add a description of your algorithm either in a comment in the code, or in the Message box below.
// Oops! We could not locate your form.

// [sat][gpa]

// some list
// decreasing sat
// increasing gpa
#include <iostream>
#include <fstream>

using namespace std;

// Structs
struct Data {
  double gpa;
  int sat;

  Data() {
    gpa = 0;
    sat = 0;
  }

  Data(double _gpa, int _sat) {
    gpa = _gpa;
    sat = _sat;
  }

  void operator=(Data &rhs) {
    gpa = rhs.gpa;
    sat = rhs.sat;
  }
};

struct Node {
  Data data;
  Node* next;

  // Should point to the closest node with > gpa and < sat
  Node* relevant;

  Node(Data _data) {
    next = NULL;
    relevant = NULL;
    data = _data;
  }
};

// Forward declare methods
void print(Node* head);
Node* insert(Node* head, Data data);

int main(int argc, char* argv[]) {
  // Open program properly
  if (argc != 2) {
    cout << "Run the program './program.out <filename>' e.g. './program.out data.txt'" << endl;
    exit(0);
  }

  ifstream file(argv[1]);

  // grab data from file
  Node* head = NULL;
  int n, sat;
  double gpa;
  if (file.is_open()) {
    file >> n;
    for(int i = 0; i < n; i++) {
      file >> gpa >> sat;

      Data newData(gpa, sat);
      // Insert in linked list sorted by ascending gpa
      head = insert(head, newData);
    }
  }

  print(head);


  // dynamic programming, find most length

  file.close();
  return 0;
}

/**
* Insert a new node in the list in ascending GPA order
* head = head of the list
* data = data for new node
* @return curent head of the list
*/
Node* insert(Node* head, Data data) {
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

  return head;
}

/**
* Prints the list
* head = head of the list
*/
void print(Node* head) {
  Node* currNode = head;
  while(currNode != nullptr) {
    cout << "(" << currNode->data.gpa << "," << currNode->data.sat << ")" << endl;
    currNode = currNode->next;
  }
}
