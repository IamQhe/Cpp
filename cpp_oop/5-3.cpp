#include <iostream>
using namespace std;

/*
    5.3 左移运算符重载
      运算符： <<
    
    cout.operator<<(obj)

    成员函数:
        调用形式 c.operator<<(cout)
                c << cout

    全局函数：
        调用形式 cout << c;
*/

// 复数类
class Complex {
  friend Complex operator+(Complex& a, Complex& b);
  friend Complex operator-(Complex& a, Complex& b);
  friend ostream& operator<<(ostream& cout, Complex c);

 public:
  Complex() : real(0), image(0) {}

  Complex(int real, int image) {
    this->real = real;
    this->image = image;
  }

  Complex add(Complex& other) {
    Complex res;
    res.real = this->real + other.real;
    res.image = this->image + other.image;
    return res;
  }

  void print() { cout << this->real << " + " << this->image << "i" << endl; }

 private:
  int real;
  int image;
};

Complex operator+(Complex& a, Complex& b) {
  Complex res;
  res.real = a.real + b.real;
  res.image = a.image + b.image;
  return res;
}

Complex operator-(Complex& a, Complex& b) {
  Complex res;
  res.real = a.real - b.real;
  res.image = a.image - b.image;
  return res;
}

// 重载左移运算符
//      cout 要用引用形式，因为全局只有一个 cout 。
//      内部实现对于拷贝构造函数为 delete，即不能调用拷贝构造函数。不加引用会进行拷贝，从而 delete。
ostream& operator<<(ostream& cout, Complex c) {
  cout << c.real << " + " << c.image << "i";
  return cout;  // 返回 ostream& cout 是为了能够链式输出 cout << a << b << endl;
}

int main() {
  Complex a(10, 20);
  Complex b(5, -4);
  // Complex c = a.add(b);
  Complex c = a + b;
  Complex d = a - b;
  c.print();
  d.print();
  cout << d << endl;

  return 0;
}