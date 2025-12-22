#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap: virtual public ClapTrap {

    protected:
        static const int initHitPoints = 100;
        static const int initEnergyPoints = 50;
        static const int initAttackDamage = 20;

    public:
        ScavTrap( void );
        ScavTrap( std::string name );
        ScavTrap( const ScavTrap& oldObj );
        ScavTrap& operator= (const ScavTrap& other);
        ~ScavTrap ( void );

        void attack( const std::string& target );

        void guardGate( void );
        friend std::ostream& operator<<(std::ostream &out, const ScavTrap &obj);
};