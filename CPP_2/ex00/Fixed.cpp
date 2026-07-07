#include "Fixed.hpp"

Fixed::Fixed() : number(0)
{
	std::cout << "Default constructor called." << std::endl;
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