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

Fixed::Fixed(void)
{
    std::cout << "Execution of the default constructor of the Fixed Class!\n";
    this->fixed_point_number_value = 0;
}

Fixed::Fixed(const Fixed &original)
{
    std::cout << "Execution of the copy constructor of the Fixed Class!\n";
    this->fixed_point_number_value = original.fixed_point_number_value;
}

Fixed& Fixed::operator=(const Fixed& original) { // Sobrecarga del operador de asignación de copia
    std::cout << "Copy assignment operator called\n";
    if (this != &original) {
        this->fixed_point_number_value = original.fixed_point_number_value;
    }
    return *this;
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
