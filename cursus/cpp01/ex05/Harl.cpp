#include "Harl.hpp"
#include "Harl.h"

const char* const Harl::DEBUG = DEBUG_MSG;
const char* const Harl::INFO = INFO_MSG;
const char* const Harl::WARNING = WARNING_MSG;
const char* const Harl::ERROR = ERROR_MSG;

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

void Harl::complain( std::string level ) {
    t_pair pairs[4] = {
        {"DEBUG", &Harl::debug},
        {"INFO", &Harl::info},
        {"WARNING", &Harl::warning},
        {"ERROR", &Harl::error}
    };

    for (t_pair pair : pairs) {
        if (pair.level == level) {
            (this->*pair.function)();
        }
    }
}