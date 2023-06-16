/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:26:10 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/16 20:44:25 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
class Point 
{
	private:
		const Fixed	x;
		const Fixed y;
	public:
		/*Constructor and destructors*/
		Point(void);
		Point(const float value_x, const float value_y);
		Point(const Point &original);
		~Point();
		/*Assignment operator overload*/
		Point&	operator=(const Point& original);
		/*Useful stuff*/
		Fixed const	getX(void) const;
		Fixed const	getY(void) const;
};

#endif