/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:18:01 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/01 13:14:20 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

 
Base *generate(void)
{
    Base *ptr = NULL;
    std::srand(std::time(0));
    int r = (rand() % 3);
    if (r == 0)
    {
        std::cout << "Generating A Class" << std::endl;
        ptr = new A();
    }
    else if (r == 1)
    {
        std::cout << "Generating B Class" << std::endl;
        ptr = new B();
    }
    else if (r == 2)
    {
        std::cout << "Generating C Class" << std::endl;
        ptr = new C();
    }
    return (ptr);
}

void identify(Base *ptr)
{
    if (dynamic_cast<A *>(ptr))
        std::cout << "A Class identified!" << std::endl;
    else if (dynamic_cast<B *>(ptr))
        std::cout << "B Class identified!" << std::endl;
    else if (dynamic_cast<C *>(ptr))
        std::cout << "C Class identified!" << std::endl;
}

void identify(Base& p)
{
    try 
    {
        if (dynamic_cast<A *>(&p))
            std::cout << "A Class identified!" << std::endl;
        else if (dynamic_cast<B *>(&p))
            std::cout << "B Class identified!" << std::endl;
        else if (dynamic_cast<C *>(&p))
            std::cout << "C Class identified!" << std::endl;   
    }
    catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main(void)
{
    Base *ptr_result = generate();
    std::cout << " (pointer)" << std::endl;
	Base* tmp = generate();
	Base& ref = *tmp;
	std::cout << " (reference)" << std::endl;

	identify(ptr_result);
	identify(ref);

	delete ptr_result;
	delete tmp;
}