/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:39:35 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/25 10:59:05 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";

	FT_MSG("Cat() Constructor")
	return;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	*this = copy;

	FT_MSG("Cat(Cat copy) Constructor")
	return;
}

Cat::~Cat()
{
	FT_MSG("~Cat Destructor")
	return;
}

Cat &Cat::operator=(const Cat &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}

	return *this;
}

/* --- --- --- */

void Cat::makeSound(void) const
{
	PRINT << BRIGHT_GREEN BOLT "meow meow!" << RESEND;

	return;
}
