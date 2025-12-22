#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>

class Ice {
	public:
		Ice( void );
		Ice( const Ice & oldObj );
		Ice & operator=( const Ice & oldObj );
		~Ice( void );
};

#endif
