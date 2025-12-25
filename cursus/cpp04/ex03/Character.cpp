#include "Character.hpp"
#include "debug.h"

Character::Character(void)
{
    if (DEBUGING) std::cout << "Character default constructor called" << std::endl;
    _availableInventory = 4;
    for (int i = 0; i < _availableInventory; i++)
        _inventory[i] = NULL;
}

Character::Character( const std::string &name)
{
    if (DEBUGING) std::cout << "Character parametrized constructor called" << std::endl;
    _name = name;
    _availableInventory = 4;
    for (int i = 0; i < _availableInventory; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character &oldObj)
{
    if (DEBUGING) std::cout << "Character copy constructor called" << std::endl;
    _name = oldObj._name;
    _availableInventory = oldObj._availableInventory;
    for (int i = 0; i < 4; i++)
        _inventory[i] = oldObj._inventory[i];
}

Character &Character::operator=(const Character &oldObj)
{
    if (DEBUGING) std::cout << "Character assignment operator called" << std::endl;
    if (this != &oldObj)
    {
        _name = oldObj._name;
        // for (int i = 0; i < _availableInventory; i++)
        //     delete _inventory[i];
        _availableInventory = oldObj._availableInventory;
        for (int i = 0; i < 4; i++)
            _inventory[i] = oldObj._inventory[i];
    }
    return *this;
}

Character::~Character(void)
{
    if (DEBUGING) std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] != NULL)
            delete _inventory[i];
    }
}

std::string const &Character::getName(void) const
{
    return (_name);
}

void Character::equip(AMateria *m)
{
    if (_availableInventory > 0)
    {
        _inventory[4 - _availableInventory] = m;
        _availableInventory--;
    }
}

void Character::unequip(int idx)
{
    if (idx >= 4 - _availableInventory)
        return ;
    _inventory[idx] = NULL;
    _availableInventory++;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 4 - _availableInventory)
        return ;
    _inventory[idx]->use(target);
}
