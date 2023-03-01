/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:57:16 by dnieto-c          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/21 19:07:54 by dnieto-c         ###   ########.fr       */
=======
/*   Updated: 2023/02/23 19:11:25 by dnieto-c         ###   ########.fr       */
>>>>>>> eb844f85b4720f2e112af5a5856fb8cccf2bd0a0
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
#define WEAPON

# include <iostream>

class Weapon
{
    private:
<<<<<<< HEAD
        std::string	type;
=======
        std::string	_type;
>>>>>>> eb844f85b4720f2e112af5a5856fb8cccf2bd0a0
    public:
        Weapon();
		Weapon(std::string type_value);
        ~Weapon();
<<<<<<< HEAD
		std::string			getSimpleType(void);
        const std::string	&getType(void);
		void				setType(std::string new_value_type);
};

=======
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
>>>>>>> eb844f85b4720f2e112af5a5856fb8cccf2bd0a0
#endif 