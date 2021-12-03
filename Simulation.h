#ifndef SIMULATION_H //header guard
#define SIMULATION_H //header guard


#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

class Simulation{
  public: //public
    Simulation(); //constructor
    ~Simulation();  //destructor
    void processFile(); //define method that processes the file
    int stringToInt(string id);

  private: //private variables
    ifstream inFS; //read in the file

    BST<Student>* masterStudent;
    BST<Faculty>* masterFaculty;
};
#endif
