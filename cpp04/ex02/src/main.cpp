/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:48:02 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/25 14:31:21 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main(void)
{
	/* {
		Animal *penguin = new Animal("penguin");

		penguin->printType();
		penguin->makeSound();

		delete penguin;
	} */

	SPACER(5)
	{
		Dog *dog = new Dog();

		dog->printType();
		dog->makeSound();
		dog->setIdea(0, "Bark");
		dog->setIdea(1, "Bark");
		dog->setIdea(2, "Bark");
		dog->showIdeas();
		delete dog;
	}

	SPACER(5)
	{
		Cat *cat = new Cat();

		cat->printType();
		cat->makeSound();
		cat->setIdea(0, "Sleep");
		cat->setIdea(1, "Eat");
		cat->setIdea(2, "Repeat");
		cat->showIdeas();
		
		SPACER(1)

		Cat *copy_cat = cat;
		copy_cat->printType();
		copy_cat->makeSound();
		copy_cat->showIdeas();

		delete cat;
	}

	SPACER(5)
	{
		size_t nb = 4;
		Animal *zoo[nb];

		for (size_t i = 0; i < nb; i++)
		{
			if (i % 2)
				zoo[i] = new Cat();
			else
				zoo[i] = new Dog();
			zoo[i]->printType();
			zoo[i]->makeSound();
			SPACER(1)
		}

		for (size_t i = 0; i < nb; i++)
		{
			delete zoo[i];
			SPACER(1)
		}
	}

	/*
		SPACER(2)
		{
			WrongAnimal *w_cat = new WrongCat();

			w_cat->printType();
			w_cat->makeSound();
			delete w_cat;
		}
	 */
	return 0;
}
