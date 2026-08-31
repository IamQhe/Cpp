#include <iostream>
#include <cstring>
using namespace std;

/*
    11 联合体 union   
*/

// 结构体
struct DataS {
    int i;
    double d;
    char s[10];
};

// 联合体
// 成员变量共享起始地址，内存大小以最大成员所占空间
// char s[10] 占 10 字节最大，但由于内存对齐，故 DataU 占 16 字节（char s[10] 非 4 的倍数，补 6 个填充）
//      对齐场景
//          1. 结构体中前一字段不满足后一个字段的对齐要求
//          2. 结构体加上最后字段不满 4 的倍数
union DataU {
  int i;        // 4 bytes
  double d;     // 8 bytes
  char s[10];   // 10 bytes
};

// 11.1 定义和使用
//  1. 先定义后使用
// union DataU {
//   int i;       // 4 bytes
//   double d;    // 8 bytes
//   char s[10];  // 10 bytes
// };
// DataU a, b, c;

// 2. 定义并使用
// union DataU {
//   int i;       // 4 bytes
//   double d;    // 8 bytes
//   char s[10];  // 10 bytes
// }a , b, c;

// 3. 匿名（别人无法使用）
// union {
//   int i;       // 4 bytes
//   double d;    // 8 bytes
//   char s[10];  // 10 bytes
// }a, b, c;

struct Person{
    char _name[20];
    int _role;
    union {
        double score;
        char course[20];
    }_sc;

    Person(const char name[20], int role, double score, const char course[20]) {
      strcpy_s(_name, name);
      _role = role;
      if (score > 0) {
        _sc.score = score;
      }
      if (strlen(course) > 0) {
        strcpy_s(_sc.course, course);
      }
    }
};

int main() {
    // 11.1 结构体和联合体区别
    //  结构体各个成员变量独占内存，起始内存地址不一样
    //  联合体各个成员变量共享内存，起始内存地址相同
    DataS ds;
    cout << &ds.i << ' ' << &ds.d << ' ' << (void *)&ds.s << endl;  // 0xce47dffe30 0xce47dffe38 0xce47dffe40

    DataU du;
    cout << &du.i << ' ' << &du.d << ' ' << (void *)&du.s << endl;  // 0xce47dffe20 0xce47dffe20 0xce47dffe20


    // 11.3 union 应用
    //  当某个字段需要因为一些条件而不同，又不想浪费内存
    Person p[4] = {
        {"王老师", 0, -1, "C++"},
        {"刘老师", 0, -1, "Python"},
        {"孙同学", 1, 99, ""},
        {"里同学", 1, 100, ""}
    };
    for(int i = 0; i < 4; i++) {
        if(p[i]._role == 0) {
            cout << p[i]._name << "教 " << p[i]._sc.course << endl;
        } else if(p[i]._role == 1) {
            cout << p[i]._name << "考了 " << p[i]._sc.score << endl;
        }
    }
    return 0;
}