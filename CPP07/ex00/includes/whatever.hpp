/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:09:25 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/23 10:56:55 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

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

#define BGBLACK "\033[40m"
#define BGRED "\033[41m"
#define BGGREEN "\033[42m"
#define BGYELLOW "\033[43m"
#define BGBLUE "\033[44m"
#define BGMAGENTA "\033[45m"
#define BGCYAN "\033[46m"
#define BGWHITE "\033[47m"

template<typename TYPE>
void swap(TYPE& ptr1, TYPE& ptr2)
{
	TYPE temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

template<typename T>
T&	min(T &a, T &b)
{
	return (a < b) ? a : b;	
}

template<typename TIPO>
TIPO&	max(TIPO &a, TIPO &b){
	return (a > b) ? a : b; 
}

#endif /* ******************************************************** WHATEVER_H */