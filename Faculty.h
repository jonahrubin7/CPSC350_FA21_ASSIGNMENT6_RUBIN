#ifndef FACULTY_H //header guard
#define FACULTY_H //header guard
#include "Person.h"
using namespace std;

class Faculty : public Person{
public:
  Faculty();
  Faculty(int id, string name, string level, string department);
  ~Faculty();


private:
  int m_ID;
  string m_name;
  string m_level;
  string m_department;
  DoublyLinkedList<T> *advisees = new DoublyLinkedList<T>();

  //overloaded operators??
};
#endif
