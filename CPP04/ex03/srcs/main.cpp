/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:15:07 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/03 12:36:43 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/MateriaSource.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->printInventory();
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	// tmp = src->createMateria("cure");
	bob->equip(tmp);
	bob->use(0, *me);
	bob->printInventory();
	delete bob;
	delete me;
	delete src;
	return 0;
}