#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr)
{
	std::cout<<"HumanB ["<<this->_name<<"] created"<<std::endl;
}

HumanB::~HumanB()
{	
	std::cout<<"HumanB ["<<this->_name<<"] destroyed"<<std::endl;
}

void HumanB::attack()
{
	if (this->_weapon != nullptr)
		std::cout<<this->_name<<" attacks with their "<<this->_weapon->getType()<<std::endl;
	else
		std::cout<<this->_name<<" has NO weapon"<<std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
