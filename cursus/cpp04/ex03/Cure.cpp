#include "Cure.hpp"
#include "ICharacter.hpp"
#include "debug.h"

Cure::Cure( void ): AMateria("cure") {
    if (DEBUGING) std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure( const Cure & oldObj ): AMateria(oldObj._type) {
    if (DEBUGING) std::cout << "Cure copy constructor called" << std::endl;
}

Cure & Cure::operator=( const Cure & oldObj ) {
    if (DEBUGING) std::cout << "Cure assignment operator called" << std::endl;
    if (this != &oldObj) {
        _type = oldObj._type;
    }
    return *this;
}

Cure::~Cure( void ) {
    if (DEBUGING) std::cout << "Cure destructor called" << std::endl;
}

Cure* Cure::clone() const {
    Cure *cure = new Cure();
    cure->setType(_type);
    return (cure);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}