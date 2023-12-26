/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:05:13 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/19 12:58:22 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_HPP
# define CUBE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const & src);
		~Cure();
		Cure &operator=(Cure const &rhs);
		/*Methods*/
		AMateria*	clone(void) const;
		void use(ICharacter &target);
};

#endif /* ************************************************************ CUBE_H */