#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int _fixedPoint;
        static const int _fractionalBits = 8;

    public:
        Fixed( void );
        Fixed( const Fixed& n );
        Fixed& operator= ( const Fixed& n );
        ~Fixed( void );

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif