#include "HumanB.hpp"

HumanB::HumanB( std::string name ): _weapon(NULL), _name(name) {}

HumanB::HumanB( std::string name, Weapon weapon ): _weapon(&weapon), _name(name) {}

void HumanB::attack( void ) {
    if (_weapon != NULL)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " doesn't have a weapon" << std::endl;
}

void HumanB::setWeapon( Weapon& weapon ) {
    _weapon = &weapon;
}
