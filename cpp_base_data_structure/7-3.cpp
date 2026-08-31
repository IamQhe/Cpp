#include <iostream>
#include <queue>
using namespace std;

/*
    C++: queue
*/

int main() {
    queue<int> q;
    q.push(5);
    q.push(4);
    q.push(7);
    q.push(8);
    
    while(!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << endl;

    return 0;
}