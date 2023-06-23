/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:32:24 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/21 14:10:43 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point(void) : x(0), y(0) {
    // std::cout << "Execution of the default constructor of the Point Class!\n";
    return ;
}

Point::Point(const float value_x, const float value_y) : x(value_x), y(value_y){
    // std::cout << "Execution of the constructor with float parameters of the Point Class!\n";
    return ;
}

Point::Point(const Point &original) : x(original.x), y(original.y){
    return ;
}

Point::~Point(void){
    // std::cout << "Execution of the default destructor of the Point Class!\n";
    return ;
}

Point&	Point::operator=(const Point& original){
    (void)original;
    std::cout << "Impossible assign new values to const variables, values will stay the same as in the default constructor." << std::endl;
    return *this;
}

/*Useful stuff*/
Fixed Point::getX(void) const {
    return (this->x);
}

Fixed Point::getY(void) const {
    return (this->y);
}
