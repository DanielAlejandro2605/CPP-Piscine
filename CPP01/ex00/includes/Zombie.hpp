/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:38:57 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/02/20 13:38:57 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE
# define ZOMBIE

# include <iostream>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(std::string name_of_zombie);
        ~Zombie();
        void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
#endif