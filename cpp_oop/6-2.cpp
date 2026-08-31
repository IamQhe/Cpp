#include <iostream>
using namespace std;

/*
    6.2 继承方式
        class 子类名 : 继承方式 父类名

        三种方式:
            - 公共 public
            - 保护 protected
            - 私有 private

        父类成员也有三种方式，所以共计 3 * 3 = 9 种情况

                        |     public      |     protected     |   private
            public      |     public      |     protected     |   无法访问
            protected   |     protected   |     protected     |   无法访问
            private     |     private     |      private      |   无法访问

        结果即子类的访问权限
*/

class Animal {
    public:
        int m_pub;

        void eat() {
            cout << "吃" << endl;
        }

    protected:
        int m_pro;

    private:
        int m_pri;
};

class Cat : public Animal {
    public:
        Cat() {
            m_pub = 1;
            m_pro = 2;
            // m_pri = 1;   // 父类私有成员，子类公有继承，无法访问
        }
};

class BossCat : protected Animal {
    public:
        BossCat() {
            m_pub = 1;
            m_pro = 2; // 证明不是私有，故为保护
        }
};

void testCat() {
    Cat c;
    c.m_pub = 111; // public
                   //  c.m_pro = 222;  无法访问，可能保护，可能私有
}

class Dog : protected Animal {
    public:
        Dog() {
            m_pub = 11; // 可能保护、可能私有，由子类 PoliceDog 继承验证
            m_pro = 22; // 可能保护、可能私有，由子类 PoliceDog 继承验证
                        // m_pri = 33; 父类私有成员，子类保护继承，无法访问
        }
};

class PoliceDog : public Dog {
    public:
        PoliceDog() {
            m_pub = 1; // 证明 m_pub 在父类 Dog 中不是私有，故为保护
            m_pro = 2; // 证明 m_pro 在父类 Dog 中不是私有，故为保护
        }
};

void testDog() {
    Dog d;
    //  d.m_pub = 1;    类外无法访问，要么保护，要么私有
}

class Bird : private Animal {
    public:
        Bird() {
            m_pub = 1; // 可能保护、可能私有，由子类 PoliceDog 继承验证
            m_pro = 2; // 可能保护、可能私有，由子类 PoliceDog 继承验证
                       //  m_pri = 3;  父类私有成员，子类私有继承，无法访问
        }
};

void testBird() {
    Bird b;
    //  b.m_pub = 1;    类外无法访问，要么保护，要么私有
    //  b.m_pro = 2;    类外无法访问，要么保护，要么私有
}

class BlackBird : public Bird {
    public:
        BlackBird() {
            //  m_pub = 1;  父类私有
            //  m_pro = 2;  父类私有
        }
};

int main() {

    return 0;
}