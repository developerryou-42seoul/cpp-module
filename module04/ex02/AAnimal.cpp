#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout<<"AAnimal Constructor Called"<<std::endl;
}

AAnimal::~AAnimal()
{
	std::cout<<"AAnimal Destructor Called"<<std::endl;
}

AAnimal::AAnimal(const AAnimal &animal)
{
	std::cout<<"AAnimal Copy Constructor Called"<<std::endl;
	(*this) = animal;
}

AAnimal& AAnimal::operator=(const AAnimal &animal)
{
	std::cout<<"AAnimal Copy Assignment operator Called"<<std::endl;
	if (this != &animal) {
		this->type = animal.type;
	}
	return (*this);
}

void AAnimal::makeSound(void) const
{
	std::cout<<"AAnimal Sounds Anything"<<std::endl;
}

std::string AAnimal::getType(void) const
{
	return (type);
}
