#include <algorithm>
#include <iostream>
using namespace std;

/*
    HDOJ 2037  今年暑假不AC   
*/

struct Interval {
    int s;
    int e;
}I[100];

bool cmp(const Interval &a, const Interval &b) {
    return a.e < b.e;
}

int main() {
    int n;
    while(cin >> n) {
        if(!n) break;
        for(int i = 0; i < n; i++) {
            cin >> I[i].s >> I[i].e;
        }

        sort(I, I + n, cmp);

        int end = -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (I[i].s >= end) {
                ans++;
                end = I[i].e;
            }
        }
        cout << ans << endl;
    }

    return 0;
}