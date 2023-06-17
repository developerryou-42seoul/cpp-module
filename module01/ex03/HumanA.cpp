#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon)
{
	std::cout<<"HumanA ["<<this->_name<<"] created"<<std::endl;
}

HumanA::~HumanA()
{	
	std::cout<<"HumanA ["<<this->_name<<"] destroyed"<<std::endl;
}

void HumanA::attack()
{
	std::cout<<this->_name<<" attacks with their "<<this->_weapon->getType()<<std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
