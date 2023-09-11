/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:04:57 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/09/11 11:08:54 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstring>
# include <cstdlib>
# include <string>
# include <vector>
# include <set>
# include <list>
# include <algorithm>

class PmergeMe
{
	private:
		/*Vector data*/
		std::vector<int>							_main_chain_v;
		std::vector<int>							_pending_v;
		std::vector<int>							_data_v;
		int											_data_v_length;
		std::vector<int>::iterator 					_i;
		std::vector<int>::iterator					_j;
		/*This is iterator is for the recursion*/
		std::vector<std::pair<int, int> >::iterator _i_pairs_v;
		std::list<std::pair<int, int> >::iterator 	_i_pairs_l;
		/*List data*/
		std::list<int>								_data_l;
		std::list<int>								_main_chain_l;
		std::list<int>								_pending_l;
		
	public:
		PmergeMe(char **);
		// PmergeMe(PmergeMe const &src);
		~PmergeMe();
		// PmergeMe &operator=(PmergeMe const &rhs);
		/*Sort function*/
		void	sort(void);
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
		class DuplicatesError : public std::exception {
		public:
			const char* what() const throw();
		};
};

bool checkSortVector(const std::vector<int>& vec);
bool checkSortList(const std::list<int>& lst);
void imprimirElementosUnicos(const std::vector<int>& vec1, const std::vector<int>& vec2);
std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

template <typename Container>
void TrouverDoublons(const Container& container) {
    std::set<typename Container::value_type> elements_uniques;
    std::set<typename Container::value_type> doublons;

    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        if (elements_uniques.find(*it) == elements_uniques.end()) {
            elements_uniques.insert(*it);
        } else {
            doublons.insert(*it);
        }
    }

    for (typename std::set<typename Container::value_type>::iterator it = doublons.begin(); it != doublons.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void AfficherElementsDifferents(const Container& container1, const Container& container2) {
    std::set<typename Container::value_type> elements_container1(container1.begin(), container1.end());
    std::set<typename Container::value_type> elements_container2(container2.begin(), container2.end());
    
    for (typename std::set<typename Container::value_type>::iterator it = elements_container1.begin(); it != elements_container1.end(); ++it) {
        if (elements_container2.find(*it) == elements_container2.end()) {
            // Si l'élément de container1 n'est pas présent dans container2, l'afficher
            std::cout << *it << " ";
        }
    }
    
    for (typename std::set<typename Container::value_type>::iterator it = elements_container2.begin(); it != elements_container2.end(); ++it) {
        if (elements_container1.find(*it) == elements_container1.end()) {
            // Si l'élément de container2 n'est pas présent dans container1, l'afficher
            std::cout << *it << " ";
        }
    }
    
    std::cout << std::endl;
}

template <typename Container>
void AfficherElements(const Container& container) {
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


#endif /* ******************************************************** PMERGEME_H */