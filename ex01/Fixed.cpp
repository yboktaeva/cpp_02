/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:56:41 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/07 12:40:31 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0) {

    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {

    std::cout << "Destructor called" << std::endl;
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

int Fixed::getRawBits(void) const {

    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {

    _fixedPointValue = raw;
}

Fixed::Fixed(int const a) {

    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = a << _numFracBits;
}

Fixed::Fixed(float const b) {

    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(b * (1 << _numFracBits));
}

float Fixed::toFloat() const {

    return (float)_fixedPointValue / (1 << _numFracBits);
}

int Fixed::toInt() const {

    return _fixedPointValue >> _numFracBits;
}

std::ostream& operator<<(std::ostream& out, Fixed const& ref) {

    out << ref.toFloat();
    return out;
}