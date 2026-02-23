/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:36:25 by gneto-co          #+#    #+#             */
/*   Updated: 2024/10/28 13:47:34 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombie_horde;

	zombie_horde = new Zombie[N];
    
	for (int i = 0; i < N; i++)
		zombie_horde[i].setName(name);
        
	return (zombie_horde);
}
