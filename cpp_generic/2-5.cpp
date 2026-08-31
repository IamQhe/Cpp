#include <iostream>
using namespace std;

/*
    2.5 多参数函数模板

    规则：
        1. 函数模板支持多参数
        2. 一旦有类型不能推导，编译器会报错
        3. 返回值类型无法作为推导依据
*/

// template<typename T1, typename T2, typename T3>
// T1 add(T2 t2, T3 t3) {
//     T1 t1 = t2 + t3;
//     return t1;
// }

template<typename T2, typename T3>
T2 add(T2 t2, T3 t3) {
    cout << typeid(T2).name() << endl;
    cout << typeid(T3).name() << endl;
    T2 t1 = t2 + t3;
    return t1;
}

int main() {
    int a = 1;
    double b = 1.1;
    // 返回值类型无法作为类型依据
    // double c = add(a, b); error -> no instance of function template "add" matches the argument list

    add(a, b);
    add(0.4f, 99999999999);
    return 0;
}