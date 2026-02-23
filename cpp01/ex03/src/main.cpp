/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:48:02 by gneto-co          #+#    #+#             */
/*   Updated: 2024/10/28 16:18:04 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

/*
int main(void)
{
	Weapon sword = Weapon("Sword");
	HumanA Micaela("Micaela", sword);
	Micaela.attack();
	sword.setType("Wrap");
	Micaela.attack();

	Weapon biggerSword = Weapon("Bigger Sword");
	HumanB Eva("Eva");
	Eva.setWeapon(biggerSword);
	Eva.attack();
	biggerSword.setType("Another Wrap");
	Eva.attack();

	return (0);
} */

int main()
{
	{
		Weapon sword = Weapon("Sword");
		HumanA Micaela("Micaela", sword);
		Micaela.attack();
		sword.setType("Wrap");
		Micaela.attack();

		Weapon biggerSword = Weapon("Bigger Sword");
		HumanB Eva("Eva");
		Eva.attack();
		Eva.setWeapon(biggerSword);
		Eva.attack();
		biggerSword.setType("Another Wrap");
		Eva.attack();
	}
	std::cout << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
