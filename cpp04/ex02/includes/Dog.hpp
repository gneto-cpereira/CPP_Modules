/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:30:12 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/25 10:54:22 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;
public:
	Dog();
	Dog(const Dog &copy);
	~Dog();
	Dog &operator=(const Dog &src);

	/* --- --- --- */

	void makeSound(void) const;

	/* --- */
	
	void showIdeas(void) const;
	void setIdea(size_t i, std::string idea);
};

#endif