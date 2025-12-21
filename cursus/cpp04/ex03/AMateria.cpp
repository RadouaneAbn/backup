#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
    _type = type;
}

AMateria::~AMateria( void ) {}

AMateria::AMateria( const AMateria & oldObj ) {
    _type = oldObj._type;
}

AMateria& AMateria::operator=( const AMateria & oldObj ) {
    if (this != &oldObj) {
        _type = oldObj._type;
    }
    return (*this);
}

std::string const & AMateria::getType() const {
    return (_type);
}

void AMateria::setType(std::string type ) {
    _type = type;
}