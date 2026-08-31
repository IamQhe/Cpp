#include <iostream>
using namespace std;

/*
    3.5 对象的函数传参
*/

template<typename NameType, typename HpType>
class People {
    public:
        NameType m_name;
        HpType m_hp;

        People(NameType name, HpType hp) {
            m_name = name;
            m_hp = hp;
        }
};

// 1. 直接指定类型
void test1(People<string, double>& p) {
}

// 2. 参数模板化
template<typename T1, typename T2>
void test2(People<T1, T2>& p) {
}

// 3. 类模板化
template<typename T>
void test3(T& p) {
}

int main() {
    People<string, double> p1("宋江", 100.0);
    test1(p1);

    test2(p1);

    test3(p1);
    return 0;
}