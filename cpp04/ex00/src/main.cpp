/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:48:02 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/25 11:40:12 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main(void)
{
	{
		Animal *penguin = new Animal("penguin");

		penguin->printType();
		penguin->makeSound();

		delete penguin;
	}

	SPACER(2)
	{
		Animal *dog = new Dog();

		dog->printType();
		dog->makeSound();
		delete dog;
	}

	SPACER(2)
	{
		Animal *cat = new Cat();

		cat->printType();
		cat->makeSound();
		delete cat;
	}

	SPACER(2)
	{
		WrongAnimal *w_cat = new WrongCat();

		w_cat->printType();
		w_cat->makeSound();
		delete w_cat;
	}

	return 0;
}
