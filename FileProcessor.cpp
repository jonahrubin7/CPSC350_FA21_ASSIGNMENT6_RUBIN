#include "FileProcessor.h"


FileProcessor::FileProcessor(){} //empty constructor

FileProcessor::~FileProcessor(){} //empty destructor

void FileProcessor::processFile(string inputFile){
  inFS.open(inputFile);

  string input = "";
  if(!inFS.is_open()){
    cout << "Sorry, the file you have entered cannot be opened, please try again with a valid file." << endl;
    exit(1);
  }

  if(inputFile == "studentTable"){
    //for every line, create student, add student to BST
  }else if(inputFile == "facultyTable"){
    //for every line, create faculty member, add faculty to BST
  }

  //this is code from last project-- irrelevant but structure will be helpful so leaving it here
  int lineCount = 0;
  while(!inFS.eof()){
    if(!inFS.fail()){
      if(lineCount == 0){
        inFS >> numWindows;
        // registrar = new Registrar(numWindows);
      }
      inFS >> input;
      int currTime = stoi(input);
      inFS >> input;
      int numStudents = stoi(input);
      for(int i = 0; i < numStudents; i++){
        inFS >> input;
        int timeNeeded = stoi(input);
        Student* currStudent = new Student(timeNeeded,currTime);
        students->insert(currStudent);
      }
      lineCount++;
    }
  }
}
