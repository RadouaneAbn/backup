#include "C.hpp"

C::C()
{
	std::cout << "C Default Constructor called" << std::endl;
}

C::C(const C &oldObj)
{
	std::cout << "C Copy Constructor called" << std::endl;
	// *this = oldObj;
}

C &C::operator=(const C &oldObj)
{
	std::cout << "C Copy Assignment Operator called" << std::endl;
	if (this != &oldObj)
	{
		// _member = oldObj._member;
	}
	return (*this);
}

C::~C()
{
	std::cout << "C Destructor called" << std::endl;
}
