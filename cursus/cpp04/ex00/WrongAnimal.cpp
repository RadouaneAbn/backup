#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ): _type("Wrong animal") {}

WrongAnimal::WrongAnimal( std::string type ): _type(type) {}

WrongAnimal::~WrongAnimal( void ) {}

WrongAnimal::WrongAnimal( const WrongAnimal &old_obj): _type(old_obj._type) {}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& old_obj ) {
    if (this != &old_obj)
        _type = old_obj._type;
    return (*this);
}

std::string WrongAnimal::getType( void ) const {
    return (_type);
}

void WrongAnimal::makeSound( void) const {
    std::cout << "I have the wrong voice" << std::endl;
}