#include <iostream>
using namespace std;

/*
    6. 继承
        抽离共性为基类，子类继承为派生类

        class 子类名 : 继承方式 父类名
*/

class Animal {
    public:
        void eat() {
            cout << "握持" << endl;
        }
};

class Cat : public Animal {
    public:
        void say() {
            cout << "大狗大狗" << endl;
        }
};

class Dog : public Animal {
    public:
        void say() {
            cout << "叫叫叫" << endl;
        }
};

int main() {
    Cat cat;
    Dog dog;
    cat.eat();
    cat.eat();

    cat.say();
    dog.say();

    return 0;
}