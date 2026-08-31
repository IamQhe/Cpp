#include <iostream>
using namespace std;

/*
    结构体   
*/

typedef struct Book{
    string name;
    double price;
    int value;
};

// 嵌套结构体
struct Point {
    double x;
    double y;
};

struct Circle {
    Point center;
    double radius;
};

struct Circles {
    int size;
    Circle c[10];
};

// 结构体传参
void printCircle(Circle c) {
    cout << "(" << c.center.x << "," << c.center.y << ") " << c.radius << endl;
}

/**
 * 打印圆
 *  与上述区别：不用再拷贝一份结构体，而是直接根据地址输出
 */
void printCircle(const Circle *c) {
  cout << "(" << c->center.x << "," << c->center.y << ") " << c->radius << endl;
}

void moveCircle(Circle* c, int x, int y) {
    c->center.x += x;
    c->center.y += y;
}

int main() {
    // 10.1 创建结构体
    // 10.1.1 方法 1
    Book dog_money;
    dog_money.name = "小狗钱钱";
    dog_money.price = 10.00;
    dog_money.value = 10;
    cout << dog_money.name << ' ' << dog_money.price << ' ' << dog_money.value << endl;

    // 10.1.2 方法 2
    Book wanli_15 = {"万历十五年", 99.00, 20};
    cout << wanli_15.name << ' ' << wanli_15.price << ' ' << wanli_15.value << endl;

    // 10.2 结构体数组
    Book books[3] ={ 
        {"万历十五年", 99.00, 20},
        {"小狗钱钱", 19.99, 10},
        {"神秘复苏", 20.00, 30} 
    };
    for(int i = 0; i < 3; i++) {
      cout << books[i].name << ' ' << books[i].price << books[i].value << endl;
    }

    books[2].name = "超神机械师";
    cout << books[2].name << endl;

    // 10.3 结构体指针
    Book copy;
    copy = books[0];
    cout << "copy: " << copy.name << ' ' << copy.price << ' ' << copy.value << endl;
    copy.name = "白夜行";
    cout << "copy_name: " << copy.name << "; books[0]_name: " << books[0].name << endl;

    Book* sp = &books[0];
    cout << "sp_name: " << sp -> name << "; books[0]_name: " << books[0].name << endl;
    sp -> name = "白夜行";
    cout << "sp_name: " << sp -> name << "; books[0]_name: " << books[0].name << endl;

    // 10.4 嵌套结构体
    Circle c;
    c.center.x = 0;
    c.center.y = 1;
    c.radius = 10;

    Circles cs;
    cs = {2, {{{0, 1}, 3}, {{1, 0}, 5}}

    };
    for (int i = 0; i < cs.size; i++) {
        Circle tmp = cs.c[i];
        cout << tmp.center.x << ' ' << tmp.center.y << ' ' << tmp.radius << endl;
    }

    // 10.5 结构体传参
    Circle c5 = {{0, 0}, 5};

    printCircle(&c5);
    moveCircle(&c5, -1, 1);
    printCircle(&c5);

    return 0;
}