#include "Fixed.hpp"


Fixed::Fixed( void ) {
    std::cout << "Default constructor called" << std::endl;
    _fixedPoint = 0;
}

Fixed::Fixed ( const Fixed& n ) {
    std::cout << "Copy constructor called" << std::endl;
    _fixedPoint = n._fixedPoint;
}

void Fixed::operator= ( const Fixed& n ) {
    std::cout << "Copy assignment operator called" << std::endl;
    _fixedPoint = n.getRawBits();
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor operator called" << std::endl;
}

int Fixed::getRawBits( void ) {
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixedPoint);
}

void Fixed::setRawBits( int raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPoint = raw;
}
