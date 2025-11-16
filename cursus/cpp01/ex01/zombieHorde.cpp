#include "zombie.h"
#include <vector>
#include <new>

Zombie* zombieHorde( int N, std::string name ) {
    Zombie *zombieHordeArr = new (std::nothrow) Zombie[N];

    if (zombieHorde == nullptr)
        return (nullptr);
    for (int i = 0; i < N; i++) {
        zombieHordeArr[i].setName(name);
    }
    return (zombieHordeArr);
}