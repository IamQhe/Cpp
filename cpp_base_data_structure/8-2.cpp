#include <iostream>
#include <queue>
using namespace std;

/*
    队列实现栈
*/

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int ft = q1.front();
        q1.pop();
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return ft;
    }
    
    int top() {
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int ft = q1.front();
        q2.push(ft);
        q1.pop();
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return ft;
    }
    
    bool empty() {
        return q1.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
};

int main() {


    return 0;
}