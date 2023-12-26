/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:36:55 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/29 23:31:37 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

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

class Brain {
	private:
		std::string	_ideas[100];
	public:
		Brain(void);
		Brain(Brain const &src);
		~Brain(void);
		Brain &operator=(Brain const &rhs);
		/*Getters*/
		std::string getIdeaByIdx(int idx) const;
		std::string	*getIdeas(void);
		/*Setters*/
		void    	setIdeas(std::string idea);
		void		setIdeaIdx(int idx, std::string idea);
		/*Methods*/
		void		printFirstIdeas(void) const;
};

#endif
