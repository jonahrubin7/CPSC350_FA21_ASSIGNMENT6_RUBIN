#include "Faculty.h"

using namespace std;

Faculty::Faculty(){
  m_ID = 0;
  m_name = "";
  m_level = "";
  m_department = "";
  m_isFaculty = true;
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

string Faculty::getName(){
  return m_name;
}

string Faculty::getLevel(){
  return m_level;
}
string Faculty::getDepartment(){
  return m_department;
}

string Faculty::advisees(){
  string advs = "";
  ListNode<int>* currNode = m_advisees->getFrontNode();
  while(currNode != NULL){
    advs += to_string(currNode->getValue());
    if(currNode->next == NULL){
      break;
    }else{
      advs += ",";
      currNode = currNode->next;
    }
  }
  //iterate through linked list and add each value to a string
  //
  return advs;
}

void Faculty::print(){
  cout << "Faculty ID: " << m_ID << endl;
  cout << "Name: " << m_name << endl;
  cout << "Level: " << m_level << endl;
  cout << "Department: " << m_department << endl;
  cout << "Advisees: ";
  for(int i = 0; i < m_advisees->getSize(); ++i){
    cout << m_advisees->accessAtPos(i);
    if(i != m_advisees->getSize()-1){
      cout << ", ";
    }
  }
  cout << " " << endl;
}

DoublyLinkedList<int>* Faculty::getAdvisees(){
  return m_advisees;
}

void Faculty::addToAdvisees(int idNum){
  m_advisees->insertBack(idNum);
}

void Faculty::removeAdvisee(int idNum){
  //cout << "works 2.5 \n";
  m_advisees->removeNode(idNum);
}

bool Faculty::checkForAdvisee(int advisee){
  //if advisee is in the list
  if(m_advisees->find(advisee) == -1){
    return false;
  }else{
    return true;
  }
}
