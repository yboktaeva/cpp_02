/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:56:30 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/07 11:51:57 by yuboktae         ###   ########.fr       */
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
    Fixed(int const a);
    Fixed(float const b);

    float toFloat()const;
    int toInt() const;
    Fixed& operator=(Fixed const& f);
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, Fixed const& ref);

#endif