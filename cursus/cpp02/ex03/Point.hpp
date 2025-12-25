#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        Fixed const _x;
        Fixed const _y;

    public:
        Point( void );
        Point( const float x, const float y );
        Point( const Point& p );
        ~Point( void );

        const Fixed& getX( void ) const;
        const Fixed& getY( void ) const;

        Point& operator= ( const Point& p);
};

#endif
