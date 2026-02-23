/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:39:35 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/25 10:59:05 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
	FT_MSG("Brain() Constructor")
	return;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;

	FT_MSG("Brain(Brain copy) Constructor")
	return;
}

Brain::~Brain()
{
	FT_MSG("~Brain Destructor")
	return;
}

Brain &Brain::operator=(const Brain &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			if (src._ideas[i].length() > 0)
				this->_ideas[i].assign(src._ideas[i]);
	}

	return *this;
}

/* --- --- --- */

void Brain::setIdea(size_t nb, STRING str)
{
	this->_ideas[nb] = str;

	return;
}

STRING Brain::getIdea(size_t nb) const
{
	return this->_ideas[nb];
}
