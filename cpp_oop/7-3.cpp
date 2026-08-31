#include <iostream>
using namespace std;

/*
    7.3 纯虚函数 和 抽象类
        有纯虚函数的类为抽象类，抽象类无法实例化对象
        抽象类为继承而生
*/

class Animal {
    public:
        virtual void eat() = 0; // 不实现 
};

class Cat : public Animal {
    public:
        // 若 Cat 不重写该方法，那 Cat 也将是抽象类，无法实例化
        void eat() {
            cout << "猫吃东西" << endl;
        }
};



int main() {
    //  Animal a;   error -> object of abstract class type "Animal" is not allowed
    //  有纯虚函数的类为抽象类，抽象类无法实例化对象
    Cat c;
    c.eat();
    return 0;
}