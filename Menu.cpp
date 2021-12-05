#include "Menu.h"

Menu::Menu(){
  //empty constructor
}

Menu::~Menu(){
  //empty destructor
}

void Menu::displayOptions(){
  string choice;
  cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
  cout << "2. Print all faculty and their information (sorted by ascending id #) " << endl;
  cout << "3. Find and display student information given the students id " << endl;
  cout << "4. Find and display faculty information given the faculty id " << endl;
  cout << "5. Given a student’s id, print the name and info of their faculty advisor " << endl;
  cout << "6. Given a faculty id, print ALL the names and info of his/her advisees. " << endl;
  cout << "7. Add a new student " << endl;
  cout << "8. Delete a student given the id " << endl;
  cout << "9. Add a new faculty member " << endl;
  cout << "10. Delete a faculty member given the id. " << endl;
  cout << "11. Change a student’s advisor given the student id and the new faculty id" << endl;
  cout << "12. Remove an advisee from a faculty member given the ids " << endl;
  cout << "13. Rollback " << endl;
  cout << "14. Exit" << endl;

  chooseCommand();
}


void Menu::chooseCommand(){
  cout << "\nPlease select an option from the menu displayed above: ";
  cin >> choice;

  if(choice == "1"){
    s.printStudents();
  }else if(choice == "2"){
    s.printFaculty();
  }else if(choice == "3"){
    string studentID;
    cout << "Please enter student ID of the student you would like to display: ";
    cin >> studentID;
    s.printStudent(studentID);
  }else if(choice == "4"){
    string facultyID;
    cout << "Please enter faculty ID: ";
    cin >> facultyID;
    s.printFaculty(facultyID);
  }else if(choice == "5"){
    string studentID;
    cout << "Please enter student ID: ";
    cin >> studentID;
    s.printAdvisor(studentID);
  }else if(choice == "6"){
    string facultyID;
    cout << "Please enter faculty ID: ";
    cin >> facultyID;
    //s.printAdvisees(facultyID);
  }else if(choice == "7"){
    s.addStudent();
  }else if(choice == "8"){
    string deleteStu;
    cout << "Enter the ID of the student you would like to delete: ";
    cin >> deleteStu;
    //s.deleteStudent(deleteStu);
  }else if(choice == "9"){
    s.addFaculty();
  }else if(choice == "10"){
    string deleteFacMem;
    cout << "Enter the ID of the faculty member you would like to delete: ";
    cin >> deleteFacMem;
    //s.deleteFaculty(deleteFacMem);
  }else if(choice == "11"){
    string studentID;
    cout << "Enter the ID of the student whose advisor you'd like to change: ";
    cin >> studentID;
    string newAdvisor;
    cout << "Enter the ID of the faculty member that will be their new advisor: ";
    cin >> newAdvisor;
    //s.changeAdvisor(studentID, newAdvisor);
  }else if(choice == "12"){
    string advisor;
    cout << "Enter the ID of the faculty member that you would like to remove an advisee from: ";
    cin >> advisor;
    string advisee;
    cout << "Enter the ID of the student/advisee you would like to remove: ";
    cin >> advisee;
    //s.removeAdvisee(advisor, advisee);
  }else if(choice == "13"){
    //rollback.Rollback();
    //not implemented at all yet
  }else if(choice == "14"){
    //exit.Exit();
    //not implemented at all yet
  }else{
    cout << "Sorry, the number you have entered does not seem to be a valid option. Please review the menu options and make a new selection." << endl;
  }

  if(choice == "0"){
    cout << "done!" << endl;
  }else if(choice != "14"){
    displayOptions();
  }
}




void Menu::beginSimulation(){
  s.CreateInitialBSTs();
  displayOptions();
}
