#ifndef EDIT_H //header guard
#define EDIT_H //header guard

#include "Simulation.h"

namespace std;

class Edit : public Simulation{

public:
  Edit();
  ~Edit();
  //all of these made void rn, will not neccesarily stay void (??)
  void changeAdvisor(int studentID, int newAdvisor);
  void removeAdvisee(int advisor, int advisee);

};

#endif
