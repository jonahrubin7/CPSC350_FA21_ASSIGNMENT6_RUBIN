#include "Edit.h"

Edit::Edit(){
  //empty constructor
}

Edit::~Edit(){
  //empty destructor
}

void Edit::changeAdvisor(int studentID, int newAdvisor){
  //find student in masterStudent BST
  //get old advisor ID
  //change advisor to new advisor

  //go to new advisor and add student to the list of printAdvisees

  //go to old advisor and remove student from list of advisees
}

void Edit::removeAdvisee(int advisor, int advisee){
  //find faculty mem in masterFaculty BST
  //remove advisee from the list of advisees
  //find the student that was just removed in the masterStudent BST
  //assign them a new advisor
}
