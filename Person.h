#ifndef PERSON_H //header guard
#define PERSON_H //header guard
#include <string>
using namespace std;
#include "LinkedList.h" //include needed files


//abstract person class
class Person{
public:
  Person(); //initiate methods that will be used
  Person(int id, string name, string level); // overloaded
  ~Person(); //destructor
  //getters and setters
  int getID(); //needed methods
  string getName();
  string getLevel();
  string getCall();
  void setCall(string call);
  bool isFaculty();


private: //member variables
  int m_ID;
  string m_name;
  string m_level;
  string m_call;
  bool m_isFaculty;

};

#endif
