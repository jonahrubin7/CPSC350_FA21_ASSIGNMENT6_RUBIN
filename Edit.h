#ifndef EDIT_H //header guard
#define EDIT_H //header guard

namespace std;

class Edit{

public:
  Edit();
  ~Edit();
  //all of these made void rn, will not neccesarily stay void (??)
  void changeAdvisor(int studentID, int newAdvisor);
  void removeAdvisee(int advisor, int advisee);

};

#endif
