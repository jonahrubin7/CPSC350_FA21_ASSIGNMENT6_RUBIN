#include "Student.h"

using namespace std;

Student::Student(){
  m_ID = 0;
  m_name = "";
  m_level = "";
  m_major = "";
  m_GPA = 0;
  m_advisor = 0;
}

Student::Student(int ID, string name, string level, string major, double gpa, int advisor){
  //think i need to add the other things back
  m_ID = ID;
  m_name = name;
  m_level = level;
  m_major = major;
  m_GPA = gpa;
  m_advisor = advisor;
}

Student::~Student(){

}

void Student::setAdvisor(int advisor){
  m_advisor = advisor;
}

double Student::getGPA(){
  return m_GPA;
}

string Student::getMajor(){
  return m_major;
}

int Student::getAdvisor(){
  return m_advisor;
}
