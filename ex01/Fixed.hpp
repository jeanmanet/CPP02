/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:21:18 by jmanet            #+#    #+#             */
/*   Updated: 2023/04/05 15:13:47 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:

	int					_value;
	const static int	_fBits = 8;

public:

	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed& src);
	~Fixed();
	Fixed &	operator=(const Fixed & rhs);
	friend std::ostream& operator<<(std::ostream& out, const Fixed& rhs);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

#endif
