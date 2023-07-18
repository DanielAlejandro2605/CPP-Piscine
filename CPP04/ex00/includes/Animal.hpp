/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:09:17 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/05 17:48:17 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

// Colores de texto
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"
#define PURPLE    "\e[95m"

// Colores de fondo
#define BGBLACK "\033[40m"
#define BGRED "\033[41m"
#define BGGREEN "\033[42m"
#define BGYELLOW "\033[43m"
#define BGBLUE "\033[44m"
#define BGMAGENTA "\033[45m"
#define BGCYAN "\033[46m"
#define BGWHITE "\033[47m"

/*La declaración del destructor virtual es importante cuando se trabaja con herencia
y se espera que las clases derivadas tengan su propio comportamiento de limpieza.
Al hacer que el destructor sea virtual, se garantiza que se llame correctamente al
destructor de la clase derivada cuando se destruye un objeto de la clase base a través
de un puntero de la clase base.*/

class Animal
{
	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const & src);
		virtual ~Animal();
		Animal &operator=(Animal const & rhs);
		/*Accessors*/
		std::string		getType(void) const;
		/*Methods*/
		virtual void	makeSound(void) const;
};

std::ostream& operator<<(std::ostream &output, Animal const &instance_animal);

#endif /* ********************************************************** ANIMAL_H */