#include <iostream>
using namespace std;

/*
    3.6 类模板的继承
*/

template<typename NameType, typename HpType>
class People {
    public:
        NameType m_name;
        HpType m_hp;

        People(NameType name, HpType hp) {
            m_name = name;
            m_hp = hp;
        }
};


template<typename T1, typename T2, typename T3>
class PeopleSon : public People<T1, T2> {
    T3 a;
};

int main() {

    return 0;
}