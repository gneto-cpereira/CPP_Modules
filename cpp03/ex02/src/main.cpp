/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:48:02 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/20 15:02:24 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main(void)
{
	/* ClapTrap tests */
	{
		ClapTrap wall_e("wall-e");
		SPACER(1)

		// tests
		wall_e.beRepaired(1);
		wall_e.attack("bad_guy");
		wall_e.takeDamage(10);
		wall_e.beRepaired(1);

		// kill him
		wall_e.takeDamage(20);

		// tests
		wall_e.takeDamage(2);
		wall_e.beRepaired(1);
		wall_e.attack("bad_guy");
		SPACER(1)
	}

	SPACER(5)

	/* ScavTrap tests */
	{
		ScavTrap R2D2("R2D2");
		SPACER(1)

		// tests
		R2D2.guardGate();
		R2D2.beRepaired(1);
		R2D2.attack("bad_guy");
		R2D2.takeDamage(10);
		R2D2.beRepaired(1);
		R2D2.guardGate();

		// kill him
		R2D2.takeDamage(200);

		// tests
		R2D2.beRepaired(1);
		R2D2.attack("bad_guy");
		R2D2.takeDamage(10);
		R2D2.guardGate();
		SPACER(1)
	}

	SPACER(5)

	/* FragTrap tests */
	{
		FragTrap Iron_Giant("Iron_Giant");
		SPACER(1)

		// tests
		Iron_Giant.highFivesGuys();
		Iron_Giant.beRepaired(1);
		Iron_Giant.attack("bad_guy");
		Iron_Giant.takeDamage(10);
		Iron_Giant.beRepaired(1);

		// kill him
		Iron_Giant.takeDamage(200);

		// tests
		Iron_Giant.beRepaired(1);
		Iron_Giant.attack("bad_guy");
		Iron_Giant.takeDamage(10);
		Iron_Giant.highFivesGuys();
		SPACER(1)
	}

	return 0;
}
