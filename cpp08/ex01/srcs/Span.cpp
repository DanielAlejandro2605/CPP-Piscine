/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:22:36 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/29 11:35:04 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(unsigned int N) : _size(N)
{
	std::cout << BLUE << "Span class constructor called!" << RESET << std::endl;
}


Span::Span(const Span& src)
	: _v(src._v), _size(src._size)
{
	std::cout << BLUE << "Span class copy constructor called!" << RESET << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
	std::cout << BLUE << "Span class destructor called!" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span& Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		this->_v = rhs._v;
		this->_size = rhs._size;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Span::addNumber(int n)
{
	if (this->_v.size() <  this->_size)
		this->_v.push_back(n);
	else
		throw SpanIsFull();
}

void	Span::addNumber(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end)
{
	int	distance_iterators = std::distance(begin, end);
	if ((distance_iterators + this->_v.size()) > this->_size)
	{
		this->_v.insert(this->_v.end(), begin, begin + (this->_size - this->_v.size()));
		throw SpanIsFull();
	}
	else
		this->_v.insert(this->_v.end(), begin, end);
}

unsigned int	Span::shortestSpan(void)
{
	std::vector<int>	distances;
	int					d;
	unsigned int		r;

	if (this->_v.size() <= 1)
		throw ImpossibleComputeSpan();
	for (std::vector<int>::iterator iter_i = this->_v.begin(); iter_i != (this->_v.end() - 1); iter_i++)
	{
		for (std::vector<int>::iterator iter_j = iter_i + 1; iter_j != this->_v.end(); iter_j++)
		{
			d = std::abs(*iter_i - *iter_j);
			distances.push_back(d);	
		}
	}
	r = static_cast<unsigned int>(*std::min_element(distances.begin(), distances.end()));
	return (r);
}

unsigned int	Span::longestSpan(void)
{
	std::vector<int>	distances;
	int					d;
	unsigned int		r;

	if (this->_v.size() <= 1)
		throw ImpossibleComputeSpan();
	for (std::vector<int>::iterator iter_i = this->_v.begin(); iter_i != (this->_v.end() - 1); iter_i++)
	{
		for (std::vector<int>::iterator iter_j = iter_i + 1; iter_j != this->_v.end(); iter_j++)
		{
			d = std::abs(*iter_i - *iter_j);
			distances.push_back(d);	
		}
	}
	r = static_cast<unsigned int>(*std::max_element(distances.begin(), distances.end()));
	return (r);
}

void	Span::printSpan(void) {
    for (std::vector<int>::iterator iter = this->_v.begin(); iter != this->_v.end(); iter++)
		std::cout << YELLOW << *iter << " " << RESET;
	std::cout << std::endl;
}

/*
** --------------------------------- EXCEPTIONS ---------------------------------
*/

const char* Span::SpanIsFull::what() const throw() {
   return ("Span is already full!");
}

const char* Span::ImpossibleComputeSpan::what() const throw() {
  return ("Span is empty or has only one element!");
}
/* ************************************************************************** */