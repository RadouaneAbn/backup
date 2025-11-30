#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : _name("Default"), ClapTrap("Default_clap_name") {
    std::cout << "Diamond default contructor called!" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name) : _name(name), ClapTrap(name.append("_clap_name")) {
    std::cout << "Diamond contructor called!" << std::endl;
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap( const DiamondTrap& oldObj ) :
    _name(oldObj.DiamondTrap::_name), ClapTrap(oldObj.getName()) {
    std::cout << "Diamond copy contructor called!" << std::endl;
	setName(oldObj.getName());
	setHitPoints(oldObj.getHitPoints());
	setEnergyPoints(oldObj.getEnergyPoints());
	setAttackDamage(oldObj.getAttackDamage());
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& oldObj ) {
    std::cout << "Diamond copy operator called!" << std::endl;
	setName(oldObj.getName());
    ClapTrap::setName(oldObj.ClapTrap::getName());
	setHitPoints(oldObj.getHitPoints());
	setEnergyPoints(oldObj.getEnergyPoints());
	setAttackDamage(oldObj.getAttackDamage());
	return (*this);
}

DiamondTrap::~DiamondTrap( void ) {
    std::cout << "DiamondTrap destructor called!" << std::endl;
}

void DiamondTrap::attack( const std::string& target ) {
	std::cout << "DiamondTrap::attack()" << std::endl;
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void ) {
	std::cout << "DiamondTrap::whoAmI()" << std::endl;
	std::cout << "Name: " << DiamondTrap::getName() << std::endl;
	std::cout << "Clap name: " << ClapTrap::getName() << std::endl;
}