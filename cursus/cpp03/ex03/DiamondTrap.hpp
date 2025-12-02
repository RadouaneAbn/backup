#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string _name;

    protected:
        static const int initHitPoints = FragTrap::initHitPoints;
        static const int initEnergyPoints = ScavTrap::initEnergyPoints;
        static const int initAttackDamage = FragTrap::initAttackDamage;
    
    public:
        DiamondTrap( void );
        DiamondTrap( std::string name );
        DiamondTrap( const DiamondTrap& oldObj );
        ~DiamondTrap( void );
        DiamondTrap& operator=( const DiamondTrap& oldObj );
        
        void whoAmI( void );
        void attack( const std::string& target );

        const std::string &getName( void ) const;
        // int getEnergyPoints( void );
};

std::ostream& operator<<(std::ostream &out, const DiamondTrap &obj);