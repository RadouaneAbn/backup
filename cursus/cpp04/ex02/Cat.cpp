#include "Cat.hpp"

Cat::Cat( void ) {
    std::cout << "> Cat default constructor\n";
    _type = "Cat";
    brain = new Brain();
}

Cat::~Cat( void ) {
    std::cout << "> Cat destructor constructor\n";
    delete brain;
    brain = NULL;
}

Cat::Cat( const Cat &old_obj): Animal() {
    std::cout << "> Cat copy constructor\n";
    _type = old_obj._type;
    brain = new Brain(*old_obj.brain);
}

Cat &Cat::operator=( const Cat &old_obj ) {
    std::cout << "> Cat copy operator overload\n";
    if (this != &old_obj) {
        _type = old_obj._type;
        if (brain != NULL)
            delete brain;
        brain = new Brain(*old_obj.brain);
    }
    return (*this);
}

void Cat::makeSound( void) const {
    std::cout << "Meow" << std::endl;
}

const std::string Cat::getIdea( int i ) const {
    return (brain->getIdea(i));
}

void Cat::setIdea( std::string idea, int i ) {
    brain->setIdea(idea, i);
}

bool Cat::hasIdeas( void ) {
    return (brain != NULL);
}

void Cat::brainAddr( void ) {
    std::cout << "Brain Addr: " << &brain << std::endl;
    brain->ideaAddr();
}