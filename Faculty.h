
using namespace std;

class Faculty{
public:
  Faculty();
  Faculty(int id, string name, string level, string department)
  ~Faculty();


private:
  int m_ID;
  string m_name;
  string m_level;
  string m_department;
  int advisees[];

  //overloaded operators??
};
