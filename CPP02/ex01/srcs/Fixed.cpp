/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:03:58 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/03/23 14:03:58 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Default constructor
Fixed::Fixed () : fixed_point_number_value(0)
{
    std::cout << "Execution of the default constructor of the Fixed Class!\n";
    return ;
}

// Copy constructor
Fixed::Fixed(const Fixed &original)
{
    std::cout << "Execution of the copy constructor of the Fixed Class!\n";
    *this = original;
}

// Destructor
Fixed::~Fixed(void)
{
    std::cout << "Executing destructor of Fixed Class!\n";
    return ;
}

/*
In general, mathematically, given a fixed binary point position, shifting the bit pattern of a
number to the right by 1 bit always divide the number by 2. Similarly, shifting a number to the
left by 1 bit multiplies the number by 2.
*/

/*Int constructor*/
Fixed::Fixed(int const integer_number)
{
    std::cout << "Execution of the int constructor of the Fixed Class!\n";
    this->fixed_point_number_value = integer_number * (1 << this->fractional_bits);
}

/*
Float constructor
En algunos casos, esta funcion puede causar directamente perdida de precision
en los float e.g 42.42
*/
Fixed::Fixed(float const float_number)
{ 
    std::cout << "Execution of the float constructor of the Fixed Class!\n";
    this->fixed_point_number_value = roundf(float_number * (1 << this->fractional_bits));
}

float   Fixed::toFloat(void) const
{
	float float_number = (float)this->fixed_point_number_value / (1 << this->fractional_bits);
	return (float_number);
}

int Fixed::toInt( void ) const
{
	int	integer_number = (int)this->fixed_point_number_value / (1 << this->fractional_bits);
	return (integer_number);
}

/*
"RawBits" refers to the raw bits or direct binary representation of a value. In simpler terms, 
they are the bits that make up a piece of data without performing any additional interpretation
or manipulation.
*/

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return (this->fixed_point_number_value);
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point_number_value = raw;
}

// Member operator overload
Fixed& Fixed::operator=(const Fixed& original)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &original) {
        this->fixed_point_number_value = original.getRawBits();
    }
    return *this;
}

std::ostream&	operator<<(std::ostream &output, Fixed const &fixed_point_number)
{
	output << fixed_point_number.toFloat();
	return (output);
}
