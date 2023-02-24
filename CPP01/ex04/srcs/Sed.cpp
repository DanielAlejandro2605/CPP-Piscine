/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:06:47 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/02/24 19:08:48 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"

Sed::Sed(char *argv[])
{
    std::cout << "Executing the constructor of class Sed\n";
    this->_name_file = argv[0];
	this->_str_to_search = argv[1];
    this->_str_to_replace = argv[2];
	this->length_str_to_search = (int)this->_str_to_search.length();
	this->length_str_to_replace = (int)this->_str_to_replace.length();
}

Sed::~Sed(void)
{
    std::cout << "Executing the destructor of class Sed\n";
}

void	Sed::replacePatternLine(int first_occurrence_idx)
{
	std::string	line_pattern;

	line_pattern = this->_buffer;
	line_pattern.erase(first_occurrence_idx, this->_str_to_search.length());
	line_pattern.append(this->_str_to_replace);
	if (line_pattern.find(this->_str_to_search))
	{
		std::cout << "Ici\n\n";
	}
	std::cout << "Ici\n\n";
	std::cout << line_pattern;
}

void    Sed::sedIsForLosers(void)
{
    std::ifstream 	fs_infile;
	std::ofstream	fs_outfile;
	std::string		line_pattern;
	std::string		line_aux;
	std::string		line_result;
	size_t			ch;

    fs_infile.open(this->_name_file.c_str(), std::fstream::in);
	if (fs_infile.fail())
	{
		std::cout << "Error: Failed to open the infile\n";
		return ;
	}
	fs_outfile.open(this->_name_file.append(".replace").c_str(), std::fstream::out);
	if (fs_outfile.fail())
	{
		std::cout << "Error: Failed to open the outfile\n";
		fs_infile.close();
		return ;
	}
	while(std::getline(fs_infile, this->_buffer))
    {
		// std::cout << "Original line : \n";
		// std::cout << this->_buffer;
		// std::cout << "\n";
		if (this->_buffer.empty())
			std::cout << "Is empty\n";
		else
			std::cout << "Hay algo\n";
		ch = this->_buffer.find(this->_str_to_search);
		if (ch != std::string::npos)
		{
			line_pattern.assign(this->_buffer);
			while (ch != std::string::npos)
			{
				line_result.append(line_pattern.substr(0, ch));
				// std::cout << "Lo que habia antes por si hay :";
				// std::cout << line_result;
				// std::cout << "\n";
				line_result.append(this->_str_to_replace);
				// std::cout << "Ahora remplazando : ";
				// std::cout << line_result;
				// std::cout << "\n";
				line_aux = line_pattern.substr(this->_str_to_search.length() + ch);
				// std::cout << "Line aux avanzanda \n";
				// std::cout << line_aux;
				// std::cout << "\n";
				line_pattern.assign(line_aux);
				// std::cout << "Line pattern avanzanda \n";
				// std::cout << line_aux;
				// std::cout << "\n";
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
}