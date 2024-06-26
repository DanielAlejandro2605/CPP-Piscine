/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:59:07 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/18 11:24:51 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        try {
            ScalarConverter::convert(argv[1]);
        } catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    else
    {
        std::cerr << "An argument is necessary." << std::endl;
    }
    return (0);
}