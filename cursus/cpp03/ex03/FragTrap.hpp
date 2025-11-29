#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: public ClapTrap {

    public:
        FragTrap( std::string name);
        FragTrap( const FragTrap& oldObj );
        FragTrap& operator= (const FragTrap& other);
        ~FragTrap ( void );

        void attack( const std::string& target );

        void highFivesGuys( void );
        friend std::ostream& operator<<(std::ostream &out, const FragTrap &obj);
};