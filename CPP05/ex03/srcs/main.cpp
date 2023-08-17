/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:10 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/17 11:42:24 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "Intern.hpp"

int main()
{
	Bureaucrat john("John", 5);
	Bureaucrat jim("Jim", 45);
	Bureaucrat jane("Jane", 137);

	std::cout << john << std::endl;
	std::cout << jim << std::endl;
	std::cout << jane << std::endl;

	Intern intern;

	AForm* formA = NULL;
	AForm* formB = NULL;
	AForm* formC = NULL;
	AForm* formD = NULL;

	try
	{
		std::cout << "&&&&&&&&&&&&&&& CREATING FORMS &&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
		formA = intern.makeForm("shrubbery creation", "home");
		formB = intern.makeForm("robotomy request", "Bender");
		formC = intern.makeForm("presidential pardon", "Stephen Bannon");
		formD = intern.makeForm("test", "test");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "-------------------------------------------------------" << std::endl;
	john.executeForm(*formA);
	jim.executeForm(*formA);
	std::cout << std::endl;
	john.signForm(*formA);
	jim.signForm(*formA);
	std::cout << std::endl;
	john.executeForm(*formA);
	std::cout << "-------------------------------------------------------" << std::endl;
	john.executeForm(*formB);
	std::cout << std::endl;
	john.signForm(*formB);
	std::cout << std::endl;
	john.executeForm(*formB);;
	std::cout << "-------------------------------------------------------" << std::endl;
	john.executeForm(*formC);
	std::cout << std::endl;
	john.signForm(*formC);
	std::cout << std::endl;
	john.executeForm(*formC);
	
	if (formA)
		delete formA;
	if (formB)
		delete formB;
	if (formC)
		delete formC;
	if (formD)
		delete formD;
}
