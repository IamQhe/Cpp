#include <iostream>
using namespace std;

/*
    3. 函数模板

    3.1 普通函数的隐式转换

    3.2 函数模板自动类型推导无隐式类型转换
*/

int addInt(int a, int b) {
    int c = a + b;
    return c;
}

double addDouble(double a, double b) {
    double c = a + b;
    return c;
}

template<typename T>
T add(T a, T b) {
    T c = a + b;
    return c;
}

int main() {
    // 1. 普通函数的隐式类型转换
    int a = 1;
    double b = 2;
    double c = addDouble(a, b);
    int d = addDouble(a, b);
    cout << c << endl;
    cout << d << endl;

    // 2. 函数模板自动类型推导无隐式类型转换
    //  c = add(a, b);  error -> no instance of function template "add" matches the argument list

    // 3. 函数模板显式指定类型有隐式类型转换
    c = add<double>(a, b);
    cout << c << endl;
    c = add<int>(a, b);
    cout << c << endl;
    return 0;
}