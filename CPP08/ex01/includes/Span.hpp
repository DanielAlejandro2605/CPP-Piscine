/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:14:05 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/29 11:04:14 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>

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

class Span
{
	private:
		std::vector<int>	_v;
		unsigned int		_size;
	public:
		/*Constructors*/
		Span(unsigned int N);
		Span(Span const &src);
		/*Destructors*/
		~Span();
		/*Operator overloada*/
		Span &operator=(Span const &rhs);
		/*Member functions*/
		void			addNumber(int n);
		void			addNumber(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		/*Print*/
		void 			printSpan(void);
		/*Exceptions*/
		class SpanIsFull : public std::exception {
		public:
			const char* what() const throw();
		};
		class ImpossibleComputeSpan : public std::exception {
		public:
			const char* what() const throw();
		};
};

#endif /* ************************************************************ SPAN_H */