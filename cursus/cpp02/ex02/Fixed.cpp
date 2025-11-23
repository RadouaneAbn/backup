#include "Fixed.hpp"
#include <cmath>


Fixed::Fixed( void ) {
    _fixedPoint = 0;
}

Fixed::Fixed ( const Fixed &n ) {
    this->_fixedPoint = n._fixedPoint;
}

Fixed& Fixed::operator= ( const Fixed& n ) {
    if (this == &n)
        return (*this);
    this->_fixedPoint = n._fixedPoint;
    return (*this);
}

Fixed::~Fixed( void ) {
}

int Fixed::getRawBits( void ) const {
    return (_fixedPoint);
}

void Fixed::setRawBits( int const raw ) {
    _fixedPoint = raw;
}

Fixed::Fixed( const int n ) {
    _fixedPoint = (n * (1 << _fractionalBits));
}

Fixed::Fixed( const float n ) {
    _fixedPoint = roundf(n * (1 << _fractionalBits));
}


int Fixed::toInt( void ) const {
    return (_fixedPoint / int(1 << _fractionalBits));
} 

float Fixed::toFloat( void ) const {
    return (float(_fixedPoint) / float(1 << _fractionalBits));
}

bool Fixed::operator> ( const Fixed& n ) const {
    return (this->getRawBits() > n.getRawBits());
}

bool Fixed::operator< ( const Fixed& n ) const {
    return (this->getRawBits() < n.getRawBits());
}

bool Fixed::operator>= ( const Fixed& n ) const {
    return (this->getRawBits() >= n.getRawBits());
}

bool Fixed::operator<= ( const Fixed& n ) const {
    return (this->getRawBits() <= n.getRawBits());
}

bool Fixed::operator== ( const Fixed& n ) const {
    return (this->getRawBits() == n.getRawBits());
}

bool Fixed::operator!= ( const Fixed& n ) const {
    return (this->getRawBits() != n.getRawBits());
}

Fixed Fixed::operator+ ( const Fixed& n ) const {
    return (Fixed(this->toFloat() + n.toFloat()));
}

Fixed Fixed::operator- ( const Fixed& n ) const {
    return (Fixed(this->toFloat() - n.toFloat()));
}

Fixed Fixed::operator* ( const Fixed& n ) const {
    return (Fixed(this->toFloat() * n.toFloat()));
}

Fixed Fixed::operator/ ( const Fixed& n ) const {
    return (Fixed(this->toFloat() / n.toFloat()));
}

Fixed& Fixed::operator++ ( void ) {
    _fixedPoint++;
    return (*this);
}

Fixed& Fixed::operator-- ( void ) {
    _fixedPoint--;
    return (*this);
}

Fixed Fixed::operator++ ( int ) {
    Fixed tmp = *this;
    _fixedPoint++;
    return (tmp);
}

Fixed Fixed::operator-- ( int ) {
    Fixed tmp = *this;
    _fixedPoint--;
    return (tmp);
}

Fixed& Fixed::min (Fixed& a, Fixed& b) {
    if (a.toFloat() <= b.toFloat())
        return (a);
    return (b);
}

Fixed& Fixed::max (Fixed& a, Fixed& b) {
    if (a.toFloat() >= b.toFloat())
        return (a);
    return (b);
}

const Fixed& Fixed::min (const Fixed& a,const Fixed& b) {
    if (a.toFloat() <= b.toFloat())
        return (a);
    return (b);
}

const Fixed& Fixed::max (const Fixed& a,const Fixed& b) {
    if (a.toFloat() >= b.toFloat())
        return (a);
    return (b);
}
