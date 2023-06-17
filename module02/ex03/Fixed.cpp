#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	//std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int value)
{
	//std::cout<<"Int constructor called"<<std::endl;
	this->_value = value << this->fractional_bit;
}

Fixed::Fixed(const float value)
{
	//std::cout<<"Float constructor called"<<std::endl;
	this->_value = roundf(value * (1 << this->fractional_bit));
}

Fixed::Fixed(const Fixed &fixed)
{
	//std::cout<<"Copy constructor called"<<std::endl;
	(*this) = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	//std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	//std::cout<<"Destructor called"<<std::endl;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}
bool Fixed::operator<(const Fixed &fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}
bool Fixed::operator>=(const Fixed &fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}
bool Fixed::operator<=(const Fixed &fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}
bool Fixed::operator==(const Fixed &fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}
bool Fixed::operator!=(const Fixed &fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}
float Fixed::operator+(const Fixed &fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}
float Fixed::operator-(const Fixed &fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}
float Fixed::operator*(const Fixed &fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}
float Fixed::operator/(const Fixed &fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}
Fixed Fixed::operator++()
{
	this->_value++;
	return (*this);
}
Fixed Fixed::operator--()
{
	this->_value--;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->_value++;
	return (tmp);
}
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_value++;
	return (tmp);
}

Fixed& Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed& Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}


int Fixed::toInt(void) const
{
	return (this->_value >> this->fractional_bit);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->fractional_bit));
}

int Fixed::getRawBits(void) const
{
	//std::cout<<"getRawBits member function called"<<std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	//std::cout<<"setRawBits member function called"<<std::endl;
	this->_value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out<<fixed.toFloat();
	return (out);
}
