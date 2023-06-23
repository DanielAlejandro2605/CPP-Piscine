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
    //std::cout << "Execution of the default constructor of the Fixed Class!\n";
    return ;
}

// Copy constructor
Fixed::Fixed(const Fixed &original)
{
    //std::cout << "Execution of the copy constructor of the Fixed Class!\n";
    *this = original;
}

// Destructor
Fixed::~Fixed(void)
{
    //std::cout << "Executing destructor of Fixed Class!\n";
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
    //std::cout << "Execution of the int constructor of the Fixed Class!\n";
    this->fixed_point_number_value = integer_number * (1 << this->fractional_bits);
}

/*
Float constructor
En algunos casos, esta funcion puede causar directamente perdida de precision
en los float e.g 42.42
*/
Fixed::Fixed(float const float_number)
{
    //std::cout << "Execution of the float constructor of the Fixed Class!\n";
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
    //std::cout << "getRawBits member function called\n";
    return (this->fixed_point_number_value);
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point_number_value = raw;
}

/**************************OPERATORS************************************************/

// Member operator overload
Fixed& Fixed::operator=(const Fixed& original)
{
    //std::cout << "Copy assignment operator called\n";
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

/*Arithmetic operators*/
Fixed	Fixed::operator+(const Fixed& addition_number) const {
	Fixed	fixed_point_number_result;
	int		integer_result;

	integer_result = this->fixed_point_number_value + addition_number.fixed_point_number_value;
	fixed_point_number_result.setRawBits(integer_result);
	return (fixed_point_number_result);
}

Fixed	Fixed::operator-(const Fixed& subtraction_number) const {
	Fixed	fixed_point_number_result;
	int		integer_result;

	integer_result = this->fixed_point_number_value - subtraction_number.fixed_point_number_value;
	fixed_point_number_result.setRawBits(integer_result);
	return (fixed_point_number_result);
}

Fixed	Fixed::operator*(const Fixed &factor_number) const {
	Fixed			fixed_point_number_result;
    float			float_instance_value = this->toFloat();
    float			float_factor_value = factor_number.toFloat();
    float			float_result;

    float_result = float_instance_value * float_factor_value;
    fixed_point_number_result.fixed_point_number_value = roundf(float_result * (1 << this->fractional_bits));
	return (fixed_point_number_result);
}

Fixed Fixed::operator/(const Fixed &divisor_number) const {
    Fixed			fixed_point_number_result;
    float			float_instance_value = this->toFloat();
    float			float_factor_value = divisor_number.toFloat();
    float			float_result;

    float_result = float_instance_value / float_factor_value;
    fixed_point_number_result.fixed_point_number_value = roundf(float_result * (1 << this->fractional_bits));
	return (fixed_point_number_result);
}

/*Comparison operators*/
bool Fixed::operator>(const Fixed& other_fixed_point_number) const {
    return this->fixed_point_number_value > other_fixed_point_number.fixed_point_number_value;
}

bool Fixed::operator<(const Fixed& other_fixed_point_number) const {
    return this->fixed_point_number_value < other_fixed_point_number.fixed_point_number_value;
}

bool Fixed::operator>=(const Fixed& other_fixed_point_number) const {
    return this->fixed_point_number_value >= other_fixed_point_number.fixed_point_number_value;
}

bool Fixed::operator<=(const Fixed& other_fixed_point_number) const {
    return this->fixed_point_number_value <= other_fixed_point_number.fixed_point_number_value;
}

bool Fixed::operator==(const Fixed& other_fixed_point_number) const {
    return this->fixed_point_number_value == other_fixed_point_number.fixed_point_number_value;
}

bool Fixed::operator!=(const Fixed& other_fixed_point_number) const {
    return this->fixed_point_number_value != other_fixed_point_number.fixed_point_number_value;
}

/*Increment and decrement*/
//Pre-increment
Fixed& Fixed::operator++()
{
	++this->fixed_point_number_value;
	return (*this);
}
//Post-increment
Fixed   Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->fixed_point_number_value;
	return (temp);
}

//Pre-decrement
Fixed& Fixed::operator--()
{
	--this->fixed_point_number_value;
	return (*this);
}

//Post-decrement
Fixed   Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->fixed_point_number_value;
	return (temp);
}


/*Min and max functions*/
Fixed&	Fixed::min(Fixed& fixed_point_number_1, Fixed& fixed_point_number_2){
    if (fixed_point_number_1 < fixed_point_number_2)
        return (fixed_point_number_1);
    else
        return (fixed_point_number_2);
}

const Fixed&    Fixed::min(const Fixed& fixed_point_number_1, const Fixed& fixed_point_number_2){
    if (fixed_point_number_1 < fixed_point_number_2)
        return (fixed_point_number_1);
    else
        return (fixed_point_number_2);
}

Fixed&	Fixed::max(Fixed& fixed_point_number_1, Fixed& fixed_point_number_2){
    if (fixed_point_number_1 > fixed_point_number_2)
        return (fixed_point_number_1);
    else
        return (fixed_point_number_2);
}

const Fixed&	Fixed::max(const Fixed& fixed_point_number_1, const Fixed& fixed_point_number_2){
    if (fixed_point_number_1 > fixed_point_number_2)
        return (fixed_point_number_1);
    else
        return (fixed_point_number_2);
}