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

# include <iostream>

class Fixed
{
    private:
		int					_fixed_point_number_value;
		static const int	_fractional_bits = 8;
    public:
        Fixed(void);
		Fixed(const Fixed &original);
        ~Fixed();
		Fixed& operator=(const Fixed& original);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
