#ifndef SIMULATION_H //header guard
#define SIMULATION_H //header guard
#include <string>
using namespace std;


#include <iostream>// needed files 
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "bst.h"
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"
#include "RollbackData.h"


//using namespace std;

class Simulation{
  public: //public
    Simulation(); //constructor
    ~Simulation();  //destructor

    void CreateInitialBSTs();

    int stringToInt(string id);
    double gpaStringToDouble(string gpa);
    void printBSTs();

    Student createStudent(string studentStringID, string name, string level, string major, string gpa, string advisor);
    Faculty createFaculty(string facultyStringID, string name, string level, string department, string advisees, bool added);

    //Display options
    void printStudents(); //1
    void printFaculty(); //2
    void printStudent(string studentIDstring); //3
    void printFaculty(string facultyIDstring); //4
    void printAdvisor(string studentIDstring); //5
    void printAdvisees(string facultyIDstring); //6

    //Add or delete options
    void addStudent();
    void deleteStudent(string id, bool rollback);
    void addFaculty();
    void deleteFaculty(string id, bool rollback);
    void rollback();
    string treeToStringStudent(TreeNode<Student>* root);
    string treeToStringFaculty(TreeNode<Faculty>* root);
    void exitSim();
    //void rollback();

    //Edit functions
    void changeAdvisor(string studentID, string newAdvisor, bool newA);
    void removeAdvisee(string advisor, string advisee);

    //need to add rollback and exit


  private: //private variables
    ifstream inFS; //read in the file
    string studentStringID;
    int studentID;
    int id;
    string name;
    string level;
    string major;
    string gpa;
    double sGPA;
    string advisor;
    int intAdvisor;
    string line;
    string facultyStringID;
    int facultyID;
    string currAdvisee;
    string advisees;
    string department;
    int advisee;


    DoublyLinkedList<int> *adviseeIDs;

    DoublyLinkedList<int> *facultyIDs;
    DoublyLinkedList<int> *studentIDs;

    int numFacultyMembers;
    int numStudents;

    BST<Student>* masterStudent;
    BST<Faculty>* masterFaculty;

    GenStack<RollbackData> *stack;
    GenStack<RollbackData> *topFourStack;
    //Menu m;
};
#endif
