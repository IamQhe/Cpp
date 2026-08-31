#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        double score;
        double max = 0;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> score;
            if(score > max) max = score;
        }
        printf("%.2lf\n", max);
    }
    return 0;
}