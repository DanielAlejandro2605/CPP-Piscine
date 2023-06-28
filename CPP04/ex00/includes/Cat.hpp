/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 23:31:12 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/28 23:35:12 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat : public Animal
{

	public:
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);
		Cat &operator=( Cat const & rhs );
		void	makeSound(void) const;
};

std::ostream& operator<<(std::ostream &output, Cat const &instance_cat);

#endif /* ************************************************************* CAT_H */