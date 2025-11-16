#include "Weapon.hpp"

void Weapon::setType( std::string type ) {
    _type = type;
}

const std::string& Weapon::getType( void ) const {
    return (_type);
}
