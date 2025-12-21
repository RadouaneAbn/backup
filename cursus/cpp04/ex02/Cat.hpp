#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
    Brain *brain;
    public:
        Cat( void );
        virtual ~Cat( void );
        Cat( const Cat &old_obj);
        Cat &operator=( const Cat &old_obj );
        virtual void makeSound( void ) const;

        const std::string getIdea( int i ) const;
        void setIdea( std::string idea, int i );
        bool hasIdeas( void );
        void brainAddr( void );
};
