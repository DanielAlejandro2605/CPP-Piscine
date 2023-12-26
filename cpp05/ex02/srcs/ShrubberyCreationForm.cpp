/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:35:25 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/19 16:38:42 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Form", target, 145, 137) 
{
	std::cout << PURPLE << "ShrubberyCreationForm constructor called!" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
	std::cout << PURPLE << "ShrubberyCreationForm copy constructor called!" << RESET << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << PURPLE << "ShrubberyCreationForm destructor called!" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &		ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs)
{
	this->AForm::operator=(rhs);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/* Esta excepción es específica de la clase std::ofstream y se utiliza para indicar errores
relacionados con la apertura o escritura de archivos. */
void	ShrubberyCreationForm::action(Bureaucrat const &executor) const {
	this->AForm::execute(executor);
	try {
    	std::ofstream outfile((this->getTarget() + "_shrubbery").c_str());
		if (!outfile.is_open()) {
			throw std::ofstream::failure(strerror(errno));
		}
		outfile << "                                .         ;" << std::endl;  
		outfile << "       .              .              ;%     ;;" << std::endl;   
		outfile << "        ,           ,                :;%  %;" << std::endl;
		outfile << "         :         ;                   :;%;'     .,"  << std::endl;
		outfile << ",.        %;     %;            ;        %;'    ,;" << std::endl;
		outfile << "         ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
		outfile << "          %;       %;%;      ,  ;       %;  ;%;   ,%;'"  << std::endl;
		outfile << "           ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
		outfile << "            `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
		outfile << "             `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
		outfile << "                `:%;.  :;bd%;          %;@%;'" << std::endl;
		outfile << "                  `@%:.  :;%.         ;@@%;'"    << std::endl;
		outfile << "                    `@%.  `;@%.      ;@@%;"          << std::endl;
		outfile << "                      `@%%. `@%%    ;@@%;"         << std::endl;
		outfile << "                        ;@%. :@%%  %@@%;"        << std::endl;
		outfile << "                          %@bd%%%bd%%:;"      << std::endl;
		outfile << "                            #@%%%%%:;;" << std::endl;
		outfile << "                            %@@%%%::;" << std::endl;
		outfile << "                            %@@@%(o);  . '"          << std::endl;
		outfile << "                            %@@@o%;:(.,'"          << std::endl;
		outfile << "                        `.. %@@@o%::;"          << std::endl;
		outfile << "                           `)@@@o%::;"         << std::endl;
		outfile << "                            %@@(o)::;"         << std::endl;
		outfile << "                           .%@@@@%::;"         << std::endl;
		outfile << "                           ;%@@@@%::;."           << std::endl;
		outfile << "                          ;%@@@@%%:;;;."  << std::endl;
		outfile << "                      ...;%@@@@@%%:;;;;,.." << std::endl;
	} catch (const std::ofstream::failure& ex) {
		std::cerr << "Error opening the file: " << ex.what() << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/