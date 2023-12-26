/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:40:59 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/26 14:01:09 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED
#define SED

# include <iostream>
# include <fstream>

class Sed
{
	private:
		std::string		_buffer;
		std::string		_name_file;
		std::string		_str_to_search;
		std::string		_str_to_replace;
		int				_len_str_to_search;
		int				_len_str_to_replace;
	public:
		Sed(char *argv[]);
		~Sed();
		void	sedIsForLosers(void);
};

#endif