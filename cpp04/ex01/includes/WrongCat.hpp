/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 23:47:08 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/28 23:53:11 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "../includes/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const &src);
		~WrongCat();
		WrongCat &operator=(WrongCat const &rhs);
		void	makeSound(void) const;
};

std::ostream& operator<<(std::ostream &output, WrongCat const &instance_wrong_cat);

#endif /* ******************************************************** WRONGCAT_H */