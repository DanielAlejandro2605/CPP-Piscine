/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:08:55 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/27 11:17:56 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main(void)
{
	// {
	// 	std::cout << GREEN << "****************************************" << RESET << std::endl;
	// 	AForm *a = NULL;
	// 	try {
	// 		Bureaucrat daniel("Daniel", 1);
	// 		a = new ShrubberyCreationForm("file");
	// 		daniel.signForm(*a);
	// 		a->action(daniel);
	// 		delete a;
	// 	} catch (const AForm::FormIsNotSignedException& ex) {
	// 		delete a;
	// 		std::cerr << "Caught FormIsNotSignedException: " << ex.what() << std::endl;
	// 	}
	// }
	// {
	// 	std::cout << GREEN << "****************************************" << RESET << std::endl;
	// 	AForm *b = NULL;
	// 	try {
	// 		Bureaucrat alejo("Alejo", 45);
	// 		b = new RobotomyRequestForm("voldemort");
	// 		alejo.signForm(*b);
	// 		b->action(alejo);
	// 		delete b;
	// 	}
	// 	catch (const AForm::GradeTooLowException& ex)
	// 	{
	// 		std::cerr << "Caught GradeTooLowException: " << ex.what() << std::endl;
	// 		delete b;
	// 	}
	// 	catch (const AForm::FormIsNotSignedException& ex) {
	// 		std::cerr << "Caught FormIsNotSignedException: " << ex.what() << std::endl;
	// 		delete b;
	// 	}
	// }
	{
		std::cout << GREEN << "****************************************" << RESET << std::endl;
		AForm *c = NULL;
		Bureaucrat hugo("Hugo", 6);
		c = new PresidentialPardonForm("barack obama");
		hugo.signForm(*c);
		hugo.executeForm(*c);
		hugo.signForm(*c);
		hugo.incrementGrade();
		hugo.executeForm(*c);
		delete c;
	}
}