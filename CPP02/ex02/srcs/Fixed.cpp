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
}

// Copy constructor
Fixed::Fixed(const Fixed &original)
{
    std::cout << "Execution of the copy constructor of the Fixed Class!\n";
    *this = original;
}

// Int constructor
Fixed::Fixed(int const integer_number)
{
    std::cout << "Execution of the int constructor of the Fixed Class!\n";
    this->fixed_point_number_value = integer_number << this->fractional_bits;
}

// Float constructor
Fixed::Fixed(float const float_number)
{
    std::cout << "Execution of the float constructor of the Fixed Class!\n";
    // int result = 0;
    // int i = 0;
    // while (i < this->fractional_bits)
    // {
    //     if (i == 0)
    //         result += 2;
    //     else
    //     {
    //         result *= 2;
    //     }
    //     i++;
    // }
    fixed_point_number_value = roundf(float_number * (1 << this->fractional_bits));
}

Fixed::~Fixed(void)
{
    std::cout << "Executing destructor of Fixed Class!\n";
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return (this->fixed_point_number_value);
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point_number_value = raw;
}

float   Fixed::toFloat(void) const
{
    float float_number = (float)this->fixed_point_number_value;
    int i = 1;

    while (i <= this->fractional_bits)
    {
        float_number /= 2.0f;
        i++;
    }
	// std::cout << float_number << "\n";
	// std::cout << (float)this->fixed_point_number_value / (1 << this->fractional_bits) << "\n";
	return (float_number);
}

int Fixed::toInt( void ) const
{
	int	integer_number = (int)this->fixed_point_number_value;
	int	i = 1;

	while (i <= this->fractional_bits)
	{
		integer_number /= 2;
		i++;
	}
	// std::cout << integer_number << "\n";
	return (integer_number);
}

/*
*************************OPERATORS***********************************************
*/

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

Fixed	Fixed::operator+(const Fixed& addition_number)
{
	Fixed	fixed_point_number_result;
	int		integer_result;

	integer_result = this->fixed_point_number_value + addition_number.fixed_point_number_value;
	fixed_point_number_result.setRawBits(integer_result);
	return (fixed_point_number_result);
}

Fixed	Fixed::operator-(const Fixed& subtraction_number)
{
	Fixed	fixed_point_number_result;
	int		integer_result;

	integer_result = this->fixed_point_number_value - subtraction_number.fixed_point_number_value;
	fixed_point_number_result.setRawBits(integer_result);
	return (fixed_point_number_result);
}

Fixed	Fixed::operator*(const Fixed &factor_number)
{
	Fixed			fixed_point_number_result;
    float			float_instance_value = this->toFloat();
    float			float_factor_value = factor_number.toFloat();
    float			float_result;

    float_result = float_instance_value * float_factor_value;
    std::cout << float_result * (1 << this->fractional_bits) << "\n";
    fixed_point_number_result.fixed_point_number_value = roundf(float_result * (1 << this->fractional_bits));
	return (fixed_point_number_result);
}

Fixed Fixed::operator/(const Fixed &divisor_number)
{
    Fixed			fixed_point_number_result;
    float			float_instance_value = this->toFloat();
    float			float_factor_value = divisor_number.toFloat();
    float			float_result;

    float_result = float_instance_value / float_factor_value;
    fixed_point_number_result.fixed_point_number_value = roundf(float_result * (1 << this->fractional_bits));
	return (fixed_point_number_result);
}