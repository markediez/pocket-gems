// There is a hypothesis floating around that SAT score is a strong indicator of GPA. Your task is to provide the strongest counter example for this hypothesis. Given a data set of (sat, gpa) for the final year of a group of students, devise an algorithm to construct the longest sequence of (sati, gpai) of students with progressively better SAT scores, and progressively worse gpa’s, i.e. sat1 < sat2 < … < satk and gpa1 > gpa2 > … > gpak ( Assume SAT scores and gpa’s are unique )
// Please submit your code as a file in the language of your choice. Please add a description of your algorithm either in a comment in the code, or in the Message box below.
// Oops! We could not locate your form.

// [sat][gpa]

// some list
// decreasing sat
// increasing gpa
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

  // grab data from file
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
  }

  list.print();

  // dynamic programming, find most length
  Node* h = list.findLongestSequence();
  list.printSequence(h);

  file.close();
  return 0;
}
