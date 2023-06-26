#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "../includes/ClapTrap.hpp"
class FragTrap : public virtual ClapTrap
{
	public:
		/*Orthodox Canonical Form*/
		FragTrap();
		FragTrap(std::string _name);
		FragTrap(const FragTrap &original);
		~FragTrap();
		/*Member functions*/
		void	highFivesGuys(void);
};

std::ostream &			operator<<(std::ostream &output, FragTrap const &instance_frag_trap);

#endif /* ******************************************************** FRAGTRAP_H */