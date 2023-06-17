#include "Harl.hpp"

Harl::Harl(void) 
{
}

Harl::~Harl() 
{
}

void Harl::debug(void)
{
	std::cout<<"[ DEBUG ]"<<std::endl;
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl<<std::endl;
}

void Harl::info(void)
{
	std::cout<<"[ INFO ]"<<std::endl;
	std::cout<<"I cannot believe adding extra bacon costs more money."<<std::endl<<
	"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl<<std::endl;
}

void Harl::warning(void)
{
	std::cout<<"[ WARNING ]"<<std::endl;
	std::cout<<"I think I deserve to have some extra bacon for free."<<std::endl<<
	"I’ve been coming for years whereas you started working here since last month."<<std::endl<<std::endl;
}

void Harl::error(void)
{
	std::cout<<"[ ERROR ]"<<std::endl;
	std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl<<std::endl;
}

void Harl::complain(std::string level) 
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*function[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int index = -1;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			index = i;
			break;
		}
	}
	switch (index)
	{
	case 0:
		(this->*function[0])();
	case 1:
		(this->*function[1])();
	case 2:
		(this->*function[2])();
	case 3:
		(this->*function[3])();
		break;
	default:
		std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
		break;
	}
}