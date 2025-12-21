#include "Ice.hpp"
Ice::Ice( void ): AMateria("ice") {
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice( const Ice & oldObj ): AMateria(oldObj._type) {
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice & Ice::operator=( const Ice & oldObj ) {
    std::cout << "Ice assignment operator called" << std::endl;
    if (this != &oldObj) {
        _type = oldObj._type;
    }
    return *this;
}

Ice::~Ice( void ) {
    std::cout << "Ice destructor called" << std::endl;
}

Ice* Ice::clone() const {
    Ice *ice = new Ice();
    ice->setType(_type);
    return (ice);
}

void Ice::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}