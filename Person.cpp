#include "Person.h"

using namespace std;

Person::Person(){
  m_ID = 0;
  m_name = "";
  m_level = "";
}

Person::Person(int id, string name, string level){
  m_ID = id;
  m_name = name;
  m_level = level;
}

Person::~Person(){

}

string Person::getName(){
  return m_name;
}

int Person::getID(){
  return m_ID;
}

string Person::getLevel(){
  return m_level;
}
