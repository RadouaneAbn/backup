#include "Dog.hpp"

Dog::Dog( void ) {
    std::cout << "> Dog default constructor\n";
    _type = "Dog";
    brain = new Brain();
}

Dog::~Dog( void ) {
    std::cout << "> Dog destructor constructor\n";
    delete brain;
    brain = NULL;
}

Dog::Dog( const Dog &old_obj): Animal() {
    std::cout << "> Dog copy constructor\n";
    _type = old_obj._type;
    brain = new Brain(*old_obj.brain);
}

Dog &Dog::operator=( const Dog &old_obj ) {
    std::cout << "> Dog copy operator overload\n";
    if (this != &old_obj) {
        _type = old_obj._type;
        if (brain != NULL)
            delete brain;
        brain = new Brain(*old_obj.brain);
    }
    return (*this);
}

void Dog::makeSound( void) const {
    std::cout << "Bark, bark!!!" << std::endl;
}

const std::string Dog::getIdea( int i ) const {
    return (brain->getIdea(i));
}

void Dog::setIdea( std::string idea, int i ) {
    brain->setIdea(idea, i);
}

bool Dog::hasIdeas( void ) {
    return (brain != NULL);
}
