#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe(char **arg)
{
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
	if (this->_data_v.size() == 1)
		throw PmergeMe::MissingError();
	for (this->_i = this->_data_v.begin(); this->_i != this->_data_v.end(); this->_i++)
	{
		for (this->_j = this->_i + 1; this->_j != this->_data_v.end(); this->_j++)
		{
			if (*this->_i == *this->_j)
				throw PmergeMe::DuplicatesError();
		}
	}
}

PmergeMe::PmergeMe(const PmergeMe & src)
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	(void)rhs;
	return (*this);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	PmergeMe::sort(void)
{
	sortVector();
	sortList();
	// checkPmergeMe();
}

void	PmergeMe::sortList(void)
{
	this->_start = clock();
	getPairsList(this->_data_l);
	std::reverse(this->_main_chain_l.begin(), this->_main_chain_l.end());
	this->_end = clock();
  	std::cout << "Time to process a range of    " << this->_data_l.size() << " elements with std::list : " << std::fixed << (static_cast<double>(this->_end - this->_start)/CLOCKS_PER_SEC) * 100000 << " us." << std::endl;
}

void	PmergeMe::sortVector(void)
{
	std::cout << "Before: ";
	printContainerElements(this->_data_v);
	this->_start = clock();
	getPairsVector(this->_data_v);
	std::reverse(this->_main_chain_v.begin(), this->_main_chain_v.end());
	this->_end = clock();
	std::cout << "After: ";
	printContainerElements(this->_main_chain_v);
  	std::cout << "Time to process a range of    " << this->_data_v.size() << " elements with std::vector : " << std::fixed << (static_cast<double>(this->_end - this->_start)/CLOCKS_PER_SEC) * 100000 << " us." << std::endl;
}

void	PmergeMe::checkPmergeMe(void)
{
	if (checkContainerSorted(this->_main_chain_v) && checkContainerSorted(this->_main_chain_l)
		&& (this->_main_chain_v.size() == this->_data_v.size())
		&& (this->_main_chain_l.size() == this->_data_l.size()))
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "KO" << std::endl;
	}
}

void	PmergeMe::getPairsVector(std::vector<int> v)
{
	std::vector<int>							new_vec;
	std::vector<std::pair<int, int> > 			pairs;
	int											p1;
	int											p2;

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
			new_vec.push_back(this->_i_pairs_v->first);
		else
			this->_pending_v.push_back(this->_i_pairs_v->first);
	}
	
	if (pairs.size() == 2)
	{
		this->_i_pairs_v = pairs.begin();
		this->_main_chain_v.push_back(this->_i_pairs_v->first);
		if (this->_i_pairs_v->second != 0)
			this->_main_chain_v.push_back(this->_i_pairs_v->second);
		this->_i_pairs_v++;
		if (this->_i_pairs_v->second != 0)
		{
			addToMainChainVector(this->_i_pairs_v->first);
			addToMainChainVector(this->_i_pairs_v->second);
		}
		else if (this->_data_v.size() == 3)
			addToMainChainList(this->_i_pairs_v->first);
		return;
	}
	else if (pairs.size() == 1)
	{
		this->_i_pairs_v = pairs.begin();
		this->_main_chain_v.push_back(this->_i_pairs_v->first);
		this->_main_chain_v.push_back(this->_i_pairs_v->second);
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
	std::list<int> 					new_lst;
	std::list<int>::iterator 		it;
	std::list<std::pair<int, int> > pairs;
	int 							p1;
	int 							p2;

	it = lst.begin();
	while (it != lst.end())
	{
		p1 = *it;
		it++;
		if (it == lst.end())
		{
			p2 = 0;
			if (p1 < p2) {
				pairs.push_back(std::make_pair(p2, p1));
			} else {
				pairs.push_back(std::make_pair(p1, p2));
			}
			break;
		}
		p2 = *it;
		it++;
		if (p1 < p2) {
			pairs.push_back(std::make_pair(p2, p1));
		} else {
			pairs.push_back(std::make_pair(p1, p2));
		}
	}

	for (this->_i_pairs_l = pairs.begin(); this->_i_pairs_l != pairs.end(); this->_i_pairs_l++) {
		if (this->_i_pairs_l->second != 0) {
			new_lst.push_back(this->_i_pairs_l->first);
		} else {
			this->_pending_l.push_back(this->_i_pairs_l->first);
		}
	}

	if (pairs.size() == 2)
	{
		this->_i_pairs_l = pairs.begin();
		this->_main_chain_l.push_back(this->_i_pairs_l->first);
		if (this->_i_pairs_l->second != 0)
			this->_main_chain_l.push_back(this->_i_pairs_l->second);
		this->_i_pairs_l++;
		if (this->_i_pairs_l->second != 0)
		{
			addToMainChainList(this->_i_pairs_l->first);
			addToMainChainList(this->_i_pairs_l->second);
		}
		else if (this->_data_l.size() == 3)
			addToMainChainList(this->_i_pairs_l->first);
		return;
	}
	else if (pairs.size() == 1)
	{
		this->_i_pairs_l = pairs.begin();
		this->_main_chain_l.push_back(this->_i_pairs_l->first);
		this->_main_chain_l.push_back(this->_i_pairs_l->second);
		return;
	}

	getPairsList(new_lst);
	for (std::list<int>::iterator it = this->_pending_l.begin(); it != this->_pending_l.end(); it++) {
		addToMainChainList(*it);
	}
	this->_pending_l.clear();
	for (this->_i_pairs_l = pairs.begin(); this->_i_pairs_l != pairs.end(); this->_i_pairs_l++) {
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

const char* PmergeMe::MissingError::what() const throw() {
    return ("Error: only one number is not a sequence.");
}

const char* PmergeMe::DuplicatesError::what() const throw() {
    return ("Error: duplicate.");
}

/* ************************************************************************** */