#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("undefined"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout<<"ClapTrap constructor Called"<<std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout<<"ClapTrap constructor with name Called"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout<<"ClapTrap copy constructor Called"<<std::endl;
	(*this) = clapTrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &clapTrap)
{
	std::cout<<"ClapTrap copy assignment operator Called"<<std::endl;
	if (this != &clapTrap)
	{
		this->_name = clapTrap._name;
		this->_hit_points = clapTrap._hit_points;
		this->_energy_points = clapTrap._energy_points;
		this->_attack_damage = clapTrap._attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout<<"ClapTrap destructor Called"<<std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points == 0)
	{
		std::cout<<"ClapTrap "<<this->_name<<" Out of Energy"<<std::endl;
	}
	else if (this->_hit_points == 0)
	{
		std::cout<<"ClapTrap "<<this->_name<<" Out of HP"<<std::endl;
	}
	else
	{
		std::cout<<"ClapTrap "<< this->_name<< " attacks "<<target
		<<", causing "<<this->_attack_damage<<" points of damage!"<<std::endl;
		this->_energy_points--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int damagedHP = 0;
	if (this->_hit_points > amount)
		damagedHP = this->_hit_points - amount;
	std::cout<<"ClapTrap "<< this->_name<< " is damaged "
	<<", HP changed "<<this->_hit_points<<" to "<<damagedHP<<std::endl;
	if (damagedHP == 0)
		std::cout<<"ClapTrap "<< this->_name<< " is stopped"<<std::endl;
	this->_hit_points = damagedHP;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points == 0)
	{
		std::cout<<"ClapTrap "<<this->_name<<" Out of Energy"<<std::endl;
	}
	else if (this->_hit_points == 0)
	{
		std::cout<<"ClapTrap "<<this->_name<<" Out of HP"<<std::endl;
	}
	else
	{
		int repairedHP = std::min((unsigned long)this->_hit_points + amount, MAX_HP);
		std::cout<<"ClapTrap "<< this->_name<< " is repaired "
		<<", HP changed "<<this->_hit_points<<" to "<<repairedHP<<std::endl;
		this->_hit_points = repairedHP;
		this->_energy_points--;
	}
}
