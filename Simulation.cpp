#include "Simulation.h"


Simulation::Simulation(){
  masterStudent = new BST<Student>();
  masterFaculty = new BST<Faculty>();
  facultyIDs = new DoublyLinkedList<int>;
  studentIDs = new DoublyLinkedList<int>;
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
  numFacultyMembers = 0;
  numStudents = 0;

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
        studentIDs->insertBack(id);
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

        Faculty f = createFaculty(facultyStringID, name, level, department, advisees, false);
        id = f.getID();
        masterFaculty->insert(id, f);
        facultyIDs->insertBack(id);

      }
    }
  }
  inFS.close();

  //printBSTs();
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
    }else if(n > 1){
      currNum = (double(gpa[n]) - '0');
      ++count;
      for(int i = 0; i < count; ++i){
        currNum = currNum/10;
      }
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

Faculty Simulation::createFaculty(string facultyStringID, string name, string level, string department, string advisees, bool added){
  facultyID = stringToInt(facultyStringID);
  //not sure if the advisee list is working 100%
  string currAdvisee = "";
  adviseeIDs = new DoublyLinkedList<int>();
  for(int i = 0; i < advisees.size(); ++i){
    if(advisees[i] != ','){
      currAdvisee += advisees[i];
    }else{
      advisee = stringToInt(currAdvisee);
      currAdvisee = "";
      if(added){
        ++i;
      }
      adviseeIDs->insertBack(advisee);
    }

    if(i == advisees.size()-1){
      advisee = stringToInt(currAdvisee);
      currAdvisee = "";
      //++i;
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
  cout << "\nStudent Information:\n" << endl;
  printStudent.print();
  cout << endl;
  //masterFaculty->printStudent();
  //cout << "Student ID: " << studentID << endl;
  //neeed to do this one
}

//4
void Simulation::printFaculty(string facultyIDstring){
  facultyID = stringToInt(facultyIDstring);
  Faculty printFac = masterFaculty->find(facultyID);
  cout << "\nFaculty Information:\n" << endl;
  printFac.print();
  cout << endl;
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
  cout << "\nAdvisor Information:\n" << endl;
  sAdvisor.print();
  cout << endl;
}

//6
void Simulation::printAdvisees(string facultyIDstring){
  int advisorID = stringToInt(facultyIDstring);
  Faculty advisor = masterFaculty->find(advisorID);

  DoublyLinkedList<int> *advisees = advisor.getAdvisees();

  for(int i = 0; i < advisees->getSize(); ++i){
    int id = advisees->accessAtPos(i);
    Student s = masterStudent->find(id);
    cout << "\nAdvisee #" << i+1 << endl;
    s.print();
  }

  // for(int i = 0; i < advisees->getSize(); ++i){
  //   cout << advisees->accessAtPos(i);
  //   if(i != advisees->getSize()-1){
  //     cout << ", ";
  //   }
  // }

}

//7
void Simulation::addStudent(){
  cout << "Please enter the following information for the student you would like to add: " << endl;
  cout << "ID: ";
  cin >> studentStringID;
  cout << "\nName: ";
  getline(cin >> ws, name);
  cout << "\nGrade: ";
  cin >> level;
  cout << "\nMajor: ";
  getline(cin >> ws, major);
  cout << "\nGPA: ";
  cin >> gpa;
  cout << "\nAdvisor ID: ";
  cin >> advisor;

  //create student
  Student student = createStudent(studentStringID, name, level, major, gpa, advisor);

  id = student.getID();
  masterStudent->insert(id, student);
  studentIDs->insertBack(id);

  cout << "\nThe student you have entered has been inserted into the database.\n";

  int advisorID = student.getAdvisor();
  Faculty advisor = masterFaculty->find(advisorID);
  advisor.addToAdvisees(id);
  //printBSTs();
}

//8
void Simulation::deleteStudent(string id){
  int intID = stringToInt(id);
  Student deleteS = masterStudent->find(intID);
  int advisorID = deleteS.getAdvisor();
  masterStudent->deleteNode(intID);
  Faculty advisor = masterFaculty->find(advisorID);
  advisor.removeAdvisee(intID);
  studentIDs->removeNode(intID);
}

//9
void Simulation::addFaculty(){
  cout << "Please enter the following information for the faculty member you would like to add: " << endl;
  cout << "ID: ";
  cin >> facultyStringID;
  cout << "\nName: ";
  getline(cin >> ws, name);
  cout << "\nLevel: ";
  getline(cin >> ws, level);
  cout << "\nDepartment: ";
  getline(cin >> ws, department);
  cout << "\nPlease enter the student IDs of all advisees in a comma and space seperated list (EX: 14256, 23763, 87261, ...): " << endl;
  getline(cin >> ws, advisees);

  Faculty f = createFaculty(facultyStringID, name, level, department, advisees, true);
  ++numFacultyMembers;
  //Faculty f = Faculty(facultyID, facultyName, level, department, addAdvisees);
  id = f.getID();
  //cout << f.getID() << endl;

  //cout << "does it seg fault here " << endl;
  masterFaculty->insert(id, f);
  facultyIDs->insertBack(id);
  //masterFaculty->insert(id, f);
  // cin list of id numbers, not sure how to do that yet

  printBSTs();
}

//10
void Simulation::deleteFaculty(string id){

  int intID = stringToInt(id);
  Faculty deleteF = masterFaculty->find(intID);
  adviseeIDs = deleteF.getAdvisees();
  //linked list of id nmbers, deleted faculty is removed
  facultyIDs->removeNode(intID);
  //--numFacultyMembers;
  //each advisee from the list is randomly assigned to a new advisor
  for(int i = 0; i < adviseeIDs->getSize(); ++i){

    int currentStudent = adviseeIDs->accessAtPos(i);
    int randNum = rand() % (facultyIDs->getSize());
    int randomAdvisorID = facultyIDs->accessAtPos(randNum);
    Faculty newAdvisor = masterFaculty->find(randomAdvisorID);
    newAdvisor.addToAdvisees(currentStudent);
    Student reassignedStudent = masterStudent->find(currentStudent);
    reassignedStudent.setAdvisor(randomAdvisorID);

  }
  masterFaculty->deleteNode(intID);

  cout << "\nThe faculty member has been deleted and their advisees have been randomly reassigned to new advisors\n";

}
