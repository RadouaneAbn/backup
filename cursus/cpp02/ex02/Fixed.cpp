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
	_fixedPoint = (n << _fractionalBits);
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

/**
 * A_real = A_raw / 256
 * B_real = B_raw / 256
 * result_real = A_real + B_real
 *             = (A_raw / 256) + (B_raw / 256)
 *             = (A_raw + B_raw) / 256
 * 
 * result_raw = result_real * 256
 *            = ((A_raw + B_raw) / 256) * 256
 * <==>
 * result_raw = A_raw + B_raw
 */

Fixed Fixed::operator+ ( const Fixed& n ) const {
	Fixed new_fixed;
	new_fixed.setRawBits(this->getRawBits() + n.getRawBits());
	return (new_fixed);
}

/**
 * A_real = A_raw / 256
 * B_real = B_raw / 256
 * result_real = A_real - B_real
 *             = (A_raw / 256) - (B_raw / 256)
 *             = (A_raw - B_raw) / 256
 * 
 * result_raw = result_real * 256
 *            = ((A_raw - B_raw) / 256) * 256
 * <==>
 * result_raw = A_raw - B_raw
 */

Fixed Fixed::operator- ( const Fixed& n ) const {
	Fixed new_fixed;
	new_fixed.setRawBits(this->getRawBits() - n.getRawBits());
	return (new_fixed);
}

/**
 * A_real = A_raw / 256
 * B_real = B_raw / 256
 *
 * result_real = A_real * B_real
 * <==>
 *             = (A_raw/256) * (B_raw/256)
 *             = (A_raw * B_raw) / 65536
 * ==>
 * result_raw = result_real * 256
 *            = ((A_raw * B_raw) / 65536) * 256
 *            = (A_raw * B_raw) / 256
 * <==>
 * result_raw = (A_raw * B_raw) >> 8
 */

Fixed Fixed::operator* ( const Fixed& n ) const {
	Fixed new_fixed;
	new_fixed.setRawBits((this->getRawBits() * n.getRawBits()) >> _fractionalBits);
	return (new_fixed);
}

/**
 * A_real = A_raw / 256
 * B_real = B_raw / 256
 *
 * result_real = A_real * B_real
 * <==>
 *             = (A_raw/256) / (B_raw/256)
 *             = A_raw / B_raw
 * ==>
 * result_raw = result_real * 256
 *            = (A_raw / B_raw) * 256
 *            = (A_raw * 256) / B_raw
 * <==>
 * result_raw = (A_raw << 8) / B_raw
 */

Fixed Fixed::operator/ ( const Fixed& n ) const {
	Fixed new_fixed;
	new_fixed.setRawBits((this->getRawBits() << _fractionalBits) / n.getRawBits());
	return (new_fixed);
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
	if (a.toInt() <= b.toInt())
		return (a);
	return (b);
}

Fixed& Fixed::max (Fixed& a, Fixed& b) {
	if (a.toInt() >= b.toInt())
		return (a);
	return (b);
}

const Fixed& Fixed::min (const Fixed& a,const Fixed& b) {
	if (a.toInt() <= b.toInt())
		return (a);
	return (b);
}

const Fixed& Fixed::max (const Fixed& a,const Fixed& b) {
	if (a.toInt() >= b.toInt())
		return (a);
	return (b);
}
