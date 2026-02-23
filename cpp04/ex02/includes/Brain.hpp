/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:30:12 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/25 11:27:39 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "Animal.h"

class Brain
{
private:
	STRING _ideas[100];

public:
	Brain();
	Brain(const Brain &copy);
	~Brain();
	Brain &operator=(const Brain &src);

	/* --- --- --- */

	void setIdea(size_t number, STRING idea);
	STRING getIdea(size_t number) const;
};

#endif