#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice: public AMateria {
	public:
		Ice( void );
		Ice( const Ice & oldObj );
		Ice & operator=( const Ice & oldObj );
		~Ice( void );
		Ice *clone() const;
		void use(ICharacter& target);
};

#endif
