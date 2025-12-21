#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure: public AMateria {
	public:
		Cure( void );
		Cure( const Cure & oldObj );
		Cure & operator=( const Cure & oldObj );
		~Cure( void );
		Cure *clone() const;
		void use(ICharacter& target);
};

#endif
