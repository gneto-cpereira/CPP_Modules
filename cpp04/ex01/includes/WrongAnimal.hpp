/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:30:12 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/25 11:35:19 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP
#include "Animal.h"

class WrongAnimal
{
protected:
	STRING _type;

public:
	WrongAnimal();
	WrongAnimal(STRING name);
	WrongAnimal(const WrongAnimal &copy);
	virtual ~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &src);

	/* --- --- --- */

	void makeSound() const;
	void printType() const;
	STRING getType() const;
};

#endif