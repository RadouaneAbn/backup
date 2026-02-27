#include "identify.hpp"

Base *generate(void)
{
    switch (std::rand() % 3)
    {
    case 0:
        if (DEBUG) std::cout << "creating A()\n";
        return new A();
    case 1:
        if (DEBUG) std::cout << "creating B()\n";
        return new B();
    case 2:
        if (DEBUG) std::cout << "creating C()\n";
        return new C();
    }
    return (NULL);
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Not a known type *" << std::endl;
}

void identify(Base &p)
{
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch (std::exception &) {}

    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch (std::exception &) {}

    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception &) {}

    std::cout << "Not a known type &" << std::endl;
}