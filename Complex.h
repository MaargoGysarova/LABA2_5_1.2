
#include <iostream>

using namespace std;

template<class C>
class Complex{
private:
	C re, im;
public:
	
	Complex(C re=0, C im = 0);
	Complex& operator*(const Complex& other) const;
	Complex& operator*=(const C& other) const;

	friend ostream& operator<< (ostream& out, const Complex& x); //вывод
	friend istream& operator>> (istream& in, Complex& x); //ввод

	// преобразование типа Complex в double
	operator double() const;

	Complex& operator=(const Complex& other);//оператор присваивания

	C Get_Re()const;
	C Get_Im()const;
};

