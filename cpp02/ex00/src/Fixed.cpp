/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:39:35 by gneto-co          #+#    #+#             */
/*   Updated: 2024/10/28 14:01:15 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int Fixed::_fract_bits = 8;
static STRING class_name = "Fixed";

Fixed::Fixed() : _fp_value(0)
{
	FT1_ANNOUNCE(class_name, "default constructor")
}

Fixed::Fixed(const Fixed &copy)
{
	FT1_ANNOUNCE(class_name, "copy constructor")
	
	*this = copy;
}

Fixed::~Fixed()
{
	FT1_ANNOUNCE(class_name, "destructor")
}

Fixed &Fixed::operator=(const Fixed &src)
{
	FT1_ANNOUNCE(class_name, "assignation operator")

	if (this != &src)
		this->_fp_value = src.getRawBits();

	return *this;
}

/* functions */

int Fixed::getRawBits(void) const
{
	FT2_ANNOUNCE(class_name, "getRawBits")

	return (this->_fp_value);
}

void Fixed::setRawBits(int const raw)
{
	FT2_ANNOUNCE(class_name, "setRawBits")

	this->_fp_value = raw;
}
