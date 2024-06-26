/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:06:47 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/26 14:05:36 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"

Sed::Sed(char *argv[])
{
    std::cout << "Executing the constructor of class Sed" << std::endl;
    this->_name_file = argv[0];
	this->_str_to_search = argv[1];
    this->_str_to_replace = argv[2];
	this->_len_str_to_search = (int)this->_str_to_search.length();
	this->_len_str_to_replace = (int)this->_str_to_replace.length();
}

Sed::~Sed(void)
{
    std::cout << "Executing the destructor of class Sed" << std::endl;
}

void    Sed::sedIsForLosers(void)
{
    std::ifstream 	fs_infile;
	std::ofstream	fs_outfile;
	std::string		line_pattern;
	std::string		line_aux;
	std::string		line_result;
	size_t			ch;

	if (this->_str_to_search.empty() || this->_str_to_replace.empty())
	{
		std::cout << "Is better to search or replace not empty strings!" << std::endl;
		return ;
	}
    fs_infile.open(this->_name_file.c_str(), std::fstream::in);
	if (fs_infile.fail())
	{
		std::cout << "Error: Failed to open the infile" << std::endl;
		return ;
	}
	fs_outfile.open(this->_name_file.append(".replace").c_str(), std::fstream::out);
	if (fs_outfile.fail())
	{
		std::cout << "Error: Failed to open the outfile" << std::endl;
		fs_infile.close();
		return ;
	}
	while(fs_infile.eof() == 0)
    {
		std::getline(fs_infile, this->_buffer);
		if (fs_infile.eof() == 0)
		{
			this->_buffer.append("\n");
		}
		ch = this->_buffer.find(this->_str_to_search);
		if (ch != std::string::npos)
		{
			line_pattern.assign(this->_buffer);
			while (ch != std::string::npos)
			{
				// Append the content of string before first occurence of the word searched
				line_result.append(line_pattern.substr(0, ch));
				// Append string to replace
				line_result.append(this->_str_to_replace);
				// Get line after the first occurence + the length of the word searched
				line_aux = line_pattern.substr(this->_str_to_search.length() + ch);
				// Update the line for continue searching
				line_pattern.assign(line_aux);
				// Concatenate the result string
				ch = line_pattern.find(this->_str_to_search);
				if (ch == std::string::npos && line_pattern.length() > 0)
					line_result.append(line_pattern);
			}
			fs_outfile << line_result; 
			line_result.clear();
			line_pattern.clear();
			line_aux.clear();
		}
		else
		{
			fs_outfile << this->_buffer; 
		}
    }
    fs_infile.close();
	fs_outfile.close();
}