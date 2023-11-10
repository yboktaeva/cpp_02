/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:23:28 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/07 12:22:45 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0) {

    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {

    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {

    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {

    std::cout << "setRawBits member function called" << std::endl;
    _fixedPointValue = raw;
}

Fixed::Fixed(Fixed const& copy) {

    std::cout << "Copy constructor called" << std::endl;
    _fixedPointValue = copy.getRawBits();
}

Fixed& Fixed::operator=(Fixed const& f) {

    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &f)
        return *this;
    this->_fixedPointValue = f.getRawBits();
    
    return *this;
}
