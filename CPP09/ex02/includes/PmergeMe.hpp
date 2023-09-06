/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:04:57 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/09/06 20:50:17 by dnieto-c         ###   ########.fr       */
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

#endif /* ******************************************************** PMERGEME_H */