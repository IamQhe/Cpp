#include <iostream>
using namespace std;

/*
    指针   
*/

string getHex(size_t x) {
  char buff[10];
  sprintf_s(buff, "%X", (x & 0xFFFF));
  return (string)buff;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* getArray(int a, int d, int n) {
    int* ret = new int[n];

    for(int i = 0; i < n; i++) {
        ret[i] = a + i * d;
    }
    return ret;
}

// 函数指针
double (*ptr)(int a, int b, int c);

double func(int a, int b, int c) {
    cout << a << ' ' << b << ' ' << c << endl;
    return 0.0;
}

void (*ptr1)(int a, int b);

void func1(int a, int b) {
    cout << a << ' ' << b << endl;
}

// 函数指针的类型定义
typedef void (*fptr) (int a, int b, int c);

void fp1(int a, int b, int c) {
    cout << a << ' ' << b << ' ' << c << endl;
}

// 函数指针数组
// [函数指针1, 函数指针2, ...]
typedef void (*fptrArr[])(int a, int b, int c);

void fp2(int a, int b, int c) {
  cout << a << ' ' << b << ' ' << c << endl;
}
void fp3(int a, int b, int c) {
  cout << a << ' ' << b << ' ' << c << endl;
}
void fp4(int a, int b, int c) {
  cout << a << ' ' << b << ' ' << c << endl;
}

int main() {
    int a = 10;
    int b = 20;

    // 1.1 地址
    printf("a的地址: %#X\n", &a);
    printf("b的地址: %#X\n", &b);

    // 1.2. 指针变量
    int* pa = &a;
    printf("pa的值: %#X\n", pa);
    pa = &b;
    printf("pa的值: %#X\n", pa);
    pa = &a;

    // 1.3. 解引用
    //  用法： *指针变量名 = 数值;
    int* pb = &b;
    *pb = 5;
    cout << b << ' ' << (*pb) << endl;

    // 1.4. * 和 & 互逆(右结合)
    // *&a == *(&a) == *pa == a == 10
    cout << "a: " << a << "; *&a: " << *&a << endl;
    // &*pa == &a == pa
    cout << "pa: " << pa << "; &*pa: " << &*pa << endl;

    cout << "--------------------------------------" << endl;

    // 2 指针的内存空间
    // sizeof
    // 指针内存空间大小只和操作系统有关，下面指针大小均相同（64位操作系统）。
    cout << "sizeof(int*): " << sizeof(int*) << endl;
    cout << "sizeof(short*): " << sizeof(short*) << endl;
    cout << "sizeof(char*): " << sizeof(char*) << endl;
    cout << "sizeof(long*): " << sizeof(long*) << endl;
    cout << "sizeof(long long*): " << sizeof(long long*) << endl;
    cout << "sizeof(float*): " << sizeof(float*) << endl;
    cout << "sizeof(double*): " << sizeof(double*) << endl;

    cout << "--------------------------------------" << endl;

    // 3 空指针和野指针
    // 3.1 空指针
    // 程序异常退出，代码并非 0
    int *p = NULL;
    // cout << "空指针 *p: " << *p << endl;

    // 3.2 野指针
    p = (int*)0x121412;
    // error: cout << "野指针 *p: " << *p << endl;

    cout << "--------------------------------------" << endl;

    // 4 const 和 指针的关系
    int c = 1;
    int d = 2;
    cout << "c: " << c << "; d: " << d << endl;

    // 4.1 指针常量：
    //  指针的值是一个常量，即指针指向的地址不能改变
    int* const p41 = &c;
    // error: p41 = &b; 试图修改 指针常量 p 指向的地址；
    *p41 = 3; // 可以修改指向地址的值，即解引用的值。
    cout << "c: " << c << "; d: " << d << endl;

    // 4.2 常量指针
    //  指向常量的指针
    const int* p42 = &c;
    cout << "*p42: " << *p42 << endl;
    // error: *p42 = 8; 不可修改解引用的值
    p42 = &d;
    cout << "*p42: " << *p42 << endl;   // 可以修改指向地址

    // 4.3 常量指针常量
    const int* const p43 = &b; // 初始化
    // error: *p43 = 6;  不可修改解引用的值
    // error: p43 = &d;  不可修改地址

    cout << "--------------------------------------" << endl;

    // 5 指针和数组
    int arr1[5] = {5, 4, 3, 2, 1};
    cout << "arr1[0]: " << arr1[0] << endl;
    int* p5 = arr1;

    cout << "arr1: " << arr1 << endl;
    cout << "p5: " << p5 << endl; 
    cout << "*p5: " << *p5 << endl;

    cout << "&arr[3]: " << &arr1[3] << endl;
    cout << "p5 + 3: " << p5 + 3 << endl;
    cout << "arr1[3]: " << arr1[3] << endl;
    cout << "*(p5 + 3): " << *(p5 + 3) << endl;

    // 6 指针数组
    char c6_1[] = "I";
    char c6_2[] = "am";
    char c6_3[] = "Qhe";

    char *p6[3];
    p6[0] = c6_1;
    p6[1] = c6_2;
    p6[2] = c6_3;

    for(int i = 0; i < 3; i++) {
        cout << p6[i] << ' ';
    }
    cout << endl;
    

    int mat[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int* p6_2[3];
    p6_2[0] = mat[0];
    p6_2[1] = mat[1];
    p6_2[2] = mat[2];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
          cout << *(p6_2[i] + j) << ' ';
        }
        cout << endl;
    }

    cout << mat[0] << endl;

    // 数组指针
    int (*p6_3)[5];
    int mat_2[4][5] = {
        {1, 2, 3, 4, 5},
        {2, 3, 4, 5, 6},
        {3, 4, 5, 6, 7},
        {4, 5, 6, 7 ,8}
    };

    // c0 - d4 之间为 20 字节，即 4 * 5。指针 +1 的跨度为 20
    cout << "p6_3: " << p6_3 << endl;           // c0
    cout << "p6_3 + 1: " << p6_3 + 1 << endl;   // d4

    // 指针数组和数组指针
    int mat_3[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int *p_temp = &mat_3[i][j];
            cout << getHex((size_t)p_temp) << "   ";
        }
        cout << endl;
    }

    // 指针数组
    int *p6_4[3] = { mat_3[0], mat_3[1], mat_3[2]}; // { &mat_3[0][0], &mat_3[1][0], &mat_3[2][0]}
    // 数组指针
    int (*p6_5)[4] = &mat_3[0];
    // 注意： a[0] 隐式转换后是 int*，指向第一个元素的指针；
    // 而 &a[0] 隐式转换后类型为 int(*)[4]。二者数值相同，但类型不同

    // 1. p6_4 + i 和 p6_5 + i
    // 指针数组： 第 i 个指针数组元素的地址
    for(int i = 0; i < 3; i++) {
      cout << getHex((size_t)(p6_4 + i)) << ' ';
    }
    cout << endl;

    // 数组指针： 第 i 个[4]数组的首地址
    for (int i = 0; i < 3; i++) {
      cout << getHex((size_t)(p6_5 + i)) << ' ';
    }
    cout << endl;

    // 2. *(p6_4 + i) 和 *(p6_5 + i)
    // 指针数组： mat_3 数组的第 i 行数组第 0 个元素的地址
    //           *(p6_4 + i) 为 p6_4 第 i 个元素的值，即 mat_3[i]
    for (int i = 0; i < 3; i++) {
      cout << getHex((size_t)(*(p6_4 + i))) << ' ';
    }
    cout << endl;

    // 数组指针： mat_3 数组的第 i 行数组第 0 个元素的地址 （int(*)[] 转 int *）
    //           *(p6_5 + i) 为 int[4] 类型，退化为 int*
    for (int i = 0; i < 3; i++) {
      cout << getHex((size_t)(*(p6_5 + i))) << ' ';
    }
    cout << endl;

    // 3. *(p6_4 + i) 和 *(p6_5 + i)
    // 指针数组： mat_3 数组的第 i 行数组第 2 个元素的地址
    for (int i = 0; i < 3; i++) {
      cout << getHex((size_t)(*(p6_4 + i) + 2)) << ' ';
    }
    cout << endl;

    // 数组指针： mat_3 数组的第 i 行数组第 3 个元素的地址
    for (int i = 0; i < 3; i++) {
      cout << getHex((size_t)(*(p6_5 + i)) + 3) << ' ';
    }
    cout << endl;

    // 9.7 指针传参 指针函数 函数指针
    // 9.7.1 指针传参
    int a_7 = 3;
    int b_7 = 4;
    cout << "a_7: " << a_7 << endl;
    cout << "b_7: " << b_7 << endl;
    swap(&a_7, &b_7);
    cout << "a_7: " << a_7 << endl;
    cout << "b_7: " << b_7 << endl;

    // 9.7.2 指针函数
    int *p7 = getArray(5, 3, 6);
    for(int i = 0; i < 6; i++) {
      cout << *(p7 + i) << ' ';
    }
    cout << endl;
    
    // 9.7.3 函数指针
    ptr = func;
    ptr(1, 2, 3);

    ptr1 = func1;
    ptr1(1, 2);

    // 9.7.4 函数指针类型定义
    fptr f1 = fp1;
    fptr f2 = fp1;
    f1(1, 2, 3);
    f2(3, 4, 5);

    // 9.7.5 函数指针数组
    // [函数指针1, 函数指针2, ...]
    fptrArr fps = {fp1, fp2, fp3, fp4};
    for(int i = 0; i < 4; i++) {
        cout << (void*)fps[i] << endl; 
    }
    return 0;
}