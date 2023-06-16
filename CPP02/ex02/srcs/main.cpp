/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:49:14 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/03/23 14:49:14 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main( void )
{
    Fixed a(42.42f);
    Fixed b(Fixed(5.05f) * Fixed(2));
    Fixed c(10.1016f);
    Fixed d(26);
    Fixed e(0.008f);
    std::cout << "***************************************\n";
    std::cout << "Voila my numbers !\n";
    std::cout << "a " << a << "\n";
    std::cout << "b " << b << "\n";
    std::cout << "c " << c << "\n";
    std::cout << "d " << d << "\n";
    std::cout << "e " << e << "\n";
    {
        std::cout << "***************************************\n";
        if (a > b)   
            std::cout << "a is greather than b\n";
        if (c == b)
            std::cout << "c is equals to b\n";
        if (d != c)
            std::cout << "d is different to c\n";
        if (e < c && e < b)
            std::cout << "e is very small\n";
    }
    {
        Fixed a;
        std::cout << "***************************************\n";
        std::cout << "a " << a << "\n";
        std::cout << ++a << "\n";
    }
    return 0;
}
