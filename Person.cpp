#include "Person.h"

using namespace std;

Person::Person(){
  m_ID = 0;
  m_name = "";
  m_level = "";
}

Person::Person(int id, string name, string level){
  m_level = level;
  m_ID = id;
  m_name = name;
}

Person::~Person(){

}

string Person::getName(){
  return m_name;
}

int Student::getID(){
  return m_ID;
}
