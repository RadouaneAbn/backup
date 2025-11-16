#include "HumanB.hpp"

void HumanB::attack( void ) {
    if (_weapon != nullptr)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " doesn't have a weapon" << std::endl;
}

void HumanB::setWeapon( Weapon& weapon ) {
    _weapon = &weapon;
}
