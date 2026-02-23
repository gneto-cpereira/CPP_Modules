/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:39:35 by gneto-co          #+#    #+#             */
/*   Updated: 2024/10/28 14:01:15 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name = "default";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_on_gate = false;

	PRINT << BRIGHT_CYAN BOLT << this->_name << " identifies as ScavTrap" << RESEND;

	return;
}

ScavTrap::ScavTrap(STRING name) : ClapTrap(name)
{
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_on_gate = false;

	PRINT << BRIGHT_CYAN BOLT << this->_name << " identifies as ScavTrap" << RESEND;

	return;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	*this = copy;

	PRINT << BRIGHT_CYAN BOLT << this->_name << " its a copy of someone" << RESEND;

	return;
}

ScavTrap::~ScavTrap()
{
	PRINT << BRIGHT_CYAN BOLT << this->_name << " no longer identifies as ScavTrap" << RESEND;

	return;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
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

void ScavTrap::attack(const std::string &target)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		PRINT << BRIGHT_BLUE << this->_name << " attacked really hard " << target << " (it loses " << this->_attack_damage << " hp)" << RESEND;
		this->_energy_points--;
	}
	else
		OFF_MESSAGE(this->_name);
	return;
}

void ScavTrap::guardGate()
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		if (this->_on_gate == false)
		{
			PRINT << BRIGHT_YELLOW << this->_name << " is now guarding the gate" << RESEND;
			this->_on_gate = true;
		}
		else
			PRINT << BRIGHT_YELLOW << this->_name << " is already on the gate" << RESEND;
	}
	else
		OFF_MESSAGE(this->_name);
	return;
}
