/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:36:32 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/17 11:40:17 by dnieto-c         ###   ########.fr       */
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
	AForm		*form;
	std::string	known_forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int		c;
	
	for (c = 0; c < 3; c++)
	{
		if (name_form.compare(known_forms[c]) == 0)
			break ;
	}
	try 
	{
		switch (c)
		{
			case 0:
				form = new ShrubberyCreationForm(target_form);  
				break;
			case 1:
				form = new RobotomyRequestForm(target_form); 
				break;
			case 2:
				form = new PresidentialPardonForm(target_form); 
				break ;
			default:
				throw Intern::InvalidFormIntern();
		}	
	}
	catch (std::bad_alloc & exception) 
	{ 
		std::cerr << "bad_alloc detected: " << exception.what();
		return (NULL); 
	}
	std::cout << BGGREEN << "Intern creates " << name_form << RESET << std::endl;
	return (form);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */