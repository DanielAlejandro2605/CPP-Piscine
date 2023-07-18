/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:21:24 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/03 16:41:21 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "../includes/ClapTrap.hpp"
class FragTrap : public ClapTrap
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
