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

Fixed::Fixed(void) : _fixed_point_number_value(0)
{
    std::cout << "Execution of the default constructor of the Fixed Class!" << std::endl;
}

/*
Copy constructor
()	It is defined with a parameter that is a constant reference
	to the same class (by convention, it is named const Type& another).
	This allows passing an instance of the class as an argument without making an additional copy.
()	Its main function is to perform a bitwise copy of the member data from the original instance to the new instance.
*/

Fixed::Fixed(const Fixed &original)
{
    std::cout << "Execution of the copy constructor of the Fixed Class!" << std::endl;
    this->_fixed_point_number_value = original._fixed_point_number_value;
}


/*
Copy assignment operator overload
Is a special member function of a class that is used to map the values of one instance of the
class to another existing instance of the same class, it is used to perform a deep copy of the
member data from one instance to another.

()	Why must I verify that it is not the same instance ? 
	The if (this == &other) check within the assignment operator is intended to prevent 
	unnecessary and potentially dangerous assignment when you attempt to assign an instance 
	of a class to itself.
	If the assignment operator did not perform this check and an attempt was made to assign 
	an instance to itself, problems would occur in copying the member data. This is because, 
	when performing a deep copy of the member data, the values of the current instance would 
	be modified before performing the copy, leading to incorrect or unexpected results.
*/

Fixed& Fixed::operator=(const Fixed& original) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &original) {
		return (*this);
    }
	this->_fixed_point_number_value = original._fixed_point_number_value;
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Executing destructor of Fixed Class!" << std::endl;
}

/*
"RawBits" refers to the raw bits or direct binary representation of a value. In simpler terms, 
they are the bits that make up a piece of data without performing any additional interpretation
or manipulation.
*/

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixed_point_number_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixed_point_number_value = raw;
}
