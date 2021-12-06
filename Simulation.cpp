#include "Simulation.h"


Simulation::Simulation(){
  masterStudent = new BST<Student>();
  masterFaculty = new BST<Faculty>();
  facultyIDs = new DoublyLinkedList<int>;
  studentIDs = new DoublyLinkedList<int>;
  //stack = new GenStack<Person>();
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
  if(studentIDs->find(studentID) != -1){
    Student printStudent = masterStudent->find(studentID);
    cout << "\nStudent Information:\n" << endl;
    printStudent.print();
    cout << endl;
  }else{
    cout << "\nSorry, the ID number that you have entered did not have a match in our system. Please try again or select a new option from the menu.\n";
  }
}

//4
void Simulation::printFaculty(string facultyIDstring){
  facultyID = stringToInt(facultyIDstring);
  if(facultyIDs->find(facultyID) != -1){
    Faculty printFac = masterFaculty->find(facultyID);
    cout << "\nFaculty Information:\n" << endl;
    printFac.print();
    cout << endl;
  }else{
    cout << "\nSorry, the ID number that you have entered did not have a match in our system. Please try again or select a new option from the menu.\n";
  }
  //need to actually do this
}

//5
void Simulation::printAdvisor(string studentIDstring){
  studentID = stringToInt(studentIDstring);
  //get the correct student
  if(studentIDs->find(studentID) != -1){
    Student printAdv = masterStudent->find(studentID);
    //gets the students advisor id, finds it in the bst, assigns the whole faculty member to sAdvisor
    int advisorID = printAdv.getAdvisor();
    if(advisorID == 0){
      cout << "\nThis student does not currently have an advisor. Please see menu option 11 if you would like to assign them one." << endl;
    }else{
      Faculty sAdvisor = masterFaculty->find(advisorID);
      cout << "\nAdvisor Information:\n" << endl;
      sAdvisor.print();
      cout << endl;
    }
  }else{
    cout << "\nSorry, the ID number that you have entered did not have a match in our system. Please try again or select a new option from the menu.\n";
  }
}

//6
void Simulation::printAdvisees(string facultyIDstring){
  int advisorID = stringToInt(facultyIDstring);

  if(facultyIDs->find(advisorID) != -1){
    Faculty advisor = masterFaculty->find(advisorID);

    DoublyLinkedList<int> *advisees = advisor.getAdvisees();

    for(int i = 0; i < advisees->getSize(); ++i){
      int id = advisees->accessAtPos(i);
      Student s = masterStudent->find(id);
      cout << "\nAdvisee #" << i+1 << endl;
      s.print();
    }

  }else{
    cout << "\nSorry, the ID number that you have entered did not have a match in our system. Please try again or select a new option from the menu.\n";
  }
}

//7
void Simulation::addStudent(){

  //get user input for all of the needed student info
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

  int intAdvisor = stringToInt(advisor);

  //this int will be -1 if the advisor does not exist in the system
  int inFacultyll = facultyIDs->find(intAdvisor);

  //if the advisor entered does not exist this error message will be displayed and the advisor will be set to 0 = no advisor
  if(inFacultyll == -1){
    cout << "\nWARNING: The advisor ID that you have entered does not match a faculty member in our system. This student will not be assigned an advisor because of this. If you would like to reassign an advisor for this student, please see menu option 11." << endl;
    advisor = "0";
  }

  //student is created
  Student student = createStudent(studentStringID, name, level, major, gpa, advisor);
  student.setCall("Delete");
  //stack->push(student);

  //student inserted into the bst
  id = student.getID();
  masterStudent->insert(id, student);
  //student ID number inserted into the linked list of student IDs
  studentIDs->insertBack(id);

  cout << "\nThe student you have entered has been inserted into the database.\n";

  //the advisor (if they have an advisor) gets this student added to their advisee list
  int advisorID = student.getAdvisor();
  if(advisorID != 0){
    Faculty advisor = masterFaculty->find(advisorID);
    advisor.addToAdvisees(id);
  }
}

//8
void Simulation::deleteStudent(string id){
  int intID = stringToInt(id);
  if(studentIDs->find(intID) != -1){
    Student deleteS = masterStudent->find(intID);
    deleteS.setCall("Insert");
    //stack->push(deleteS);
    int advisorID = deleteS.getAdvisor();
    //student is deleted from bst
    masterStudent->deleteNode(intID);
    Faculty advisor = masterFaculty->find(advisorID);
    //student is removed from advisors advisee list
    advisor.removeAdvisee(intID);
    //student ID removed from list of student IDs
    studentIDs->removeNode(intID);
    cout << "\nThe student has been deleted from the database.\n";
  }else{
    cout << "\nSorry, the student you are requesting to be deleted does not exist in the system. Please try a different ID or select a new option.\n";
  }
}

//9
void Simulation::addFaculty(){
  //gets user input for a new faculty member
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

  id = f.getID();
  DoublyLinkedList<int> *adviseesToRemove = new DoublyLinkedList<int>;

  masterFaculty->insert(id, f);
  facultyIDs->insertBack(id);
  //need to check the advisees that were just added
  stringstream ss;
  adviseeIDs = f.getAdvisees();
  for(int i = 0; i < adviseeIDs->getSize(); ++i){
    //if the student exists in the database
    int currentAdviseeID = adviseeIDs->accessAtPos(i);
    if(studentIDs->find(currentAdviseeID) != -1){
      //the student is already in the advisee list so does not need to be added
      //call change advisor to switch the advisor for the student
      string stringID = to_string(currentAdviseeID);

      //carries out the functions to change the advisor in this next call
      changeAdvisor(stringID, facultyStringID, false);
    }else{
      //if the advisee is not a student that exists in the system remove from the advisee list
      cout << "\nOops! Seems like an advisee ID that was entered is not an existing student. They have been removed from the advisors list.\n";
      adviseesToRemove->insertBack(currentAdviseeID);
    }

  }

  for(int i = 0; i < adviseesToRemove->getSize(); ++i){
    int currentRemoval = adviseesToRemove->accessAtPos(i);
    f.removeAdvisee(currentRemoval);
  }

  f.setCall("Delete");
  //stack->push(f);
}

//10
void Simulation::deleteFaculty(string id){

  int intID = stringToInt(id);
  if(facultyIDs->find(intID) != -1){
    Faculty deleteF = masterFaculty->find(intID);
    deleteF.setCall("Insert");
    //stack->push(deleteF);
    adviseeIDs = deleteF.getAdvisees();
    //linked list of id nmbers, deleted faculty is removed
    facultyIDs->removeNode(intID);
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
  }else{
    cout << "\nSorry, the ID number that you have entered did not have a match in our system. Please try again or select a new option from the menu.\n";
  }

}

//11
void Simulation::changeAdvisor(string studentID, string newAdvisor, bool newA){
    int sID = stringToInt(studentID);
    int aID = stringToInt(newAdvisor);
    if(studentIDs->find(sID) == -1){
      cout << "Sorry, the student ID you have entered does not exist in the system. Your current request will be terminated. Please try again with a valid student ID." << endl;
    }else if(facultyIDs->find(aID) == -1){
      cout << "Sorry, the advisor ID you have entered does not exist in the system. Your current request will be terminated. Please try again with a valid advisor ID." << endl;
    }else{
      Student changeAdv = masterStudent->find(sID);
      Faculty oldAdvisor = masterFaculty->find(changeAdv.getAdvisor());
      Faculty newAdvisor = masterFaculty->find(aID);
      changeAdv.setAdvisor(aID);
      masterStudent->deleteNode(sID);
      masterStudent->insert(sID, changeAdv);

      oldAdvisor.removeAdvisee(sID);
      //The new A boolean is for when option 11 is actually being called
      //This way these last two things dont happen when this function is being called from addFaculty
      if(newA){
        cout << "\nYour requested advisor change has been made." << endl;
        newAdvisor.addToAdvisees(sID);
      }
    }
}

//12
void Simulation::removeAdvisee(string advisor, string advisee){
  int aID = stringToInt(advisor);
  int sID = stringToInt(advisee);
  if(masterFaculty->contains(aID)){
    Faculty f = masterFaculty->find(aID);
    if(f.checkForAdvisee(sID)){
      f.removeAdvisee(sID);
      Student s = masterStudent->find(sID);
      masterStudent->deleteNode(sID);
      s.setAdvisor(0);
      masterStudent->insert(sID, s);
      cout << "The requested change has been applied. Student " << sID << " now currrently has no advisor. If you would like to reassign them a new advisor, please see menu option 11.\n";
    }else{
      cout << "\nSorry, the advisee you have entered is not currently advised by this faculty member.\n";
    }
  }else{
    cout << "\nSorry, the faculty ID you have entered does not match any ID in the system.\n";
  }

  //check to see if the advisee is in the advisee list
  // if they are remove
  // remove

}



// void Simulation::rollback(){
//   p = stack->pop();
//   id = p.getID()
//   stringstream ss;
//   ss<<id;
//   int i;
//   ss>>i;
//   if(p.getCall() == "Insert"){
//     if(p.isFaculty() == true){
//       masterFaculty->insert(i, p);
//     }else{
//       masterStudent->insert(i, p);
//     }
//   }
//   else if(p.getCall() == "Delete"){
//     if(p.isFaculty() == true){
//       deleteFaculty(i);
//     }else{
//       deleteStudent(i);
//     }
//   }
// }
