#ifndef FACULTY_H //header guard
#define FACULTY_H //header guard
#include <string>
using namespace std;


#include "Person.h" //include needed files
#include "LinkedList.h"

class Faculty : public Person{ //inherits person.
public: //create methods that will be used
  Faculty(); //constructor
  Faculty(int id, string name, string level, string department, DoublyLinkedList<int> *advisees); //overloaded
  ~Faculty();// destructor
  int getID(); //needed methods 
  string getName();
  string getLevel();
  string getDepartment();
  string advisees();
  DoublyLinkedList<int>* getAdvisees(); //create linked list of advisees
  void print();
  void addToAdvisees(int idNum);
  void removeAdvisee(int idNum);
  bool checkForAdvisee(int advisee);



private: //create member variables
  int m_ID;
  string m_name;
  string m_level;
  string m_department;
  DoublyLinkedList<int> *m_advisees = new DoublyLinkedList<int>();
  bool m_isFaculty;
};
#endif
