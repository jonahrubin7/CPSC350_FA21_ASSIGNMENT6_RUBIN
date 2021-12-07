#include "Student.h"


Student::Student(){
  m_ID = 0;
  m_name = "";
  m_level = "";
  m_major = "";
  m_GPA = 0;
  m_advisor = 0;
}

Student::Student(int id, string name, string level, string major, double gpa, int advisor){
  //think i need to add the other things back
  m_ID = id;
  m_name = name;
  m_level = level;
  m_major = major;
  m_GPA = gpa;
  m_advisor = advisor;
}

Student::~Student(){

}

int Student::getID(){
  return m_ID;
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

string Student::getName(){
  return m_name;
}

string Student::getLevel(){
  return m_level;
}

void Student::print(){
  cout << "Student ID: " << m_ID << endl;
  cout << "Name: " << m_name << endl;
  cout << "Grade: " << m_level << endl;
  cout << "Major: " << m_major << endl;
  cout << "GPA: " << m_GPA << endl;
  cout << "Advisor: " << m_advisor << endl;
}
