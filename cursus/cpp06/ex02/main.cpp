#include "identify.hpp"

#define ARRAY_SIZE 10

int main()
{
    std::srand(std::time(0));

    Base *arr[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = generate();
    
    for (int i = 0; i < ARRAY_SIZE; i++)
        identify(arr[i]);

    Base &ref = *arr[0];
    Base b = Base();
    Base &ref2 = b;

    identify(&b);
    identify(ref);
    identify(ref2);

}
