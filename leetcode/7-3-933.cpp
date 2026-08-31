#include <iostream>
#include <queue>
using namespace std;

/*
    LeetCode 933. 最近的请求次数
*/

class RecentCounter {
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        q.push(t);
        while(q.front() > t - 3000) {
            q.pop();
        }
        return q.size();
    }

    private:
        queue<int> q;
};

int main() {


    return 0;
}