#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal {
    public:
        Cat( void );
        virtual ~Cat( void );
        Cat( const Cat &old_obj);
        Cat &operator=( const Cat &old_obj );
        virtual void makeSound( void ) const;
};
