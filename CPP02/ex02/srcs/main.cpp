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
    std::cout << "***************************************" << std::endl;
    std::cout << "Voila my numbers !" << std::endl;
    std::cout << "a " << a << std::endl;
    std::cout << "b " << b << std::endl;
    std::cout << "c " << c << std::endl;
    std::cout << "d " << d << std::endl;
    std::cout << "e " << e << std::endl;
    {
        std::cout << "***************************************" << std::endl;
        std::cout << "Let's compare" << std::endl;
        if (a > b)   
            std::cout << "a is greather than b" << std::endl;
        if (c == b)
            std::cout << "c is equals to b" << std::endl;
        if (d != c)
            std::cout << "d is different to c" << std::endl;
        if (e < c && e < b)
            std::cout << "e is very small" << std::endl;
    }
    {
        Fixed a;
        std::cout << "***************************************" << std::endl;
        std::cout << "Let's increment and decrement" << std::endl;
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << --a << std::endl;
        std::cout << a << std::endl;
        std::cout << a-- << std::endl;
        std::cout << a << std::endl;
    }
    {
        Fixed a(68.58f);
        Fixed b(Fixed(6.045f) * Fixed(2.258f));
        Fixed const num1;
        Fixed const num2(-0.1f);
        std::cout << "***************************************" << std::endl;
        std::cout << "Let's use min and max" << std::endl;
        std::cout << Fixed::min( a, b ) << std::endl;
        std::cout << Fixed::min( num1, num2 ) << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
        std::cout << Fixed::max( num1, num2 ) << std::endl;
    }
    return 0;
}
