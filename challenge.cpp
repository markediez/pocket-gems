/**
* Author: Mark Emmanuel Diez
* Date: 05 February 2017
*
* Program Description:
* This program provides the longest sequence such that as GPA increases, SAT scores decreases.
*/
#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char* argv[]) {
  // Open program properly
  if (argc != 2) {
    cout << "Run the program './program.out <filename>' e.g. './program.out data.txt'" << endl;
    exit(0);
  }

  ifstream file(argv[1]);

  // Grab data from file and store in LinkedList
  LinkedList list;
  int n, sat;
  double gpa;
  if (file.is_open()) {
    file >> n;
    for(int i = 0; i < n; i++) {
      file >> gpa >> sat;

      Data newData(gpa, sat);
      list.insert(newData);
    }
  } else {
    cout << "File '" << argv[1] << "' does not exist.";
    exit(0);
  }

  Node* h = list.findLongestSequence(list.getHead());
  cout << "Longest Sequence has the size of " << h->sequenceSize << ":" << endl;
  list.printSequence(h);

  file.close();
  return 0;
}
