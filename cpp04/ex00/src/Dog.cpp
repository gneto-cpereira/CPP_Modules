/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:39:35 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/25 10:59:05 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";

	FT_MSG("Dog() Constructor")
	return;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	*this = copy;

	FT_MSG("Dog(Dog copy) Constructor")
	return;
}

Dog::~Dog()
{
	FT_MSG("~Dog Destructor")
	return;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}

	return *this;
}

/* --- --- --- */

void Dog::makeSound(void) const
{
	PRINT << BRIGHT_GREEN BOLT "woof woof!" << RESEND;

	return;
}
