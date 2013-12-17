#include <sstream>

template <class R, class A> R cast(A a)
{
	R r;
	std::stringstream strs;
	strs << a;
	strs >> r;
	return r;
}