/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:04:04 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/03/23 14:04:04 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED
#define FIXED

# include <iostream>
# include <math.h>

class Fixed
{
    private:
		int					fixed_point_number_value;
		static const int	fractional_bits = 8;
    public:
		// Constructor and destructor functions
        Fixed(void);
		Fixed(const Fixed &original);
		Fixed(int const integer_number);
		Fixed(float const float_number);
        ~Fixed();
		// Member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt( void ) const;
		/* Operator prototypes*/
		Fixed&	operator=(const Fixed& original);
		// Arithmetic operators
		Fixed	operator+(const Fixed& addition_number) const;
		Fixed	operator-(const Fixed& subtraction_number) const;
		Fixed	operator*(const Fixed &factor_number) const;
		Fixed	operator/(const Fixed &divisor_number) const;
		// Comparison operators
		bool	operator>(const Fixed& other_fixed_point_number) const;
		bool	operator<(const Fixed& other_fixed_point_number) const;
		bool	operator>=(const Fixed& other_fixed_point_number) const;
		bool	operator<=(const Fixed& other_fixed_point_number) const;
		bool	operator==(const Fixed& other_fixed_point_number) const;
		bool	operator!=(const Fixed& other_fixed_point_number) const;
		/*Increment and decrement*/
		Fixed&	operator++();
		Fixed&	operator++(int);
};

// Functions
std::ostream& operator<<(std::ostream &output, Fixed const &fixed_point_number);
#endif