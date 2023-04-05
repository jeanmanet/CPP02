/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:21:18 by jmanet            #+#    #+#             */
/*   Updated: 2023/04/05 11:10:34 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:

	int					_value;
	const static int	_fBits = 8;

public:

	Fixed();
	Fixed(Fixed& src);
	~Fixed();
	Fixed &	operator=(const Fixed & rhs);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};



#endif
