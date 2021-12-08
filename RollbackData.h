#ifndef ROLLBACKDATA_H //header guard
#define ROLLBACKDATA_H //header guard
#include <string>
#include "Faculty.h"
#include "Student.h"
using namespace std;
//#include "LinkedList.h" //include needed files


//abstract person class
class RollbackData{
public:
  RollbackData(); //initiate methods that will be used
  RollbackData(int id, Student student, string transaction);
  RollbackData(int id, Faculty faculty, string transaction);
  ~RollbackData();
  string getTransaction();
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
