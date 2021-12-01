#ifndef FACULTY_H //header guard
#define FACULTY_H //header guard

using namespace std;

class Faculty : public Person{
public:
  Faculty();
  Faculty(string department)
  ~Faculty();


private:
  //think i need to add the other things back
  string m_department;
  int advisees[];

  //overloaded operators??
};
#endif
