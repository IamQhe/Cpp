#include <iostream>
using namespace std;

/*
    补码
*/

int main() {
    int x;
    while (cin >> x) {
        cout << ((x >= 0) ? x : (~x + 1)) << endl;
    }
    return 0;
}