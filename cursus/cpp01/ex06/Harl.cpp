#include "Harl.hpp"
#include "Harl.h"

const char* const Harl::DEBUG = DDEBUG_MSG;
const char* const Harl::INFO = DINFO_MSG;
const char* const Harl::WARNING = DWARNING_MSG;
const char* const Harl::ERROR = DERROR_MSG;

// Harl::Harl( std::string level ) {
//     setFilter(level);
// }

void Harl::debug( void ) {
    std::cout << Harl::DEBUG << std::endl;
}

void Harl::info( void ) {
    std::cout << Harl::INFO << std::endl;
}

void Harl::warning( void ) {
    std::cout << Harl::WARNING << std::endl;
}

void Harl::error( void ) {
    std::cout << Harl::ERROR << std::endl;
}

void Harl::setFilter( std::string level ) {
    std::string levels[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    _filter = -1;
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level)
            _filter = i;
    }
}

void Harl::complain( std::string level ) {
    t_pair pairs[4] = {
        {"DEBUG", &Harl::debug},
        {"INFO", &Harl::info},
        {"WARNING", &Harl::warning},
        {"ERROR", &Harl::error}
    };

    for (int i = _filter; i < 4; i++) {
        if (pairs[i].level == level) {
            (this->*pairs[i].function)();
            return ;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]\n";

}