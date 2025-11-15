#include "Zombie.hpp"

Zombie::Zombie ( std::string name ) {
    _name = name;
    std::cout << _name << ": created!" << std::endl;
}

Zombie::~Zombie () {
    std::cout << _name << ": died!" << std::endl;
};

void Zombie::announce( void ) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}