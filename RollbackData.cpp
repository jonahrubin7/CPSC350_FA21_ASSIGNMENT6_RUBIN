#include "RollbackData.h"

RollbackData::RollbackData(){
  //m_student = NULL;
  //m_faculty = NULL;
  m_transaction = "";
}

RollbackData::RollbackData(int id, Student student, string transaction){
  m_student = student;
  m_transaction = transaction;
  m_isFaculty = false;
  m_id = id;

}

RollbackData::RollbackData(int id, Faculty faculty, string transaction){
  m_faculty = faculty;
  m_transaction = transaction;
  m_isFaculty = true;
  m_id = id;
}

RollbackData::~RollbackData(){

}

string RollbackData::getTransaction(){
  return m_transaction;
}

bool RollbackData::isFaculty(){
  return m_isFaculty;
}

Faculty RollbackData::getPerson(string faculty){
  return m_faculty;

}

Student RollbackData::getPerson(){
  cout << "THIS IN GET PERSON ID " << m_student.getID();
  return m_student;
}

int RollbackData::getID(){
  return m_id;
}
