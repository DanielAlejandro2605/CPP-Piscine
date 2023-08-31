#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe(char **arg)
{
	std::pair<std::set<int>::iterator,bool> ret;
	std::string	set;
	int			i;

	set = "0123456789";
	i = 0;
	while (arg[i])
	{
		std::string arg_str(arg[i], strlen(arg[i]));
		if (!(arg_str.find_first_not_of(set) == std::string::npos))
			throw PmergeMe::Error();
		this->_data.push_back(std::atoi(arg[i]));
		i++;
	}
	for (this->_i = this->_data.begin(); this->_i != this->_data.end(); this->_i++)
	{
		for (this->_j = this->_i + 1; this->_j != this->_data.end(); this->_j++)
		{
			if (*this->_i == *this->_j)
				throw PmergeMe::DuplicatesError();
		}
	}
	this->_data_length = this->_data.size();
	std::cout << "Hay :" << this->_data_length << std::endl;
}

// PmergeMe::PmergeMe( const PmergeMe & src )
// {
// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

// std::ostream &			operator<<( std::ostream & o, PmergeMe const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/
void	PmergeMe::sort(void)
{
	getPairsFromVector(this->_data);
	// std::cout << "main chain: ";
	// for(std::vector<int>::iterator i = this->_main_chain.begin(); i != this->_main_chain.end(); i++)
	// 	std::cout << " " << *i;
	// std::cout << std::endl;
	// std::cout << "pending: ";
	// for(std::vector<int>::iterator i = this->_pending.begin(); i != this->_pending.end(); i++)
	// 	std::cout << " " << *i;
	// std::cout << std::endl;
}

void	PmergeMe::getPairsFromVector(std::vector<int> v)
{
	(void)v;
	// std::vector<int>							new_vec;
	// std::vector<std::pair<int, int> > 			pairs;
	// std::vector<std::pair<int, int> >::iterator i_pairs;
	// // int	firstValue;
	// // int	secondValue;
	// int p1;
	// int p2;
	// // int	insert;

	// for (size_t i = 0; i < v.size(); i += 2) {
	// 	p1 = v[i];
    //     p2 = (i + 1 < v.size()) ? v[i + 1] : 0;
	// 	if (p1 < p2) {
	// 		pairs.push_back(std::make_pair(p2, p1));
	// 	} else {
	// 		pairs.push_back(std::make_pair(p1, p2));
	// 	}
    // }

	// for(i_pairs = pairs.begin(); i_pairs != pairs.end(); i_pairs++)
	// {
	// 	std::cout << "(" << i_pairs->first << "-" << i_pairs->second << ")";
	// 	// if (i_pairs->second != 0 || (i_pairs->second == 0 && this->_pending.size() > 0))
	// 	// {
	// 	// 	new_vec.push_back(i_pairs->first);
	// 	// }
	// 	// else if (i_pairs->second == 0 && this->_pending.size() == 0)
	// 	// {
	// 	// 	this->_pending.push_back(i_pairs->first);
	// 	// }
	// 	if (i_pairs->second != 0)
	// 	{
	// 		new_vec.push_back(i_pairs->first);
	// 	}
	// 	else
	// 	{
	// 		this->_pending.push_back(i_pairs->first);
	// 	}
	// }
	// std::cout << std::endl;
	// std::cout << "new vec :";
	// for(std::vector<int>::iterator i = new_vec.begin(); i != new_vec.end(); i++)
	// 	std::cout << " " << *i;
	// std::cout << std::endl;
	// if (((this->_data.size() % 2) == 0) && pairs.size() == 1)
	// {
	// 	i_pairs = pairs.begin();
	// 	this->_main_chain.push_back(i_pairs->first);
	// 	this->_main_chain.push_back(i_pairs->second);
	// 	return;
	// }
	// else if (!((this->_data.size() % 2) == 0) && pairs.size() == 2)
	// {
	// 	i_pairs = pairs.begin();
	// 	this->_main_chain.push_back(i_pairs->first);
	// 	this->_main_chain.push_back(i_pairs->second);
	// 	return;
	// }

	// getPairsFromVector(new_vec);
	// // std::cout << "After getPairsFromVector : ";
	// // for(i_pairs = pairs.begin(); i_pairs != pairs.end(); i_pairs++)
	// // {
	// // 	std::cout << "(" << i_pairs->first << "-" << i_pairs->second << ")";
	// // 	// this->_pending.push_back(i_pairs->second);
	// // }
	// // std::cout << std::endl;

	// // addToMainChain(this->_pending.begin());

	// // std::cout << "main chain: ";
	// // for(std::vector<int>::iterator i = this->_main_chain.begin(); i != this->_main_chain.end(); i++)
	// // 	std::cout << " " << *i;
	// // std::cout << std::endl;

	// // std::cout << "pending: ";
	// // for(std::vector<int>::iterator i = this->_pending.begin(); i != this->_pending.end(); i++)
	// // 	std::cout << " " << *i;
	// // std::cout << std::endl;

	// for(std::vector<int>::iterator i = this->_pending.begin(); i != this->_pending.end(); i++)
	// {
	// 	addToMainChain(*i);
	// }
	// for(i_pairs = pairs.begin(); i_pairs != pairs.end(); i_pairs++)
	// {
	// 	// insert = i_pairs->second;
	// 	addToMainChain(i_pairs->second);
	// 	// std::cout << "insert :" << insert << std::endl;
	// }

	std::vector<int>			vec;
	vec.push_back(20);
	vec.push_back(17);
	vec.push_back(15);
	vec.push_back(12);
	vec.push_back(10);
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	addToMainChain(vec, 2);
	std::cout << "main chain: ";
	for(std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
		std::cout << " " << *i;
	std::cout << std::endl;
}

void	PmergeMe::addToMainChain(std::vector<int> vec, int n)
{
	// std::vector<int>			aux_vec;
	std::vector<int>::iterator	insertion_it;
	// size_t	i;
	int	media;
	// int		value;

	if (n == 0)
		return;
	// vec = this->_main_chain;
	std::cout << "main chain: ";
	for(std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
		std::cout << " " << *i;
	std::cout << std::endl;
	std::cout << "n: " << n << std::endl;

	if ((vec.size() % 2) == 0)
	{
		insertion_it = vec.begin() + (vec.size() / 2);
		// std::cout << *insertion_it << std::endl;
		media = (*insertion_it + *(--insertion_it)) / 2;
		std::cout << "media ici: " << media << std::endl;
		if (n < media)
		{
			aux_vec.insert(aux_vec.end(), vec.begin() + (vec.size() / 2), vec.end());
			std::cout << "aux vec: ";
			for(std::vector<int>::iterator i = aux_vec.begin(); i != aux_vec.end(); i++)
				std::cout << " " << *i;
			std::cout << std::endl;
			addToMainChain(aux_vec, n);
		}
		else
		{
			vec.insert(insertion_it + 1, n);
			std::cout << "main chain: ";
			for(std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
				std::cout << " " << *i;
			std::cout << std::endl;
			return;
		}
		// media = vec.size() / 2;
		// i = 0;
		// this->_i = vec.begin();
		// while (i < media)
		// {
		// 	this->_i++;
		// 	i++;
		// }
	}
	else
	{
		insertion_it = vec.begin() + (vec.size() / 2);
		media = *insertion_it;
		std::cout << "media " << media << std::endl; 
	}

	// media = vec.size() / 2;
	// i = 0;
	// this->_i = vec.begin();
	// while (i < media)
	// {
	// 	this->_i++;
	// 	i++;
	// }

	// std::cout << "vec[media] " << vec[media] << std::endl;
	// if (n > vec[media])
	// {
	// 	std::cout << "we are going to left" << std::endl;
	// 	aux_vec.insert(aux_vec.end(), vec.begin(), vec.begin() + (vec.size() / 2));
	// 	for(std::vector<int>::iterator i = aux_vec.begin(); i != aux_vec.end(); i++)
	// 		std::cout << " " << *i;
	// 	std::cout << std::endl;
	// 	std::cout << "****************** No se que va a pasar! ****************" << std::endl;
	// 	addToMainChain(aux_vec, n);
	// }
	// else
	// {
	// 	std::cout << "we are going to rigth" << std::endl;
	// 	aux_vec.insert(aux_vec.end(), vec.begin() + (vec.size() / 2), vec.end());
	// 	for(std::vector<int>::iterator i = aux_vec.begin(); i != aux_vec.end(); i++)
	// 		std::cout << " " << *i;
	// 	std::cout << std::endl;
	// 	std::cout << "****************** No se que va a pasar! ****************" << std::endl;
	// 	// addToMainChain(aux_vec, n);
	// }
	// // while (n < vec[media])
	// // {
	// // 	this->_i++;
	// // 	media = vec.size() / 2;
	// // }
	// std::cout << "media " << media << std::endl;
	// std::cout << "vec[media] " << vec[media] << std::endl;
	// std::cout << "this->_i " << *this->_i << std::endl;
	// this->_i = vec.begin();
	// for (i = 0; i < media;i++)
	// 	this->_i++;
	// if (n < *this->_i)
	// 	insertion_it = this->_i + 1;
	// else
	// 	insertion_it = this->_i;
	// std::cout << "insertion:" << *insertion_it << std::endl;
	// vec.insert(insertion_it, n);
	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/*
** --------------------------------- EXCEPTIONS -------------------------------
*/

const char* PmergeMe::Error::what() const throw() {
    return ("Error: invalid character.");
}

const char* PmergeMe::DuplicatesError::what() const throw() {
    return ("Error: duplicate.");
}

/* ************************************************************************** */