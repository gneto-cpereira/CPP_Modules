/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:39:35 by gneto-co          #+#    #+#             */
/*   Updated: 2024/10/28 14:01:15 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "default";
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;

	PRINT << BRIGHT_CYAN BOLT << this->_name << " just arrived to battle" << RESEND;

	return;
}

ClapTrap::ClapTrap(STRING name)
{
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;

	PRINT << BRIGHT_CYAN BOLT << this->_name << " just arrived to battle" << RESEND;

	return;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;

	PRINT << BRIGHT_CYAN BOLT << this->_name << " its a copy of someone" << RESEND;

	return;
}

ClapTrap::~ClapTrap()
{
	PRINT << BRIGHT_CYAN BOLT << this->_name << " just retired early" << RESEND;

	return;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
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

void ClapTrap::attack(const std::string &target)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		PRINT << BRIGHT_BLUE << this->_name << " attacked " << target << " (it loses " << this->_attack_damage << " hp)" << RESEND;
		this->_energy_points--;
	}
	else
		OFF_MESSAGE(this->_name);
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		this->_hit_points -= amount;
		if (this->_hit_points < 0)
			this->_hit_points = 0;
		PRINT << RED << this->_name << " has been attacked: -" << amount
			  << " hp (" << this->_hit_points << " hp remain)" << RESEND;
	}
	else
		OFF_MESSAGE(this->_name);
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		this->_hit_points += amount;
		PRINT << GREEN << this->_name << " began repair itself: +" << amount
			  << " hp (" << this->_hit_points << " hp remain)" << RESEND;
		this->_energy_points--;
	}
	else
		OFF_MESSAGE(this->_name);
	return;
}
