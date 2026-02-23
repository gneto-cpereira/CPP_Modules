/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:30:12 by gneto-co          #+#    #+#             */
/*   Updated: 2024/10/28 14:00:34 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include "Fixed.h"

class Fixed
{
private:
	int _fp_value;
	static const int _fract_bits;

public:
	Fixed();
	Fixed(const Fixed &copy);
	~Fixed();
	Fixed &operator=(const Fixed &src);

	/* ---------- */

	Fixed(const int);
	Fixed(const float);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;z
};

std::ostream &operator<<(std::ostream &output, Fixed const &fixed);

#endif