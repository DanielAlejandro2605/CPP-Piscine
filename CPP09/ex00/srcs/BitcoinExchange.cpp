/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:37:15 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/21 18:19:04 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

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


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

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
	int	i;

	this->_arg_infile.open(input_file.c_str(), std::fstream::in);
	if (this->_arg_infile.fail())
		throw BitcoinExchange::ErrorOpenArgFile();
	i = 0;
	while (this->_arg_infile.eof() == 0)
    {
        std::getline(this->_arg_infile, this->_buffer);
		if (i == 0)
		{
			if (this->_buffer.compare("date | value") != 0)
				throw BitcoinExchange::ErrorInvalidArgFile();
		}
		else
		{
			try
			{
				exchangeLine(this->_buffer, "0123456789-|. ", '|');
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		i++;
    }
}

void	BitcoinExchange::exchangeLine(const std::string &line, std::string set, char delim)
{
	std::string	line_trim;
	std::string	date;
	std::string	aux_date;
	std::string btc_char_representation;
	double		btc_exchange;
	size_t		sep;
	char		*endptr;

	if (!(line.find_first_not_of(set) == std::string::npos) || (line[10] != ' ' || line[12] != ' '))
	{
		std::cout << "Error: bad input => " << line << std::endl;	
		return ;
	}
	/*Removing quotes for check*/
	line_trim.assign(line);
	removeSpaces(line_trim);
	/*Getting date from string line*/
	date = line_trim.substr(0, line_trim.find(delim));
	sep = line.find(delim); 
	if ((sep == std::string::npos) || (sep == (line.length() - 2) && line[sep + 1] == ' '))
	{
		std::cout << "Error: value not provided => " << line << std::endl;
		return;
	}
	/*Checking date*/
	if ((checkDateFormat(date) == false))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return;
	}
	/*Checking amount to convert*/
	btc_char_representation = line.substr(line.find(delim) + 1);
	btc_exchange = std::strtod(btc_char_representation.c_str(), &endptr);
	if (btc_exchange < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return;
	}
	else if (btc_exchange > std::numeric_limits<int>::max())
	{
		std::cout << "Error: too large a number." << std::endl;
		return;	
	}
	exchangeValue(date, btc_exchange);
	// std::cout << date << std::endl;
	
}

/*Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.*/
void	BitcoinExchange::exchangeValue(std::string &date, float amount)
{
	this->_it_find = this->_map.lower_bound(date);
	if (this->_it_find != this->_map.begin() && (this->_it_find == this->_map.end() || this->_it_find->first != date)) {
		--this->_it_find;
	}
	std::cout << date << " => " << amount << " = " << (amount * this->_it_find->second) << std::endl;
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
			this->_map.insert(addLineDB(this->_buffer, "0123456789-,.", ','));
        else
        {
            if (this->_buffer.compare("date,exchange_rate") != 0)
				throw BitcoinExchange::ErrorInvalidDB();
        }
        i++;
    }
}

string_float_pair BitcoinExchange::addLineDB(const std::string &line, std::string set, char delim)
{
	std::string	date;
	std::string btc_char_representation;
	double		btc_exchange;
	size_t		sep;
	char		*endptr;

	/*Check correct set characters*/
	if (!(line.find_first_not_of(set) == std::string::npos))
		throw BitcoinExchange::ErrorInvalidDB();
	/*Getting value from string line*/
	date = line.substr(0, line.find(delim));
	sep = line.find(delim); 
	if ((sep == std::string::npos) || sep == (line.length() - 1))
	{
		BitcoinExchange::ErrorInvalidDB();
	}
	btc_char_representation = line.substr(line.find(delim) + 1);
	btc_exchange = std::strtod(btc_char_representation.c_str(), &endptr);
	/*Checking date*/
	if ((checkDateFormat(date) == false) || (!(*endptr == '\0' || *endptr == '\n')))
	{
		throw BitcoinExchange::ErrorInvalidDB();
	}
	return (std::make_pair(date, btc_exchange));
}

/*
** --------------------------------- UTILS ---------------------------------
*/

bool		BitcoinExchange::checkDateFormat(std::string &l)
{
	std::string	aux_date;
	bool		valid_date;
	size_t		pos;
	long int	i;
	int			n;
	std::string token;
	std::string	delimiter;

	aux_date = l;
	valid_date = true;
	if (aux_date.length() > 10 || (aux_date[4] != '-' || aux_date[7] != '-'))
		valid_date = false;
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

void BitcoinExchange::removeSpaces(std::string &str) {
    size_t pos = 0;
    size_t length = str.length();

    for (size_t i = 0; i < length; ++i) {
        if (str[i] != ' ') {
            str[pos] = str[i];
            ++pos;
        }
    }
    str.resize(pos);
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