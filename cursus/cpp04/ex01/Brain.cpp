#include "Brain.hpp"

Brain::Brain( void ) {}

Brain::~Brain( void ) {}

Brain::Brain( const Brain &oldObj ) {
    for (int i = 0; i < 100; i++) {
        ideas[i] = oldObj.ideas[i];
    }
}

Brain &Brain::operator=( const Brain &oldObj ) {
    if (this != &oldObj) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = oldObj.ideas[i];
        }
    }
    return (*this);
}

const std::string Brain::getIdea( int i ) const {
    if (i < 0 || i >= 100)
        return ("");
    return (ideas[i]);
}

void Brain::setIdea( std::string idea, int i ) {
    if (i < 0 || i >= 100)
        return ;
    ideas[i] = idea;
}

void Brain::ideaAddr( void ) {
    std::cout << "Idea Addr: " << &ideas << std::endl;
}
