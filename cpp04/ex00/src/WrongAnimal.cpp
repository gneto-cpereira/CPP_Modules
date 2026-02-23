/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:39:35 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/25 11:03:27 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "";

	FT_MSG("WrongAnimal() Constructor")
	return;
}

WrongAnimal::WrongAnimal(STRING type)
{
	this->_type = type;

	FT_MSG("WrongAnimal(String) Constructor")
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;

	FT_MSG("WrongAnimal(WrongAnimal copy) Constructor")
	return;
}

WrongAnimal::~WrongAnimal()
{
	FT_MSG("~WrongAnimal Destructor")
	return;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}

	return *this;
}

/* --- --- --- */

void WrongAnimal::printType(void) const
{
	PRINT << CYAN BOLT << this->_type << RESEND;

	return;
}

STRING WrongAnimal::getType(void) const
{
	return this->_type;
}

void WrongAnimal::makeSound(void) const
{
	PRINT << BRIGHT_GREEN BOLT "wrong raaawwwrr!" << RESEND;

	return;
}
