/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:57:16 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/26 13:39:46 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
#define WEAPON

# include <iostream>

class Weapon
{
    private:
        std::string	_type;
    public:
        Weapon();
		Weapon(std::string type_value);
        ~Weapon();
        const std::string   &getType(void);
		void				setType(const std::string new_value_type);
};

/*
https://www.reddit.com/r/Cplusplus/comments/d7wpro/should_a_function_return_a_referenceconst

Only consider returning a reference to objects that you know are still alive
after the function has returned, e.g. static variables, member variables, etc.

There's something called return value optimization (rvo). It basically means that if you
create an object in a function and return this object, the compiler will eliminate the
unnecessary intermediate copy. This means returning by value is often better.

Anyhow, for what you're too use add return. There's basically a few options.

1:  Small types (roughly smaller than 8 bytes) should be returned by value.
    Copying them is more efficient than any pointer/reference nonsense.

2:  Creating a new object that's created inside the function. Return by value. Let rvo work for you.

3:  Give access to a variable the class owns: use a (const) reference. Consider carefully when not
    making the reference const: This is often a code smell.
*/
#endif 