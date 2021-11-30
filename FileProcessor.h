#ifndef FILEPROCESSOR_H //header guard
#define FILEPROCESSOR_H //header guard


#include <iostream>
#include <fstream>

using namespace std;

class FileProcessor{
  public: //public
    FileProcessor(); //constructor
    ~FileProcessor();  //destructor
    void processFile(string inputFile); //define method that processes the file

  private: //private variables
    //ifstream inFS; //read in the file
    // Registrar* registrar;
    //GenQueue<Student>* students;
};
#endif
