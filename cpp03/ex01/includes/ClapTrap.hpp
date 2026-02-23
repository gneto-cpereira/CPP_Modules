/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:30:12 by gneto-co          #+#    #+#             */
/*   Updated: 2024/10/28 14:00:34 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include "ClapTrap.h"

class ClapTrap
{
protected:
	STRING _name;
	int _hit_points;
	int _energy_points;
	int _attack_damage;

public:
	ClapTrap();
	ClapTrap(STRING name);
	ClapTrap(const ClapTrap &copy);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &src);

	/* --- --- --- */

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif