/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:10:20 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/23 11:54:24 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _array_size(0)
{
    try 
	{
		this->_data = new T[0];
    }
	catch (std::bad_alloc & exception) 
	{ 
		std::cerr << "bad_alloc detected in Array class constructor" << exception.what() << std::endl; 
	}
}

template <typename T>
Array<T>::Array(unsigned int n) : _array_size(n)
{
    try 
    {
        this->_data = new T[n];
    }
    catch (std::bad_alloc & exception) 
	{ 
		std::cerr << "bad_alloc detected in Array class constructor" << exception.what() << std::endl; 
	}
}

template <typename T>
Array<T>::Array(Array const &src)
{
	try
	{
		this->_array_size = src.size();
		this->_data = new T[src._array_size];
		for (unsigned int i = 0; i < src.size(); i++)
			this->_data[i] = src._data[i];
	}
	catch (std::bad_alloc & exception) 
	{ 
		std::cerr << "bad_alloc detected in Array class copy constructor" << exception.what() << std::endl; 
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(Array const &rhs)
{
	try
	{
		if (*this != rhs)
		{
			delete [] this->_data;
			this->_array_size = rhs.size();
			this->_array_size = new T[rhs.size()];
			for (unsigned int i = 0; i < rhs.size(); i++)
				this->_data[i] = rhs._data[i];
		}
	}
	catch (std::bad_alloc & exception) 
	{ 
		std::cerr << "bad_alloc detected in Array class copy constructor" << exception.what() << std::endl; 
	}
	return (*this);
}

template<typename T>
T&	Array<T>::operator[](size_t idx)
{
	if (idx >= this->_array_size)
		throw OutOfRangeException();
	return (this->_data[idx]);
}

template<typename T>
unsigned int Array<T>::size() const
{
	return (this->_array_size);
}

template<typename T>
Array<T>::~Array()
{
	delete [] this->_data;
}