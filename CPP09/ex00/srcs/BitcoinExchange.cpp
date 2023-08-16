/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:37:15 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/16 22:46:24 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// /*
// ** ------------------------------- CONSTRUCTOR --------------------------------
// */

BitcoinExchange::BitcoinExchange()
{
    int i;

    this->_fs_infile.open("./database/data.csv", std::fstream::in);
    if (this->_fs_infile.fail())
	{
		throw BitcoinExchange::ErrorOpenFileDB();
	}
    i = 0;
    while (this->_fs_infile.eof() == 0)
    {
        std::getline(this->_fs_infile, this->_buffer);
        // std::cout << this->_buffer << std::endl;
        // std::cout << i << std::endl;
        if (this->_buffer.empty())
            break;
        if (i != 0)
        	checkLine(this->_buffer, 0);
        else
        {
            if (this->_buffer.compare("date,exchange_rate") != 0)
				throw BitcoinExchange::ErrorInvalidDB();
        }
        i++;
    }
}

// BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
// {
// }


// /*
// ** -------------------------------- DESTRUCTOR --------------------------------
// */

BitcoinExchange::~BitcoinExchange()
{
}


// /*
// ** --------------------------------- OVERLOAD ---------------------------------
// */

// BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

// std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


// /*
// ** --------------------------------- METHODS ----------------------------------
// */

// DB : 2011-12-21,4.08
// File : 2011-01-03|1

void	BitcoinExchange::checkLine(const std::string &line, int c)
{
    std::string	sets[2] = {"0123456789-,.", "0123456789 |.-"};

	

	switch (c)
	{
		case 0:
			checkLineFile(line);
			break ;
		case 1:
			if (!(line.find_first_not_of(sets[1]) == std::string::npos))
				throw BitcoinExchange::ErrorInvalidCharFile();
			break ;
	}
}

void	BitcoinExchange::checkLineFile(const std::string &line)
{
	std::string	date;
	std::string	aux_date;
	std::string btc_char_representation;
	double		btc_exchange;
	size_t		comma;
	
	/*Getting value from string line*/
	date = line.substr(0, line.find(','));
	aux_date = date;
	comma = line.find(','); 
	if ((comma == std::string::npos) || comma == (line.length() - 1))
		throw BitcoinExchange::ErrorInvalidDB();
	btc_char_representation = line.substr(line.find(',') + 1);
	btc_exchange = std::strtod(btc_char_representation.c_str(), NULL);
	
	/*Checking date*/
	if (aux_date.length() > 10 || (aux_date[4] != '-' || aux_date[7] != '-'))
		throw BitcoinExchange::ErrorInvalidDB();

	size_t		pos;
	long int	i;
	int			n;
	std::string token;
	std::string	delimiter;

	pos = 0;
	i = 0;
	delimiter = "-";
	while ((pos = aux_date.find("-")) != std::string::npos || i < 3) {
		token = aux_date.substr(0, pos);
		n = std::strtol(token.c_str(), NULL, 10);
		aux_date.erase(0, pos + delimiter.length());
		switch (i)
		{
			case 0:
				if (n > 2023)
					throw BitcoinExchange::ErrorInvalidDB();
				break;
			case 1:
				if (n > 12)
					throw BitcoinExchange::ErrorInvalidDB();
				break;
			case 2:
				if (n > 31)
					throw BitcoinExchange::ErrorInvalidDB();
				break;
		}
		i++;
	}
	/* */
	if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		throw BitcoinExchange::ErrorInvalidDB();
	this->_map.insert(std::pair<std::string, float>(date, btc_exchange));
}

/*
** --------------------------------- UTILS ---------------------------------
*/


std::string BitcoinExchange::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";

    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

// /* ************************************************************************** */