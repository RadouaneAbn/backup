#pragma once

#include <iostream>

class Harl {
    static const char * const DEBUG;
    static const char * const INFO;
    static const char * const WARNING;
    static const char * const ERROR;
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );

    public:
        Harl () {};
        void complain( std::string level );
};