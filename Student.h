#ifndef STUDENT_H //header guard
#define STUDENT_H //header guard
#include "Person.h"

#include <string>
using namespace std;

class Student : public Person{
public:
  Student();
  Student(int id, string name, string level, string major, double gpa, int advisor); //overloaded
  ~Student();
  //getters and setters
  void setAdvisor(int advisor);
  double getGPA();
  int getAdvisor();
  string getMajor();
  int getID();
  void print();
  string getName();
  string getLevel();
  bool compareStudent(Student s1, Student s2);


private:
  int m_ID;  //member varibales 
  string m_name;
  string m_level;
  string m_major;
  double m_GPA;
  int m_advisor;

  //compare (greater than or less than) ???
};

#endif
