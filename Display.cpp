#include "Display.h"

Display::Display(){
  //empty constructor
}

Display::~Display(){
  //empty destructor
}

void Display::printStudents(){
  //goes to masterStudent BST
  //prints student info for every student in order

}

void Display::printFaculty(){
  //goes to masterFaculty BST
  //prints faculty member info for every person in order

}

void Display::printStudent(int studentID){
  //searches the masterStudent BST to find correct student using id
  //then prints the information of that student

}

void Display::printFaculty(int facultyID){
  //searches masterFaculty BST to find the specified faculty member
  //then prints info for that faculty member

}

void Display::printAdvisor(int studentID){
  //searches masterStudent BST to find the specified student
  //gets the advisor id number
  //searches the masterFaculty BST using the advisor ID
  //prints info for the advisor

}

void Display::printAdvisees(int facultyID){
  //searches masterFaculty BST to find the specified faculty member
  //gets the linked list of student advisee id numbers
  //for loop
  //for everey student id num in the list
  //searches masterStudent BST and prints info for each studnent

}
