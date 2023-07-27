/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:36:32 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/27 12:01:20 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	std::cout << BGMAGENTA << "Intern constructor called!" << RESET << std::endl;
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	std::cout << BGMAGENTA << "Inter destructor called!" << RESET << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
AForm	*Intern::makeForm(const std::string &name_form, const std::string &target_form) 
{
	AForm	*form;

	if (name_form.compare("shrubbery creation") == 0)
	{
		try
		{ 
			form = new ShrubberyCreationForm(target_form); 
		} 
		catch (std::bad_alloc & exception) 
		{ 
			std::cerr << "bad_alloc detected: " << exception.what(); 
		}
	}
	else if (name_form.compare("robotomy request") == 0)
	{
		try
		{ 
			form = new RobotomyRequestForm(target_form); 
		} 
		catch (std::bad_alloc & exception) 
		{ 
			std::cerr << "bad_alloc detected: " << exception.what(); 
		}
	}
	else if (name_form.compare("presidential pardon") == 0)
	{
		try
		{ 
			form = new PresidentialPardonForm(target_form); 
		} 
		catch (std::bad_alloc & exception) 
		{ 
			std::cerr << "bad_alloc detected: " << exception.what(); 
		}
	}
	else
		throw Intern::InvalidFormIntern();
	std::cout << BGGREEN << "Intern creates " << name_form << RESET << std::endl;
	return (form);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */