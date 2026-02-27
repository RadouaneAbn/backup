#include "Data.hpp"

Data::Data()
{
	std::cout << "Data Default Constructor called" << std::endl;
}

Data::Data(const Data &oldObj)
{
	std::cout << "Data Copy Constructor called" << std::endl;
	_value = oldObj._value;
}

Data &Data::operator=(const Data &oldObj)
{
	std::cout << "Data Copy Assignment Operator called" << std::endl;
	if (this != &oldObj)
		_value = oldObj._value;
	return (*this);
}

Data::~Data()
{
	std::cout << "Data Destructor called" << std::endl;
}

void	Data::setValue(int value)
{
	_value = value;
}

int		Data::getValue() const
{
	return (_value);
}