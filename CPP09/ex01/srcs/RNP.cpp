/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:00:57 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/21 20:47:03 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RNP::RNP()
{
}

// RNP::RNP(const RNP &src)
// {
// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RNP::~RNP()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// RNP &				RNP::operator=( RNP const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

// std::ostream &			operator<<( std::ostream & o, RNP const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	RNP::run(std::string arg)
{
	int		val1;
	int 	val2;
	size_t	idx;

	idx = 0;
	while (idx < arg.size())
	{
		if (isOperator(arg[idx]))
		{
			if (this->_stack.size() < 2)
			{
				throw RNP::Error();
				return ;
			}
			val1 = this->_stack.top();
			this->_stack.pop();
			val2 = this->_stack.top();
			this->_stack.pop();
			doOperation(arg[idx], val1, val2);
		}
		else if (arg[idx] >= '0' && arg[idx] <= '9')
		{
			this->_stack.push(static_cast<int>(arg[idx] - '0'));
		}
		idx++;
	}
	print();
}

void	RNP::print(void)
{
	std::stack<int>	s;

	s = this->_stack;
	while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

void	RNP::doOperation(char op, int val1, int val2)
{
	switch(op)
	{
		case '+':
			this->_stack.push(val2 + val1);
			break;
		case '-':
			this->_stack.push(val2 - val1);
			break;
		case '/':
			this->_stack.push(val2 / val1);
			break;
		case '*':
			this->_stack.push(val2 * val1);
			break;
	}	
}

bool	RNP::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return -(true);
	return (false);
}
/* ************************************************************************** */