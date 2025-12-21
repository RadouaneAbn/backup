#include "Ice.hpp"
Ice::Ice( void ) {
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice( const Ice & oldObj ) {
    std::cout << "Ice copy constructor called" << std::endl;
    /* ... */
}

Ice & Ice::operator=( const Ice & oldObj ) {
    std::cout << "Ice assignment operator called" << std::endl;
    if (this != &oldObj) {
        /* ... */
    }
    return *this;
}

Ice::~Ice( void ) {
    std::cout << "Ice destructor called" << std::endl;
}

