/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:30:12 by gneto-co          #+#    #+#             */
/*   Updated: 2024/10/28 14:00:34 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool _on_gate;

public:
	ScavTrap();
	ScavTrap(STRING name);
	ScavTrap(const ScavTrap &copy);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &src);

	/* --- --- --- */

	void attack(const std::string &target);
	void guardGate();
};

#endif