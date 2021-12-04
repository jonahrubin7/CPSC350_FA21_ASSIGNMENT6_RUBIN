#include "Faculty.h"

using namespace std;

Faculty::Faculty(){
  m_ID = 0;
  m_name = "";
  m_level = "";
  m_department = "";
}

Faculty::Faculty(int id, string name, string level, string department, DoublyLinkedList<int> *advisees){
  m_ID = id;
  m_name = name;
  m_level = level;
  m_department = department;
  m_advisees = advisees;
  //add param and advisee list
}

Faculty::~Faculty(){

}

int Faculty::getID(){
  return m_ID;
}
