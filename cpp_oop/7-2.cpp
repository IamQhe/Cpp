#include <iostream>
using namespace std;

/*
    7.2 虚函数
*/

class Animal {
    public:
        // 加上 virtual 后 Animal 的 size 由 1 -> 8， 变化原因是出现了虚函数指针 __vfptr， 该指针指向一个虚函数表
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

void eat(Animal& a) {
    // 此处将 Cat 类的 c 隐式转换为 Animal 类， 会将 Animal 类的虚函数指针指向 Cat 对应的方法
    //  子类函数覆盖父类虚函数
    a.eat();

    // 原生生成的 Animal 对象的虚函数指针仍指向 Animal 函数
    Animal animal; 
}

void Test() {
    Cat c;
    eat(c);
    cout << "Animal's size: " << sizeof(Animal) << endl;    // Animal 无任何成员变量，但有占位占用一定内存空间(函数存放在别处)
}

int main() {
    Test();

    return 0;
}