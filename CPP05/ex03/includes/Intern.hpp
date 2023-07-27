/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:33:53 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/27 11:55:03 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		~Intern();
		/*Methods*/
		AForm	*makeForm(const std::string &name_form, const std::string &target_form);
		class InvalidFormIntern : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Intern doesn't handle this kind of form!");
				}
		};
};

#endif /* ********************************************************** INTERN_H */