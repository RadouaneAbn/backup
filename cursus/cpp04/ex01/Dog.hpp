#pragma once

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal {
    public:
        Dog( void );
        virtual ~Dog( void );
        Dog( const Dog &old_obj);
        Dog &operator=( const Dog &old_obj );
        virtual void makeSound( void ) const;
};
