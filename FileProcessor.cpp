#include "FileProcessor.h"


FileProcessor::FileProcessor(){} //empty constructor

FileProcessor::~FileProcessor(){} //empty destructor

void FileProcessor::processFile(){
  string studentStringID = "";
  int studentID = 0;
  string name = "";
  string level = "";
  string major = "";
  double gpa = 0.0;
  string advisor = "";
  inFS.open("studentTable.txt");
  if(!inFS.is_open()){
    masterStudent = new BST<Student>();
    exit(1);
  }else{
    while(!inFS.eof()){
      if(!inFS.fail()){
        string line = "";
        string parsed = "";
        getline(inFS,line);
        while(getline(line, parsed, ",")){
          studentStringID = parsed;
          studentID = stringToInt(studentStringID);
          name = getline(line, parsed, ",");
          level = getline(line, parsed, ",");
          major = getline(line, parsed, ",");
          gpa = getline(line, parsed, ",");
          sGPA = stringToInt(studentStringID); //doesnt work
          advisor = getline(line, parsed, "");
        }
        Student s = new Student(studentID, name, level, major, sGPA, advisor);
        masterStudent->insert(studentID, s);
      }
    }
  }
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
  //         string advisees = getline(line, parsed, "/n");
  //       }
  //       Faculty f = new Faculty(facultyID, name, level, department, advisees);
  //       masterFaculty->insert(facultyID, f);
  //     }
  //   }
  // }
}


int FileProcessor::stringToInt(string id){
  int number = 0;
  for(int n = 0; n < id.size(); ++n){
    number *= 10;
    number += (int(id[n]) - '0');
  }
  return number;
}
