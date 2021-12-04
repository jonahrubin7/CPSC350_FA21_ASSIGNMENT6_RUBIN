#ifndef ADDORDELETE_H //header guard
#define ADDORDELETE_H //header guard

#include "Simulation.h"

namespace std;

class AddOrDelete : public Simulation{

public:
  AddOrDelete();
  ~AddOrDelete();
  //all of these made void rn, will not neccesarily stay void (??)
  void addStudent();
  void deleteStudent(int deleteStu);
  void addFaculty();
  void deleteFaculty(int deleteFacMem);

private:
  //info needed to add a student
  int studentID;
  string studentName;
  string grade;
  string major;
  double studentGPA;
  int advisorID;

  //info needed to add an advisor
  int facultyID;
  string facultyName;
  string level;
  string department;
  //linked list of advisees
};

#endif
