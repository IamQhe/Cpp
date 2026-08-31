#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
    HDOJ 1276 士兵队列训练问题
*/

int main() {
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        queue<int> q;
        for(int i = 1; i <= x; i++) {
            q.push(i);
        }
        int base = 2;
        int flag = -1;
        int count = 1;
        while(q.size() > 3) {
            int count = 1;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int ele = q.front();
                q.pop();
                if (count == base) {
                    count = 1;
                } else {
                    q.push(ele);
                    count++;
                }
            }
            
            base = (base == 2) ? 3 : 2;
        }
        while(!q.empty()) {
            cout << q.front() << ' ';
            q.pop();
        }
        cout << endl;
    }

    return 0;
}