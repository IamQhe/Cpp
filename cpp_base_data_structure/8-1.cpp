#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
    用栈实现队列
*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ele = s2.top();
        s2.pop();
        return ele;
    }
    
    int peek() {
        if (s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }

private:
    stack<int> s1;
    stack<int> s2;
};

int main() {

    return 0;
}