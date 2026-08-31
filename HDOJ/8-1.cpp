#include <iostream>
#include <cmath>
using namespace std;

/*
    HDOJ 2003 绝对值
*/

int main() {
    double x;
    while(cin >> x) {
        if (x < 0) {
            x = abs(x);
        }
        printf("%.2lf\n", x);
    }
}