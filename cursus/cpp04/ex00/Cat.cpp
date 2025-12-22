#include "Cat.hpp"

Cat::Cat( void ) {
    _type = "Cat";
}

Cat::~Cat( void ) {}

Cat::Cat( const Cat &old_obj): Animal() {
    _type = old_obj._type;
}

Cat &Cat::operator=( const Cat &old_obj ) {
    if (this != &old_obj)
        _type = old_obj._type;
    return (*this);
}

void Cat::makeSound( void) const {
    std::cout << "Meow" << std::endl;
}