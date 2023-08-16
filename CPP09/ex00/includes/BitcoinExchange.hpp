/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:13:21 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/16 22:33:27 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <cstdlib>
# include <limits>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_map;
		std::ifstream 					_fs_infile;
		std::string						_buffer;

		/*Errors*/
		void		checkLine(const std::string &line, int c);
		void		checkLineFile(const std::string &line);
		/*Utils*/
		std::string trim(const std::string& str);
	public:
		BitcoinExchange();
		// BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();
		// BitcoinExchange &operator=(BitcoinExchange const &rhs);
		class ErrorOpenFileDB : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Error: to open the .csv file.");
				}
		};
		class ErrorInvalidCharFile : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Error: Invalid character input file.");
				}
		};
		class ErrorInvalidDB : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Error: Invalid character DB file used.");
				}
		};
};

#endif /* ************************************************* BITCOINEXCHANGE_H */