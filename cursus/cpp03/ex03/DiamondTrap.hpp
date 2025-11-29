#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string _name;
    
    public:
        DiamondTrap( std::string name );
        DiamondTrap( const DiamondTrap& oldObj );
        ~DiamondTrap( void );
        DiamondTrap& operator=( const DiamondTrap& oldObj );
        

};
