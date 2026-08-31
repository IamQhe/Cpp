#include <iostream>
using namespace std;

/*
    2 函数模板

    template<typename T>
    函数的定义
*/

// int addInt(int a, int b) {
//     int c = a + b;
//     return c;
// }

// double addDouble(double a, double b) {
//     int c = a + b;
//     return c;
// }

template<typename T>
T addT(T a, T b) {
    T c = a + b;
    return c;
}

int main() {


    return 0;
}