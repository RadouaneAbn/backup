#pragma once

#include "Weapon.hpp"

class HumanB {
    private:
        Weapon* _weapon;
        std::string _name;

    public:
        HumanB( std::string name ) : _name(name), _weapon(nullptr) {};
        HumanB( std::string name, Weapon weapon ) : _name(name), _weapon(&weapon) {};
        ~HumanB ( void ) {};
        void attack( void );
        void setWeapon( Weapon& weapon);
};
