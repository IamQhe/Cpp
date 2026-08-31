#include <iostream>
#include <string>
using namespace std;

/*
    2.2 函数模板的调用

    方式：
        1. 自动类型推导
        2. 显式指定类型
*/

int addInt(int a, int b) {
    int c = a + b;
    return c;
}

double addDouble(double a, double b) {
    double c = a + b;
    return c;
}

// 自动类型推导
template<typename T>
T add(T a, T b) {
    T c = a + b;
    return c;
}

// 显式指定类型

int main() {
    int a = 1;
    int b = 2;
    int c = addInt(a, b);
    cout << c << endl;

    double aa = 1.0;
    double bb = 2.1;
    double cc = addDouble(aa, bb);
    cout << cc << endl;

    // 自动类型推导
    cout << add(a, b) << endl;
    cout << add(aa, bb) << endl;

    string e = "e";
    string f = "f";
    cout << add(e, f) << endl;


    // 显式指定类型
    c = add<int>(a, b);
    cout << c << endl;
    cc = add<double>(aa, bb);
    cout << cc << endl;
    cout << add<char>('a', 'b') << endl;
    return 0;
}