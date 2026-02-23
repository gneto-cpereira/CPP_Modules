/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:39:35 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/25 10:59:05 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "W_Cat";

	FT_MSG("WrongCat() Constructor")
	return;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	*this = copy;

	FT_MSG("WrongCat(WrongCat copy) Constructor")
	return;
}

WrongCat::~WrongCat()
{
	FT_MSG("~WrongCat Destructor")
	return;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}

	return *this;
}

/* --- --- --- */

void WrongCat::makeSound(void) const
{
	PRINT << BRIGHT_GREEN BOLT "wrong meow meow!" << RESEND;

	return;
}
