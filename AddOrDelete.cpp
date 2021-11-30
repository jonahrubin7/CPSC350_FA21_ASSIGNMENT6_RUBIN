#include "AddOrDelete.h"

AddOrDelete::AddOrDelete(){
  //empty constructor
}

AddOrDelete::~AddOrDelete(){
  //empty destructor
}

void AddOrDelete::addStudent(){
  cout << "Please enter the following information for the student you would like to add: " << endl;
  cout << "ID: ";
  cin >> studentID;
  cout << "\nName: ";
  cin >> studentName;
  cout << "\nGrade: ";
  cin >> grade;
  cout << "\nMajor: ";
  cin >> major;
  cout << "\nGPA: ";
  cin >> studentGPA;
  cout << "\nAdvisor ID: ";
  cin >> advisorID;

  //then need to create this student with the information above
  //and add them to the BST
}

void AddOrDelete::deleteStudent(int deleteStu){
  //find the student in the masterStudent BST
  //get id of advisor
  //delete student from BST
  //delete student id num from the advisors list of advisees
}

void AddOrDelete::addFaculty(){
  cout << "Please enter the following information for the faculty member you would like to add: " << endl;
  cout << "ID: ";
  cin >> facultyID;
  cout << "\nName: ";
  cin >> facultyName;
  cout << "\nLevel: ";
  cin >> level;
  cout << "\nDepartment: ";
  cin >> department;
  cout << "\nAdvisee ID numbers: ";
  // cin list of id numbers, not sure how to do that yet
}

void AddOrDelete::deleteFaculty(int deleteFacMem){
  //find faculty mem in masterFaculty BST
  //get list of advisee id numbers
  //delete faculty member from BST
  //redistribute advisees to new advisors 
}
