#include "Fixed.hpp"


Fixed::Fixed( void ) {
    std::cout << "Default constructor called" << std::endl;
    _fixedPoint = 0;
}

Fixed::Fixed ( const Fixed &n ) {
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedPoint = n.getRawBits();
}

Fixed& Fixed::operator= ( const Fixed& n ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &n)
        return (*this);
    this->_fixedPoint = n.getRawBits();
    return (*this);
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixedPoint);
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPoint = raw;
}
