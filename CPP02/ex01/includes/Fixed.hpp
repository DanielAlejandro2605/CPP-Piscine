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
		int					_fixed_point_number_value;
		static const int	_fractional_bits = 8;
    public:
        Fixed(void);
		Fixed(const Fixed &original);
		Fixed(int const integer_number);
		Fixed(float const float_number);
        ~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt( void ) const;
		Fixed& operator=(const Fixed& original);
};

std::ostream& operator<<(std::ostream &output, Fixed const &fixed_point_number);
#endif