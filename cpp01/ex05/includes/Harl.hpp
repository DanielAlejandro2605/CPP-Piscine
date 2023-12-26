/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:55:34 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/03/01 16:55:34 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL
#define HARL

# include <iostream>
class Harl
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:
        Harl(/* args */);
        ~Harl();
        void complain(std::string level);
};


#endif 