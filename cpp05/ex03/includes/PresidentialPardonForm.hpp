/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:53:15 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/27 10:58:39 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
		/*Methods*/
		void	action(Bureaucrat const &executor) const;
};

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */