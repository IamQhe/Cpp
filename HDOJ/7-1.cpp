#include <iostream>
#include <cmath>
using namespace std;

/**
 * 奇数乘积：
 *      输入： 给 n 个整数，求其中奇数的乘积
 */

int main() {
    // int n;
    // while(cin >> n) {
    //     for(int i = 0; i < n; i++) {
    //         cin >> a[i];
    //     }

    //     int prod = 1;
    //     for(int i = 0; i < n; i++) {
    //         if(a[i] & 1) {
    //            prod *= a[i];
    //         }
    //     }

    //     cout << prod << endl;
    // }

    int a = -2147483648;
    int b = -2147483647;

    cout << (~a + 1) << endl;
    cout << (~b + 1) << endl;

    cout << abs(a) << endl;
    cout << abs(b) << endl;

    return 0;
}