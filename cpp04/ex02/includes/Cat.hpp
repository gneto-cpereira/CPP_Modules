/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:30:12 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/25 10:54:22 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;

public:
	Cat();
	Cat(const Cat &copy);
	~Cat();
	Cat &operator=(const Cat &src);

	/* --- --- --- */

	void makeSound(void) const;

	/* --- */
	
	void showIdeas(void) const;
	void setIdea(size_t i, std::string idea);
};

#endif