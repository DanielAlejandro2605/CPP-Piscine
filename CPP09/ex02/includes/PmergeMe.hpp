/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:04:57 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/09/06 18:34:39 by dnieto-c         ###   ########.fr       */
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
# include <algorithm>

class PmergeMe
{
	private:
		std::vector<int>							_data;
		std::vector<int>							_main_chain;
		std::vector<int>							_pending;
		int											_data_length;
		std::vector<std::pair<int, int> > 			_pairs;
		std::vector<int>::iterator 					_i;
		std::vector<int>::iterator					_j;
		std::vector<std::pair<int, int> >::iterator _i_pairs;
		int											_i_debug;
	public:
		PmergeMe(char **);
		// PmergeMe(PmergeMe const &src);
		~PmergeMe();
		// PmergeMe &operator=(PmergeMe const &rhs);
		/*Sort function*/
		void	sort(void);
		void	getPairsFromVector(std::vector<int>);
		void	addToMainChain(int n);
		class Error : public std::exception {
		public:
			const char* what() const throw();
		};
		class DuplicatesError : public std::exception {
		public:
			const char* what() const throw();
		};
};

bool estaOrdenado(const std::vector<int>& vec);
void imprimirElementosUnicos(const std::vector<int>& vec1, const std::vector<int>& vec2);
std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */