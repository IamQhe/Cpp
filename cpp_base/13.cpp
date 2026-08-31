#include <iostream>
using namespace std;

/*
    引用：作用和指针一样，但更易于理解
    给变量取别名
    &
    数据类型& 变量名 = 变量;
*/

void countAndSum1(int* arr, int len, int* num, int* sum) {
    *sum = 0;
    for(int i = 0; i < len; i++) {
        if(arr[i] == 2) {
            *sum += 2;
            (*num)++;
        }
    }
}

void countAndSum2(int* arr, int len, int& num, int& sum) {
    num = 0;
    sum = 0;
    for(int i = 0; i < len; i++) {
        if (arr[i] == 2) {
            num ++;
            sum += 2;
        }
    }
}

int& getArrayValue(int arr[], int index) {
    return arr[index];
}

int main() {
    // 1. 引用的语法
    int a = 1314;
    int& b = a;
    b = 520;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    // 2. 引用的特性：
    //      1. 必须初始化 
    //      2. 初始化后不可修改
    int a1 = 3, b1 = 6;
    int& c1= a1;
    c1 = b1;  // 实际为 c = 6;
    cout << a1 << ' ' << b1 << ' ' << c1 << endl;

    // 3.引用的本质： 指针常量
    int a2 = 520;

    // 3.1 引用实现
    int& b2 = a2;
    b2 = 1314;
    cout << "a2: " << a2 << endl;
    cout << "b2: " << b2 << endl;

    // 3.2 指针常量实现
    a2 = 520;
    int* const c2 = &a2;
    *c2 = 1314;
    cout << "a2: " << a2 << endl;
    cout << "*c2: " << *c2 << endl;

    // 4. 引用作为参数传参
    //  作用：函数传参不需要再拷贝一份， 更高效
    int num4 = 0;
    int sum4 = 0;
    int arr4[] = { 1, 2, 3, 2, 4, 5, 6, 4, 3, 2};
    countAndSum1(arr4, 10, &num4, &sum4);
    cout << "num: " << num4 << "; sum: " << sum4 << endl;

    num4 = 0;
    sum4 = 0;
    countAndSum2(arr4, 10, num4, sum4);
    cout << "num: " << num4 << "; sum: " << sum4 << endl;

    // 5. 引用作为函数返回值
    //      优点：返回值可以作为左值被赋值
    int arr5[] = {1, 2, 3, 4, 5};
    cout << getArrayValue(arr5, 3) << endl;
    getArrayValue(arr5, 3) = 999;
    cout << getArrayValue(arr5, 3) << endl;

    // 6. 常量引用
    //      引用 = 指针常量
    //      常量引用 = 常量指针常量
    //  作用：禁止函数内部修改引用值


    // 7. 指针引用
    //  *&
    return 0;
}