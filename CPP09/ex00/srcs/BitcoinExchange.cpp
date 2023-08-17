/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:37:15 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/17 17:56:30 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// /*
// ** ------------------------------- CONSTRUCTOR --------------------------------
// */

BitcoinExchange::BitcoinExchange()
{
    this->_db_infile.open("./database/data.csv", std::fstream::in);
    if (this->_db_infile.fail())
		throw BitcoinExchange::ErrorOpenFileDB();
	loadDataBase();
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


/*
** --------------------------------- METHODS ----------------------------------
*/

void	BitcoinExchange::exchange(const std::string &input_file)
{
	this->_arg_infile.open(input_file.c_str(), std::fstream::in);
	if (this->_arg_infile.fail())
		throw BitcoinExchange::ErrorOpenArgFile();
	while (this->_arg_infile.eof() == 0)
    {
        std::getline(this->_db_infile, this->_buffer);
		try
		{
			exchangeLine(this->_buffer);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
        i++;
    }
}


void	BitcoinExchange::loadDataBase(void)
{
	int i;

	i = 0;
    while (this->_db_infile.eof() == 0)
    {
        std::getline(this->_db_infile, this->_buffer);
        if (this->_buffer.empty())
            break;
        if (i != 0)
			addLineDB(this->_buffer, 0);
        else
        {
            if (this->_buffer.compare("date,exchange_rate") != 0)
				throw BitcoinExchange::ErrorInvalidDB();
        }
        i++;
    }
}

void	BitcoinExchange::addLineDB(const std::string &line, int c)
{
    std::string	sets[2] = {"0123456789-,.", "0123456789 |.-"};
	char		delim;

	/*Check set charaters*/
	switch (c)
	{
		case 0:
			if (!(line.find_first_not_of(sets[c]) == std::string::npos))
				throw BitcoinExchange::ErrorInvalidDB();
			delim = ',';
			break;
		case 1:
			// if (!(line.find_first_not_of(sets[c]) == std::string::npos))
			// 	throw;
			delim = '|';
			break;
	}
	checkLineFile(line, c, delim);
}

void	BitcoinExchange::checkLineFile(const std::string &line, int c, char delim)
{
	std::string	line_trim;
	std::string	date;
	std::string	aux_date;
	std::string btc_char_representation;
	double		btc_exchange;
	size_t		comma;
	char		*endptr;
	
	line_trim = trim(line);
	/*Getting value from string line*/
	date = line_trim.substr(0, line_trim.find(delim));
	aux_date = date;
	comma = line_trim.find(delim); 
	if ((comma == std::string::npos) || comma == (line_trim.length() - 1))
	{
		if (c == 0)
			BitcoinExchange::ErrorInvalidDB();
	}
	btc_char_representation = line_trim.substr(line_trim.find(delim) + 1);
	btc_exchange = std::strtod(btc_char_representation.c_str(), &endptr);
	/*Checking date*/
	if (checkDateFormat(aux_date) == false)
	{
		if (c == 0)
			throw BitcoinExchange::ErrorInvalidDB();
		
	}
	if (!(*endptr == '\0' || *endptr == '\n'))
	{
		if (c == 0)
			throw BitcoinExchange::ErrorInvalidDB();
	}
	this->_map.insert(std::make_pair(date, btc_exchange));
}

/*
** --------------------------------- UTILS ---------------------------------
*/

bool		BitcoinExchange::checkDateFormat(std::string &l)
{
	bool		valid_date;
	size_t		pos;
	long int	i;
	int			n;
	std::string token;
	std::string	delimiter;

	valid_date = true;
	if (l.length() > 10 || (l[4] != '-' || l[7] != '-'))
		valid_date = false;
	pos = 0;
	i = 0;
	delimiter = "-";
	while ((pos = l.find("-")) != std::string::npos || i < 3) {
		token = l.substr(0, pos);
		n = std::strtol(token.c_str(), NULL, 10);
		l.erase(0, pos + delimiter.length());
		switch (i)
		{
			case 0:
				if (n > 2023)
					valid_date = false;
				break;
			case 1:
				if (n > 12)
					valid_date = false;
				break;
			case 2:
				if (n > 31)
					valid_date = false;
				break;
		}
		i++;
	}
	return (valid_date);
}

std::string BitcoinExchange::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";

    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}


/*
** --------------------------------- PRINT ---------------------------------
*/

void BitcoinExchange::printMap(const std::map<std::string, float>& m) {
    std::map<std::string, float>::const_iterator it;
    for (it = m.begin(); it != m.end(); ++it) {
        std::cout << "Clave: " << it->first << ", Valor: " << it->second << std::endl;
    }
}
/* ************************************************************************** */