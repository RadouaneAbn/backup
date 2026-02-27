#include "easyfind.hpp"
#include "ElementNotFoundException.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    for (typename T::iterator i = container.begin(); i != container.end(); i++)
    {
        if (*i == value)
            return (i);
    }
    throw ElementNotFoundException();
}
