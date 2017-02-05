#ifndef _DATA_H
#define _DATA_H

struct Data {
  double gpa;
  int sat;

  Data();
  Data(double _gpa, int _sat);

  void operator=(Data &rhs);
};

#endif
