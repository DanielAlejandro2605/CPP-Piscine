/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:56:13 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/23 11:00:19 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main()
{
    {
        std::cout << BGBLUE << "Testing swap function" << RESET << std::endl;
        int a = 2;
        int b = 3;
        float c = 88.8f;
        float d = 63.09f;
        std::cout << "Values : " << RESET << std::endl;
        std::cout << YELLOW << "a: " << a << RESET << std::endl;
        std::cout << YELLOW << "b: " << b << RESET << std::endl;
        std::cout << YELLOW << "c: " << c << RESET << std::endl;
        std::cout << YELLOW << "d: " << d << RESET << std::endl;
        std::cout << BGMAGENTA << "calling swap(a, b)" << RESET << std::endl;
        swap( a, b );
        std::cout << GREEN << "a: " << a << RESET << std::endl;
        std::cout << GREEN << "b: " << b << RESET << std::endl;
        std::cout << BGMAGENTA << "calling swap<float>(c, d)" << RESET << std::endl;
        swap( c, d );
        std::cout << GREEN << "c: " << c << RESET << std::endl;
        std::cout << GREEN << "d: " << d << RESET << std::endl;
        std::cout << "**********************************" << RESET << std::endl;
        
        std::cout << BGBLUE << "Testing max function" << RESET << std::endl;
        std::cout << "Actual values : " << RESET << std::endl;
        std::cout << YELLOW << "a: " << a << RESET << std::endl;
        std::cout << YELLOW << "b: " << b << RESET << std::endl;
        std::cout << YELLOW << "c: " << c << RESET << std::endl;
        std::cout << YELLOW << "d: " << d << RESET << std::endl;
        std::cout << BGMAGENTA << "calling max(a, b)" << RESET << std::endl;
        std::cout << GREEN << "max: " << max( a, b ) << RESET << std::endl;
        std::cout << BGMAGENTA << "calling max<float>(c, d)" << RESET << std::endl;
        std::cout << GREEN << "max : " << max( c, d ) << RESET << std::endl;
        std::cout << "**********************************" << RESET << std::endl;

        std::cout << BGBLUE << "Testing min function" << RESET << std::endl;
        char x = 'X';
        char z = 'Z';
        std::cout << "Actual values : " << RESET << std::endl;
        std::cout << YELLOW << "a: " << a << RESET << std::endl;
        std::cout << YELLOW << "b: " << b << RESET << std::endl;
        std::cout << YELLOW << "c: " << c << RESET << std::endl;
        std::cout << YELLOW << "d: " << d << RESET << std::endl;
        std::cout << YELLOW << "x: " << x << RESET << std::endl;
        std::cout << YELLOW << "z: " << z << RESET << std::endl;
        std::cout << BGMAGENTA << "calling min(x, z)" << RESET << std::endl;
        std::cout << GREEN << "min: " << min( x, z ) << RESET << std::endl;
        std::cout << BGMAGENTA << "calling min<int>(a, b)" << RESET << std::endl;
        std::cout << GREEN << "min: " << min<int>( a, b ) << RESET << std::endl;
        std::cout << "**********************************" << RESET << std::endl;
    }
    {
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
}