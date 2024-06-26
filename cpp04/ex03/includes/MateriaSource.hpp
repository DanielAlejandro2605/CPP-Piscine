/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:26:39 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/05 17:41:01 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &src);
		~MateriaSource();
		MateriaSource &operator=(MateriaSource const &rhs);
		void		learnMateria(AMateria*m);
		AMateria*	createMateria(std::string const &type);
	private:
		AMateria*	_materia[4];
};

#endif /* *************************************************** MATERIASOURCE_H */