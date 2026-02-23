/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:48:02 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/01 13:36:50 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main()
{
	Harl harl = Harl();
	harl.complain("DEBUG");
	putchar('\n');
	harl.complain("INFO");
	putchar('\n');
	harl.complain("WARNING");
	putchar('\n');
	harl.complain("ERROR");
	putchar('\n');
	harl.complain("xxxx invalid xxxx");
	putchar('\n');
	return 0;
}
