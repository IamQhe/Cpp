#include <iostream>
using namespace std;

/*
    成员函数作为友元： 一个类的某个函数能访问另一个类的私有变量
*/
class People;

class PeopleFriend {
 public:
    void askForGender(People* p);

    void askForAge(People* p);
};

class People {
    friend void PeopleFriend::askForAge(People* p);

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

void PeopleFriend::askForGender(People* p) {
    cout << "朋友问你的性别： " << p->m_gender << endl;
}

void PeopleFriend::askForAge(People* p) {
  cout << "朋友问你的年龄： " << p->m_age << endl;
}

int main() {
  People p;
  PeopleFriend pf;
  pf.askForGender(&p);
  pf.askForAge(&p);

  return 0;
}