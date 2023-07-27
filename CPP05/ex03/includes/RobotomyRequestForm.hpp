/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:26:57 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/27 10:38:35 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=( RobotomyRequestForm const &rhs);
		/*Methods*/
		void	action(Bureaucrat const &executor) const;
};

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */