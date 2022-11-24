#include "Complex.h"

template<class C>
Complex<C>::Complex(C re, C im): re(re), im(im)
{}

template<class C>
Complex<C>& Complex<C>::operator*(const Complex& other)const {
    Complex tmp(*this);
    re = tmp.re * other.re - tmp.im * other.im;
    im = tmp.re * other.im + tmp.im * other.re;
        return (*this);
}

template<class C>
Complex<C>& Complex<C>::operator*=(const C& other)const {
    Complex tmp(*this);
    re = tmp.re * other;
    re = tmp.im * other;
       return (*this);
}

template<class C>
ostream& operator<<(ostream& out, const Complex<C>& x)
{
    return (out << "(" << x.re << "," << x.im << ")");
}

template<class C>
istream& operator>>(istream& in, Complex<C>& x)
{
    return (in >> x.re >> x.im);
}

template<class C>
Complex<C>::operator double() const
{
    return (re * re - im * im);
}

template<class C>
Complex<C>& Complex<C>::operator=(const Complex<C>& other)
{
    if (*this != other)
    {
        re = other.re;
        im = other.im;
    }
    return *this;
}

template<class C>
C Complex<C>::Get_Re()const {
    return this->re;
}

template<class C>
C Complex<C>::Get_Im()const {
    return this->im;
}