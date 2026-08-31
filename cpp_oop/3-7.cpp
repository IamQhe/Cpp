#include <iostream>
#include <string>
using namespace std;

/*
     this 指针
        1. 解决构造函数命名冲突
        2. *this 获取对象   
*/

class People {
    public:
        People() {
        }

        // 作用域： 在函数的作用域中，若命名相同，形参会覆盖成员变量
        People(string name, int gender, int age) {
            this->name = name;
            this->gender = gender;
            this->age = age;
            cout << (*this).name << endl;
        }

    private:
        string name;
        int gender;
        int age;
};

int main() {


    return 0;
}