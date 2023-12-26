/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:03:36 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/03 17:46:51 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>

#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"
#define RESET	"\033[0m"
#define PURPLE	"\e[95m"

#define BGBLACK "\033[40m"
#define BGRED "\033[41m"
#define BGGREEN "\033[42m"
#define BGYELLOW "\033[43m"
#define BGBLUE "\033[44m"
#define BGMAGENTA "\033[45m"
#define BGCYAN "\033[46m"
#define BGWHITE "\033[47m"

template<typename T>
typename T::iterator easyfind(T& container, int n) {
    typename T::iterator iter = std::find(container.begin(), container.end(), n);
	return iter;
}

template<typename T>
void printContainerInline(T& container) {
    for (typename T::iterator iter = container.begin(); iter != container.end(); iter++)
		std::cout << YELLOW << *iter << ", " << RESET;
	std::cout << std::endl;
}

#endif /* ******************************************************** EASYFIND_H */