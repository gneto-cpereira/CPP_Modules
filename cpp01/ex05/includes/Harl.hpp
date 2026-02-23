/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:30:12 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/01 13:32:15 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"

class Harl
{
private:
	void debug(void) const;
	void info(void) const;
	void warning(void) const;
	void error(void) const;

public:
	Harl();
	~Harl();
	void complain(std::string level) const;
};
typedef void (Harl::*function_p)(void) const;

#endif