/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:04:57 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/30 18:57:17 by dnieto-c         ###   ########.fr       */
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

class PmergeMe
{
	private:
		std::vector<int>							_data;
		std::vector<int>							_pending;
		int											_data_length;
		std::vector<std::pair<int, int> > 			_pairs;
		std::vector<int>::iterator 					_i;
		std::vector<int>::iterator					_j;
		std::vector<std::pair<int, int> >::iterator _i_pairs;
	public:
		PmergeMe(char **);
		// PmergeMe(PmergeMe const &src);
		~PmergeMe();
		// PmergeMe &operator=(PmergeMe const &rhs);
		/*Sort function*/
		void	sort(void);
		void	getPairsFromVector(std::vector<int>);
		class Error : public std::exception {
		public:
			const char* what() const throw();
		};
		class DuplicatesError : public std::exception {
		public:
			const char* what() const throw();
		};
};

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */