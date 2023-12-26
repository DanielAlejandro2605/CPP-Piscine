/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:35:54 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/01 11:09:33 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
# include <stdint.h> 

typedef struct Data
{
	std::string	_name;
	std::string	_adresses[4];
	int			_num_employees;
	std::string	_trade_registration;
	double		_actives;
	double		_pasives;
}				Data;

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);
#endif /* ************************************************************ DATA_H */