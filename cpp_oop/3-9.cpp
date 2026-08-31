#include <iostream>
using namespace std;

/*
    mutable 关键字 （可变的）
        在常函数中修改成员变量的值   
*/

class Person {
    public:
     Person() : m_age(0), m_getAgeCounter(0) {}

     Person(int age) { m_age = age; }

     int getAge() const {
       m_getAgeCounter++;
       return m_age;
     }

        void printCounter() const {
          cout << "m_getAgeCounter: " << m_getAgeCounter << endl;
        }

    private:
        int m_age;
        mutable int m_getAgeCounter;
};


int main() {
    Person p;
    p.printCounter();
    p.getAge();
    p.getAge();
    p.getAge();
    p.printCounter();

    return 0;
}