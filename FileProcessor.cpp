#include "FileProcessor.h"


FileProcessor::FileProcessor(){} //empty constructor

FileProcessor::~FileProcessor(){} //empty destructor

void FileProcessor::processFile(){

  inFS.open("studentTable.txt");
  if(!inFS.is_open()){
    masterStudent = new bst<student>();
    exit(1);
  }else{
    while(!inFS.eof()){
      if(!inFS.fail()){
        string line = "";
        string parsed = "";
        getline(inFS,line);
        while(getline(line, parsed, ",")){
          string studentStringID = parsed;
          int studentID =
          string name = getline(line, parsed, ",");
          string level = getline(line, parsed, ",");
          string major = getline(line, parsed, ",");
          string gpa = getline(line, parsed, ",");
          int sGPA = stringToInt(studentStringID);
          string advisor = getline(line, parsed, "");
        }
        Student s = new Student(studentID, name, level, major, sGPA, advisor);
        masterStudent->insert(studentID, s);
      }
    }
  }
  //populate bst


  inFS.open("facultyTable.txt");
  if(!inFS.is_open()){
    masterFaculty = new bst<faculty>();
    exit(1);
  }else{
    while(!inFS.eof()){
      if(!inFS.fail()){
        string line = "";
        string parsed = "";
        getline(inFS,line);
        while(getline(line, parsed, ",")){
          string facultyStringID = parsed;
          int facultyID = stringToInt(facultyStringID);
          string name = getline(line, parsed, ",");
          string level = getline(line, parsed, ",");
          string department = getline(line, parsed, ",");
          string advisees = getline(line, parsed, "/n");
        }
        Faculty f = new Faculty(facultyID, name, level, department, advisees);
        masterFaculty->insert(facultyID, f);
      }
    }
  }
}


int FileProcessor::stringToInt(string id){
  int number = 0;
  for(int n = 0; n < id.size(); ++n){
    number *= 10;
    number += (int(id[n]) - '0');
  }
  return number;
}
