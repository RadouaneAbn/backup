#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cstring>


class String {
    // private:
    public:
        char *_buffer;
        unsigned int _size;
  
        String( void );
        String( char *s );
        ~String( void );
        String(const String& obj);
};
