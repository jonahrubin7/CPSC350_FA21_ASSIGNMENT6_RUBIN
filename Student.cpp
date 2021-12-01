#include "Student.h"

using namespace std;

Student::Student(){
  m_major = "";
  m_GPA = 0;
  m_advisor = 0;
}

Student::Student(string major, double gpa, int advisor){
  //think i need to add the other things back
  m_major = major;
  m_GPA = gpa;
  m_advisor = advisor;
}

Student::~Student(){

}

void Student::setAdvisor(int advisor){
  m_advisor = advisor;
}

int Student::getID(){
  return m_ID;
}
