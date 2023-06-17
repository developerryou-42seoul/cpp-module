#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int _value;
	static const int fractional_bit = 8;
public:
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &fixed);
	Fixed& operator=(const Fixed &fixed);
	~Fixed(void);

	bool operator>(const Fixed &fixed) const ;
	bool operator<(const Fixed &fixed) const ;
	bool operator>=(const Fixed &fixed) const ;
	bool operator<=(const Fixed &fixed) const ;
	bool operator==(const Fixed &fixed) const ;
	bool operator!=(const Fixed &fixed) const ;
	float operator+(const Fixed &fixed) const ;
	float operator-(const Fixed &fixed) const ;
	float operator*(const Fixed &fixed) const ;
	float operator/(const Fixed &fixed) const ;
	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	
	static Fixed& min(Fixed &first, Fixed &second);
	static const Fixed& min(const Fixed &first, const Fixed &second);
	static Fixed& max(Fixed &first, Fixed &second);
	static const Fixed& max(const Fixed &first, const Fixed &second);

	int getRawBits(void) const ;
	void setRawBits(int const raw);
	float toFloat(void) const ;
	int toInt(void) const ;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
