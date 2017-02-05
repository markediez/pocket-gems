#include "Data.h"

Data::Data() {
  gpa = 0;
  sat = 0;
}

Data::Data(double _gpa, int _sat) {
  gpa = _gpa;
  sat = _sat;
}

void Data::operator=(Data &rhs) {
  gpa = rhs.gpa;
  sat = rhs.sat;
}
