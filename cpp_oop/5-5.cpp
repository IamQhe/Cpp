#include <iostream>
using namespace std;

/*
    5.5 赋值运算符重载
        运算符： =
*/

class People {
    public:
        int* m_num;

        People() {
            m_num = NULL;
        }

        People(int num){
            m_num = new int;
            *m_num = num;
        }

        People& operator=(People& p) {
            if (m_num) {
                delete m_num;
                m_num = NULL;
            }
            m_num = new int;
            *m_num = *p.m_num;
            return *this;
        }

        // 1. 解决内存泄漏
        //  若对象间进行赋值运算，成员变量内存空间依然存在，会导致内存泄漏
        ~People(){
            if (m_num) {
              delete m_num;
              m_num = NULL;
            }
        }
};

int main() {
    People p1(1);
    People p2(2);
    // 2. 解决 double free(delete)
    //  默认 = 运算符会导致 double free 问题
    //  原因 p2 将自己 m_num 地址赋给 p1, 当进程结束时，两者都会执行析构函数，对自身成员变量进行 delete
    //  但是由于地址相同，后面销毁的对象会对已删除地址再次 delete
    //  解决： 对于类进行 = 运算符重载
    cout << p1.m_num << endl;
    cout << p2.m_num << endl;

    p1 = p2;
    cout << p1.m_num << endl;
    cout << p2.m_num << endl;

    // People p3(3);
    // p1 = p2 = p3;
    // cout << p1.m_num << endl;
    // cout << p2.m_num << endl;
    // cout << p3.m_num << endl;
    return 0;
}