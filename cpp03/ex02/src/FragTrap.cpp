/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:39:35 by gneto-co          #+#    #+#             */
/*   Updated: 2024/10/28 14:01:15 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_name = "default";
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;

	PRINT << BRIGHT_CYAN BOLT << this->_name << " identifies as FragTrap" << RESEND;

	return;
}

FragTrap::FragTrap(STRING name) : ClapTrap(name)
{
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;

	PRINT << BRIGHT_CYAN BOLT << this->_name << " identifies as FragTrap" << RESEND;

	return;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	*this = copy;

	PRINT << BRIGHT_CYAN BOLT << this->_name << " its a copy of someone" << RESEND;

	return;
}

FragTrap::~FragTrap()
{
	PRINT << BRIGHT_CYAN BOLT << this->_name << " no longer identifies as FragTrap" << RESEND;

	return;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hit_points = src._hit_points;
		this->_energy_points = src._energy_points;
		this->_attack_damage = src._attack_damage;
	}

	return *this;
}

/* --- --- --- */

void FragTrap::highFivesGuys()
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		PRINT << ORANGE << this->_name << " ask for an high five" << RESEND;
	}
	else
		OFF_MESSAGE(this->_name);
	return;
}
