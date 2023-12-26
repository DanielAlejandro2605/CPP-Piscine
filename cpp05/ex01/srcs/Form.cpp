/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:38:07 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/19 13:43:59 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(const std::string name, const unsigned int grade_to_signed, const unsigned int grade_to_executed)
	: _name(name), _is_signed(false), _grade_signed(grade_to_signed), _grade_executed(grade_to_executed)
{
	if (grade_to_signed < 1 || grade_to_executed < 1)
		throw Form::GradeTooHighException();
	else if (grade_to_signed > 150 || grade_to_executed > 150)
		throw Form::GradeTooLowException();
	std::cout << BGGREEN << "Form constructor called!" << RESET << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << GREEN << "Form destructor called!" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<(std::ostream &o, Form const &i)
{
	o << MAGENTA << "\tForm Info" << RESET << std::endl;
	o << MAGENTA << "Name : " << i.getName() << RESET << std::endl;
	o << MAGENTA << "Status : ";
	if (i.isSigned())
		o << "SIGNED" << RESET << std::endl;
	else
		o << "NOT SIGNED" << RESET << std::endl;
	o << MAGENTA << "Grade to be signed : " << i.getGradeSigned() << RESET << std::endl; 
	o << MAGENTA << "Grade to be executed : " << i.getGradeExecuted() << RESET << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void				Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_grade_signed)
	{
		if (this->_is_signed == true)
			throw Form::FormIsAlreadySignedException();
		else
			this->_is_signed = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string	Form::getName(void) const {
	return (this->_name);
}

bool				Form::isSigned(void) const {
	return (this->_is_signed);
}

unsigned int	Form::getGradeSigned(void) const {
	return (this->_grade_signed);
}

unsigned int	Form::getGradeExecuted(void) const {
	return (this->_grade_executed);
}

/* ************************************************************************** */