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
	FT_MSG("Cat() Constructor")
	this->_type = "Cat";
	this->_brain = new Brain();

	return;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	FT_MSG("Cat(Cat copy) Constructor")
	*this = copy;

	return;
}

Cat::~Cat()
{
	delete this->_brain;

	FT_MSG("~Cat Destructor")
	return;
}

Cat &Cat::operator=(const Cat &src)
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

void Cat::makeSound(void) const
{
	PRINT << BRIGHT_GREEN BOLT "meow meow!" << RESEND;

	return;
}

/* --- */

void Cat::showIdeas(void) const
{
	for (int i = 0; i < 100; i++)
		if (this->_brain->getIdea(i).length() > 0)
			PRINT << BRIGHT_BLACK << i << " - " << this->_brain->getIdea(i) << std::endl;
}

void Cat::setIdea(size_t i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}
