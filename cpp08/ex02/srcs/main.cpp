/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:16:20 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/29 12:04:49 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	{
		std::cout << BGBLUE << "--- Subject example ---" << RESET << std::endl;

		mstack.push(5);
		std::cout << "MutantStack : push(5)" << std::endl;
		mstack.push(17);
		std::cout << "MutantStack : push(17)" << std::endl;
		std::cout << "top: " << mstack.top() << std::endl;

		mstack.pop();
		std::cout << "MutantStack : pop()" << std::endl;
		std::cout << "size: " << mstack.size() << std::endl;

		mstack.push(3);
		std::cout << "MutantStack : push(3)" << std::endl;
		mstack.push(6);
		std::cout << "MutantStack : push(5)" << std::endl;
		mstack.push(737);
		std::cout << "MutantStack : push(737)" << std::endl;
		mstack.push(0);
		std::cout << "MutantStack : push(0)" << std::endl;

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "Calling std::stack<int> s(mstack)" << std::endl;
		std::stack<int> s(mstack);
		std::cout << GREEN << "It's possible create a stack from MutantStack!" << RESET << std::endl;
	}
	{
		std::cout << BGBLUE << "--- Reverse iterator ---" << RESET << std::endl;
		
		MutantStack<std::string> rev;

		rev.push("one");
		std::cout << "MutantStack : push('one')" << std::endl;
		rev.push("two");
		std::cout << "MutantStack : push('two')" << std::endl;
		rev.push("three");
		std::cout << "MutantStack : push('three')" << std::endl;
		rev.push("four");
		std::cout << "MutantStack : push('four')" << std::endl;
		rev.push("five");
		std::cout << "MutantStack : push('five')" << std::endl;

		MutantStack<std::string>::reverse_iterator rev_itr = rev.rbegin();
		std::cout << BGGREEN << "Iteration with reverse iterator" << RESET << std::endl;
		for (; rev_itr != rev.rend(); rev_itr++)
			std::cout << *rev_itr << std::endl;
	}
	{
		std::cout << BGBLUE << "--- Copy constructor ---" << RESET << std::endl;
		
		std::cout << BGYELLOW << "Current state of mstack MutantStack" <<  RESET << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << BGGREEN << "MutantStack<int> copy(mstack)" <<  RESET << std::endl;
	
		MutantStack<int> copy(mstack);

		copy.pop();
		std::cout << "copy : pop()" << std::endl;
		copy.pop();
		std::cout << "copy : pop()" << std::endl;
		copy.pop();
		std::cout << "copy : pop()" << std::endl;
		copy.push(64);
		std::cout << "copy : push(64)" << std::endl;
		copy.push(65);
		std::cout << "copy : push(65)" << std::endl;
		copy.push(66);
		std::cout << "copy : push(66)" << std::endl;

		MutantStack<int>::iterator copy_itr = copy.begin();
		for (; copy_itr != copy.end(); copy_itr++)
			std::cout << *copy_itr << std::endl;
	}
	{
		std::cout << BGBLUE << "--- Assignment operator ---" << RESET << std::endl;
		MutantStack<int> a_copy = mstack;
		std::cout << BGGREEN << "MutantStack a_copy = mstack" <<  RESET << std::endl;
		
		a_copy.pop();
		std::cout << "a_copy : pop()" << std::endl;
		a_copy.pop();
		std::cout << "a_copy : pop()" << std::endl;
		a_copy.pop();
		std::cout << "a_copy : pop()" << std::endl;
		a_copy.push(1000);
		std::cout << "a_copy : push(1000)" << std::endl;
		a_copy.push(2000);
		std::cout << "a_copy : push(2000)" << std::endl;
		a_copy.push(3000);
		std::cout << "a_copy : push(3000)" << std::endl;

		MutantStack<int>::iterator a_copy_itr = a_copy.begin();
		for (; a_copy_itr != a_copy.end(); a_copy_itr++)
			std::cout << *a_copy_itr << std::endl;	
	}
}
