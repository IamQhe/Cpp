#include <iostream>
using namespace std;

/*
    5.6 关系运算符重载
        运算符： ==、 >、 <、 !=、 >=、 <=

*/

class Point {
    friend bool operator==(const Point& a, const Point& b);
    friend bool operator<(const Point& a, const Point& b);
    friend bool operator>(const Point& a, const Point& b);
    public:
        Point(int x, int y):m_x(x), m_y(y){}

    private:
        int m_x;
        int m_y;
};

bool operator==(const Point& a, const Point& b) {
    return (a.m_x == b.m_x) && (a.m_y == b.m_y);
}

bool operator<(const Point& a, const Point& b) {
    int da = a.m_x * a.m_x + a.m_y * a.m_y;
    int db = b.m_x * b.m_x + b.m_y * b.m_y;
    return da < db;
}

bool operator>(const Point& a, const Point& b) {
    if (a == b || a < b) return false;
    return true;
}

int main() {
    Point p1(1, 2);
    Point p2(1, 2);
    // 若不重载关系运算符： error -> no operator "==" matches these operands
    cout << (p1 == p2) << endl;

    return 0;
}