#ifndef FIXED_HPP
# define FIXED_HPP

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

		bool operator> ( const Fixed& n ) const;
		bool operator< ( const Fixed& n ) const;
		bool operator<= ( const Fixed& n ) const;
		bool operator>= ( const Fixed& n ) const;
		bool operator== ( const Fixed& n ) const;
		bool operator!= ( const Fixed& n ) const;

		Fixed operator+ ( const Fixed& n ) const;
		Fixed operator- ( const Fixed& n ) const;
		Fixed operator* ( const Fixed& n ) const;
		Fixed operator/ ( const Fixed& n ) const;

		Fixed& operator++ ( void );
		Fixed& operator-- ( void );
		Fixed operator++ ( int );
		Fixed operator-- ( int );


		int getRawBits( void ) const;
		void setRawBits( int const raw );
		int toInt( void ) const;
		float toFloat( void ) const;

		static Fixed& min (Fixed& a, Fixed& b);
		static Fixed& max (Fixed& a, Fixed& b);
		static const Fixed& min (const Fixed& a,const Fixed& b);
		static const Fixed& max (const Fixed& a,const Fixed& b);
};

#endif
