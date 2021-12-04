#ifndef DISPLAY_H //header guard
#define DISPLAY_H //header guard

#include "Simulation.h"

namespace std;

class Display : public Simulation{

public:
  Display();
  ~Display();
  //all of these made void rn, will not neccesarily stay void (??)
  void printStudents();
  void printFaculty();
  void printStudent(int studentID);
  void printFaculty(int facultyID);
  void printAdvisor(int studentID);
  void printAdvisees(int facultyID);

};

#endif
