/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:48:02 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/20 11:28:59 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main(void)
{
	ClapTrap wall_e("wall-e");

	wall_e.beRepaired(1);

	wall_e.attack("bad_guy");

	wall_e.takeDamage(10);

	wall_e.beRepaired(1);
	
	wall_e.takeDamage(2);
	
	wall_e.takeDamage(2);
	wall_e.beRepaired(1);
	wall_e.attack("bad_guy");

	return 0;
}
