#pragma once

#include <iostream>

class Fixed {
    private:
        int _fixedPoint;
        static const int _fractionalBits = 8;

    public:
        Fixed( void );
        Fixed( const Fixed& n );
        void operator= ( const Fixed& n );
        ~Fixed( void );

        int getRawBits( void );
        void setRawBits( int const raw );
};
