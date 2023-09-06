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
		this->_data_v.push_back(std::atoi(arg[i]));
		this->_data_l.push_back(std::atoi(arg[i]));
		i++;
	}
	for (this->_i = this->_data_v.begin(); this->_i != this->_data_v.end(); this->_i++)
	{
		for (this->_j = this->_i + 1; this->_j != this->_data_v.end(); this->_j++)
		{
			if (*this->_i == *this->_j)
				throw PmergeMe::DuplicatesError();
		}
	}
	this->_data_v_length = this->_data_v.size();
	std::cout << "Hay :" << this->_data_v_length << std::endl;
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

bool checkSortVector(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); i++) {
        if (vec[i] < vec[i - 1]) {
            // El vector no está ordenado de menor a mayor en el índice i.
            std::cout << "El vector no está ordenado en el índice " << i << "." << std::endl;
            return false;
        }
    }
    return true; // El vector está ordenado correctamente.
}

bool checkSortList(const std::list<int>& lst) {
    std::list<int>::const_iterator prev_it = lst.begin();
    std::list<int>::const_iterator it = prev_it;
    ++it;

    while (it != lst.end()) {
        if (*it < *prev_it) {
            // La lista no está ordenada en el punto actual.
            std::cout << "La lista no está ordenada en este punto." << std::endl;
            return false;
        }
        ++it;
        ++prev_it;
    }

    return true; // La lista está ordenada correctamente.
}
/*
** --------------------------------- METHODS ----------------------------------
*/
void	PmergeMe::sort(void)
{
	// getPairsVector(this->_data_v);
	// std::reverse(this->_main_chain_v.begin(), this->_main_chain_v.end());
	std::cout << "hey" << std::endl;
	getPairsList(this->_data_l);
	std::reverse(this->_main_chain_l.begin(), this->_main_chain_l.end());
	if (checkSortList(this->_main_chain_l)) {
        std::cout << "OK" << std::endl;
		std::cout << this->_main_chain_l.size() << std::endl;
    } else {
        std::cout << "KO" << std::endl;
    }
}

void	PmergeMe::getPairsVector(std::vector<int> v)
{
	std::vector<int>							new_vec;
	std::vector<std::pair<int, int> > 			pairs;
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
	for(this->_i_pairs_v = pairs.begin(); this->_i_pairs_v != pairs.end(); this->_i_pairs_v++)
	{
		if (this->_i_pairs_v->second != 0)
		{	
			new_vec.push_back(this->_i_pairs_v->first);
		}
		else
		{
			this->_pending_v.push_back(this->_i_pairs_v->first);
		}
	}
	if (((this->_data_v.size() % 2) == 0) && pairs.size() == 1)
	{
		this->_i_pairs_v = pairs.begin();
		this->_main_chain_v.push_back(this->_i_pairs_v->first);
		if (this->_i_pairs_v->second != 0)
			this->_main_chain_v.push_back(this->_i_pairs_v->second);
		return;
	}
	else if (!((this->_data_v.size() % 2) == 0) && pairs.size() == 2)
	{
		this->_i_pairs_v = pairs.begin();
		this->_main_chain_v.push_back(this->_i_pairs_v->first);
		this->_main_chain_v.push_back(this->_i_pairs_v->second);
		// if (this->_pending_v.size() > 0)
		// {
		// 	addToMainChainVector(this->_pending_v.front());
		// }
		return;
	}
	getPairsVector(new_vec);
	for(std::vector<int>::iterator i = this->_pending_v.begin(); i != this->_pending_v.end(); i++)
	{
		addToMainChainVector(*i);
	}
	this->_pending_v.clear();
	for(this->_i_pairs_v = pairs.begin(); this->_i_pairs_v != pairs.end(); this->_i_pairs_v++)
	{
		addToMainChainVector(this->_i_pairs_v->second);
	}
}

void	PmergeMe::addToMainChainVector(int n)
{
	std::vector<int>::iterator	insert_it;
	int							media;

	if (n == 0)
		return;
	if ((this->_main_chain_v.size() % 2) == 0)
	{
		insert_it = this->_main_chain_v.begin() + (this->_main_chain_v.size() / 2);
		media = (*insert_it + *(--insert_it)) / 2;
		if (n < media)
		{
			insert_it++;
			while (insert_it != this->_main_chain_v.end())
			{
				if (n > *insert_it)
					break;
				insert_it++;
			}
			this->_main_chain_v.insert(insert_it, n);
		}
		else
		{
			while (insert_it != this->_main_chain_v.begin())
			{
				if (n < *insert_it)
					break;
				insert_it--;
			}
			if (insert_it == this->_main_chain_v.begin())
			{
				if (n > *insert_it)
				{
					this->_main_chain_v.insert(this->_main_chain_v.begin(), n);
				}
				else
					this->_main_chain_v.insert(++insert_it, n);
			}
			else
				this->_main_chain_v.insert(++insert_it, n);
		}
	}
	else
	{
		insert_it = this->_main_chain_v.begin() + (this->_main_chain_v.size() / 2);
		media = *insert_it;
		if (n < media)
		{
			insert_it++;
			while (insert_it != this->_main_chain_v.end())
			{
				if (n > *insert_it)
					break;
				insert_it++;
			}
			this->_main_chain_v.insert(insert_it, n);
		}
		else
		{
			while (insert_it != this->_main_chain_v.begin())
			{
				if (n < *insert_it)
					break;
				insert_it--;
			}
			if (n > *insert_it)
				this->_main_chain_v.insert(insert_it, n);
			else
				this->_main_chain_v.insert(++insert_it, n);
		}
	}
}

void 	PmergeMe::getPairsList(std::list<int> lst) {
	std::list<int> new_lst;
	std::list<std::pair<int, int> > pairs;
	int p1;
	int p2;

	std::cout << "hey" << std::endl;
	int i = 0;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
		p1 = *it;
		++it;
		p2 = (it != lst.end()) ? *it : 0;
		std::cout << "p1 " << p1 << std::endl;
		std::cout << "p2 " << p2 << std::endl;
		if (p1 < p2) {
			pairs.push_back(std::make_pair(p2, p1));
		} else {
			pairs.push_back(std::make_pair(p1, p2));
		}
		i++;
		// if (i == 2)
		// 	exit(1);
	}

	std::cout << "hey" << std::endl;
	for (this->_i_pairs_l = pairs.begin(); this->_i_pairs_l != pairs.end(); ++this->_i_pairs_l) {
		if (this->_i_pairs_l->second != 0) {
			new_lst.push_back(this->_i_pairs_l->first);
		} else {
			this->_pending_l.push_back(this->_i_pairs_l->first);
		}
	}

	if (((this->_data_v.size() % 2) == 0) && pairs.size() == 1) {
		this->_i_pairs_l = pairs.begin();
		this->_main_chain_l.push_back(this->_i_pairs_l->first);
		if (this->_i_pairs_l->second != 0)
			this->_main_chain_l.push_back(this->_i_pairs_l->second);
		return;
	} else if (!((this->_data_v.size() % 2) == 0) && pairs.size() == 2) {
		this->_i_pairs_l = pairs.begin();
		this->_main_chain_l.push_back(this->_i_pairs_l->first);
		this->_main_chain_l.push_back(this->_i_pairs_l->second);
		return;
	}

	getPairsList(new_lst);

	for (std::list<int>::iterator it = this->_pending_l.begin(); it != this->_pending_l.end(); ++it) {
		addToMainChainList(*it);
	}
	this->_pending_l.clear();

	for (this->_i_pairs_l = pairs.begin(); this->_i_pairs_l != pairs.end(); ++this->_i_pairs_l) {
		addToMainChainList(this->_i_pairs_l->second);
	}
}

void PmergeMe::addToMainChainList(int n) {
	std::list<int>::iterator	insert_it;
	int 						media;

	if (n == 0)
		return;

	if ((this->_main_chain_l.size() % 2) == 0) {
		insert_it = this->_main_chain_l.begin();
		std::advance(insert_it, this->_main_chain_l.size() / 2);
		media = (*insert_it + *insert_it) / 2;
		if (n < media) {
			while (insert_it != this->_main_chain_l.end()) {
				if (n > *insert_it)
					break;
				++insert_it;
			}
			this->_main_chain_l.insert(insert_it, n);
		} else {
			while (insert_it != this->_main_chain_l.begin()) {
				if (n < *insert_it)
					break;
				--insert_it;
			}
			if (insert_it == this->_main_chain_l.begin()) {
				if (n > *insert_it) {
					this->_main_chain_l.insert(insert_it, n);
				} else {
					this->_main_chain_l.insert(++insert_it, n);
				}
			} else {
				this->_main_chain_l.insert(++insert_it, n);
			}
		}
	} else {
		insert_it = this->_main_chain_l.begin();
		std::advance(insert_it, this->_main_chain_l.size() / 2);
		media = *insert_it;

		if (n < media) {
			while (insert_it != this->_main_chain_l.end()) {
				if (n > *insert_it)
					break;
				++insert_it;
			}
			this->_main_chain_l.insert(insert_it, n);
		} else {
			while (insert_it != this->_main_chain_l.begin()) {
				if (n < *insert_it)
					break;
				--insert_it;
			}
			if (n > *insert_it)
				this->_main_chain_l.insert(insert_it, n);
			else
				this->_main_chain_l.insert(++insert_it, n);
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