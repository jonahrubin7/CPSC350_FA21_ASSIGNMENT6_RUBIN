#ifndef PERSON_H //header guard
#define PERSON_H //header guard

using namespace std;

//abstract person class
class Person{
public:
  Person();
  Person(int id, string name);
  ~Person();
  //getters and setters
  int getID();


private:
  //maybe need to make these public? not sure yet
  int m_ID;
  string m_name;
  string m_level;


  //compare (greater than or less than) ???
};

#endif
