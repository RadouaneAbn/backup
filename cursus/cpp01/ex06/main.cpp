#include "Harl.hpp"

int main(int ac, char *av[]) {
    std::string level;
    Harl harl;

    if (ac != 2)
        return (1);
    level = av[1];
    harl.complain(level);
    return (0);
}