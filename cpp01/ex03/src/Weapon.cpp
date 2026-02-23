/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:39:35 by gneto-co          #+#    #+#             */
/*   Updated: 2024/10/28 16:11:30 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon()
{
	return ;
}

Weapon::Weapon(std::string type) : _type(type)
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

const std::string &Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	_type = type;
}
