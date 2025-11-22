#include <iostream>

std::string toUpperCase(const std::string& str) {
    std::string result = str;

    for (char& c : result) {
        c = std::toupper(c);
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
        }
    }
    std::cout << str << std::endl;
    return (0);
}
