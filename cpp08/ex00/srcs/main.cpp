/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:56:13 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/29 10:53:38 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"
# include <vector>
# include <list>
# include <set>

int main() {
    {
        std::cout << BGWHITE << "Testing easyfind in vector container" << RESET << std::endl;
        int arr_vec[] = {1, 2, 3, 4, 5};
        std::vector<int> v(arr_vec, arr_vec + sizeof(arr_vec) / sizeof(arr_vec[0]));
        int value_searched_vec = 10;
        std::cout << BGGREEN << "Search: " << value_searched_vec << RESET << std::endl;
		printContainerInline(v);
        
        std::vector<int>::iterator iter_vec = easyfind(v, value_searched_vec);

        if (iter_vec != v.end()) {
            std::cout << "Value " << value_searched_vec << " found in v (vector)." << std::endl;
        } else {
            std::cout << "Value " << value_searched_vec << " not found in v (vector)." << std::endl;
        }   
    }
    {
		std::cout << BGWHITE << "Testing easyfind in list container" << RESET << std::endl;
		int arr_lst[] = {156, 254, 443, 44, 55};
		std::list<int> lst(arr_lst, arr_lst + sizeof(arr_lst) / sizeof(arr_lst[0]));
        int value_searched_lst = 55;
        std::cout << BGGREEN << "Search: " << value_searched_lst << RESET << std::endl;
		printContainerInline(lst);
        
		std::list<int>::iterator iter_lst = easyfind(lst, value_searched_lst);
		if (iter_lst != lst.end()) {
            std::cout << "Value " << value_searched_lst << " found in lst (list)." << std::endl;
        } else {
            std::cout << "Value " << value_searched_lst << " not found in lst (list)." << std::endl;
        }
    }
	{
		std::cout << BGWHITE << "Testing easyfind in set container" << RESET << std::endl;
		int arr_set[] = {656, -2384, 4543, 40, -55};
		std::set<int> set(arr_set, arr_set + sizeof(arr_set) / sizeof(arr_set[0]));
        int value_searched_set = 40;
        std::cout << BGGREEN << "Search: " << value_searched_set << RESET << std::endl;
		printContainerInline(set);
        
		std::set<int>::iterator iter_set = easyfind(set, value_searched_set);
        
		if (iter_set != set.end()) {
            std::cout << "Value " << value_searched_set << " found in set (set)." << std::endl;
        } else {
            std::cout << "Value " << value_searched_set << " not found in set (set)." << std::endl;
        }
	}
    return 0;
}
