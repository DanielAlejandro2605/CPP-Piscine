/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:08:55 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/17 11:01:46 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << BGCYAN << "**************************************" << RESET <<  std::endl;
		try
		{
			Form test("test", 151, 42);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Cannot initialize test because " << e.what() << std::endl;
		}
	}
	{
		std::cout << BGCYAN << "**************************************" << RESET <<  std::endl;
		Bureaucrat john("John", 5);

		std::cout << john << std::endl;
		{
			std::cout << BGCYAN << "**************************************" << RESET <<  std::endl;
			try
			{
				john.incrementGrade();
				john.incrementGrade();
				std::cout << john << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		{
			std::cout << BGCYAN << "**************************************" << RESET <<  std::endl;
			Form b("b", 3, 3);
			Form c("c", 3, 20);
			std::cout << john << std::endl;
			std::cout << b;
			john.signForm(b);
			std::cout << b;
			std::cout << c;
			john.signForm(b);
		}
		{
			std::cout << BGCYAN << "**************************************" << RESET <<  std::endl;
			Form a("a", 1, 1);
			std::cout << john << std::endl;
			john.signForm(a);
			std::cout << a;
		}
	}
}