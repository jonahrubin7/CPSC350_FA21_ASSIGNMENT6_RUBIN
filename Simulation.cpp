#include "Simulation.h"


Simulation::Simulation(){
  masterStudent = new BST<Student>();
  masterFaculty = new BST<Faculty>();
} //empty constructor

Simulation::~Simulation(){} //empty destructor

void Simulation::CreateInitialBSTs(){
  studentStringID = "";
  studentID = 0;
  name = "";
  level = "";
  major = "";
  gpa = "";
  sGPA = 0.0;
  advisor = "";
  intAdvisor = 0;
  line = "";
  facultyStringID = "";
  facultyID = 0;
  department = "";
  advisee = 0;

//adds to the student BST if file is found
  inFS.open("studentTable");
  //masterStudent = new BST<Student>();
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
        getline(parsed, name, ',');
        getline(parsed, level, ',');
        getline(parsed, major, ',');
        getline(parsed, gpa, ',');
        getline(parsed, advisor, '\n');

        Student s = createStudent(studentStringID, name, level, major, gpa, advisor);
        id = s.getID();
        masterStudent->insert(id, s);
      }
    }
  }

  inFS.close();

//adds faculty to masterFaculty if file is found
  line = "";
  inFS.open("facultyTable");
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
        getline(parsed, name, ',');
        getline(parsed, level, ',');
        getline(parsed, department, ',');
        advisees = "";
        getline(parsed, advisees, '\n');

        Faculty f = createFaculty(facultyStringID, name, level, department, advisees);
        id = f.getID();
        masterFaculty->insert(id, f);

      }
    }
  }
  inFS.close();

  printBSTs();
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
  //this one doesnt work rn for past the decimal points
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

void Simulation::printBSTs(){
  cout << "master faculty bst\n\n";
  masterFaculty->printNode();

  cout << "master student  bst\n\n";
  masterStudent->printNode();
}

Student Simulation::createStudent(string studentStringID, string name, string level, string major, string gpa, string advisor){
  studentID = stringToInt(studentStringID);
  sGPA = gpaStringToDouble(gpa);
  intAdvisor = stringToInt(advisor);
  Student newStudent = Student(studentID, name, level, major, sGPA, intAdvisor);
  return newStudent;
}

Faculty Simulation::createFaculty(string facultyStringID, string name, string level, string department, string advisees){
  facultyID = stringToInt(facultyStringID);
  //not sure if the advisee list is working 100%
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
  Faculty newFaculty = Faculty(facultyID, name, level, department, adviseeIDs);
  return newFaculty;
}

//1
void Simulation::printStudents(){
  //this one needs to print them IN ORDER
  //currently not in order
  masterStudent->printNode();
}

//2
void Simulation::printFaculty(){
  //this one needs to print them IN ORDER
  //currently not in order
  masterFaculty->printNode();
}

//3
void Simulation::printStudent(string studentIDstring){
  studentID = stringToInt(studentIDstring);
  Student printStudent = masterStudent->find(studentID);
  printStudent.print();
  //masterFaculty->printStudent();
  //cout << "Student ID: " << studentID << endl;
  //neeed to do this one
}

//4
void Simulation::printFaculty(string facultyIDstring){
  facultyID = stringToInt(facultyIDstring);
  Faculty printFac = masterFaculty->find(facultyID);
  printFac.print();
  //need to actually do this
}

//5
void Simulation::printAdvisor(string studentIDstring){
  studentID = stringToInt(studentIDstring);
  //get the correct student
  Student printAdv = masterStudent->find(studentID);
  //gets the students advisor id, finds it in the bst, assigns the whole faculty member to sAdvisor
  int advisorID = printAdv.getAdvisor();
  Faculty sAdvisor = masterFaculty->find(advisorID);
  sAdvisor.print();
}

//6
void Simulation::printAdvisees(string facultyIDstring){


}

//7
void Simulation::addStudent(){
  cout << "Please enter the following information for the student you would like to add: " << endl;
  cout << "ID: ";
  cin >> studentStringID;
  cout << "\nName: ";
  cin >> name;
  cout << "\nGrade: ";
  cin.clear();
  //cin.ignore();
  cin >> level;
  cout << "\nMajor: ";
  string majors;
  //getline(cin, majors);
  //major = majors;
  cout << "THIS IS MAJOR: " << major << endl;
  //cin >> major;
  //cin.get(string major);
  //cin >> major;
  cin.ignore();
  cout << "\nGPA: ";
  cin.clear();
  cin.ignore();
  cin >> gpa;
  cout << "\nAdvisor ID: ";
  cin.clear();
  cin.ignore();
  cin >> advisor;

  //create student
  Student student = createStudent(studentStringID, name, level, major, gpa, advisor);

  id = student.getID();
  masterStudent->insert(id, student);

  printBSTs();
}

//9
void Simulation::addFaculty(){
  cout << "Please enter the following information for the faculty member you would like to add: " << endl;
  cout << "ID: ";
  cin >> facultyStringID;
  cout << "\nName: ";
  cin >> name;
  cout << "\nLevel: ";
  cin >> level;
  cout << "\nDepartment: ";
  cin >> department;
  cout << "\nPlease enter the student IDs of all advisees in a comma and space seperated list (EX: 14256, 23763, 87261, ...): " << endl;
  cin >> advisees;

  Faculty f = createFaculty(facultyStringID, name, level, department, advisees);

  //Faculty f = Faculty(facultyID, facultyName, level, department, addAdvisees);
  id = f.getID();
  //cout << f.getID() << endl;

  //cout << "does it seg fault here " << endl;
  masterFaculty->insert(id, f);
  //masterFaculty->insert(id, f);
  // cin list of id numbers, not sure how to do that yet

  printBSTs();
}
