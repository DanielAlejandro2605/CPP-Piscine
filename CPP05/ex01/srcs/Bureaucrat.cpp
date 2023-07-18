/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:08:58 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/18 22:07:26 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name (name)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	std::cout << BGBLUE << "Bureaucrat constructor called!" << RESET << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << BGBLUE << "Bureaucrat destructor called!" << RESET << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<(std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void			Bureaucrat::incrementGrade(void) {
	if ((this->_grade - 1) >= 1)
		this->_grade = this->_grade - 1;
	else
		throw Bureaucrat::GradeTooHighException();
}

void			Bureaucrat::decrementGrade(void) {
	if ((this->_grade + 1) <= 150)
		this->_grade = this->_grade + 1;
	else
		throw Bureaucrat::GradeTooLowException();
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string		Bureaucrat::getName(void) const {
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}
/* ************************************************************************** */