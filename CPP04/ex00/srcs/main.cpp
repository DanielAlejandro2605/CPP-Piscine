/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:06:15 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/28 16:06:15 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"

int main (void)
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete j;
		delete i;
		delete meta;
	}
	{
		std::cout << CYAN << "*******  Not virtual method ! *********" RESET <<  std::endl;
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		delete i;
	}
	{
		const Animal* dog1 = new Dog();
		Dog cat1;
		cat1 = dog1;
	}
	return (0);
}