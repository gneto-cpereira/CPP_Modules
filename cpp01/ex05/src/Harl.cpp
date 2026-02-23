/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:39:35 by gneto-co          #+#    #+#             */
/*   Updated: 2024/10/28 16:11:30 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl()
{
	return;
}

Harl::~Harl()
{
	return;
}

void Harl::complain(std::string level) const
{
	const function_p complains[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string complains_str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		// std::cout << complains_str[i] << "==" << level << std::endl;
		if (complains_str[i] == level)
		{

			(this->*(complains[i]))();
			return;
		}
	}
	std::cout << "[INVALID] *invalid complaint*" << std::endl;
}

void Harl::debug(void) const
{
	std::cout << "[DEBUG] bla bla bla" << std::endl;
}

void Harl::info(void) const
{
	std::cout << "[INFO] bla bla bla, bla bla bla, bla bla bla bla bla" << std::endl;
}

void Harl::warning(void) const
{
	std::cout << "[WARNING] *grumble*" << std::endl;
}

void Harl::error(void) const
{
	std::cout << "[ERROR] *shouting nonsense at everyone*" << std::endl;
}
