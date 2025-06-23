#include <iostream> // stdio.h -> iostream.h -> iostream
#include "complex.hpp"
#include "str.hpp"
#include "addon.hpp"
using namespace std;

int complex_test () {
    const complex c1(2);
    complex c2(3);
    A::getInstance().step();    // 调用
    cout << c1;
    c2.func(c1);
    complex c3 = c1 + 4;
    cout << c3;
    return 0;
}

int string_test () {
    str s1(0);
    str s2("Hello");
    str s3(s1); // 拷贝构造
    str *s4 = new str("Hello");
    s3 = s2;  // 拷贝赋值
    cout << s3;
    return 0;
}

complex global(8, 5);    // 全局对象，也可以看成是静态对象
int memory () {
    complex c1(1, 2);   // 栈，离开作用域死亡
    complex *c2 = new complex(3);   // 堆，任意地方通过new获取全局堆空间
    static complex c3(5, 6); // 静态对象，离开作用域后仍存在，直到程序结束
}

int addon () {
    Account::set_rate(5);   // 通过类调用

    Account b;
    b.set_rate(5);  // 通过对象调用
}

int main () {

}
