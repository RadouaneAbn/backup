#include <iostream>

std::string toUpperCase(const std::string& str) {
    std::string result = str;

    for (int i = 0; str[i]; i++) {
        result[i] = std::toupper(str[i]);
    }
    return (result);
}

int main (int ac, char* av[]) {
    std::string str;

    if (ac == 1) {
        str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    } else {
        for (int i = 1; i < ac; i++) {
            str.append(toUpperCase(av[i]));
            if (i < ac - 1)
                str.append(" ");
        }
    }
    std::cout << str << std::endl;
    return (0);
}
