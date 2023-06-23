/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:25:42 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/21 15:19:02 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

static int  orientation(Point const point1, Point const point2, Point const pointSearched)
{
    /*
    Bringing the points to the origin
    Vector AB is the result of point2 minus point1
    Vector AC is the result of pointSearched minus point1
    */
    Point vectorAB (point2.getX().toFloat() - point1.getX().toFloat(), point2.getY().toFloat() - point1.getY().toFloat());
    Point vectorAC (pointSearched.getX().toFloat() - point1.getX().toFloat(), pointSearched.getY().toFloat() - point1.getY().toFloat());
    /*Cross product for determinate the orientation of the vector*/
    float cross_product = (vectorAB.getX().toFloat() * vectorAC.getY().toFloat()) - (vectorAB.getY().toFloat() * vectorAC.getX().toFloat());
    if (cross_product > 0)
        return 1;
    else
        return -1;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    int turns;

    turns = orientation(a, b, point) + orientation(b, c, point) +  orientation(c, a, point);
    if (fabs(turns) == 3)
        return (true);
    else
        return (false);
}