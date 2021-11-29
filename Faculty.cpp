#include "Faculty.h"

using namespace std;

Faculty::Faculty(){
  int m_ID = 0;
  string m_name = "";
  string m_level = "";
  string m_department = "";
  int advisees[120];
}

Faculty::Faculty(int id, string name, string level, string department){
  int m_ID = id;
  string m_name = name;
  string m_level = level;
  string m_department = department;
  int advisees[120]; //not sure what to make this. Number of id numbers
}

Faculty::~Faculty(){

}
