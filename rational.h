#ifndef RATIONAL_H
#define RATIONAL_H


#include <iostream>
#include <string>

template <class R, class A> R cast(A a);

class Rational{
	int num, denum;

	Rational norm(Rational x);

public:
    
    Rational(int x = 0, int y = 1);

    std::string to_str();

    std::string to_tex_str();

	friend std::istream &operator >>(std::istream &input, Rational &x);

	friend std::ostream &operator <<(std::ostream &output, Rational x);

    bool operator <(Rational x);

    bool operator >(Rational x);

    bool operator ==(Rational x);

    bool operator !=(Rational x);

    bool operator <=(Rational x);

    bool operator >=(Rational x);

    Rational operator -();

    Rational operator +(Rational x);

    void operator +=(Rational x);

    Rational operator -(Rational x);

    void operator -=(Rational x);

	Rational operator *(Rational x);

    void operator *=(Rational x);

	Rational operator /(Rational x);

    void operator /=(Rational x);

    int get_num() const;

    int get_denum() const;

};

Rational abs(Rational &x);

#include "rational.hpp"

#endif //RATIONAL_H