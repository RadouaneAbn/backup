#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    try {
        std::vector<int>::iterator value = easyfind(vec, 5);
        std::cout << "Found: " << *value << std::endl;
        
        value = easyfind(vec, 15);
        std::cout << "Found: " << *value << std::endl;
    } catch (const ElementNotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}