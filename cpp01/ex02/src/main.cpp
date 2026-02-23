/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:48:02 by gneto-co          #+#    #+#             */
/*   Updated: 2024/10/28 14:55:11 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define BOLD "\033[1m"

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout << BOLD "ADDRESSES" RESET << std::endl;
	std::cout << GREEN "String Address: " RESET << &string << std::endl;
	std::cout << GREEN "String Pointer Address: " RESET << stringPTR << std::endl;
	std::cout << GREEN "String Reference Address: " RESET << &stringREF << std::endl;
	
	std::cout << BOLD "VALUES" RESET << std::endl;
	std::cout << GREEN "String Value: " RESET << string << std::endl;
	std::cout << GREEN "String Pointer Value: " RESET << *stringPTR << std::endl;
	std::cout << GREEN "String Reference Value: " RESET << stringREF << std::endl;
	return (0);
}
