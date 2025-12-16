#include <iostream>
using namespace std;
int main(void)
{
    std::string var;
    // getline(std::cin, var);
    // if (std::cin.eof())
    // {
    //     std::cout << "hey got eof";
    //     std::cin.clear();
    //     std::cin >> var;
    //     std::cin.clear();
    //     if (std::cin.eof())
    //         printf("something\n");
    //     else
    //         std::cout << "hey something\n";
    // }
std::cout << "[ADD], [SEARCH], [EXIT]>> ";
    std::getline(std::cin ,var);
    if (std::cin.eof())
        printf("something");
    return (0);
}