#pragma once

#include <iostream>

class Fixed {
	private:
		int _fixedPoint;
		static const int _fractionalBits = 8;

	public:
		Fixed( void );
		Fixed( const int n );
		Fixed( const float n );
		Fixed( const Fixed& n );
		~Fixed( void );
		Fixed& operator= ( const Fixed& n );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		int toInt( void ) const;
		float toFloat( void ) const;

};
