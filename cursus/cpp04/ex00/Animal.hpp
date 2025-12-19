#pragma once

#include <iostream>

class Animal {
    protected:
        std::string _type;
    public:
        Animal( void );
        Animal( std::string type );
        virtual ~Animal( void );
        Animal( const Animal &old_obj);
        Animal &operator=( const Animal &old_obj );

        std::string getType( void ) const;
        virtual void makeSound( void ) const;
};
