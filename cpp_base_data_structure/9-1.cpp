#include <cstring>
#include <iostream>
using namespace std;

/*
    串

    接口：
        1. 获取串的长度
        2. 串的拷贝
        3. 串的比较
        4. 串的拼接
        5. 串的索引
*/

class String {
    private:
        char* str;
        size_t length;

    public:
        String();
        String(const String& s);
        String(size_t len);
        String(const char* c);
        ~String();
        size_t getLength() const;
        char operator[](size_t index) const;
        String& operator=(const String& s);
        bool operator==(const String& s) const;
        bool operator!=(const String& s) const;
        String copy() const;
        String operator+(const String& s) const;
        friend ostream& operator<<(ostream& out, const String& s);
};

String::String() {
    str = new char[1];
    str[0] = '\0';
    length = 0;
}

String::String(const String& s) {
    size_t length = s.length;
    str = new char[length + 1];
    strcpy(str, s.str);
}

String::String(size_t len) {
    str = new char[len + 1];
}

String::String(const char* c) {
    length = strlen(c);
    str = new char[length + 1];
    strcpy(str, c);
}

String::~String() {
    delete[] str;
}

size_t String::getLength() const {
    return length;
}

char String::operator[](size_t index) const {
    return str[index];
}

String& String::operator=(const String& s) {
    if (this != &s) {
        length = s.length;
        delete[] str;
        str = new char[length + 1];
        strcpy(str, s.str);
    }
    return *this;
}

bool String::operator==(const String& s) const {
    return strcmp(str, s.str) == 0;
}

bool String::operator!=(const String& s) const {
    return strcmp(str, s.str) != 0;
}

String String::copy() const {
    String s = *this;
    return s;
}

String String::operator+(const String& s) const {
    String result;
    result.length = length + s.length;
    result.str = new char[length + 1];
    strcpy(result.str, str);
    strcat(result.str, s.str);
    return result;
}

ostream& operator<<(ostream& out, const String& s) {
    out << s.str;
    return out;
}

int main() {
    String s("12345d");
    cout << s << endl;
    cout << s + "114514" << endl;
    cout << s[5] << endl;
    cout << (s == "12345d") << endl;
    cout << (s != "12345d") << endl;

    s = s + "abc";
    cout << s << endl;

    String a, b, c;
    a = b = c = s;
    cout << a << b << c << endl;

    String x = s.copy();
    cout << x << endl;
    return 0;
}