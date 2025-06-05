/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-05 11:23:38 by ggasset-          #+#    #+#             */
/*   Updated: 2025-06-05 11:23:38 by ggasset-         ###   ########student.  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(): name("Foo")
{
}

Zombie::Zombie(std::string _name): name(_name)
{
}

Zombie::~Zombie()
{
	std::cout << "Destructor called" << std::endl;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
