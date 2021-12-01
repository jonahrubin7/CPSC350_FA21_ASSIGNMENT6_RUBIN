#include "Faculty.h"

using namespace std;

Faculty::Faculty(){
  m_department = "";
  advisees[120];
}

Faculty::Faculty(string department){
  m_department = department;
  advisees[120]; //not sure what to make this. Number of id numbers
}

Faculty::~Faculty(){

}
