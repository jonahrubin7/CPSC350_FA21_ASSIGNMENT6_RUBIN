#ifndef FACULTY_H //header guard
#define FACULTY_H //header guard
#include <string>
using namespace std;


#include "Person.h"
#include "LinkedList.h"

class Faculty : public Person{
public:
  Faculty();
  Faculty(int id, string name, string level, string department, DoublyLinkedList<int> *advisees);
  ~Faculty();
  int getID();
  DoublyLinkedList<int>* getAdvisees();
  void print();


private:
  int m_ID;
  string m_name;
  string m_level;
  string m_department;
  DoublyLinkedList<int> *m_advisees = new DoublyLinkedList<int>();
  bool m_isFaculty;
  //idk
  //overloaded operators??
};
#endif
