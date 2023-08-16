/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:12:35 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/16 16:18:32 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    try {
        BitcoinExchange var;        
    }
   catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
