#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *_inventory[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &oldObj);
		MateriaSource &operator=(const MateriaSource &oldObj);
		~MateriaSource();

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif
