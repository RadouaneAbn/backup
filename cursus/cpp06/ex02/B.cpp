#include "B.hpp"

B::B()
{
	std::cout << "B Default Constructor called" << std::endl;
}

B::B(const B &oldObj)
{
	std::cout << "B Copy Constructor called" << std::endl;
	// *this = oldObj;
}

B &B::operator=(const B &oldObj)
{
	std::cout << "B Copy Assignment Operator called" << std::endl;
	if (this != &oldObj)
	{
		// _member = oldObj._member;
	}
	return (*this);
}

B::~B()
{
	std::cout << "B Destructor called" << std::endl;
}
