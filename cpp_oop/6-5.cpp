#include <iostream>
using namespace std;

/*
    6.5 同名函数访问
*/

class Animal {
    public:
        void eat() {
            cout << "动物吃" << endl;
        }
};

class Cat : public Animal {
    public:
        void eat() {
            Animal::eat();
            cout << "猫吃" << endl;
        }
};

int main() {
    Cat c;
    c.eat();
    return 0;
}