/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:48:02 by gneto-co          #+#    #+#             */
/*   Updated: 2024/10/28 14:07:09 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void)
{
	/* 	stack zombies (no manually allocate memory) */
	std::cout << std::endl << RED "The stackZombies are coming" RESET << std::endl;
	
	Zombie zombie1("Floribela");
	zombie1.announce();

	Zombie zombie3;
	zombie3.announce();

	randomChump("Maria do Carmo");


	/* stack zombies (no manually allocate memory) */

	std::cout << std::endl << RED "The heapZombies are coming" RESET << std::endl;
	Zombie *heapZ;

	heapZ = newZombie("André");
	heapZ->announce();


	/* kill zombies */
	
	std::cout << std::endl << BLUE "Someone started planting sunflowers and peashooters" RESET << std::endl;
	delete (heapZ);

	return (0);
}