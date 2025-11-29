#pragma once

#include <string>

class ClapTrap {
    private:
        std::string _name;
        unsigned int _hitPoints = 10;
        unsigned int _enegryPoints = 10;
        unsigned int _attackDamage = 0;

    public:

        ClapTrap ( std::string name ); 
        ClapTrap( const ClapTrap& oldObj );
        ClapTrap& operator= (const ClapTrap& other);
        ~ClapTrap( void );

        const std::string& getName( void ) const;
        void setName( std::string name );
        void setAttackDamage( unsigned int amount );
        unsigned int getAttackDamage( void ) const;
        void setHitPoints( unsigned int amount );
        unsigned int getHitPoints( void ) const;
        void setEnergyPoints( unsigned int amount );
        unsigned int getEnergyPoints( void ) const;

        void attack( const std::string& target );
        void takeDamage( unsigned int amount );
        void beRepaired( unsigned int amount );

        friend std::ostream& operator<<(std::ostream &out, const ClapTrap &obj);
};