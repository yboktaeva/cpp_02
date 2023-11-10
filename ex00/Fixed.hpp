/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:23:17 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/04 15:59:29 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {

private:
    int _fixedPointValue;
    static const int _numFracBits = 8;

public:
    Fixed();
    ~Fixed();
    Fixed(Fixed const& copy);
    Fixed& operator=(Fixed const& f);
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif