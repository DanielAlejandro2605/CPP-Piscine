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

bool bsp(Point const a, Point const b, Point const c, Point const point){
    std::cout << a.getX().toFloat() << "\n";
    std::cout << b.getX().toFloat() << "\n";
    std::cout << c.getX().toFloat() << "\n";
    std::cout << point.getX().toFloat() << "\n";
    return (true);
}

int main( void )
{
    Point pointA(2.25f, 3.5f);
    Point pointB(1.5f, 4.3f);
    Point pointC(5.2f, 1.2f);
    Point pointSearched(3.5f, 3.5f);
    bsp(pointA, pointB, pointC, pointSearched);
    return 0;
}
