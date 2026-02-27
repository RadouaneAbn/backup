#include "A.hpp"

A::A()
{
	std::cout << "A Default Constructor called" << std::endl;
}

A::A(const A &oldObj)
{
	std::cout << "A Copy Constructor called" << std::endl;
	// *this = oldObj;
}

A &A::operator=(const A &oldObj)
{
	std::cout << "A Copy Assignment Operator called" << std::endl;
	if (this != &oldObj)
	{
		// _member = oldObj._member;
	}
	return (*this);
}

A::~A()
{
	std::cout << "A Destructor called" << std::endl;
}
