#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout<<"FragTrap constructor Called"<<std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout<<"FragTrap constructor with name Called"<<std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
	std::cout<<"FragTrap copy constructor Called"<<std::endl;
	(*this) = fragTrap;
}

FragTrap& FragTrap::operator=(const FragTrap &fragTrap)
{
	std::cout<<"FragTrap copy assignment operator Called"<<std::endl;
	if (this != &fragTrap)
	{
		this->_name = fragTrap._name;
		this->_hit_points = fragTrap._hit_points;
		this->_energy_points = fragTrap._energy_points;
		this->_attack_damage = fragTrap._attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout<<"FragTrap destructor Called"<<std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_energy_points == 0)
	{
		std::cout<<"FragTrap "<<this->_name<<" Out of Energy"<<std::endl;
	}
	else if (this->_hit_points == 0)
	{
		std::cout<<"FragTrap "<<this->_name<<" Out of HP"<<std::endl;
	}
	else
	{
		std::cout<<"FragTrap "<< this->_name<< " highFives"<<std::endl;
		this->_energy_points--;
	}
}
