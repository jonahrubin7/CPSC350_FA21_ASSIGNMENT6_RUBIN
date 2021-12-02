#ifndef FACULTY_H //header guard
#define FACULTY_H //header guard
#include "Person.h"
using namespace std;

class Faculty : public Person{
public:
  Faculty();
  Faculty(string department);
  ~Faculty();


private:
  int m_ID;
  string m_name;
  string m_level;
  string m_department;
  int advisees[];

  //overloaded operators??
};
#endif
