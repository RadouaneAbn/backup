#include "FragTrap.hpp"
#include <iostream>

int main(void) {
    FragTrap p1("player_1");
    FragTrap p2("player_2");
    FragTrap p3 = p1;
    FragTrap p4("");
    p4 = p1;

    p1.attack(p2.getName());
    p2.takeDamage(p1.getAttackDamage());

    p2.beRepaired(1);

    p2.attack(p1.getName());
    p1.takeDamage(p2.getAttackDamage());

    std::cout << p1;
    std::cout << p2;

    p1.highFivesGuys();
    p2.highFivesGuys();
    return (0);
}