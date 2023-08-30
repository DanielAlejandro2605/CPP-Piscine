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
	std::cout << "pending: ";
	for(std::vector<int>::iterator i = this->_pending.begin(); i != this->_pending.end(); i++)
		std::cout << " " << *i;
}

void	PmergeMe::getPairsFromVector(std::vector<int> v)
{
	std::vector<int>							new_vec;
	std::vector<std::pair<int, int> > 			pairs;
	std::vector<std::pair<int, int> >::iterator i_pairs;
	// int	firstValue;
	// int	secondValue;
	int p1;
	int p2;

	for (size_t i = 0; i < v.size(); i += 2) {
		p1 = v[i];
        p2 = (i + 1 < v.size()) ? v[i + 1] : -1;
		if (p1 < p2) {
			pairs.push_back(std::make_pair(p2, p1));
		} else {
			pairs.push_back(std::make_pair(p1, p2));
		}
    }

	for(i_pairs = pairs.begin(); i_pairs != pairs.end(); i_pairs++)
	{
		std::cout << "(" << i_pairs->first << "-" << i_pairs->second << ")" << std::endl;
		if (i_pairs->second != -1)
			new_vec.push_back(i_pairs->first);
		else
			this->_pending.push_back(i_pairs->first);
	}

	// // std::cout << (int)pairs.size() << std::endl;
	if (pairs.size() == 2)
	{
		return;
	}
	std::cout << "new vec :";
	for(std::vector<int>::iterator i = new_vec.begin(); i != new_vec.end(); i++)
		std::cout << " " << *i;
	std::cout << std::endl;
	getPairsFromVector(new_vec);
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