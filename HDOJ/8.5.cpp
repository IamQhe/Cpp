#include <iostream>
using namespace std;

/*
    HDOJ 2012 素数
*/

bool isPrime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0)
      return false;
  }
  return true;
}

int main() {
    int x, y;
    while(cin >> x >> y) {
        if(!x && !y) break;
        bool flag = true;
        for(int i = x; i <= y; i++) {
          int z = i * i + i + 41;
          if (!isPrime(z)) {
            flag = false;
            break;
          }
        }
        cout << (flag ? "OK" : "Sorry") << endl;
    }

    return 0;
}