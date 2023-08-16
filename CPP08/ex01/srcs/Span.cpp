/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:22:36 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/10 13:15:37 by dnieto-c         ###   ########.fr       */
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
	for (std::vector<int>::iterator iter = this->_v.begin(); iter != (this->_v.end() - 1); iter++)
	{
		d = std::abs(*(iter + 1) - *iter);
		distances.push_back(d);
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
	for (std::vector<int>::iterator iter = this->_v.begin(); iter != (this->_v.end() - 1); iter++)
	{
		d = std::abs(*(iter + 1) - *iter);
		distances.push_back(d);
	}
	r = static_cast<unsigned int>(*std::max_element(distances.begin(), distances.end()));
	return (r);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */