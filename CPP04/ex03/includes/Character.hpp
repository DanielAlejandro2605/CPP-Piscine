/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:07:54 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/30 17:04:22 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string _name);
		Character(Character const &src);
		~Character();
		Character &		operator=( Character const & rhs );
		std::string const & getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		/*Additional methods*/
		void				printInventory(void) const;
	private:
		std::string		_name;
		AMateria*		_inventory[4];
};

std::ostream& operator<<(std::ostream &output, Character const &instance_character);

#endif /* ******************************************************* CHARACTER_H */