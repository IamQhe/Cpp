#include <iostream>
#include <string>
using namespace std;

/*
    常函数： const 修饰成员函数
        函数体中不能修改成员属性的值
*/

class People {
    public:
        People(): name("") {}

        // 常函数
        string getName() const {
            return name;
        }

        void setName(string name) {
            this->name = name;
        }

    private:
        string name;
};


int main() {
    const People p;
    string name = p.getName();
    // error: p.setName("qwe");     常量对象只能调用常函数

    return 0;
}