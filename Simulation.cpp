#include "Simulation.h"


Simulation::Simulation(){} //empty constructor

Simulation::~Simulation(){} //empty destructor

void Simulation::Simulate(){
  string studentStringID = "";
  int studentID = 0;
  string name = "";
  string level = "";
  string major = "";
  string gpa = "";
  double sGPA = 0.0;
  string advisor = "";
  int intAdvisor = 0;
  string line = "";
  string facultyStringID = "";
  int facultyID = 0;
  string department = "";
  int advisee = 0;


  inFS.open("studentTable");
  masterStudent = new BST<Student>();
  if(!inFS.is_open()){
    exit(1);
  }else{
    while(!inFS.eof()){
      getline(inFS, line);
      if(line == "END OF FILE"){
        break;
      }else{
        stringstream parsed(line);
        getline(parsed, studentStringID, ',');
        studentID = stringToInt(studentStringID);
        getline(parsed, name, ',');
        getline(parsed, level, ',');
        getline(parsed, major, ',');
        getline(parsed, gpa, ',');
        sGPA = gpaStringToDouble(gpa);
        getline(parsed, advisor, '\n'); //maybe should be \n
        intAdvisor = stringToInt(advisor);
        Student s = Student(studentID, name, level, major, sGPA, intAdvisor);
        //cout << s.getID() << endl;
        masterStudent->insert(studentID, s);
      }
    }
  }

  inFS.close();

  //}
  //populate bst

  line = "";
  inFS.open("facultyTable");
  masterFaculty = new BST<Faculty>();
  if(!inFS.is_open()){
    exit(1);
  }else{
    while(!inFS.eof()){
      getline(inFS,line);
      if(line == "END OF FILE"){
        break;
      }else{
        stringstream parsed(line);
        getline(parsed, facultyStringID, ',');
        facultyID = stringToInt(facultyStringID);
        getline(parsed, name, ',');
        getline(parsed, level, ',');
        getline(parsed, department, ',');
        string advisees = "";
        getline(parsed, advisees, '\n');
        string currAdvisee = "";
        DoublyLinkedList<int> *adviseeIDs = new DoublyLinkedList<int>();
        for(int i = 0; i < advisees.size(); ++i){
          if(advisees[i] != ','){
            currAdvisee += advisees[i];
          }else{
            advisee = stringToInt(currAdvisee);
            currAdvisee = "";
            ++i;
            adviseeIDs->insertBack(advisee);
          }
        }
        //getline(parsed, advisees, '\n'); //maybe should be \n
        //intAdvisor = stringToInt(advisor);
        //plus advisee list
        Faculty f = Faculty(facultyID, name, level, department, adviseeIDs);
        //cout << f.getID() << endl;
        masterFaculty->insert(facultyID, f);
        //break;

      }
    }
  }
  inFS.close();

  cout << "LETS PRINT SOME BSTTSSSSS" << endl;

  cout << "master faculty bst\n\n";
  masterFaculty->printNode();

  cout << "master student  bst\n\n";
  masterStudent->printNode();
}


int Simulation::stringToInt(string id){
  int number = 0;
  for(int n = 0; n < id.size(); ++n){
    number *= 10;
    number += (int(id[n]) - '0');
  }
  return number;
}

double Simulation::gpaStringToDouble(string gpa){
  double returnGPA = 0;
  double currNum = 0;
  int count = 0;

  for(int n = 0; n < gpa.size(); ++n){
    if(n == 0){
      returnGPA = (double(gpa[n]) - '0');
    }else if(n > 1)
    currNum = (double(gpa[n]) - '0');
    ++count;
    for(int i = 0; i < count; ++i){
      currNum = currNum/10;
    }
    returnGPA += currNum;
  }

  return returnGPA;
}
