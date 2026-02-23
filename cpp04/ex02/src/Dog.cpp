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
	FT_MSG("Dog() Constructor")
	this->_type = "Dog";
	this->_brain = new Brain();

	return;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	FT_MSG("Dog(Dog copy) Constructor")
	*this = copy;

	return;
}

Dog::~Dog()
{
	delete this->_brain;

	FT_MSG("~Dog Destructor")
	return;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain();
		*this->_brain = *src._brain;
	}

	return *this;
}

/* --- --- --- */

void Dog::makeSound(void) const
{
	PRINT << BRIGHT_GREEN BOLT "woof woof!" << RESEND;

	return;
}

/* --- */

void Dog::showIdeas(void) const
{
	for (int i = 0; i < 100; i++)
		if (this->_brain->getIdea(i).length() > 0)
			PRINT << BRIGHT_BLACK << i << " - " << this->_brain->getIdea(i) << std::endl;
}

void Dog::setIdea(size_t i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}
