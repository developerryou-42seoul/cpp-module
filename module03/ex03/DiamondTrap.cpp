#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : _name(ClapTrap::_name)
{
	std::cout<<"DiamondTrap constructor Called"<<std::endl;
	ClapTrap::_name += "_clap_name";
	ClapTrap::_energy_points = 50;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout<<"DiamondTrap constructor with name Called"<<std::endl;
	ClapTrap::_name += "_clap_name";
	ClapTrap::_energy_points = 50;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
	std::cout<<"DiamondTrap copy constructor Called"<<std::endl;
	(*this) = diamondTrap;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	std::cout<<"DiamondTrap copy assignment operator Called"<<std::endl;
	if (this != &diamondTrap)
	{
		this->_name = diamondTrap._name;
		ClapTrap::operator=(diamondTrap); 
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout<<"DiamondTrap destructor Called"<<std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout<<"DiamondTrap name : "<< this->_name <<std::endl;
	std::cout<<"ClapTrap name : "<<ClapTrap::_name<<std::endl;
}
