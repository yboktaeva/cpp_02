/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:01:18 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/06 18:43:52 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed {

private:
    int _fixedPointValue;
    static const int _numFracBits = 8;

public:
    Fixed();
    ~Fixed();
    Fixed(Fixed const& copy);
    Fixed(int a);
    Fixed(float b);

    float toFloat()const;
    int toInt() const;
    Fixed& operator=(Fixed const& f);
    
    bool operator>(Fixed const& f);
    bool operator<(Fixed const& f);
    bool operator>=(Fixed const& f);
    bool operator<=(Fixed const& f);
    bool operator==(Fixed const& f);
    bool operator!=(Fixed const& f);
    
    Fixed operator+(Fixed const& f) const;
    Fixed operator-(Fixed const& f) const;
    Fixed operator*(Fixed const& f) const;
    Fixed operator/(Fixed const& f) const;
    
    Fixed& operator++();
    Fixed& operator--();
    
    Fixed operator++(int);
    Fixed operator--(int);
    
    static Fixed& min(Fixed& a, Fixed& b);
    static Fixed& min(Fixed const& a, Fixed const& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static Fixed& max(Fixed const& a, Fixed const& b);
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, Fixed const& ref);

#endif