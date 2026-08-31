#include <iostream>
using namespace std;

/*
    7.1 多态

    - 静态多态：
        函数重载、运算符重载
    
    - 动态多态：
        利用派生类和虚函数，实现运行时多态
*/

class Animal {
    public:
        virtual void eat() {
            cout << "动物吃东西" << endl;
        }
};

class Cat : public Animal {
    public:
        void eat() {
            cout << "猫吃东西" << endl;
        }
};

class Pig : public Animal {
    public:
        void eat() {
            cout << "猪吃东西" << endl;
        }
};

// 调用链: main -> test -> eat -> Animal::eat
// 多态：函数传父类对象参数，实际传入不同子类会产生不同行为
void eat(Animal& a) {
    a.eat();
}

void Test() {
    Cat c;
    Pig p;
    eat(c);
    eat(p);
}

int main() {
    Test();
    return 0;
}