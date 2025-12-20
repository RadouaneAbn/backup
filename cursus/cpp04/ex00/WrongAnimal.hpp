#pragma once

#include <iostream>

class WrongAnimal {
    protected:
        std::string _type;
    public:
        WrongAnimal( void );
        WrongAnimal( std::string type );
         ~WrongAnimal( void );
        WrongAnimal( const WrongAnimal &old_obj);
        WrongAnimal &operator=( const WrongAnimal &old_obj );

        std::string getType( void ) const;
        void makeSound( void ) const;
};
