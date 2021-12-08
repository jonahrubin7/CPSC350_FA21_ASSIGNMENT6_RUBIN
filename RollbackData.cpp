#include "RollbackData.h" //import needed files

RollbackData::RollbackData(){  //constructor
  //m_student = NULL;
  //m_faculty = NULL;
  m_transaction = "";
}

RollbackData::RollbackData(int id, Student student, string transaction){ //overloaded
  m_student = student;
  m_transaction = transaction;
  m_isFaculty = false;
  m_id = id;

}

RollbackData::RollbackData(int id, Faculty faculty, string transaction){ //overloaded
  m_faculty = faculty;
  m_transaction = transaction;
  m_isFaculty = true;
  m_id = id;
}

RollbackData::~RollbackData(){ //destructor

}

string RollbackData::getTransaction(){ //returns transaction
  return m_transaction;
}

bool RollbackData::isFaculty(){ // returns boolean to see if type is faculty
  return m_isFaculty;
}

Faculty RollbackData::getPerson(string faculty){ //checks if type is person
  return m_faculty;

}

Student RollbackData::getPerson(){  // return person type
  cout << "THIS IN GET PERSON ID " << m_student.getID();
  return m_student;
}

int RollbackData::getID(){ // returns ID
  return m_id;
}
