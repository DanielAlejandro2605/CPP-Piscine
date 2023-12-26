/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:59:00 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/09/13 17:27:14 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
# define RNP_HPP

# include <iostream>
# include <string>
# include <stack>

class RNP
{
	private:
		std::stack<int>		_stack;
		std::string			_buffer;
	public:
		RNP();
		RNP(RNP const &src);
		~RNP();
		RNP &operator=(RNP const &rhs);

		void	run(std::string);
		void	doOperation(char op, int val1, int val2);
		bool	isOperator(char c);
		void	print(void);
		class Error : public std::exception {
		public:
			const char* what() const throw();
		};
};

#endif /* ************************************************************* RNP_H */