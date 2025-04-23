#ifndef LIKE_CLASSES_HPP
#define LIKE_CLASSES_HPP

template<class T>
class shared_ptr {
    public:
        T &operator* () const { return *px; }
        T *operator-> () const { return px; }
        shared_ptr (T *p)
            : px(p) {}
    private:
        T *px;
        long *pn;
};

struct Foo {
    void method () {};
};

void test () {
    shared_ptr<Foo> sp(new Foo);
    sp->method(); // sp-> 会被替换为 px
}

template<class T>
struct ident {
    const T &operator() (const T &x) const { return x; }
};

#endif //LIKE_CLASSES_HPP
