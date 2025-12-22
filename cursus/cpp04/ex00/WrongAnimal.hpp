#pragma once

#include <iostream>

class WrongAnimal {
    protected:
        std::string _type;
    public:
        WrongAnimal( void );
        WrongAnimal( std::string type );
        virtual ~WrongAnimal( void );
        WrongAnimal( const WrongAnimal &old_obj);
        WrongAnimal &operator=( const WrongAnimal &old_obj );\
                void setSound( std::string str ) {
            _type = str;
        }

        std::string getType( void ) const;
        virtual void makeSound( void ) const;
};
