#include "Fixed.hpp"
#include <cmath>


Fixed::Fixed( void ) {
    std::cout << "Default constructor called" << std::endl;
    _fixedPoint = 0;
}

Fixed::Fixed ( const Fixed &n ) {
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedPoint = n._fixedPoint;
}

Fixed& Fixed::operator= ( const Fixed& n ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &n)
        return (*this);
    this->_fixedPoint = n._fixedPoint;
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

Fixed::Fixed( const int n ) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPoint = (n << _fractionalBits);
}

Fixed::Fixed( const float n ) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPoint = roundf(n * (1 << _fractionalBits));
}


int Fixed::toInt( void ) const {
    return (_fixedPoint >> _fractionalBits);
} 

float Fixed::toFloat( void ) const {
    return (float(_fixedPoint) / float(1 << _fractionalBits));
}
