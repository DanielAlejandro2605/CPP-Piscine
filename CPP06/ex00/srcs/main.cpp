/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:59:07 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/27 14:59:58 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        try {
            ScalarConverter instance(argv[1]);
            instance.convert();
        }
    }
    return (0);
}