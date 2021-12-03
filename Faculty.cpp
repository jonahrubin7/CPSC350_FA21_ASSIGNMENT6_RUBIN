#include "Faculty.h"

using namespace std;

Faculty::Faculty(){
  m_ID = 0;
  m_name = "";
  m_level = "";
  m_department = "";
}

Faculty::Faculty(int id, string name, string level, string department){
  m_ID = id;
  m_name = name;
  m_level = level;
  m_department = department;
  //add param and advisee list 
}

Faculty::~Faculty(){

}
