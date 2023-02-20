#include "../includes/Zombie.hpp"

int main(void)
{
    Zombie *zombie_heap1 = newZombie("Daniel");
    Zombie *zombie_heap2 = newZombie("Louis");
    Zombie *zombie_heap3 = newZombie("Lisa");


    zombie_heap1->announce();
    zombie_heap2->announce();
    zombie_heap3->announce();

    randomChump("Nicolas");
    randomChump("Germancho");
    randomChump("Alix");
    
    delete zombie_heap1;
    delete zombie_heap2;
    delete zombie_heap3;
    return(0);
}