#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class complex {
        friend complex &__doapl (complex *, const complex &);
    public:
        complex &operator+= (const complex &r);
        complex (double r = 0, double i = 0) // 初值列
            : re(r), im(i) {}
        complex ()  // 重载
            : re(0), im(0) {}
        double imag () const { return im; }
        double real () const { return re; }
        void real (double r) { re = r; }
        double func (const complex &param) { return param.re + param.im; }
    private:
        double re, im;
};
inline complex &complex::operator+= (const complex &r) {
    return __doapl(this, r);
}
inline complex &__doapl (complex *ths, const complex &r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}
inline double imag (const complex &x) {
    return x.imag();
}
inline double real (const complex &x) {
    return x.real();
}
std::ostream &operator<< (std::ostream &os, const complex &x) { // ostream不能是const，因为输出时状态会改变
    return os << '(' << real(x) << ',' << imag(x) << ')';
}
inline complex operator+ (const complex &x, double y) {
    return complex(real(x) + y, imag(x));
}
inline complex operator+(const complex&x){
    return x;
}
inline complex operator-(const complex&x){
    return complex(-real(x),-imag(x));
}

class A { // Singleton 单例
    public:
        static A &getInstance ();
        void step () {}
    private:
        A () {};
        A (const A &rhs){};
};
A &A::getInstance () {
    static A a;
    return a;
}


#endif //COMPLEX_HPP
