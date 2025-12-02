#include "DiamondTrap.hpp"
#include <iostream>


int	main(void)
{
	ClapTrap	trapA("Hugo");
	ScavTrap	trapB("Tom");
	FragTrap	trapC("Paul");
    DiamondTrap	trapD("Diamond1");
    
    // trapD.takeDamage(50);
    // std::cout << trapD << std::endl;
    // trapD.beRepaired(10);

    // std::cout << trapD << std::endl;

	trapD.attack("everyone!");
	trapD.whoAmI();
	trapD.highFivesGuys();
	trapD.guardGate();
	
	trapC.highFivesGuys();
	trapC.attack(trapD.getName());
	
	trapD.guardGate();
	trapD.attack(trapC.getName());
	trapB.takeDamage(20);
	trapA.attack(trapB.getName());
	trapB.takeDamage(2);
	trapB.attack(trapC.getName());
	trapC.takeDamage(7);
	trapC.attack(trapA.getName());
	trapA.takeDamage(5);
	trapA.beRepaired(3);
	trapB.attack(trapA.getName());
	trapA.takeDamage(2);
	trapC.attack(trapB.getName());
	trapA.attack(trapB.getName());
	trapB.takeDamage(2);
	trapB.attack(trapC.getName());
	trapC.takeDamage(7);
	trapC.attack(trapA.getName());
	trapA.takeDamage(5);
	trapA.beRepaired(3);
	trapB.attack(trapA.getName());
	trapA.takeDamage(2);
	trapC.attack(trapB.getName());
	trapC.beRepaired(5);
	trapA.beRepaired(3);
	trapB.beRepaired(3);
	trapD.beRepaired(6);

    std::cout << trapA << std::endl;
    std::cout << trapB << std::endl;
    std::cout << trapC << std::endl;
    std::cout << trapD << std::endl;

	return (0);
}