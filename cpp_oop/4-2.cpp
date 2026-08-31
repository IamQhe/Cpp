#include <iostream>
using namespace std;

/*
    类作为友元
*/

class People {

  friend class PeopleFriend;

 public:
  People() {
    m_gender = 1;
    m_age = 20;
  }

 public:
  int m_gender;

 private:
  int m_age;
};

class PeopleFriend {
    public:
        void askForGender(People* p) {
            cout << "有朋友询问性别：" << p->m_gender << endl;
        }

        void askForAge(People* p) {
          cout << "有朋友询问年龄：" << p->m_age << endl;
        }
};

int main() {
  People p;

  return 0;
}