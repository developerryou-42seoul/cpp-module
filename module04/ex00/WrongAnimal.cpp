#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout<<"WrongAnimal Constructor Called"<<std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<"WrongAnimal Destructor Called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	std::cout<<"WrongAnimal Copy Constructor Called"<<std::endl;
	(*this) = animal;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &animal)
{
	std::cout<<"WrongAnimal Copy Assignment operator Called"<<std::endl;
	if (this != &animal) {
		this->type = animal.type;
	}
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout<<"WrongAnimal Sounds Anything"<<std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (type);
}
