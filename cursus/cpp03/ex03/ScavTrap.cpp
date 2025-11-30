#include "ScavTrap.hpp"

ScavTrap::ScavTrap ( void ) : ClapTrap("Default") {
    std::cout << "ScavTrap Default constructor called\n";
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap ( std::string name ) : ClapTrap(name) {
    std::cout << "ScavTrap constructor called\n";
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::~ScavTrap ( void ) {
    std::cout << "ScavTrap destructor called!\n";
}

ScavTrap::ScavTrap ( const ScavTrap& oldObj ) : ClapTrap(oldObj.getName()) {
    std::cout << "ScavTrap copy Constructor called\n";
    setName(oldObj.getName());
    setHitPoints(oldObj.getHitPoints());
    setEnergyPoints(oldObj.getEnergyPoints());
    setAttackDamage(oldObj.getAttackDamage());
}

ScavTrap& ScavTrap::operator= ( const ScavTrap& oldObj) {
    std::cout << "ScavTrap copy assignment operator Constructor called\n";
    if (this != &oldObj) {
        setName(oldObj.getName());
        setHitPoints(oldObj.getHitPoints());
        setEnergyPoints(oldObj.getEnergyPoints());
        setAttackDamage(oldObj.getAttackDamage());
    }
    return (*this);
}

void ScavTrap::guardGate( void ) {
    std::cout << "ScavTrap::guardGate()" << std::endl;
    std::cout << "ScavTrap " << getName() << " is in gate keeper mode\n";
}

void ScavTrap::attack( const std::string& target ) {
    std::cout << "ScavTrap::attack()" << std::endl;
    if (getEnergyPoints() <= 0)
        return ;
    std::cout << "ScavTrap " << getName() << " attacks " << target
        << ", causing " << getAttackDamage() << " points of damage!\n";
    setEnergyPoints(getEnergyPoints() - 1);
}

std::ostream& operator<<(std::ostream &out, const ScavTrap &obj) {
    out << "ScavTrap: " << obj.getName() << std::endl 
        << "    Attack Damage: " << obj.getAttackDamage() << std::endl 
        << "    Hit Points   : " << obj.getHitPoints() << std::endl 
        << "    energy points: " << obj.getEnergyPoints() << std::endl;
    return out;
}
