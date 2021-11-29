#include "Simulation.h"

//main method only calls commands for the simulation
int main(int argc, char** argv){
  Menu m;
  FileProcessor f;

  // need to look for the correct file names in the current directory
  // if files found, send file to file processor like the lines below
  f.processFile("studentTable") //this line will not work rn
  f.processFile("facultyTable") //this line will not work rn

  //BSTs will have now been created... somewhere

  //now begin the process of working with the database

  m.displayOptions(); //optionsPrinted

  return 0;
}
