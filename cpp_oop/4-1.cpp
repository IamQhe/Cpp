#include <iostream>
using namespace std;

/*
    友元
    作用：让一个类 或者 函数能够访问另一个类的私有成员
    
    关键字： friend

    三种友元：
        - 全局函数作为友元
        - 类作为友元
        - 成员函数作为友元
*/

class People {
    friend void askForAge(People* p);

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

void askForGender(People* p) {
  cout << "有人问你的性别： " << p->m_gender << endl;
}

void askForAge(People* p) {
  cout << "有人问你的年龄： " << p->m_age << endl;
}

int main() {
    People p;
    askForGender(&p);
    askForAge(&p);

    return 0;
}