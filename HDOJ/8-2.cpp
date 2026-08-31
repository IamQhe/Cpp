#include <iostream>
#include <cmath>
using namespace std;

/*
    HDOJ 2001 计算两点间距离
*/

int main() {
    double a, b, c, d;
    while(cin >> a >> b >> c >> d) {
        printf("%.2lf\n", sqrt((a-c) * (a-c) + (b-d) * (b-d)));
    }
}