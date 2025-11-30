#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap ( std::string name ) {
    std::cout << "ClapTrap constructor called\n";
    _name = name;
}

ClapTrap::ClapTrap ( const ClapTrap& oldObj ) : _name(oldObj.getName()) {
    std::cout << "ClapTrap copy Constructor called\n";
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other ) {
    std::cout << "ClapTrap copy assignment operator Constructor called\n";
    if (this != &other) {
        setName(other.getName());
        setAttackDamage(other.getAttackDamage());
        setHitPoints(other.getHitPoints());
        setEnergyPoints(other.getEnergyPoints());
    }
    return (*this);
}

ClapTrap::~ClapTrap( void ) {
    std::cout << "ClapTrap destructor called!\n";
}

// ClapTrap <name> attacks <target>, causing <damage> points of damage!

void ClapTrap::attack( const std::string& target ) {
    std::cout << "ClapTrap::attack()" << std::endl;
    if (_enegryPoints <= 0)
        return ;
    std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
    _enegryPoints--;
}

void ClapTrap::takeDamage( unsigned int amount ) {
    std::cout << "ClapTrap::takeDamage()" << std::endl;
    if (amount > _hitPoints)
        return ;
    std::cout << "ClapTrap " << getName() << " has taken " << amount << " points of damage!\n";
    _hitPoints -= amount;
}

void ClapTrap::beRepaired( unsigned int amount ) {
    std::cout << "ClapTrap::beRepaired()" << std::endl;
    if (_enegryPoints <= 0 && _hitPoints > 0)
        return ;
    std::cout << "ClapTrap " << getName() << " has restored " << amount << " hit point\n";
    _hitPoints += amount;
    _enegryPoints--;
}

/**
 * const string& function() const {}
 * const 1: the string cant be modified using the returned referecnce
 * const 2: the method (function()) is not allowed to change anything 
 */

const std::string& ClapTrap::getName( void ) const {
    std::cout << "ClapTrap::getName()" << std::endl;
    return (_name);
}

void ClapTrap::setName( std::string name ) {
    std::cout << "ClapTrap::setName()" << std::endl;
    _name = name;
}

void ClapTrap::setAttackDamage( unsigned int amount ) {
    std::cout << "ClapTrap::setAttackDamage()" << std::endl;
    _attackDamage = amount;
}

unsigned int ClapTrap::getAttackDamage( void ) const {
    std::cout << "ClapTrap::getAttackDamage()" << std::endl;
    return (_attackDamage);
}

void ClapTrap::setHitPoints( unsigned int amount ) {
    std::cout << "ClapTrap::setHitPoints()" << std::endl;
    _hitPoints = amount;
}

unsigned int ClapTrap::getHitPoints( void ) const {
    std::cout << "ClapTrap::getHitPoints()" << std::endl;
    return (_hitPoints);
}

void ClapTrap::setEnergyPoints( unsigned int amount ) {
    std::cout << "ClapTrap::setEnergyPoints()" << std::endl;
    _enegryPoints = amount;
}

unsigned int ClapTrap::getEnergyPoints( void ) const {
    std::cout << "ClapTrap::getEnergyPoints()" << std::endl;
    return (_enegryPoints);
}

std::ostream& operator<<(std::ostream &out, const ClapTrap &obj) {
    out << "ClapTrap: " << obj.getName() << std::endl 
        << "    Attack Damage: " << obj.getAttackDamage() << std::endl 
        << "    Hit Points   : " << obj.getHitPoints() << std::endl 
        << "    energy points: " << obj.getEnergyPoints() << std::endl;
    return out;
}