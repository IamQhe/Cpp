#include <iostream>
#include <stack>
using namespace std;

/*
    STL 栈

    接口: 
        - push(v)
        - pop()
        - top()

        - size()
        - empty()
*/

int main() {
    stack<int> intStack;
    stack<double> doubleStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.push(4);

    while(!intStack.empty()) {
        cout << intStack.top() << endl;
        intStack.pop();
    }

    return 0;
}