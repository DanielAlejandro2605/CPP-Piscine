/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:56:10 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/02 17:11:25 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    std::cout << MAGENTA << "iter with std::string" << RESET << std::endl;
    std::string string_array[] = {"Daniel", "Nieto", "Castro"};
    size_t string_array_length = sizeof(string_array) / sizeof(string_array[0]);

    std::cout << "Original string_array: ";
    for (size_t i = 0; i < string_array_length; ++i) {
        std::cout << string_array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << BGGREEN << "iter called for std::string" << RESET << std::endl;
    iter(string_array, string_array_length, add3times<std::string>);

    std::cout << "Modified int_array: ";
    for (size_t i = 0; i < string_array_length; ++i) {
        std::cout << string_array[i] << " ";
    }

    std::cout << std::endl;
    
    std::cout << MAGENTA << "iter with int" << RESET << std::endl;
    int int_array[] = {1, -2, 83, 974, -65};
    size_t int_array_len = sizeof(int_array) / sizeof(int_array[0]);

    std::cout << "Original int_array: ";
    for (size_t i = 0; i < int_array_len; ++i) {
        std::cout << int_array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << BGGREEN << "iter called for int" << RESET << std::endl;
    iter(int_array, int_array_len, add3times<int>);

    std::cout << "Modified int_array: ";
    for (size_t i = 0; i < int_array_len; ++i) {
        std::cout << int_array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << MAGENTA << "iter with double" << RESET << std::endl;
    double double_array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t double_array_len = sizeof(double_array) / sizeof(double_array[0]);

    std::cout << "Original double_array: ";
    for (size_t i = 0; i < double_array_len; ++i) {
        std::cout << double_array[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << BGGREEN << "iter called for double" << RESET << std::endl;
    iter(double_array, double_array_len, add3times<double>);

    std::cout << "Modified double_array: ";
    for (size_t i = 0; i < double_array_len; ++i) {
        std::cout << double_array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
