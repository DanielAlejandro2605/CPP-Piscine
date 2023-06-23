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

#include "../includes/Point.hpp"

int main( void )
{
    {
        Point const pointA(-2.0f, 1.0f);
        Point const pointB(2.0f, 2.5f);
        Point const pointC(1.0f, -3.2f);
        Point const pointSearched(-0.8f, -1.0f);
        if (bsp(pointA, pointB, pointC, pointSearched))
            std::cout << "The point is inside the triangle!" << std::endl;
        else
           std::cout << "The point is NOT inside the triangle :(" << std::endl; 
    }
    {
        Point const pointA(-2.0f, 1.0f);
        Point const pointB(2.0f, 2.5f);
        Point const pointC(1.0f, -3.2f);
        Point const pointSearched(1.0f, 1.0f);
        if (bsp(pointA, pointB, pointC, pointSearched))
            std::cout << "The point is inside the triangle!" << std::endl;
        else
           std::cout << "The point is NOT inside the triangle :(" << std::endl; 
    }
    {
        Point const pointA(-2.0f, 1.0f);
        Point const pointB(2.0f, 2.5f);
        Point const pointC(1.0f, -3.2f);
        Point const pointSearched(2.0f, 2.5f);
        if (bsp(pointA, pointB, pointC, pointSearched))
            std::cout << "The point is inside the triangle!" << std::endl;
        else
           std::cout << "The point is NOT inside the triangle :(" << std::endl; 
    }
    return 0;
}
