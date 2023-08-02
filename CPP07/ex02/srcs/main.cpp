/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:56:10 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/02 19:57:46 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

int main()
{
	{
		std::cout << PURPLE << "Testing Array Canonical Form and strings" << RESET << std::endl;
		
		Array<std::string> string_array(5);
		string_array[0] = "John";
		string_array[1] = "Jim";
		string_array[2] = "Joe";
		string_array[3] = "Jkk";
		string_array[4] = "James";

		Array<std::string> copy(string_array);

		for (unsigned int i = 0; i < string_array.size(); i++)
			std::cout << "original: " << string_array[i] << " | copy" << "\t" << copy[i] << std::endl;
	}
	{
		std::cout << PURPLE << "Testing Array<int>:" << RESET << std::endl;
		Array<int> intArray(5);
		for (size_t i = 0; i < intArray.size(); ++i) {
			intArray[i] = i + 1;
		}
		for (size_t i = 0; i < intArray.size(); ++i) {
			std::cout << "Element " << i << ": " << intArray[i] << std::endl;
		}

		std::cout << PURPLE << "Testing Array<double>:" << RESET << std::endl;
		Array<double> doubleArray(4);
		for (size_t i = 0; i < doubleArray.size(); ++i) {
			doubleArray[i] = 3.14 * (i + 1);
		}
		for (size_t i = 0; i < doubleArray.size(); ++i) {
			std::cout << "Element " << i << ": " << doubleArray[i] << std::endl;
		}

		std::cout << PURPLE << "Testing Array<float>:" << RESET << std::endl;
		Array<float> floatArray(3);
		for (size_t i = 0; i < floatArray.size(); ++i) {
			floatArray[i] = 2.5f * (i + 1);
		}
		for (size_t i = 0; i < floatArray.size(); ++i) {
			std::cout << "Element " << i << ": " << floatArray[i] << std::endl;
		}
	}
	{
		Array<int> e;

		try
		{
			std::cout << e[0] << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
    return 0;
}
