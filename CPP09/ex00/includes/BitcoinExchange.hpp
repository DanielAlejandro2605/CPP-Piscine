/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:13:21 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/17 17:53:31 by dnieto-c         ###   ########.fr       */
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
		std::ifstream 					_db_infile;
		std::ifstream 					_arg_infile;
		std::string						_buffer;

		/*Add line*/
		void		loadDataBase(void);
		void		addLineDB(const std::string &line, int c);
		/*Checking*/
		void		checkLine(const std::string &line, int c);
		void		checkLineFile(const std::string &line, int c, char delim);
		/*Utils*/
		bool		checkDateFormat(std::string &l);
		std::string trim(const std::string& str);
		/*Print*/
		void		printMap(const std::map<std::string, float>& m);
	public:
		BitcoinExchange();
		// BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();
		// BitcoinExchange &operator=(BitcoinExchange const &rhs);

		/*Convert main function*/
		void	exchange(const std::string &input_file);

		/*Exceptions*/
		class ErrorOpenFileDB : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Error: could not open .csv file.");
				}
		};
		class ErrorInvalidDB : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Error: invalid character DB file used.");
				}
		};
		class ErrorInvalidArgFile : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Error: invalid character input file.");
				}
		};
		class ErrorOpenArgFile : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Error: could not open file.");
				}
		};
};

#endif /* ************************************************* BITCOINEXCHANGE_H */