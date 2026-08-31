#include <iostream>
using namespace std;

/*
    7.4 虚析构

    目的：主要解决内存泄漏问题
*/

class BaseA {
    public:
        BaseA() {}

        ~BaseA() {
            cout << "BaseA 销毁了" << endl;
        }
};

class SonA : public BaseA {
    public:
        SonA(): m_value(NULL) {
            m_value = new int(10);
        }

        ~SonA() {
            cout << "SonA 销毁了" << endl;
            delete m_value;
        }

        int* m_value;
};

class BaseB {
    public:
        BaseB() {}

        // 虚析构
        virtual ~BaseB() {
            cout << "BaseB 销毁了" << endl;
        }
};

class SonB : public BaseB {
    public:
        SonB(): m_value(NULL) {
            m_value = new int(10);
        }

        ~SonB() {
            cout << "SonB 销毁了" << endl;
            delete m_value;
        }

        int* m_value;
};

class BaseC {
    public:
        BaseC() {}

        // 纯虚析构
        virtual ~BaseC() = 0;
};

BaseC::~BaseC() {
    cout << "BaseB 销毁了" << endl;
}

class SonC : public BaseC {
    public:
        SonC(): m_value(NULL) {
            m_value = new int(10);
        }

        ~SonC() {
            cout << "SonC 销毁了" << endl;
            delete m_value;
        }

        int* m_value;
};

int main() {
    // 堆上分配 SonA 对象，指向基类的指针
    BaseA* a = new SonA();
    // 只有基类的析构函数被调用，子类堆上的内存没有销毁
    delete a;   

    // 方式一： 虚构析
    BaseB* b = new SonB();
    delete b;

    // 方式二： 纯虚构析
    //  抽象类无法实例化，子类必须
    BaseC* c = new SonC();
    delete c;

    return 0;
}