#include "zombie.h"

int main( void ) {
    Zombie *zombie1 = newZombie("H-Zombie");
    Zombie zombie2 = Zombie("S-Zombie");

    if (zombie1 == NULL)
        return (1);
    zombie1->announce();
    zombie2.announce();

    randomChump("T-Champ");

    delete zombie1;
    return (0);
}