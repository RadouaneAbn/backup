#include "Array.hpp"

int main()
{
    Array<int> arr(15);

    for (unsigned int i = 0; i < 7; i++)
        arr[i] = i;
    
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << "arr[" << i << "]: " << arr[i] << std::endl;

    Array<std::string> strArr(11);

    for (unsigned int i = 0; i < 5; i++)
        strArr[i] = "String " + std::string(1, 'a' + i);

    for (unsigned int i = 0; i < strArr.size(); i++)
        std::cout << "strArr[" << i << "]: " << strArr[i] << std::endl;

    return 0;
}