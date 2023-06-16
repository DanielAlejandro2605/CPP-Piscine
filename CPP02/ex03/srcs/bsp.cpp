/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:12:02 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/16 20:42:39 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

// static bool orientation(Point const a, Point const b, Point const c)
// {
//     (void)c;
//     (void)a;
//     std::cout << b.getX() << "\n";
//     // Point vectorAB (b.getX() - a.getX(), b.getY() - a.getY());
//     // Point vectorAC (c.getX() - a.getX(), c.getY() - a.getY());
//     // float cross_product = (vectorAB.getX() * vectorAC.getY()) - (vectorAB.getY() * vectorAC.getX());
//     // if (cross_product > 0)
//     //     return true;
//     // else
//     //     return false;
//     return (false);
// }

bool bsp(Point const a, Point const b, Point const c, Point const point){
    // orientation(a, b, c);
    std::cout << b.getX().toFloat() << "\n";
    return (false);
}