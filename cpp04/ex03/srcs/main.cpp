/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:15:07 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/06 00:25:47 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/MateriaSource.hpp"

int main(void)
{
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
		me->unequip(1);
		me->printInventory();
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		tmp = src->createMateria("cure");
		bob->equip(tmp);
		bob->use(0, *me);
		bob->printInventory();
		delete bob;
		delete me;
		delete src;	
	}
	// {
	// 	std::cout << "\n\n\nTesting little controls in Materia Source!\n\n\n" << std::endl;
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	src->learnMateria(new Cure());
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Ice());
	// 	delete src;
	// }
	// {
	// 	std::cout << "\n\n\nTesting little controls in of Character!\n\n\n" << std::endl;
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	ICharacter* me = new Character("me");
	// 	AMateria* tmp;
	// 	for (int i = 0; i < 3; i++)
	// 	{
	// 		tmp = src->createMateria("ice");
	// 		me->equip(tmp);
	// 		tmp = src->createMateria("cure");
	// 		me->equip(tmp);
	// 	}
	// 	me->unequip(1);
	// 	me->unequip(1);
	// 	delete src;
	// 	delete me;
	// }
	return 0;
}