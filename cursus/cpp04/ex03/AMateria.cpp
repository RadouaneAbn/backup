#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "debug.h"

AMateria::AMateria(std::string const & type) {
    _type = type;
    if (DEBUGING) std::cout << "AMateria constructed with type '" << _type << "'" << std::endl;
}

AMateria::~AMateria( void ) {
    if (DEBUGING) std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria( const AMateria & oldObj ) {
    _type = oldObj._type;
    if (DEBUGING) std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=( const AMateria & oldObj ) {
    if (this != &oldObj) {
        _type = oldObj._type;
    }
    if (DEBUGING) std::cout << "AMateria copy assignment operator called" << std::endl;
    return (*this);
}

std::string const & AMateria::getType() const {
    return (_type);
}

void AMateria::setType(std::string type ) {
    _type = type;
}

void AMateria::use(ICharacter& target) {
    (void)target; // base class does nothing
}