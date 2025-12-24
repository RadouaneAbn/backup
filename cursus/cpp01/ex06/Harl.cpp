#include "Harl.hpp"
#include "Harl.h"

Harl::Harl(void) {}

void Harl::debug( void ) {
	std::cout << DDEBUG_MSG << std::endl;
}

void Harl::info( void ) {
	std::cout << DINFO_MSG << std::endl;
}

void Harl::warning( void ) {
	std::cout << DWARNING_MSG << std::endl;
}

void Harl::error( void ) {
	std::cout << DERROR_MSG << std::endl;
}

int getLevel(std::string &level) {
	if (level == "DEBUG")
		return (DEBUG);
	if (level == "INFO")
		return (INFO);
	if (level == "WARNING")
		return (WARNING);
	if (level == "ERROR")
		return (ERROR);
	return (-1);
}

void Harl::complain( std::string level ) {
	int wanted_level = getLevel(level);
	switch (wanted_level)
	{
	case DEBUG:
		Harl::debug();
	case INFO:
		Harl::info();
	case WARNING:
		Harl::warning();
	case ERROR:
		Harl::error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	}
}

/*          L

	debug   0:   0   1   2   3
	info    1:   1   2   3
	warning 2:   2   3
	error   3:   3

	0: 0 1 2 3
*/