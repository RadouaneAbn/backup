#include "Animal.hpp"

Animal::Animal( void ) {}

Animal::Animal( std::string type ): _type(type) {}

Animal::~Animal( void ) {}

Animal::Animal( const Animal &old_obj): _type(old_obj._type) {}

Animal& Animal::operator=( const Animal& old_obj ) {
    if (this != &old_obj)
        _type = old_obj._type;
    return (*this);
}

std::string Animal::getType( void ) const {
    return (_type);
}

void Animal::makeSound( void) const {
    std::cout << "I don't have a voice" << std::endl;
}