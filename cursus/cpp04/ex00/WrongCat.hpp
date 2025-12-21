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
        void mm(void) {
            std::cout << "hey\n";
        };
};

// class Base : public WrongCat
// {
//     public:
//         void makeSound(void) const {std::cout << "Based\n";}
// };

// class Derived : public Base
// {
//     public:
//         void makeSound(void) const {std::cout << "Derived\n";}
// };
