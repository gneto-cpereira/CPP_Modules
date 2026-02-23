/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:48:02 by gneto-co          #+#    #+#             */
/*   Updated: 2024/10/28 14:00:09 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void)
{
	int		z_amount;
	Zombie	*zombie_horde;

	// create and announce zombies
	std::cout << std::endl << RED "The zombies are coming" RESET << std::endl;
	z_amount = 5;
	zombie_horde = zombieHorde(z_amount, "bad_zombie");
	for (int i = 0; i < z_amount; i++)
		zombie_horde[i].announce();

	// kill zombies
	std::cout << std::endl << BLUE "Someone started planting sunflowers and peashooters" RESET << std::endl;
	delete[] zombie_horde;
		
	return (0);
}
