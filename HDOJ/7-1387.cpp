#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

/*
    HDOJ 1387 Team Queue
*/

int t[1000000];

int main() {
    int n;
    int caseNum = 1;
    while (cin >> n && n) {
        int team = 0;
        while(n--) {
            int x;
            cin >> x;
            for(int i = 1; i <= x; i++) {
                int num;
                cin >> num;
                t[num] = team;
            }
            team++;
        }

        string command;
        cout << "Scenario #" << caseNum << endl;
        caseNum++;
        queue<int> q[1001];
        int s = 0, e = 0;
        while(cin >> command) {
            if (command == "STOP") break;
            if (command == "ENQUEUE") {
                int ele, i;
                cin >> ele;
                
                for(i = s; i < e; i++) {
                    if(t[q[i].front()] == t[ele]) {
                        break;
                    }
                }
                q[i].push(ele);
                if (i == e) {
                    e++;
                }
            }
            if (command == "DEQUEUE") {
                cout << q[s].front() << endl;
                q[s].pop();
                if (q[s].size() == 0) {
                    s++;
                }
            }
        }
        cout << endl;
    }

    return 0;
}