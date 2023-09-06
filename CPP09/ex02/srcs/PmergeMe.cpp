#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe(char **arg) : _i(0)
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

bool estaOrdenado(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); i++) {
        if (vec[i] < vec[i - 1]) {
            // El vector no está ordenado de menor a mayor en el índice i.
            std::cout << "El vector no está ordenado en el índice " << i << "." << std::endl;
            return false;
        }
    }
    return true; // El vector está ordenado correctamente.
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void	PmergeMe::sort(void)
{
	getPairsFromVector(this->_data);

	std::reverse(this->_main_chain.begin(), this->_main_chain.end());

	if (estaOrdenado(this->_main_chain)) {
        std::cout << "OK" << std::endl;
		std::cout << this->_main_chain.size() << std::endl;
    } else {
        std::cout << "KO" << std::endl;
    }
}

void	PmergeMe::getPairsFromVector(std::vector<int> v)
{
	std::vector<int>							new_vec;
	std::vector<std::pair<int, int> > 			pairs;
	std::vector<std::pair<int, int> >::iterator i_pairs;
	int p1;
	int p2;

	for (size_t i = 0; i < v.size(); i += 2) {
		p1 = v[i];
        p2 = (i + 1 < v.size()) ? v[i + 1] : 0;
		if (p1 < p2) {
			pairs.push_back(std::make_pair(p2, p1));
		} else {
			pairs.push_back(std::make_pair(p1, p2));
		}
    }
	for(i_pairs = pairs.begin(); i_pairs != pairs.end(); i_pairs++)
	{
		if (i_pairs->second != 0)
		{	
			new_vec.push_back(i_pairs->first);
		}
		else
		{
			this->_pending.push_back(i_pairs->first);
		}
	}
	if (((this->_data.size() % 2) == 0) && pairs.size() == 1)
	{
		i_pairs = pairs.begin();
		this->_main_chain.push_back(i_pairs->first);
		if (i_pairs->second != 0)
			this->_main_chain.push_back(i_pairs->second);
		return;
	}
	else if (!((this->_data.size() % 2) == 0) && pairs.size() == 2)
	{
		i_pairs = pairs.begin();
		this->_main_chain.push_back(i_pairs->first);
		this->_main_chain.push_back(i_pairs->second);
		// if (this->_pending.size() > 0)
		// {
		// 	addToMainChain(this->_pending.front());
		// }
		return;
	}
	getPairsFromVector(new_vec);
	for(std::vector<int>::iterator i = this->_pending.begin(); i != this->_pending.end(); i++)
	{
		addToMainChain(*i);
	}
	this->_pending.clear();
	for(i_pairs = pairs.begin(); i_pairs != pairs.end(); i_pairs++)
	{
		addToMainChain(i_pairs->second);
	}
}

void	PmergeMe::addToMainChain(int n)
{
	std::vector<int>::iterator	insert_it;
	int							media;

	if (n == 0)
		return;
	if ((this->_main_chain.size() % 2) == 0)
	{
		insert_it = this->_main_chain.begin() + (this->_main_chain.size() / 2);
		media = (*insert_it + *(--insert_it)) / 2;
		if (n < media)
		{
			insert_it++;
			while (insert_it != this->_main_chain.end())
			{
				if (n > *insert_it)
					break;
				insert_it++;
			}
			this->_main_chain.insert(insert_it, n);
		}
		else
		{
			while (insert_it != this->_main_chain.begin())
			{
				if (n < *insert_it)
					break;
				insert_it--;
			}
			if (insert_it == this->_main_chain.begin())
			{
				if (n > *insert_it)
				{
					this->_main_chain.insert(this->_main_chain.begin(), n);
				}
				else
					this->_main_chain.insert(++insert_it, n);
			}
			else
				this->_main_chain.insert(++insert_it, n);
		}
	}
	else
	{
		insert_it = this->_main_chain.begin() + (this->_main_chain.size() / 2);
		media = *insert_it;
		if (n < media)
		{
			insert_it++;
			while (insert_it != this->_main_chain.end())
			{
				if (n > *insert_it)
					break;
				insert_it++;
			}
			this->_main_chain.insert(insert_it, n);
		}
		else
		{
			while (insert_it != this->_main_chain.begin())
			{
				if (n < *insert_it)
					break;
				insert_it--;
			}
			if (n > *insert_it)
				this->_main_chain.insert(insert_it, n);
			else
				this->_main_chain.insert(++insert_it, n);
		}
	}
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