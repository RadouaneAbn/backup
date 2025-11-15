#include "zombie.h"
#include <new>

Zombie* newZombie( std::string name ) {
    Zombie *newZombie = new (std::nothrow) Zombie(name);
    return (newZombie);
}