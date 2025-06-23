#ifndef CONVERT_HPP
#define CONVERT_HPP

class Fraction {
    public:
        explicit Fraction (int num, int den = 1)
            : m_numerator(m_denominator), m_denominator(m_denominator) {};
        operator double () const {
            return (double) (m_numerator / m_denominator);
        }
        Fraction operator+ (const Fraction &f) { return Fraction(...); };
    private:
        int m_numerator;
        int m_denominator;
};

Fraction f(3, 5);

struct __bit_reference {
        unsigned int *p;
        unsigned int mask;
    public:
        operator bool () const { return !(!(*p&mask)); }
};

template<class Alloc>
class vector<bool, Alloc> {
    public:
        typedef __bit_reference reference;
    protected:
        reference operator[] (size_type n) {
            return *(begin() + difference_type(n));
        }

};

#endif //CONVERT_HPP
