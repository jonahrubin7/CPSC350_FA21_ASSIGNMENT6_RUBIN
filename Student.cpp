#include "Student.h"

using namespace std;

Student::Student(){
  int m_ID = 0;
  string m_name = "";
  string m_field = "";
  string m_major = "";
  double m_GPA = 0;
  int m_advisor = 0;
}

Student::Student(int id, string name, string field, string major, double gpa, int advisor){
  int m_ID = id;
  string m_name = name;
  string m_field = field;
  string m_major = major;
  double m_GPA = gpa;
  int m_advisor = advisor;
}

Student::~Student(){

}

void Student::setAdvisor(int advisor){
  int m_advisor = advisor;
}

int Student::getID(){
  return m_ID;
}
