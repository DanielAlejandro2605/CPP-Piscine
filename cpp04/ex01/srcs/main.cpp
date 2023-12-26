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
		Animal*	pets[6];
		std::cout << BGYELLOW << "******************" << RESET << std::endl;
		std::cout << BGYELLOW << "Filling the array!" << RESET << std::endl;
		std::cout << BGYELLOW << "******************" << RESET << std::endl;
		for (int i = 0; i < 6; i++){
			if (i < 3)
				pets[i] = new Dog();
			else
				pets[i] = new Cat();
		}
		std::cout << BGYELLOW << "******************" << RESET << std::endl;
		std::cout << BGYELLOW << "Emptying the array!" << RESET << std::endl;
		std::cout << BGYELLOW << "******************" << RESET << std::endl;
		for (int i = 0; i < 6; i++){
			delete pets[i];
		}
	}
	{
		Dog	dog1;
		dog1.getBrain()->setIdeas("Thinking about food!");
		dog1.getBrain()->setIdeaIdx(1, "I want to scratch me!");
		dog1.getBrain()->setIdeaIdx(3, "I want a cake!");
		dog1.getBrain()->printFirstIdeas();
	}
	return (0);
}