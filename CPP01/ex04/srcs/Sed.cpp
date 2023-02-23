/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:06:47 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/02/24 00:42:57 by dnieto-c         ###   ########.fr       */
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

void	Sed::replacePatternLine(void)
{
	std::string	new_line;
	int			i;
	int			j;
	int			len_fd_output;

	len_fd_output = (int)this->_buffer.length();
	std::cout << "En este caso la string tiene de length: " << len_fd_output << "\n";
	i = 0;
	while (i < len_fd_output)
	{
		// std::cout << this->_buffer[i];
		if (this->_buffer[i] == this->_str_to_search[0])
		{
			j = 0;
			while (this->_buffer[i + j] == this->_str_to_search[j])
				j++;
			if (j - 1 == this->length_str_to_replace)
			{
				std::cout << "Yes\n";
			}
		}
		i++;
	}
	std::cout << "\n";
}

void    Sed::sedIsForLosers(void)
{
    std::fstream	fs_infile;
	std::fstream	fs_outfile;
	int				ch;
	// int				i;

	ch = -1;
    fs_infile.open (this->_name_file, std::fstream::in);
	fs_outfile.open ("result.txt", std::fstream::out);
	while(fs_infile.eof() == 0)
    {
		std::getline(fs_infile, this->_buffer);
		std::cout << this->_buffer << "\n";
		ch = this->_buffer.find(this->_str_to_search);
		if ((int)ch > -1)
		{
			
			std::cout << "En esta linea esta la palabra : " << this->_buffer << "\n";
			std::cout << this->_buffer[ch] << " " << ch << "\n";
			this->replacePatternLine();
			// i = 0;
			// while (this->_buffer[ch + i] == this->_str_to_search[i])
			// 	i++;
			// if ((i - 1) == (int)this->_str_to_search.length())
			// {
			// 	std::cout << "Yes\n";
			// }
		}
		// // else
		// // {
			
		// // }
    }
    fs_infile.close();
}