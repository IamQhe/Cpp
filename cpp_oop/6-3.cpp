#include <iostream>
using namespace std;

/*
    6.3 构造 和 析构 的调用顺序
      继承中，构造链里，先构造的后析构
*/

class Animal {
    public:
        Animal() {
            cout << "Animal 构造..." << endl;
        }

        ~Animal() {
            cout << "Animal 析构..." << endl;
        }
};

class Cat : public Animal {
    public:
        Cat() {
            cout << "Cat 构造..." << endl;
        }

        ~Cat() {
            cout << "Cat 析构..." << endl;
        }
};

class BossCat : public Cat {
    public:
        BossCat() {
            cout << "BossCat 构造..." << endl;
        }

        ~BossCat() {
            cout << "BossCat 析构..." << endl;
        }
};

void Test() {
    // Animal a;
    // Cat c;
    BossCat bc;
}

int main() {
    Test();
    return 0;
}