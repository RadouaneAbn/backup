#include "Dog.hpp"

Dog::Dog( void ) {
    _type = "Dog";
}

Dog::~Dog( void ) {}

Dog::Dog( const Dog &old_obj) {
    _type = old_obj._type;
}

Dog &Dog::operator=( const Dog &old_obj ) {
    if (this != &old_obj)
        _type = old_obj._type;
    return (*this);
}

void Dog::makeSound( void) const {
    std::cout << "Bark, bark!!!" << std::endl;
}