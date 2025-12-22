#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : _name("Default"), ClapTrap("Default_clap_name") {
    std::cout << "Diamond default contructor called!" << std::endl;
	DiamondTrap::setHitPoints(DiamondTrap::initHitPoints);
	DiamondTrap::setEnergyPoints(DiamondTrap::initEnergyPoints);
	DiamondTrap::setAttackDamage(DiamondTrap::initAttackDamage);
}

DiamondTrap::DiamondTrap( std::string name) : _name(name), ClapTrap(name + "_clap_name") {
    std::cout << "Diamond contructor called!" << std::endl;
	DiamondTrap::setHitPoints(DiamondTrap::initHitPoints);
	DiamondTrap::setEnergyPoints(DiamondTrap::initEnergyPoints);
	DiamondTrap::setAttackDamage(DiamondTrap::initAttackDamage);
}

DiamondTrap::DiamondTrap( const DiamondTrap& oldObj ) :
    _name(oldObj.DiamondTrap::_name), ClapTrap(oldObj.ClapTrap::getName()) {
    std::cout << "Diamond copy contructor called!" << std::endl;
	setHitPoints(oldObj.getHitPoints());
	setEnergyPoints(oldObj.getEnergyPoints());
	setAttackDamage(oldObj.getAttackDamage());
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& oldObj ) {
    std::cout << "Diamond copy operator called!" << std::endl;
	setName(oldObj.DiamondTrap::getName());
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
	if (DEBUG) std::cout << "DiamondTrap::attack()" << std::endl;
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void ) {
	if (DEBUG) std::cout << "DiamondTrap::whoAmI()" << std::endl;
	std::cout << "Name: " << DiamondTrap::getName() << std::endl;
	std::cout << "Clap name: " << ClapTrap::getName() << std::endl;
}

const std::string& DiamondTrap::getName( void ) const {
	return (_name);
}

std::ostream& operator<<(std::ostream &out, const DiamondTrap &obj) {
	out << "DiamondTrap: " << obj.getName() << std::endl 
		<< "    Clap name    : " << obj.ClapTrap::getName() << std::endl
		<< "    Attack Damage: " << obj.getAttackDamage() << std::endl 
		<< "    Hit Points   : " << obj.getHitPoints() << std::endl 
		<< "    energy points: " << obj.getEnergyPoints() << std::endl;
	return out;
}
