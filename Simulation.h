#ifndef SIMULATION_H //header guard
#define SIMULATION_H //header guard
#include <string>
using namespace std;


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "bst.h"
#include "Student.h"
#include "Faculty.h"

//using namespace std;

class Simulation{
  public: //public
    Simulation(); //constructor
    ~Simulation();  //destructor
    void Simulate(); //define method that processes the file
    int stringToInt(string id);
    double gpaStringToDouble(string gpa);

  private: //private variables
    ifstream inFS; //read in the file

    BST<Student>* masterStudent;
    BST<Faculty>* masterFaculty;
};
#endif
