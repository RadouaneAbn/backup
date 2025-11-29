#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap: public ClapTrap {

    public:
        ScavTrap( std::string name);
        ScavTrap( const ScavTrap& oldObj );
        ScavTrap& operator= (const ScavTrap& other);
        ~ScavTrap ( void );

        void attack( const std::string& target );

        void guardGate( void );
        friend std::ostream& operator<<(std::ostream &out, const ScavTrap &obj);
};