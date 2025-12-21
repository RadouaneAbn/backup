#include "Character.hpp"
Character::Character(void)
{
    _availableInventory = 4;
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character &oldObj)
    : _availableInventory(oldObj._availableInventory)
{
    std::cout << "Character copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &oldObj)
{
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &oldObj)
    {
        _availableInventory = oldObj._availableInventory;
    }
    return *this;
}

Character::~Character(void)
{
    std::cout << "Character destructor called" << std::endl;
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
}