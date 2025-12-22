#include "Cat.hpp"
#include "Dog.hpp"

#define ANIMAL_COUNT 4

void test_shallow_copy( void ) {
    Cat *cat1 = new Cat();
    Cat *cat2;

    cat1->setIdea("here i am", 0);

    std::cout << "cat1 first idea: " << cat1->getIdea(0) << std::endl;
    
    cat2 = new Cat(*cat1);

    std::cout << "cat2 first idea: " << cat2->getIdea(0) << std::endl;

    cat1->brainAddr();
    cat2->brainAddr();

    // delete cat1;

    std::cout << "deleting cat1" << std::endl;

    // if (cat2->hasIdeas()) {
    //     std::cout << "cat2 first idea: " << cat2->getIdea(0) << std::endl;
    // } else {
    //     std::cout << "cat2 lost his brain" << std::endl;
    // }
}

int main() {
    Animal **all = new Animal*[ANIMAL_COUNT];

    for (int i = 0; i < ANIMAL_COUNT / 2; i++) {
        all[i] = new Cat();
    }

    for (int i = ANIMAL_COUNT / 2; i < ANIMAL_COUNT; i++) {
        all[i] = new Dog();
    }

    std::cout << "calling makeSound for all Animal objects\n";
    for (int i = 0; i < ANIMAL_COUNT; i++) {
        all[i]->makeSound();
    }
    
    std::cout << "deleting Animal objects\n";
    for (int i = 0; i < ANIMAL_COUNT; i++) {
        delete all[i];
    }

    delete[] all;

    // test_shallow_copy();

    return (0);
}