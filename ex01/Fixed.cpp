/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:07:42 by jmanet            #+#    #+#             */
/*   Updated: 2023/04/05 15:13:53 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _value(n << _fBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _value(std::roundf(f * (1 << _fBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(const Fixed & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

std::ostream & operator<<( std::ostream & out, const Fixed & rhs) {
	out << rhs.toFloat();
	return out;
}

int Fixed::getRawBits( void ) const {
	return (this->_value);
}

void Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

float Fixed::toFloat( void ) const {
	return static_cast<float>(this->getRawBits() )/ (1 << this->_fBits);
}

int Fixed::toInt( void ) const {
	return std::roundf(this->getRawBits() >> this->_fBits);
}

