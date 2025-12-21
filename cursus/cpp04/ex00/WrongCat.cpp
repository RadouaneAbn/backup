#include "WrongCat.hpp"

WrongCat::WrongCat( void ) {
    _type = "WrongCat";
}

WrongCat::~WrongCat( void ) {
    std::cout << "but but but but cat\n";
}

WrongCat::WrongCat( const WrongCat &old_obj): WrongAnimal(old_obj) {
    // _type = old_obj._type;
}

WrongCat &WrongCat::operator=( const WrongCat &old_obj ) {
    if (this != &old_obj)
        _type = old_obj._type;
    return (*this);
}

void WrongCat::makeSound( void) const {
    std::cout << "Meow" << std::endl;
}
