#include "Simulation.h"


Simulation::Simulation(){} //empty constructor

Simulation::~Simulation(){} //empty destructor

void Simulation::Simulate(){
  string studentStringID = "";
  int studentID = 0;
  string name = "";
  string level = "";
  string major = "";
  string gpa = "";
  double sGPA = 0.0;
  string advisor = "";
  int intAdvisor = 0;
  string line = "";
  inFS.open("studentTable.txt");
  if(!inFS.is_open()){
    masterStudent = new BST<Student>();
    exit(1);
  }else{
    while(!inFS.eof()){
      getline(inFS, line);
      stringstream parsed(line);
      getline(parsed, studentStringID, ',');
      studentID = stringToInt(studentStringID);
      getline(parsed, name, ',');
      getline(parsed, level, ',');
      getline(parsed, major, ',');
      getline(parsed, gpa, ',');
      //sGPA = stringToInt(studentStringID); //doesnt work
      getline(parsed, advisor, '\n'); //maybe should be \n
      intAdvisor = stringToInt(advisor);
      masterStudent = new BST<Student>();
      Student s = Student(studentID, name, level, major, sGPA, intAdvisor);
      masterStudent->insert(studentID, s);
      }
    }
  //}
  //populate bst


  // inFS.open("facultyTable.txt");
  // if(!inFS.is_open()){
  //   masterFaculty = new BST<faculty>();
  //   exit(1);
  // }else{
  //   while(!inFS.eof()){
  //     if(!inFS.fail()){
  //       string line = "";
  //       string parsed = "";
  //       getline(inFS,line);
  //       while(getline(line, parsed, ",")){
  //         string facultyStringID = parsed;
  //         int facultyID = stringToInt(facultyStringID);
  //         string name = getline(line, parsed, ",");
  //         string level = getline(line, parsed, ",");
  //         string department = getline(line, parsed, ",");
  //         string advisees = getline(line, parsed, "\n");
  //       }
  //       Faculty f = new Faculty(facultyID, name, level, department, advisees);
  //       masterFaculty->insert(facultyID, f);
  //     }
  //   }
  // }
}


int Simulation::stringToInt(string id){
  int number = 0;
  for(int n = 0; n < id.size(); ++n){
    number *= 10;
    number += (int(id[n]) - '0');
  }
  return number;
}
