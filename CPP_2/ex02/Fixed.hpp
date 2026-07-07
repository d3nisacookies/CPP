#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int number;
	static const int bits = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &assn);
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);
	bool operator==(const Fixed &assn);
	bool operator!=(const Fixed &assn);
	bool operator>(const Fixed &assn);
	bool operator<(const Fixed &assn);
	bool operator>=(const Fixed &assn);
	bool operator<=(const Fixed &assn);
	Fixed operator+(const Fixed &assn);
	Fixed operator-(const Fixed &assn);
	Fixed operator/(const Fixed &assn);
	Fixed operator*(const Fixed &assn);
	~Fixed();
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif