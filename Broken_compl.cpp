#include "Broken_compl.h"

template<class C>
inline Broken_compl<C>::Broken_compl(unsigned int grow_size, unsigned int size)
{
    this->size = size;
    points = new Complex<C>[this->size];
}

template<class C>
inline Complex<C>& Broken_compl<C>::operator[](int index) const
{
    if (index < 0 || index > counter)
        throw out_of_range("Index out of range");
    return points_compl[index];
}

template<class C>
void Broken_compl<C>::operator()(const Complex<C>& value, int index)
{
    if (index < 0 || index > counter)
        throw std::out_of_range("Index out of range");

    points_compl[index] = value;
}

template<class C>
Complex<C>& Broken_compl<C>::operator+(const Broken_compl<C>& second_line)
{
    Broken_compl<C> line;
    line.points_compl = new Complex<C>[this->size + second_line.size];
    for (int i = 0; i < this->counter; i++) {
        line.points_compl[i] = points_compl[i];
    }
    for (int i = 0; i < second_line.get_counter(); i++) {
        line.points_compl[this->counter + i] = second_line.points_compl[i];
    }
    line.counter = this->counter + second_line.counter;
    line.set_size(line.counter);
    return line;
}

template<class C>
Broken_compl<C>& Broken_compl<C>::operator+=(const Complex<C>& src)
{
    if (counter == size) {
        Complex<C>* tmp;
        tmp = new Complex<C>[this->size + grow_size];
        for (int i = 0; i < size; i++) {
            tmp[i] = points_compl[i];
        }
        tmp[size] = src;
        points_compl = tmp;
    }
    else {
        points_compl[counter] = src;
    }
    counter++;
    return *this;
}




