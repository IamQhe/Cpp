#include <iostream>
using namespace std;

/*
    5.4 递增运算符重载
        运算符: ++
    
        ++ 分两类：
            - 前置 ++
            - 后置 ++
*/

// 复数类
class Complex {
 friend ostream& operator<<(ostream& cout, const Complex& c);

 public:
  Complex() : real(0), image(0) {}

  Complex(int real, int image) {
    this->real = real;
    this->image = image;
  }

  // 前置++
  //    返回值要是自身对象，且需要引用
  Complex& operator++() {
    this->real += 1;
    return *this;
  }

  // 后置++
  //    返回值是自身的拷贝
  Complex operator++(int) {
    Complex c = *this;
    this->real += 1;
    return c;
  }

  void print() { cout << this->real << " + " << this->image << "i" << endl; }

 private:
  int real;
  int image;
};

// void operator++(Complex& c) {
//     c.real += 1;
// }

ostream& operator<<(ostream& cout, const Complex& c) {
    cout << c.real << " + " << c.image << "i";
    return cout;
}

int main() {
    int a = 1;
    cout << ++(++a) << endl;
    cout << a << endl;

    Complex c(10, 20);
    cout << ++(++c) << endl;
    cout << c << endl;
    cout << c++ << endl;
    cout << c << endl;

    cout << ((c++)++)++ << endl;

    return 0;
}