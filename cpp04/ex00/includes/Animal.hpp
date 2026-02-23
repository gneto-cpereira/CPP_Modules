/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:30:12 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/25 11:27:39 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "Animal.h"

class Animal
{
protected:
	STRING _type;

public:
	Animal();
	Animal(STRING name);
	Animal(const Animal &copy);
	virtual ~Animal();
	Animal &operator=(const Animal &src);

	/* --- --- --- */

	virtual void makeSound() const;
	void printType() const;
	STRING getType() const;
};

#endif