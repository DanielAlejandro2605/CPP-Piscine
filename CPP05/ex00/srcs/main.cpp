/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:08:55 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/18 20:38:17 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << BGCYAN << "**************************************" << RESET <<  std::endl;
		try
		{
			Bureaucrat daniel("Daniel", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << BGCYAN << "**************************************" << RESET << std::endl;
		Bureaucrat alejo("Alejo", 2);
		try
		{
			std::cout << alejo << std::endl;
			alejo.incrementGrade();
			std::cout << alejo << std::endl;
			alejo.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << BGCYAN << "**************************************" << RESET << std::endl;
		Bureaucrat john("John", 2);
		Bureaucrat jim("Jim", 149);
		try
		{
			std::cout << john << std::endl;
			std::cout << jim << std::endl;
			john.incrementGrade();
			jim.decrementGrade();
			std::cout << john << std::endl;
			std::cout << jim << std::endl;
			jim.decrementGrade();
			john.incrementGrade();
			std::cout << john << std::endl;
			std::cout << jim << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}	
	}
}