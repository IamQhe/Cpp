#include <iostream>
using namespace std;

/*
    6.6 多继承
*/

class BaseA {
    public:
        BaseA(): m_A(1), m_base(520) {}

        int m_A;
        int m_base;
};

class BaseB {
    public:
        BaseB(): m_B(2), m_base(1314) {}

        int m_B;
        int m_base;
};

class BaseC {
    public:
        BaseC(): m_C(2) {}

        int m_C;
};

class Son : public BaseA, public BaseB, public BaseC {

};

int main() {
    Son s;
    s.m_A = 11;
    s.m_B = 22;
    s.m_C = 33;
    //  s.m_base = 5;   error -> "Son::m_base" is ambiguous 有歧义
    cout << s.BaseA::m_base << endl;
    cout << s.BaseB::m_base << endl;
    cout << sizeof(s);

    return 0;
}