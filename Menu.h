//THIS CLASS WILL HAVE A LOT OF INCLUDES
//needs to include header files for all the different menu commands

#ifndef MENU_H //header guard
#define MENU_H //header guard

#include "Simulation.h"
// #include "Display.h"
// #include "AddOrDelete.h"
// #include "Edit.h"
// #include "Rollback.h"
// #include "Exit.h"
using namespace std;

class Menu{
public:
  Menu();
  ~Menu();
  void displayOptions();
  void chooseCommand();
  void beginSimulation();
  Simulation s;

private:
  string choice;
  // Display display;
  // AddOrDelete addOrDelete;
  // Edit edit;
  // Rollback rollback;
  // Exit exit;

};
#endif
