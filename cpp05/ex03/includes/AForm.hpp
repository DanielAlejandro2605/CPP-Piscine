/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:38:09 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/17 11:15:58 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const std::string	_target;
		bool				_is_signed;
		const unsigned int	_grade_signed;
		const unsigned int	_grade_executed;
	public:
		/*Constructors*/
		AForm(const std::string name, const std::string target, const unsigned int grade_to_signed, const unsigned int grade_to_executed);
		AForm(AForm const &src);
		/*Operator = overload*/
		AForm	&operator=(AForm const &rhs);
		/*Destructor*/
		virtual ~AForm();
		/*Methods*/
		void				beSigned(const Bureaucrat &bureaucrat);
		void				execute(Bureaucrat const & executor) const;
		/*Virtual methods*/
		virtual	void		action(Bureaucrat const & executor) const = 0;
		/*Accessors*/
		const std::string	getName(void) const;
		const std::string	getTarget(void) const;
		bool				isSigned(void) const;
		unsigned int		getGradeSigned(void) const;
		unsigned int		getGradeExecuted(void) const;
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Form: Grade too high to be initialized!");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Form: Grade too low to be initialized!");
				}
		};
		class GradeTooLowExceptionSigned : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Form: Grade too low to be signed!");
				}
		};
		class GradeTooLowExceptionExecuted : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Form: Grade too low to be executed!");
				}
		};
		class FormIsAlreadySignedException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Form: Is already signed!");
				}
		};
		class FormIsNotSignedException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Form: Is not signed!");
				}
		};
};

std::ostream &			operator<<(std::ostream & o, AForm const &i);

#endif /* ************************************************************ FORM_H */