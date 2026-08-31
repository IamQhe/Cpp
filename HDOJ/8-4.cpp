#include <iostream>
#include <algorithm>
using namespace std;

/*
    HDOJ 2039 三角形
*/

double a[3];

int main() {
    int n;
    cin >> n;
    while(n--) {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3);
        cout << ((a[0] + a[1] > a[2]) ? "YES" : "NO") << endl;
    }
    
    return 0;
}