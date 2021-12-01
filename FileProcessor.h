#ifndef FILEPROCESSOR_H //header guard
#define FILEPROCESSOR_H //header guard


#include <iostream>
#include <fstream>

using namespace std;

class FileProcessor{
  public: //public
    FileProcessor(); //constructor
    ~FileProcessor();  //destructor
    void processFile(); //define method that processes the file
    int stringToInt(string id);

  private: //private variables
    ifstream inFS; //read in the file

    bst<Student>* masterStudent;
    bst<Faculty>* masterFaculty;
};
#endif
