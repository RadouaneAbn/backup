#include "Ice.hpp"
#include "ICharacter.hpp"
#include "debug.h"

Ice::Ice( void ): AMateria("ice") {
    if (DEBUGING) std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice( const Ice & oldObj ): AMateria(oldObj._type) {
    if (DEBUGING) std::cout << "Ice copy constructor called" << std::endl;
}

Ice & Ice::operator=( const Ice & oldObj ) {
    if (DEBUGING) std::cout << "Ice assignment operator called" << std::endl;
    if (this != &oldObj) {
        _type = oldObj._type;
    }
    return *this;
}

Ice::~Ice( void ) {
    if (DEBUGING) std::cout << "Ice destructor called" << std::endl;
}

Ice* Ice::clone() const {
    Ice *ice = new Ice();
    ice->setType(_type);
    return (ice);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}