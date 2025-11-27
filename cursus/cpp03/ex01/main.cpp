#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
    ScavTrap p1("player_1");
    ScavTrap p2("player_2");
    ScavTrap p3 = p1;
    ScavTrap p4("");
    p4 = p1;

    p1.attack(p2.getName());
    p2.takeDamage(p1.getAttackDamage());

    p2.beRepaired(1);

    p2.attack(p1.getName());
    p1.takeDamage(p2.getAttackDamage());

    std::cout << p1;
    std::cout << p2;
    return (0);
}