#ifndef REFERENCE_HPP
#define REFERENCE_HPP

#include <iostream>

void test () {
    int a, b = 0;
    const int *p = &a;
    p = &b;
}

class A {
    public:
        virtual void vfunc1 () {};
        virtual void vfunc2 () {};
        void func1 () {};
        void func2 () {};
    private:
        int data1, data2;
};
class B: public A {
    public:
        virtual void vfunc1 () {};
        void func2 () {};
    private:
        int data3;
};
class C: public B {
    public:
        virtual void vfunc1 () {};
        void func2 () {};
    private:
        int data1, data4;
};

class myString {
    public:
        char operator[] (int loc) const {};
        char &operator[] (int loc) {};
};

void *myAlloc (size_t size) {
    return malloc(size);
}
void myFree (void *ptr) {
    return free(ptr);
}

inline void *operator new (size_t size) {
    return myAlloc(size);
}
inline void *operator new[] (size_t size) {
    return myAlloc(size);
}
inline void operator delete (void *ptr) {
    myFree(ptr);
}
inline void operator delete[] (void *ptr) {
    myFree(ptr);
}

myString *a = new myString; // 成员函数
myString *b = ::new myString; // 全局

#endif //REFERENCE_HPP
