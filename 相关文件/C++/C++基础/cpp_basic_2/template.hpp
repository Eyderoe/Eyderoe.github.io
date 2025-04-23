#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

# include <iostream>

template<class T>
class complex {
    private:
        T re, im;
};
complex<int> com;

template<class T>
inline const T &min (const T &a, const T &b) {
    return b < a ? b : a;
}
int a = min(1, 2);

template<class T1, class T2>
struct pair {
    T1 first;
    T2 second;

    template<class U1, class U2>
    pair (const pair<U1, U2> &p)
        :first(p.first, second(p.second)) {}
};
class Fish {};
class Trout: public Fish {};
class Bird {};
class Parrot: public Bird {};
pair<Fish, Bird> p (pair<Trout, Parrot>);

template<class Key>
struct hash {};
template<>
struct hash<int> {
    size_t operator() (int x) const { return x; }
};

template<class T, class Alloc>
class vector {};
// 模板个数的特化 针对bool类型
template<class Alloc>
class vector<bool, Alloc> {};
// 模板范围的特化 针对指针类型
template<class U, class Alloc>
class vector<U *, Alloc> {};

#include <list>
#include <string>

template<typename T,
    template<typename U>
    class Container
>
class XCls {
    private:
        Container<T> c;
};

template<typename T>
using Lst = std::list<T, std::allocator<T>>;
XCls<std::string, Lst> mylist1;

template<typename T, typename ... Types>
void print (const T &firstArg, const Types &...args) { // 将参数分为一个和一包(一包参数递归输出)
    std::cout << firstArg << std::endl;
    std::cout << sizeof...(args) << std::endl; // 一包的个数
    print(args...);
}

void aaaaa () {
    std::list<int> c;
    for (auto &item : c) {
        std::cout << item << std::endl;
    }
};

#endif //TEMPLATE_HPP
