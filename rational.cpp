#include "rational.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Rational::Rational(int x, int y) : num(x), denum(y) {}

Rational Rational::norm(Rational x){
	int g = __gcd(x.num, x.denum);
	x.num /= g;
	x.denum /= g;
	if (x.denum < 0){
		x.num *= -1;
		x.denum *= -1;
	}
	return x;
}

string Rational::to_str(){
	if (denum == 1)
		return cast<string>(num);
	return cast<string>(num) + "/" + cast<string>(denum);
}

string Rational::to_tex_str(){
	if (denum == 1)
		return cast<string>(num);
	return "\\sfrac{"+cast<string>(num) + "}{" + cast<string>(denum) + "}";
}

istream &operator >>(istream &input, Rational &x){
	x.denum = 1;
    input >> x.num;
    return input;
}

ostream &operator <<(ostream &output, Rational x){
    return output << x.to_str();
}

bool Rational::operator <(Rational x){
	return num * x.denum < denum * x.num;
}

bool Rational::operator >(Rational x){
	return x < *this;
}

bool Rational::operator ==(Rational x){
	return !((*this < x) || (*this > x));
}

bool Rational::operator !=(Rational x){
	return !(*this == x);
}

bool Rational::operator <=(Rational x){
	return !(*this > x);
}

bool Rational::operator >=(Rational x){
	return !(*this < x);
}

Rational Rational::operator -(){
	return Rational(-num, denum);
}

Rational Rational::operator +(Rational x){
	return norm(Rational(num * x.denum + x.num * denum, denum * x.denum));
}

void Rational::operator +=(Rational x){
	*this = *this + x;
}

Rational Rational::operator -(Rational x){
	return *this + -x;
}

void Rational::operator -=(Rational x){
	*this = *this - x;
}

Rational Rational::operator *(Rational x){
	return norm(Rational(num * x.num, denum * x.denum));
}

void Rational::operator *=(Rational x){
	*this = *this * x;
}

Rational Rational::operator /(Rational x){
	return norm(Rational(num * x.denum, denum * x.num));	
}

void Rational::operator /=(Rational x){
	*this = *this / x;
}

int Rational::get_num() const{
	return num;
}

int Rational::get_denum() const{
	return denum;
}

Rational abs(Rational &x){
	return (x.get_num() < 0) ? -x : x;
}