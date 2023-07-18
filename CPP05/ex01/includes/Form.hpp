/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:38:09 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/18 20:44:56 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"


/*Add also a beSigned() member function to the Form that takes a Bureaucrat as
parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
(higher or egal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException*/

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const unsigned int	_grade_signed;
		const unsigned int	_grade_executed;
	public:
		Form(const std::string name, const unsigned int grade_to_signed, const unsigned int grade_to_executed);
		~Form();
		/*Methods*/
		void				beSigned(const Bureaucrat &bureaucrat);
		/*Accessors*/
		const std::string	getName(void) const;
		bool				isSigned(void) const;
		unsigned int	getGradeSigned(void) const;
		unsigned int	getGradeExecuted(void) const;
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Form: Grade too high to be signed!");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Form: Grade too low to be signed!");
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
};

std::ostream &			operator<<(std::ostream & o, Form const &i);

#endif /* ************************************************************ FORM_H */