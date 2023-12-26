/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:59:20 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/01 11:08:06 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Data.hpp"

int main(void)
{
    Data input;

	input._name = "Free";
	input._adresses[0] = "15 rue Tolbiac";
    input._adresses[1] = "43 Bd Massena";
    input._adresses[2] = "58 rue Rivoli";
    input._adresses[3] = "4 rue Rennes";
	input._num_employees = 5627;
    input._trade_registration = "116-4544AB-311";
	input._actives = 885648484.24;
	input._pasives = 465456.55;

	std::cout << "Name: " << input._name << std::endl;

    std::cout << "Addresses:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "  " << input._adresses[i] << std::endl;
    }

    std::cout << "Number of Employees: " << input._num_employees << std::endl;
    std::cout << "Trade registration: " << input._trade_registration << std::endl;
    std::cout << "Actives: " << input._actives << std::endl;
    std::cout << "Pasives: " << input._pasives << std::endl;
	std::cout << "------------------------" << std::endl;

	uintptr_t output_uintptr = serialize(&input);

	Data* output = deserialize(output_uintptr);

    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "Name: " << output->_name << std::endl;

    std::cout << "Addresses:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "  " << output->_adresses[i] << std::endl;
    }

    std::cout << "Number of Employees: " << output->_num_employees << std::endl;
    std::cout << "Trade registration: " << output->_trade_registration << std::endl;
    std::cout << "Actives: " << output->_actives << std::endl;
    std::cout << "Pasives: " << output->_pasives << std::endl;
    return (0);
}