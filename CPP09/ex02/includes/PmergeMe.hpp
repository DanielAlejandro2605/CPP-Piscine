/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:04:57 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/09/13 17:22:49 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <cstring>
# include <cstdlib>
# include <string>
# include <vector>
# include <list>
# include <algorithm>

class PmergeMe
{
	private:
		/*Vector argument data*/
		std::vector<int>							_data_v;
		std::vector<int>::iterator 					_i;
		std::vector<int>::iterator					_j;
		/*Vector data*/
		std::vector<int>							_main_chain_v;
		std::vector<int>							_pending_v;
		/*This is iterator is for the recursion in std::vector*/
		std::vector<std::pair<int, int> >::iterator _i_pairs_v;
        /*This is iterator is for the recursion in std::list*/
		std::list<std::pair<int, int> >::iterator 	_i_pairs_l;
		/*List data*/
		std::list<int>								_data_l;
		std::list<int>								_main_chain_l;
		std::list<int>								_pending_l;
        /*Time variables*/
        clock_t                                     _start;
        clock_t                                     _end;
	public:
		PmergeMe(char **);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &rhs);
		/*Sort function*/
		void	sort(void);
        /*Sort list*/
        void    sortList(void);
        /*Sort vector*/
        void    sortVector(void);
        /*Check algorithm*/
        void    checkPmergeMe(void);
		/*Vector*/
		void	getPairsVector(std::vector<int>);
		void	addToMainChainVector(int);
		/*List*/
		void getPairsList(std::list<int>);
		void addToMainChainList(int);
		class Error : public std::exception {
		public:
			const char* what() const throw();
		};
        class MissingError : public std::exception {
		public:
			const char* what() const throw();
		};
		class DuplicatesError : public std::exception {
		public:
			const char* what() const throw();
		};
};

template <typename Container>
void printContainerElements(const Container& container) {
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
bool checkContainerSorted(const Container& container) {
    typename Container::const_iterator	prev_it;
    typename Container::const_iterator	it = prev_it;
	
	prev_it = container.begin();
	it = prev_it;
    ++it;

    while (it != container.end()) {
        if (*it < *prev_it) {
            std::cout << "The container is not sorted: " << *it << " " << *prev_it << std::endl;
            return false;
        }
        ++it;
        ++prev_it;
    }
    return true;
}

#endif /* ******************************************************** PMERGEME_H */