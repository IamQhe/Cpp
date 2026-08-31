#include <iostream>
using namespace std;

/*
    HDOJ 2006 求奇数的乘积
*/

int a[10000];
int main() {
    int n;
    while(cin >> n) {
        int x;
        for(int i = 0; i < n; i++) {
            cin >> x;
            a[i] = x;
        }
        int prod = 1;
        for(int i = 0; i < n; i++) {
            if(a[i] & 1) {
                prod *= a[i];
            }
        }
        cout << prod << endl;
    }

    return 0;
}