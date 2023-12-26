/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:30:29 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/29 11:35:20 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
   {
		std::cout << BGYELLOW << "*****************************" << RESET << std::endl;
		Span sp = Span(5);
		try
		{
			sp.addNumber(2);
			sp.addNumber(1);
			sp.addNumber(3);
			sp.addNumber(16);
			sp.addNumber(53);
			sp.printSpan();
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << BGYELLOW << "*****************************" << RESET << std::endl;
		Span sp = Span(100);
		std::vector<int> v;
		for (int i = 1; i < 100; i++)
			v.push_back(i);
		v.push_back(200);
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			sp.addNumber(v.begin(), v.end());
			sp.printSpan();
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}