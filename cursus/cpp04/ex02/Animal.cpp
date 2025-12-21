#include "Animal.hpp"

Animal::Animal( void ) {
    std::cout << "> Animal default constructor\n";
}

Animal::Animal( std::string type ): _type(type) {
    std::cout << "> Animal parametrized constructor\n";
}

Animal::~Animal( void ) {
    std::cout << "> Animal destructor constructor\n";
}

Animal::Animal( const Animal &old_obj): _type(old_obj._type) {
    std::cout << "> Animal copy constructor\n";
}

Animal& Animal::operator=( const Animal& old_obj ) {
    std::cout << "> Animal copy operator overload\n";
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