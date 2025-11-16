#pragma once

#include "Weapon.hpp"

class HumanA {
    private:
        Weapon& _weapon;
        std::string _name;

    public:
        HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon) {};
        ~HumanA ( void ) {};
        void attack( void );
};
