#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
    Brain *brain;
    public:
        Dog( void );
        virtual ~Dog( void );
        Dog( const Dog &old_obj);
        Dog &operator=( const Dog &old_obj );
        virtual void makeSound( void ) const;

        const std::string getIdea( int i ) const;
        void setIdea( std::string idea, int i );
        bool hasIdeas( void );
};
