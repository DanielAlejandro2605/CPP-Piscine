/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:56:27 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/19 16:26:40 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <cstring>
# include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
		/*Methods*/
		void	action(Bureaucrat const &executor) const;
};

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */