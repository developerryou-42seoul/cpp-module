#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout<<"ScavTrap constructor Called"<<std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout<<"ScavTrap constructor with name Called"<<std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
	std::cout<<"ScavTrap copy constructor Called"<<std::endl;
	(*this) = scavTrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scavTrap)
{
	std::cout<<"ScavTrap copy assignment operator Called"<<std::endl;
	if (this != &scavTrap)
	{
		this->_name = scavTrap._name;
		this->_hit_points = scavTrap._hit_points;
		this->_energy_points = scavTrap._energy_points;
		this->_attack_damage = scavTrap._attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout<<"ScavTrap destructor Called"<<std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energy_points == 0)
	{
		std::cout<<"ScavTrap "<<this->_name<<" Out of Energy"<<std::endl;
	}
	else if (this->_hit_points == 0)
	{
		std::cout<<"ScavTrap "<<this->_name<<" Out of HP"<<std::endl;
	}
	else
	{
		std::cout<<"ScavTrap "<< this->_name<< " attacks "<<target
		<<" , causing "<<this->_attack_damage<<" points of damage!"<<std::endl;
		this->_energy_points--;
	}
}

void ScavTrap::guardGate(void)
{
	if (this->_energy_points == 0)
	{
		std::cout<<"ScavTrap "<<this->_name<<" Out of Energy"<<std::endl;
	}
	else if (this->_hit_points == 0)
	{
		std::cout<<"ScavTrap "<<this->_name<<" Out of HP"<<std::endl;
	}
	else
	{
		std::cout<<"ScavTrap "<< this->_name<< " is now in Gate keeper mode"<<std::endl;
		this->_energy_points--;
	}
}
