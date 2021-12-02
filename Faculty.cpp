#include "Faculty.h"

using namespace std;

Faculty::Faculty(){
  m_ID = 0;
  m_name = "";
  m_level = "";
  m_department = "";
  advisees[120];
}

Faculty::Faculty(int id, string name, string level, string department){
  m_ID = id;
  m_name = name;
  m_level = level;
  m_department = department;
  advisees[120]; //not sure what to make this. Number of id numbers
}

Faculty::~Faculty(){

}
