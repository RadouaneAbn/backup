#include "Cure.hpp"
Cure::Cure( void ): AMateria("cure") {
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure( const Cure & oldObj ): AMateria(oldObj._type) {
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure & Cure::operator=( const Cure & oldObj ) {
    std::cout << "Cure assignment operator called" << std::endl;
    if (this != &oldObj) {
        _type = oldObj._type;
    }
    return *this;
}

Cure::~Cure( void ) {
    std::cout << "Cure destructor called" << std::endl;
}

Cure* Cure::clone() const {
    Cure *cure = new Cure();
    cure->setType(_type);
    return (cure);
}

void Cure::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}