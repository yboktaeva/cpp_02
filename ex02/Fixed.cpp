/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:02:09 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/07 12:41:31 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0) {

    //std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {

    //std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const& copy) {

    //std::cout << "Copy constructor called" << std::endl;
    _fixedPointValue = copy.getRawBits();
}

Fixed& Fixed::operator=(Fixed const& f) {

    //std::cout << "Copy assignment operator called" << std::endl;
    if (this == &f)
        return *this;
    this->_fixedPointValue = f.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {

    //std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {

    _fixedPointValue = raw;
}

Fixed::Fixed(int const a) {

    //std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = a << _numFracBits;
}

Fixed::Fixed(float const b) {

    //std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(b * (1 << _numFracBits));
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

bool Fixed::operator>(Fixed const& f) {
    
    return this->_fixedPointValue > f._fixedPointValue;
}

bool Fixed::operator<(Fixed const& f) {
    
    return this->_fixedPointValue < f._fixedPointValue;
}

bool Fixed::operator>=(Fixed const& f) {
    
    return this->_fixedPointValue >= f._fixedPointValue;
}

bool Fixed::operator<=(Fixed const& f) {
    
    return this->_fixedPointValue <= f._fixedPointValue;
}

bool Fixed::operator==(Fixed const& f) {
    
    return this->_fixedPointValue == f._fixedPointValue;
}

bool Fixed::operator!=(Fixed const& f) {
    
    return this->_fixedPointValue != f._fixedPointValue;
}

Fixed Fixed::operator+(Fixed const& f) const {
    
    int resRawBits = this->_fixedPointValue + f._fixedPointValue;
    Fixed ret;
    ret.setRawBits(resRawBits);
    return ret;
}

Fixed Fixed::operator-(Fixed const& f) const {
    
    Fixed ret;
    ret._fixedPointValue = this->_fixedPointValue - f._fixedPointValue;
    return ret;
}

Fixed Fixed::operator*(Fixed const& f) const {
    
   return Fixed(this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/(Fixed const& f) const {
    
    if (f.toFloat() == 0.0f)
        return Fixed();
    return Fixed(this->toFloat() / f.toFloat());
}

Fixed& Fixed::operator++() {

    this->_fixedPointValue++;
    return *this;
}

Fixed& Fixed::operator--() {

    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator++(int) {

    Fixed tmp(*this);
    ++(*this);
    return tmp;
}

Fixed Fixed::operator--(int) {

    Fixed tmp(*this);
    --(*this);
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    
    return a < b ? a : b;
}

Fixed& Fixed::min(Fixed const& a, Fixed const& b) {
    
    return (Fixed&)a < (Fixed&)b ? (Fixed&)a : (Fixed&)b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    
    return a > b ? a : b;
}

Fixed& Fixed::max(Fixed const& a, Fixed const& b) {
    
    return (Fixed&)a > (Fixed&)b ? (Fixed&)a : (Fixed&)b;
}
