/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:39:35 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/25 14:29:17 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
{
	FT_MSG("Animal() Constructor")
	this->_type = "";

	return;
}

Animal::Animal(const Animal &copy)
{
	FT_MSG("Animal(Animal copy) Constructor")
	*this = copy;

	return;
}

Animal::~Animal()
{
	FT_MSG("~Animal Destructor")
	return;
}

Animal &Animal::operator=(const Animal &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}

	return *this;
}

/* --- --- --- */

void Animal::printType(void) const
{
	PRINT << CYAN BOLT << this->_type << RESEND;

	return;
}

STRING Animal::getType(void) const
{
	return this->_type;
}

void Animal::makeSound(void) const
{
	PRINT << BRIGHT_GREEN BOLT "raaawwwrr!" << RESEND;

	return;
}
