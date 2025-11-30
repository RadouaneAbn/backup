#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {
    std::cout << "--- DiamondTrap tests start ---" << std::endl;

    // DiamondTrap d_default;
    // d_default.whoAmI();
    DiamondTrap d1("DiamondOne");
    d1.whoAmI();
    // d1.attack("TargetA");
    // d1.takeDamage(30);
    // d1.beRepaired(15);
    // d1.highFivesGuys();
    // d1.guardGate();

    // DiamondTrap d2(d1);
    // d2.whoAmI();
    // DiamondTrap d3("Temp");
    // d3.whoAmI();
    // d3 = d1;
    // d3.whoAmI();

    // std::cout << "\n7) WhoAmI on originals after changes" << std::endl;
    // d1.whoAmI();
    // d2.whoAmI();
    // d3.whoAmI();

    // std::cout << "\n--- DiamondTrap tests end ---" << std::endl;
    return 0;
}