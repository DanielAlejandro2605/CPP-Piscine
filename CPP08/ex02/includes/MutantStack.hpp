/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:17:29 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/29 11:44:33 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"
#define RESET	"\033[0m"
#define PURPLE	"\e[95m"

#define BGBLACK "\033[40m"
#define BGRED "\033[41m"
#define BGGREEN "\033[42m"
#define BGYELLOW "\033[43m"
#define BGBLUE "\033[44m"
#define BGMAGENTA "\033[45m"
#define BGCYAN "\033[46m"
#define BGWHITE "\033[47m"

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		/*Constructors*/
		MutantStack() : std::stack<T>() {};
		MutantStack<T>( MutantStack const &src) : std::stack<T>(src) {};
		/*Destructors*/
		~MutantStack() {};
		/*Operator '=' overload*/
		MutantStack<T> &operator=(MutantStack const &rhs)
		{
			if (*this != rhs)
				*this = std::stack<T>(rhs);
			return (*this);
		};
	
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() {return std::stack<T>::c.begin();};
		iterator end() {return std::stack<T>::c.end();};
		const_iterator cbegin() const {return std::stack<T>::c.cbegin();};
		const_iterator cend() const {return std::stack<T>::c.cend();};
		reverse_iterator rbegin() {return std::stack<T>::c.rbegin();};
		reverse_iterator rend() {return std::stack<T>::c.rend();};
		const_reverse_iterator crbegin() const {return std::stack<T>::c.crbegin();};
		const_reverse_iterator crend() const {return std::stack<T>::c.crend();};
};

#endif /* ***************************************************** MUTANTSTACK_H */