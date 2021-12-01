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
          studentID = parsed;
          name = getline(line, parsed, ",");
          level = getline(line, parsed, ",");
          major = getline(line, parsed, ",");
          gpa = getline(line, parsed, ",");
          advisor = getline(line, parsed, "");
        }
        Student s = new Student(studentID, name, level, major, gpa, advisor);
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
          facultyID = parsed;
          name = getline(line, parsed, ",");
          level = getline(line, parsed, ",");
          department = getline(line, parsed, ",");
          advisees = getline(line, parsed, "/n");
        }
        Faculty f = new Faculty(facultyID, name, level, department, advisees);
        masterFaculty->insert(facultyID, f);
      }
    }
  }
}
