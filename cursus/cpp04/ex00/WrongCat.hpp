#pragma once

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
    public:
        WrongCat( void );
        ~WrongCat( void );
        WrongCat( const WrongCat &old_obj);
        WrongCat &operator=( const WrongCat &old_obj );
        void makeSound( void ) const;
};
