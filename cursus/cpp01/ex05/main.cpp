#include "Harl.hpp"

int main(int ac, char *av[]) {
    int i = 0;
    std::string level;
    Harl harl;

    while (++i < ac) {
        level = av[i];
        harl.complain(level);
    }
}