#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character: public ICharacter {
	std::string _name;
	int _availableInventory;
	AMateria* _inventory[4];

	public:
		Character( void );
		Character( const std::string &name );
		Character( const Character & oldObj );
		Character & operator=( const Character & oldObj );
		~Character( void );

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
