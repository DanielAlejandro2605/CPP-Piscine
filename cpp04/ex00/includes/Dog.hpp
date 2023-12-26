/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:22:02 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/28 23:32:09 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const &src);
		~Dog(void);
		Dog &operator=(Dog const &rhs);
		void	makeSound(void) const;
};

std::ostream& operator<<(std::ostream &output, Dog const &instance_dog);

#endif /* ************************************************************* DOG_H */