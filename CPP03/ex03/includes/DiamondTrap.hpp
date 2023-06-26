#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & src);
		~DiamondTrap();
		DiamondTrap &operator=( DiamondTrap const &rhs);
	private:
		std::string	name;
};

std::ostream &operator<<( std::ostream &output, DiamondTrap const &instance_diamond_trap);

#endif /* ***************************************************** DIAMONDTRAP_H */