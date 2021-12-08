#ifndef ROLLBACKDATA_H //header guard
#define ROLLBACKDATA_H //header guard
#include <string>
#include "Faculty.h"
#include "Student.h" //include needed files 
using namespace std;
//#include "LinkedList.h" //include needed files


//abstract person class
class RollbackData{
public:
  RollbackData(); //initiate methods that will be used
  RollbackData(int id, Student student, string transaction); //overloaded
  RollbackData(int id, Faculty faculty, string transaction); //overloaded
  ~RollbackData(); //destructor
  string getTransaction(); //create needed methods
  bool isFaculty();
  Faculty getPerson(string faculty);
  Student getPerson();
  int getID();
  //getters and setters
//   int getID();
//   string getName();
//   string getLevel();
//   string getCall();
//   void setCall(string call);
//   bool isFaculty();
//
//
 private: //member variables
   string m_transaction;
   Student m_student;
   Faculty m_faculty;
//   string m_call;
   bool m_isFaculty;
   int m_id;

};

#endif
