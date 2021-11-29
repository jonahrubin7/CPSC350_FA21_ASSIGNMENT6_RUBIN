#ifndef STUDENT_H //header guard
#define STUDENT_H //header guard

using namespace std;

class Student{
public:
  Student();
  Student(int id, string name, string field, string major, double gpa, int advisor);
  ~Student();
  //getters and setters
  void setAdvisor();
  int getID();


private:
  int m_ID;
  string m_name;
  string m_field;
  string m_major;
  double m_GPA;
  int m_advisor;

  //compare (greater than or less than) ???
};

#endif
