#ifndef COMPOSITION_HPP
#define COMPOSITION_HPP

#include "iostream"

typedef size_t size_type;

template<class T>
struct Itr {
    T *cur;
    T *first;
    T *last;
    T **node;
};

template<class T>
class deque {
    protected:
        Itr<T> start;
        Itr<T> finish;
        T **map;
        unsigned char map_size ();
};

template<class T>
class queue {
    protected:
        deque<T> a; // 底层容器
    public: // 以下函数完全利用a的操作函数实现
        bool empty () const { return a.empty(); }
        size_type size () const { return a.size(); }
        void pop () { a.pop_front(); }
};

#endif //COMPOSITION_HPP
