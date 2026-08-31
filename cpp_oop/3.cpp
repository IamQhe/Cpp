#include <iostream>
#include <string>
using namespace std;

/*
    构造函数   
*/

class Person {
    public: 
        // 默认构造函数
        Person() {
            _name = "";
            _gender = 0;
            _age = 20;
        }

        // 有参构造函数
        Person(string name) {
            _name = name;
        }

        // 析构函数
        ~Person() {

        }

        // 拷贝构造函数
        Person(const Person& p) {
            _name = p._name;
            _gender = p._gender;
            _age = p._age;
        }

    private: 
        string _name;
        int _gender;
        int _age;
};

int main() {

    /*
        3. 拷贝构造函数
            时机：
                1. 用已创建对象来初始化对象
                2. 函数的传参
                3. 函数的返回值
    */

    return 0;
}