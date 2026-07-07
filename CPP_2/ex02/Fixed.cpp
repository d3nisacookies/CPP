#include "Fixed.hpp"

Fixed::Fixed() : number(0)
{
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int value) : number(0)
{
	std::cout << "Int constructor called." << std::endl;
	this->number = value << bits;
}

Fixed::Fixed(const float value) : number(0)
{
	std::cout << "Float constructor called." << std::endl;
	this->number = roundf(value * (1 << bits));
}

float Fixed::toFloat(void) const
{
	return ((float)number / (1 << bits));
}

int Fixed::toInt(void) const
{
	return (number >> bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &assn)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &assn)
	{
		setRawBits(assn.getRawBits());
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (number);
}

void Fixed::setRawBits(int const raw)
{
	number = raw;
}

bool Fixed::operator==(const Fixed &assn)
{
	return (this->number == assn.number);
}

bool Fixed::operator!=(const Fixed &assn)
{
	return (this->number != assn.number);
}

bool Fixed::operator>(const Fixed &assn) const
{
	return (this->number > assn.number);
}

bool Fixed::operator>=(const Fixed &assn)
{
	return (this->number >= assn.number);
}

bool Fixed::operator<(const Fixed &assn) const
{
	return (this->number < assn.number);
}

bool Fixed::operator<=(const Fixed &assn)
{
	return (this->number <= assn.number);
}

Fixed Fixed::operator+(const Fixed &assn)
{
	Fixed	result;

	result.setRawBits(this->number + assn.number);
	return (result);
}

Fixed Fixed::operator-(const Fixed &assn)
{
	Fixed	result;

	result.setRawBits(this->number - assn.number);
	return (result);
}

Fixed Fixed::operator*(const Fixed &assn)
{
	Fixed	result;

	result.setRawBits((this->number * assn.number) >> bits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &assn)
{
	Fixed	result;

	result.setRawBits((this->number / assn.number) << bits);
	return (result);
}

Fixed &Fixed::operator++(void)
{
	this->number += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	old;

	old = *this;
	this->number += 1;
	return (old);
}

Fixed &Fixed::operator--(void)
{
	this->number -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	old;

	old = *this;
	this->number -= 1;
	return (old);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}