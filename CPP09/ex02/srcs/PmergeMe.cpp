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
	// std::cout << "Hay :" << this->_data_length << std::endl;
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
	// std::cout << "data: ";
	// for(std::vector<int>::iterator i = this->_data.begin(); i != this->_data.end(); i++)
	// 	std::cout << " " << *i;
	// std::cout << std::endl;
	getPairsFromVector(this->_data);
	// std::cout << "main chain before reverse: ";
	// for(std::vector<int>::iterator i = this->_main_chain.begin(); i != this->_main_chain.end(); i++)
	// 	std::cout << " " << *i;
	// std::cout << std::endl;

	std::reverse(this->_main_chain.begin(), this->_main_chain.end());
	// std::cout << "main chain: ";
	// for(std::vector<int>::iterator i = this->_main_chain.begin(); i != this->_main_chain.end(); i++)
	// 	std::cout << " " << *i;
	// std::cout << std::endl;

	if (estaOrdenado(this->_main_chain)) {
        std::cout << "OK" << std::endl;
		// for (size_t i = 0; i < this->_main_chain.size(); i++) {
        //     std::cout << "miVector[" << i << "] = " << this->_main_chain[i] << std::endl;
        // }
    } else {
        std::cout << "KO" << std::endl;
        // for (size_t i = 0; i < this->_data.size(); i++) {
        //     std::cout << this->_data[i] << " ";
        // }
		for (size_t i = 0; i < this->_main_chain.size(); i++) {
            std::cout << this->_main_chain[i] << " ";
        }
		// std::cout << std::endl;
    }
}

void	PmergeMe::getPairsFromVector(std::vector<int> v)
{
	(void)v;
	std::vector<int>							new_vec;
	std::vector<std::pair<int, int> > 			pairs;
	std::vector<std::pair<int, int> >::iterator i_pairs;
	// int	firstValue;
	// int	secondValue;
	int p1;
	int p2;
	// int	insert;

	for (size_t i = 0; i < v.size(); i += 2) {
		p1 = v[i];
        p2 = (i + 1 < v.size()) ? v[i + 1] : 0;
		if (p1 < p2) {
			pairs.push_back(std::make_pair(p2, p1));
		} else {
			pairs.push_back(std::make_pair(p1, p2));
		}
    }
	std::cout << "************************" << std::endl;
	for(i_pairs = pairs.begin(); i_pairs != pairs.end(); i_pairs++)
	{
		std::cout << "(" << i_pairs->first << "-" << i_pairs->second << ")";
		// if (i_pairs->second != 0 || (i_pairs->second == 0 && this->_pending.size() > 0))
		// {
		// 	new_vec.push_back(i_pairs->first);
		// }
		// else if (i_pairs->second == 0 && this->_pending.size() == 0)
		// {
		// 	this->_pending.push_back(i_pairs->first);
		// }
		if (i_pairs->second != 0)
		{
			new_vec.push_back(i_pairs->first);
		}
		else
		{
			if (this->_pending.size() == 0)
			{
				// std::cout << "here" << i_pairs->first << std::endl;
				this->_pending.push_back(i_pairs->first);
			}
		}
	}
	std::cout << std::endl;
	std::cout << "************************" << std::endl;
	// std::cout << "new vec :";
	// for(std::vector<int>::iterator i = new_vec.begin(); i != new_vec.end(); i++)
	// 	std::cout << " " << *i;
	// std::cout << std::endl;
	if (((this->_data.size() % 2) == 0) && pairs.size() == 1)
	{
		i_pairs = pairs.begin();
		// if (i_pairs->first)
		// std::cout << "here " << i_pairs->first << std::endl;
		// std::cout << "here " << i_pairs->second << std::endl;
		this->_main_chain.push_back(i_pairs->first);
		if (i_pairs->second != 0)
			this->_main_chain.push_back(i_pairs->second);
		// std::cout << "caso tres" << std::endl;
		// std::cout << "esto pasa" << std::endl;
		// for (size_t i = 0; i < this->_main_chain.size(); i++) {
        //     std::cout << this->_main_chain[i] << " ";
        // }
		// std::cout << std::endl;
		return;
	}
	else if (!((this->_data.size() % 2) == 0) && pairs.size() == 2)
	{
		i_pairs = pairs.begin();
		this->_main_chain.push_back(i_pairs->first);
		this->_main_chain.push_back(i_pairs->second);
		if (this->_pending.size() > 0)
		{
			addToMainChain(this->_pending.front());
		}
		// std::cout << "esto pasa" << std::endl;
		// for (size_t i = 0; i < this->_main_chain.size(); i++) {
        //     std::cout << this->_main_chain[i] << " ";
        // }
		return;
	}
	getPairsFromVector(new_vec);
	// std::cout << "After getPairsFromVector : ";
	// for(i_pairs = pairs.begin(); i_pairs != pairs.end(); i_pairs++)
	// {
	// 	std::cout << "(" << i_pairs->first << "-" << i_pairs->second << ")";
	// 	// this->_pending.push_back(i_pairs->second);
	// }
	// std::cout << std::endl;

	// addToMainChain(this->_pending.begin());

	// std::cout << "main chain: ";
	// for(std::vector<int>::iterator i = this->_main_chain.begin(); i != this->_main_chain.end(); i++)
	// 	std::cout << " " << *i;
	// std::cout << std::endl;

	// std::cout << "pending: ";
	// for(std::vector<int>::iterator i = this->_pending.begin(); i != this->_pending.end(); i++)
	// 	std::cout << " " << *i;
	// std::cout << std::endl;
	for(std::vector<int>::iterator i = this->_pending.begin(); i != this->_pending.end(); i++)
	{
		addToMainChain(*i);
		// std::cout << "Voy a agregar esto : " << *i << std::endl;
	}
	this->_pending.clear();
	for(i_pairs = pairs.begin(); i_pairs != pairs.end(); i_pairs++)
	{
		// std::cout << "Voy a agregar esto : " << i_pairs->second << std::endl;
		// insert = i_pairs->second;
		addToMainChain(i_pairs->second);
		// std::cout << "insert :" << insert << std::endl;
	}
	// std::cout << "main chain: ";
	// for(std::vector<int>::iterator i = this->_main_chain.begin(); i != this->_main_chain.end(); i++)
	// 	std::cout << " " << *i;
	// std::cout << std::endl;
	// this->_main_chain.push_back(20);
	// this->_main_chain.push_back(17);
	// this->_main_chain.push_back(15);
	// this->_main_chain.push_back(12);
	// this->_main_chain.push_back(11);
	// this->_main_chain.push_back(10);
	// this->_main_chain.push_back(9);
	// this->_main_chain.push_back(5);
	// // this->_main_chain.push_back(4);
	// this->_main_chain.push_back(3);
	// this->_main_chain.push_back(1);
	// addToMainChain(19);
	// std::cout << "Result main chain: ";
	// for(std::vector<int>::iterator i = this->_main_chain.begin(); i != this->_main_chain.end(); i++)
	// 	std::cout << " " << *i;
	// std::cout << std::endl;
}

void	PmergeMe::addToMainChain(int n)
{
	std::vector<int>::iterator	insert_it;
	int							media;

	if (n == 0)
		return;
	std::cout << "main chain: ";
	for(std::vector<int>::iterator i = this->_main_chain.begin(); i != this->_main_chain.end(); i++)
		std::cout << " " << *i;
	std::cout << std::endl;
	std::cout << "n to insert: " << n << std::endl;
	// if (this->_i_debug < 10)
	// {
	// 	std::cout << "main chain: ";
	// 	for(std::vector<int>::iterator i = this->_main_chain.begin(); i != this->_main_chain.end(); i++)
	// 		std::cout << " " << *i;
	// 	std::cout << std::endl;
	// 	std::cout << "n to insert: " << n << std::endl;
	// 	this->_i_debug++;
	// }
	// else
	// 	exit(1);
	// std::cout << "main chain: ";
	// for(std::vector<int>::iterator i = this->_main_chain.begin(); i != this->_main_chain.end(); i++)
	// 	std::cout << " " << *i;
	// std::cout << std::endl;
	// std::cout << "n: " << n << std::endl;

	if ((this->_main_chain.size() % 2) == 0)
	{
		insert_it = this->_main_chain.begin() + (this->_main_chain.size() / 2);
		media = (*insert_it + *(--insert_it)) / 2;
		std::cout << "here media :" << media << std::endl;
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
			std::cout << "soooo: " << *insert_it << std::endl;
			if (insert_it == this->_main_chain.begin())
			{
				this->_main_chain.insert(insert_it, n);
			}
			else
			{
				while (insert_it != this->_main_chain.begin())
				{
					// std::cout << "*******************" << std::endl;
					// std::cout << n << std::endl;
					// std::cout << *insert_it << std::endl;
					// std::cout << (n < *insert_it) << std::endl;
					// std::cout << "*******************" << std::endl;
					if (n < *insert_it)
					{
						// std::cout << "break" << std::endl;
						break;
					}
					// std::cout << "decrement" << std::endl;
					insert_it--;
				}
				std::cout << "now: " << *insert_it << std::endl;
				if (insert_it == this->_main_chain.begin())
				{
					this->_main_chain.insert(insert_it, n);
				}
				else
					this->_main_chain.insert(++insert_it, n);
			}
		}
		std::cout << "main chain before exit: ";
		for(std::vector<int>::iterator i = this->_main_chain.begin(); i != this->_main_chain.end(); i++)
			std::cout << " " << *i;
		std::cout << std::endl;
		if (n == 99947)
			exit(1);
	}
	else
	{
		insert_it = this->_main_chain.begin() + (this->_main_chain.size() / 2);
		media = *insert_it;
		// std::cout << "media " << media << std::endl;
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
			// std::cout << "HERE" << *insert_it << std::endl;
			if (n > *insert_it)
			{
				this->_main_chain.insert(insert_it, n);
			}
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