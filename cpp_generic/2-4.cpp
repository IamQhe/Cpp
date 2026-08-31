#include <iostream>
using namespace std;

/*
    2.4 普通函数和函数模板的调用规则
    
    2.4.1 优先使用普通函数

    2.4.2 强制调用函数模板

    2.4.3 函数模板的优先匹配 （不显式指定类型）
*/

int add(int a, int b) {
    cout << "调用普通函数..." << endl;
    int c = a + b;
    return c;
}

template<typename T>
T add(T a, T b) {
    cout << "调用函数模板..." << endl;
    T c = a + b;
    return c;
}

int main() {
    int a = 1;
    int b = 2;
    // 2.4.1 优先使用普通函数
    add(a, b);

    // 2.4.2 强制调用函数模板
    add<int>(a, b);
    add<>(a, b);

    // 2.4.3 函数模板的优先匹配 （不显式指定类型）
    //  1. 编译器优先寻找参数列表完全匹配的普通函数
    //  2. 编译器对函数模板实例化，生成合适的函数版本
    double aa = 1, bb = 2;
    add(aa, bb);    
    return 0;
}