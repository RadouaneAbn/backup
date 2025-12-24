#include "MateriaSource.hpp"
#include "debug.h"

MateriaSource::MateriaSource()
{
	if (DEBUGING) std::cout << "MateriaSource Default Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &oldObj)
{
	if (DEBUGING) std::cout << "MateriaSource Copy Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = oldObj._inventory[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &oldObj)
{
	if (DEBUGING) std::cout << "MateriaSource Copy Assignment Operator called" << std::endl;
	if (this != &oldObj)
	{
		for (int i = 0; i < 4; i++)
			_inventory[i] = oldObj._inventory[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	if (DEBUGING) std::cout << "MateriaSource Destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] != NULL)
            delete _inventory[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for(int i = 0; i < 4; i++) {
		if (_inventory[i] && type == _inventory[i]->getType())
			return (_inventory[i]->clone());
	}
	return (0);
}
