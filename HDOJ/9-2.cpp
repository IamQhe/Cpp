#include <iostream>
using namespace std;

/*
    HDOJ 2099 整除的尾数
*/

int* calcTail(int m, int n, int *size) {
    *size = 0;
    int *ret = new int[100];
    for(int i = 0; i < 100; i++) {
      if ((m * 100 + i) % n == 0) {
        ret[(*size)++] = i;
      }
    }
    return ret;
}

int main() {
    int m, n;
    while(cin >> m >> n) {
        if(!m && !n) break;
        int size = 0;
        int *ret = calcTail(m, n, &size);
        for(int i = 0; i < size; i++) {
          if (i) cout << ' ';
          if (ret[i] < 10) cout << '0';
          cout << ret[i];
        }
        cout << endl;
        delete[] ret;
    }

    return 0;
}