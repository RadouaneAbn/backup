#include "zombie.h"

int main( void ) {
    Zombie *zombie1 = newZombie("H-Zombie");
    Zombie zombie2 = Zombie("S-Zombie");

    zombie1->announce();
    zombie2.announce();

    randomChump("T-Champ");

    delete zombie1;
}