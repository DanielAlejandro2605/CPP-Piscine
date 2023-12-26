/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:36:14 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/05 17:51:07 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain(void) {
    std::cout << BGWHITE << "Brain constructor called!" << RESET << std::endl;
    return ;
}

Brain::Brain(const Brain &src)
{
    std::cout << BGWHITE << "Brain copy constructor called!" << RESET << std::endl;
    *this = src;
    return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
    std::cout << BGWHITE << "Brain destructor called!" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &Brain::operator=(Brain const &rhs)
{
	if (this != &rhs)
	{
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void    Brain::printFirstIdeas(void) const {
    for (int i = 0; i < 5; i++)
    {
        if (!this->_ideas[i].empty())
            std::cout << BLUE << "Idea " << i << " : [ " << this->_ideas[i] << " ]" << RESET << std::endl;
    }    
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string Brain::getIdeaByIdx(int idx) const {
    if (idx >= 0 && idx < 100)
        return (this->_ideas[idx]);
    std::cout << RED << "Brain only has 100!" << RESET << std::endl;
    return (NULL);
}

std::string	*Brain::getIdeas(void) {
    return (this->_ideas);
}

void	Brain::setIdeas(std::string idea) {
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = idea;
}

void	Brain::setIdeaIdx(int idx, std::string idea) {
    if (idx >= 0 && idx < 100)
        this->_ideas[idx].assign(idea);
}

/* ************************************************************************** */