# Pocket Gems Programming Challenge
Author: Mark Emmanuel Diez  
Email: msdiez@ucdavis.edu

---
## Running the program (macOS, Linux)
1. Run `make`
2. Run `./program.out <filename>`
---
## Input
The input file should be in the format
```
# of data
gpa_1 sat_1
gpa_2 sat_2
...
gpa_n sat_n
```

For example
```
21
3.3 1100
2.1 1425
2.3 1750
2.4 1300
2.5 1800
2.6 1400
2.7 1600
2.8 1150
3.4 1325
3.6 1475
3.1 1560
2.0 1250
3.2 1650
3.5 1975
3.8 1711
4.0 1325
2.9 2000
3.9 2150
2.2 2250
3.0 2200
3.7 2300
```
---
## Output
The output should show the size of the sequence followed by the sequence itself
```
Longest Sequence has the size of 5:
(2.2,2250)
(2.3,1750)
(2.4,1300)
(2.8,1150)
(3.3,1100)
```
---
## Algorithm
#### Definitions
> A **node** has data, next, nextSequence, sequenceSize.  
> **data** consists of an individual's GPA and SAT.  
> **next** is a node N with a parent node P such that N.data.gpa > P.data.gpa  
> **nextSequence** is a node N with a parent node P such that N.data.gpa > P.data.gpa and N.data.sat < P.data.sat  
> For a node N, **sequenceSize** is an integer that represents the number of existing nextSequence nodes from N   
> A **Linked List** is a list of nodes.


The algorithm to solve the problem is as follows.
1. Sort the data loaded by ascending GPA in a Linked List
2. Traverse through the list and find the longest sequenceSize.
  - For each node *N* in the list, find its sequence.
  - Keep track of the node with the most sequenceSize
  - Keep track of the possible size of a sequence
  - As soon as the possibleSize <= *N*.sequenceSize return N
3. Output the sequence with the resulting *N* from step 2
---
## Algorithm Analysis
Takes O(n) space

#### Adding Data + Sorting
The worst case is O(n^2) because it does a search O(n) and insert O(1) n times.

#### Finding the longest sequence
Again, worse case is O(n^2) which can only happen if no sequence exists.

In both cases, searching is the cause for n^2 time complexity.
---
## Notes
- The program assumes GPA and SAT scores are unique
- The program assumes a proper input file is provided
- The program returns the first instance of the longest sequence.
  - Therefore, given the longest sequence has the size of 3, if A represents the first longest sequence of such size, and B another sequence of such size, the program will return A.
- The program can run on Windows through cygwin or other programs that can provide a C++ environment with make.
