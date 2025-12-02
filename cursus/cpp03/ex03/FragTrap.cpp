#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap("Default") {
	std::cout << "FragTrap default constructor called\n";
	setHitPoints(FragTrap::initHitPoints);
	setEnergyPoints(FragTrap::initEnergyPoints);
	setAttackDamage(FragTrap::initAttackDamage);

}

FragTrap::FragTrap ( std::string name ) : ClapTrap(name) {
	std::cout << "FragTrap constructor called\n";
	setHitPoints(FragTrap::initHitPoints);
	setEnergyPoints(FragTrap::initEnergyPoints);
	setAttackDamage(FragTrap::initAttackDamage);
}

FragTrap::~FragTrap ( void ) {
	std::cout << "FragTrap destructor called!\n";
}

FragTrap::FragTrap ( const FragTrap& oldObj ) : ClapTrap(oldObj.getName()) {
	std::cout << "FragTrap copy Constructor called\n";
	setName(oldObj.getName());
	setHitPoints(oldObj.getHitPoints());
	setEnergyPoints(oldObj.getEnergyPoints());
	setAttackDamage(oldObj.getAttackDamage());
}

FragTrap& FragTrap::operator= ( const FragTrap& oldObj) {
	std::cout << "FragTrap copy assignment operator Constructor called\n";
	if (this != &oldObj) {
		setName(oldObj.getName());
		setHitPoints(oldObj.getHitPoints());
		setEnergyPoints(oldObj.getEnergyPoints());
		setAttackDamage(oldObj.getAttackDamage());
	}
	return (*this);
}

void FragTrap::highFivesGuys( void ) {
	if (DEBUG) std::cout << "FragTrap::highFivesGuys()" << std::endl;
	std::cout << "FragTrap: " << getName() << " says 'wanna high five guys'\n";
}

void FragTrap::attack( const std::string& target ) {
	if (DEBUG) std::cout << "FragTrap::attack()" << std::endl;
	if (getEnergyPoints() <= 0)
		return ;
	std::cout << "FragTrap " << getName() << " attacks " << target
		<< ", causing " << getAttackDamage() << " points of damage!\n";
	setEnergyPoints(getEnergyPoints() - 1);
}

std::ostream& operator<<(std::ostream &out, const FragTrap &obj) {
	out << "FragTrap: " << obj.getName() << std::endl 
		<< "    Attack Damage: " << obj.getAttackDamage() << std::endl 
		<< "    Hit Points   : " << obj.getHitPoints() << std::endl 
		<< "    energy points: " << obj.getEnergyPoints() << std::endl;
	return out;
}
