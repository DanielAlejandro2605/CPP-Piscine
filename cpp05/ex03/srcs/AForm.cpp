/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:38:07 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/17 11:17:00 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(const std::string name, const std::string target, const unsigned int grade_to_signed, const unsigned int grade_to_executed)
	: _name(name), _target(target), _is_signed(false), _grade_signed(grade_to_signed), _grade_executed(grade_to_executed)
{
	if (grade_to_signed < 1 || grade_to_executed < 1)
		throw AForm::GradeTooHighException();
	else if (grade_to_signed > 150 || grade_to_executed > 150)
		throw AForm::GradeTooLowException();
	std::cout << BGGREEN << "AForm constructor called!" << RESET << std::endl;
}

AForm::AForm(const AForm &src)
	:  _name(src._name), _target(src._target), _is_signed(src._is_signed), _grade_signed(src._grade_signed), _grade_executed(src._grade_executed)
{
	std::cout << BGGREEN << "AForm copy constructor called!" << RESET << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
	std::cout << GREEN << "AForm destructor called!" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/
AForm&	AForm::operator=(AForm const &rhs) {
	(void)rhs;
	return *this;
}
		
std::ostream &			operator<<(std::ostream &o, AForm const &i)
{
	o << MAGENTA << "\tAForm Info" << RESET << std::endl;
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
void				AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_grade_signed)
	{
		if (this->_is_signed == true)
			throw AForm::FormIsAlreadySignedException();
		else
			this->_is_signed = true;
	}
	else
	{
		throw AForm::GradeTooLowExceptionSigned();
	}
}

void	AForm::execute(Bureaucrat const &executor) const {
	if (this->isSigned() == false)
		throw AForm::FormIsNotSignedException();
	else if (executor.getGrade() > this->getGradeExecuted())
		throw AForm::GradeTooLowExceptionExecuted();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string	AForm::getName(void) const {
	return (this->_name);
}

const std::string	AForm::getTarget(void) const {
	return (this->_target);
}

bool				AForm::isSigned(void) const {
	return (this->_is_signed);
}

unsigned int	AForm::getGradeSigned(void) const {
	return (this->_grade_signed);
}

unsigned int	AForm::getGradeExecuted(void) const {
	return (this->_grade_executed);
}


/* ************************************************************************** */