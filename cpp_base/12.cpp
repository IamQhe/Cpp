#include <iostream>
using namespace std;

/*
    代码区 全局区 栈区 堆区   
*/


// 1. 代码区
//  存放代码，分为 只读 和 共享


//  2. 全局区
//   存放内容：全局常量、全局变量、静态变量、字符串常量
int g_a = 1;
int g_b = 2;

const int c_g_a = 3;
const int c_g_b = 4;

// 3. 栈区 堆区
// 栈区和堆区都是程序运行过程中申请和释放的
// 区别在于，栈区由操作系统控制生命周期，堆区内存由程序员控制生命周期

// 栈区： 形参、局部变量
char* func() {
  // "我是 iamQhe" 是一个常量，存储在全局区
  // 而 c 为局部变量，存储在栈上，函数执行完毕后，内存会被释放
  char c[20] = "我是 IamQhe";
  return c;
}

// 堆区： 
// C语言： 申请 malloc 释放 free （malloc 和 free 是函数）
// C++：   申请 new 释放 delete   (new 和 delete 是运算符)
int * getValue(int value) {
    int* a = new int(value);    // int *a 是栈上的变量
    cout << a << endl;          // *a 也就是 a 的解引用后得到的值，存储在堆上
    return a;                   // 函数返回时，虽然栈上的变量 a 被操作系统释放了，但 a 指向的内存依然存在 
}

int main() {
    int c = 3;
    int d = 4;
    static int e = 5;
    static int f = 6;
    const int g = 7;
    const int h = 8;

    cout << "全局变量 g_a 地址: " << &g_a << endl;
    cout << "全局变量 g_b 地址: " << &g_b << endl;
    cout << "局部变量 c 地址: " << &c << endl;
    cout << "局部变量 d 地址: " << &d << endl;
    cout << "静态变量 e 地址: " << &e << endl;
    cout << "静态变量 f 地址: " << &f << endl;
    cout << "字符串常量地址: " << &"我是一个字符串" << endl;
    cout << "局部常量 g 地址: " << &g << endl;
    cout << "局部常量 h 地址: " << &h << endl;
    cout << "全局常量 c_g_a 地址: " << &c_g_a << endl;
    cout << "全局常量 c_g_b 地址: " << &c_g_b << endl;

    // error: 返回结果为 野指针
    // cout << func() << endl;

    // 返回结果为 a 对应地址的值
    int* p = getValue(1234);
    cout << p << endl;
    cout << *p << endl;

    // 5.1 内存申请释放
    // 申请 new
    int* ptr = new int;
    *ptr = 1234;
    cout << "*ptr: " << *ptr << endl;

     // 释放
     delete ptr;
     ptr = NULL;

     // 5.2 数组申请释放
     int* arr_p = new int[]{1, 5, 6, 4, 4, 3, 3, 2, 1, 9};
     delete[] arr_p;    // 若为 delete arr_p ，则只会删除首地址
     arr_p = NULL;
     return 0;
}