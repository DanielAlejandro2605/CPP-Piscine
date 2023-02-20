#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name_of_zombie)
{
    this->_name.assign(name_of_zombie);
}

Zombie::~Zombie()
{
    std::cout << "Now, executing the destructor of " << this->_name << "\n";
}

void Zombie::announce(void)
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ..\n";
}
