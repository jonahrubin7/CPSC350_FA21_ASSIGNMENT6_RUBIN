#include "Person.h"
//using namespace std;

Person::Person(){ //constructor
  m_ID = 0;
  m_name = "";
  m_level = "";
  m_call = "";
  m_isFaculty = false;
}

Person::Person(int id, string name, string level){ //overloaded
  m_ID = id;
  m_name = name;
  m_level = level;
}

Person::~Person(){ //destructor

}

string Person::getName(){ //retruns name
  return m_name;
}

int Person::getID(){ //returns id
  return m_ID;
}

string Person::getLevel(){ //returns level of person
  return m_level;
}

string Person::getCall(){ //return call for roolback
  return m_call;
}

void Person::setCall(string call){ //sets call for rollback
  m_call = call;
}

bool Person::isFaculty(){ //checks if person is a faculty member or not
  return m_isFaculty;
}
