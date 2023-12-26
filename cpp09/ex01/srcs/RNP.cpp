/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:00:57 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/09/13 17:27:09 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RNP::RNP()
{
}

RNP::RNP(const RNP &src)
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RNP::~RNP()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RNP &				RNP::operator=( RNP const & rhs )
{
	(void)rhs;
	return *this;
}

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
			}
			val1 = this->_stack.top();
			this->_stack.pop();
			val2 = this->_stack.top();
			this->_stack.pop();
			doOperation(arg[idx], val1, val2);
		}
		else if (arg[idx] >= '0' && arg[idx] <= '9')
		{
			if (arg[idx + 1] && arg[idx + 1] != ' ')
				throw RNP::Error();
			this->_stack.push(static_cast<int>(arg[idx] - '0'));
		}
		idx++;
	}
	if (this->_stack.size() > 1)
		throw RNP::Error();
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
			if (val1 == 0)
			{
				throw RNP::Error();
				break;
			}
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

const char* RNP::Error::what() const throw() {
    return ("Error.");
}

/* ************************************************************************** */