#include <iostream>
using namespace std;

/*
    5.7 函数调用运算符重载
        运算符: ()   

        仿函数：形似函数调用，实际是一个对象
        区别:
            普通函数不存储信息状态，只要参数一致，结果不变
            仿函数是一个对象，可以存储一些信息，能在参数外额外有数据。
*/

class AddFunc {
    public:
        AddFunc(){
            m_count = 0;
        }

        int operator() (int a, int b) {
            return a + b + m_count++;
        }
    
    private:
        int m_count;
};

int add(int a, int b) {
    return a + b;
}

int main() {
    int a = 1;
    int b = 2;
    AddFunc Add;
    cout << Add(a, b) << endl;  // 仿函数，输出: 3
    cout << add(a, b) << endl;  // 普通函数，输出: 3

    cout << Add(a, b) << endl;  // 仿函数，输出: 4
    cout << add(a, b) << endl;  // 普通函数，输出: 3

    cout << Add(a, b) << endl;  // 仿函数，输出: 5
    cout << add(a, b) << endl;  // 普通函数，输出: 3
    return 0;
}