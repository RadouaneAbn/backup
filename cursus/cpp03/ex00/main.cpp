#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
    ClapTrap p1("player_1");
    ClapTrap p2("player_2");
    ClapTrap p3 = p1;
    ClapTrap p4("");
    p4 = p1;

    p1.setAttackDamage(3);
    p2.setAttackDamage(5);

    p1.attack(p2.getName());
    p2.takeDamage(p1.getAttackDamage());

    p2.beRepaired(1);

    p2.attack(p1.getName());
    p1.takeDamage(p2.getAttackDamage());

    std::cout << p1;
    std::cout << p2;

    return (0);
}