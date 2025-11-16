#include "Harl.hpp"

int main(int ac, char *av[]) {
    int i = 0;
    std::string testStrings[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    std::string level;
    Harl harl;

    if (ac != 2)
        return (1);

    level = av[1];

    harl.setFilter(level);

    for (std::string str: testStrings) {
        harl.complain(str);
    }
}