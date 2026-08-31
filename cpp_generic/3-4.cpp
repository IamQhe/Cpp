#include <iostream>
using namespace std;

/*
    3.4 类模板中成员函数的创建时机

    区别：
        普通类成员函数在类创建时就已存在
        类模板成员函数在调用时才创建
*/

class Player {
    public:
        void run() {
            cout << "Player 跑步..." << endl;
        }
};


class Ball {
    public:
        void drop() {
            cout << "Ball 下落..." << endl;
        }
};

template<class T>
class Test {
    public:
        T obj;

        // 编译阶段 obj.run() 和 obj.drop() 不会报错
        // 故，对于编译器来说还没创建出
        void move1() {
            obj.run();
        }

        void move2() {
            obj.drop();
        }
};


int main() {
    Test<Player> test1;
    test1.move1();
    // test1.move2();   error -> 'class Player' has no member named 'drop'

    Test<Ball> test2;
    test2.move2();
    // test2.move1();   error -> 'class Ball' has no member named 'run'

    return 0;
}