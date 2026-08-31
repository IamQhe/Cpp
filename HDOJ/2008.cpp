#include <iostream>
using namespace std;

/*
    HDOJ 2008 数值统计
*/

double arr[10000];

int main() {
    int n;
    while(cin >> n) {
        if (!n) break;
        double x;
        for(int i = 0; i < n; i++) {
            cin >> x;
            arr[i] = x;
        } 
        int a = 0;
        int b = 0;
        int c = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] < -1e-8) {
                a++;
            } else if (arr[i] > 1e-8) {
                c++;
            } else {
                b++;
            }
        } 
        cout << a << ' ' << b << ' ' << c << endl;
    }
    return 0;
}