#include "zombie.h"

#define ZOMBIE_COUNT 10

int main( void ) {
    Zombie *zombieHordeList = zombieHorde(ZOMBIE_COUNT, "jeff");

    if (zombieHordeList == nullptr) {
        std::cerr << "nullptr" << std::endl;
        return (1);
    }
    for (int i = 0; i < ZOMBIE_COUNT; i++) {
        zombieHordeList[i].announce();
    }

    delete[] zombieHordeList;
}