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
    this->fixed_point_number_value = roundf(float_number * (1 << this->fractional_bits));
    std::cout << this->fixed_point_number_value << "\n";
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
	float float_number = (float)this->fixed_point_number_value / (1 << this->fractional_bits);
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

/*Not subjetc functions*/
void printFloatRepresentation(float num) {
    unsigned char binary[sizeof(float)];
    std::memcpy(binary, &num, sizeof(float));

    std::cout << "Signo: " << ((binary[3] >> 7) & 1) << std::endl;

    unsigned char exponent = (binary[3] & 0x7F) << 1;
    exponent |= (binary[2] >> 7) & 1;
    std::cout << "Exponente: ";
    for (int i = 7; i >= 0; --i) {
        std::cout << ((exponent >> i) & 1);
    }
    std::cout << std::endl;

    std::cout << "Mantisa: ";
    for (int i = 2; i >= 0; --i) {
        for (int j = 7; j >= 0; --j) {
            std::cout << ((binary[i] >> j) & 1);
        }
    }
    std::cout << std::endl;
}

