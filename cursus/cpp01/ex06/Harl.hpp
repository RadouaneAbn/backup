#pragma once

#include <iostream>

class Harl {
    static const char * const DEBUG;
    static const char * const INFO;
    static const char * const WARNING;
    static const char * const ERROR;
    private:
        int _filter = -1;

        void debug( void );
        void info( void );
        void warning( void );
        void error( void );

    public:
        Harl () {};
        // Harl ( std::string level );
        void complain( std::string level );
        void setFilter( std::string level );
        int getFilter( void );
};