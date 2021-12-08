#include "Student.h" //include header file


Student::Student(){ //constructor
  m_ID = 0;
  m_name = "";
  m_level = "";
  m_major = "";
  m_GPA = 0;
  m_advisor = 0;
}

Student::Student(int id, string name, string level, string major, double gpa, int advisor){ //overloaded
  //think i need to add the other things back
  m_ID = id;
  m_name = name;
  m_level = level;
  m_major = major;
  m_GPA = gpa;
  m_advisor = advisor;
}

Student::~Student(){ //destructor

}

int Student::getID(){ //method for getting ID
  return m_ID;
}

void Student::setAdvisor(int advisor){ //method for setting the advisor ID for a student
  m_advisor = advisor;
}

double Student::getGPA(){ //Returns student GPA
  return m_GPA;
}

string Student::getMajor(){ //returns student major
  return m_major;
}

int Student::getAdvisor(){ //retruns student Advisor id
  return m_advisor;
}

string Student::getName(){ //returns student name
  return m_name;
}

string Student::getLevel(){ //returns student level
  return m_level;
}

void Student::print(){  //prints student info
  cout << "Student ID: " << m_ID << endl;
  cout << "Name: " << m_name << endl;
  cout << "Grade: " << m_level << endl;
  cout << "Major: " << m_major << endl;
  cout << "GPA: " << m_GPA << endl;
  cout << "Advisor: " << m_advisor << endl;
}

bool Student::compareStudent(Student s1, Student s2){ //compares students
  return(s1.getID() == s2.getID());
}
