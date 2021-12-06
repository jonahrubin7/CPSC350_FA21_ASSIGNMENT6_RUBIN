#ifndef PERSON_H //header guard
#define PERSON_H //header guard
#include <string>
using namespace std;
#include "LinkedList.h"


//abstract person class
class Person{
public:
  Person();
  Person(int id, string name, string level);
  ~Person();
  //getters and setters
  int getID();
  string getName();
  string getLevel();
  string getCall();
  void setCall(string call);
  bool isFaculty();


private:
  //maybe need to make these public? not sure yet
  int m_ID;
  string m_name;
  string m_level;
  string m_call;


  //compare (greater than or less than) ???
};

#endif
