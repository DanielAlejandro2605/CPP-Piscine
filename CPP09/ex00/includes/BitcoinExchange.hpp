/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:13:21 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/18 17:58:07 by dnieto-c         ###   ########.fr       */
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

typedef std::pair<std::string, float> string_float_pair;

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_map;
		std::ifstream 					_db_infile;
		std::ifstream 					_arg_infile;
		std::string						_buffer;

		/*Add line*/
		void				loadDataBase(void);
		string_float_pair	addLineDB(const std::string &line, std::string set, char delim);
		/*Exchange*/
		void				exchangeLine(const std::string &line, std::string set, char delim);
		void				exchangeValue(std::string &date, float amount);
		/*Utils*/
		bool				checkDateFormat(std::string &l);
		std::string 		trim(const std::string& str);
		void				removeSpaces(std::string &str);
		/*Print*/
		void				printMap(const std::map<std::string, float>& m);
		/*Iterators*/
		std::map<std::string, float>::iterator it_find;
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
					return ("Error: invalid input file.");
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