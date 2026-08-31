#include <iostream>
using namespace std;

/*
    6.4 同名属性的访问
*/

class Animal {
    public:
        Animal() {
            m_data = 1;
        }

        int m_data;
};

class Cat : public Animal {
    public:
        Cat() {
            m_data = 2;
        }

        int m_data;
};

void Test() {
    Cat c;
    cout << c.m_data << endl;
    cout << c.Animal::m_data << endl;
}

int main() {
    Test();

    return 0;
}