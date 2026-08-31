#include <iostream>
using namespace std;

/*
    5.2 加号运算符重载  
        运算符: + 
*/

// 复数类
class Complex {
    friend Complex operator+(Complex& a, Complex& b);
    friend Complex operator-(Complex& a, Complex& b);

    public:
        Complex(): real(0), image(0) {}

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

        // 方式一：成员函数重载运算符
        // Complex operator+(Complex& other) {
        //   Complex res;
        //   res.real = this->real + other.real;
        //   res.image = this->image + other.image;
        //   return res;
        // }

        void print() {
            cout << this->real << " + " << this->image << "i" << endl;
        }
    private:
        int real;
        int image;
};

// 方式二：全局函数重载运算符
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

int main() {
    Complex a(10, 20);
    Complex b(5, -4);
    // Complex c = a.add(b);
    Complex c = a + b;
    Complex d = a - b;
    c.print();
    d.print();

    return 0;
}