/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:07:42 by jmanet            #+#    #+#             */
/*   Updated: 2023/04/05 18:30:37 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _value(n << _fBits) {
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _value(std::roundf(f * (1 << _fBits))) {
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & src) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(const Fixed & rhs) {
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

Fixed 	Fixed::operator+(const Fixed & rhs) const {
	return (this->toFloat() + rhs.toFloat());
}

Fixed 	Fixed::operator-(const Fixed & rhs) const {
	return (this->toFloat() - rhs.toFloat());
}

Fixed 	Fixed::operator/(const Fixed & rhs) const {
	return (this->toFloat() / rhs.toFloat());
}

Fixed 	Fixed::operator*(const Fixed & rhs) const {
	return (this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator++(int) {
	Fixed temp(this->toFloat());
	this->_value += 1;
	return (temp);
}

Fixed& Fixed::operator++(void) {
	this->_value += 1;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp(this->toFloat());
	this->_value -= 1;
	return (temp);
}

Fixed& Fixed::operator--(void) {
	this->_value -= 1;
	return (*this);
}

bool	Fixed::operator>(const Fixed & rhs) const {
	if (this->_value > rhs._value)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed & rhs) const {
	if (this->_value < rhs._value)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed & rhs) const {
	if (this->_value == rhs._value)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed & rhs) const {
	if (this->_value != rhs._value)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed & rhs) const {
	if (this->_value == rhs._value || this->_value > rhs._value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed & rhs) const {
	if (this->_value == rhs._value || this->_value < rhs._value)
		return (true);
	return (false);
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

Fixed&	Fixed::min(Fixed& a, Fixed&  b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed&  b) {
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed&  b) {
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed&  b) {
	if (a > b)
		return (a);
	return (b);
}
