#include "zombie.h"

void randomChump( std::string name ) {
    Zombie new_zombie = Zombie(name);

    new_zombie.announce();
}