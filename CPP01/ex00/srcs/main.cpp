#include "../includes/Zombie.hpp"

int main(void)
{
    std::cout << "From newZombie" << std::endl;
    Zombie *zombie_heap1 = newZombie("Daniel");
    Zombie *zombie_heap2 = newZombie("Louis");
    Zombie *zombie_heap3 = newZombie("Lisa");

    zombie_heap1->announce();
    zombie_heap2->announce();
    zombie_heap3->announce();

    std::cout << "\nFrom randomChump" << std::endl;
    randomChump("Nicolas");
    randomChump("Germancho");
    randomChump("Alix");
    std::cout << std::endl;

    std::cout << "\nFrom newZombie" << std::endl;
    delete zombie_heap1;
    delete zombie_heap2;
    delete zombie_heap3;
    return(0);
}