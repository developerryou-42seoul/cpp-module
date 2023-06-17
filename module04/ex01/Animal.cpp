#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout<<"Animal Constructor Called"<<std::endl;
}

Animal::~Animal()
{
	std::cout<<"Animal Destructor Called"<<std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout<<"Animal Copy Constructor Called"<<std::endl;
	(*this) = animal;
}

Animal& Animal::operator=(const Animal &animal)
{
	std::cout<<"Animal Copy Assignment operator Called"<<std::endl;
	if (this != &animal) {
		this->type = animal.type;
	}
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout<<"Animal Sounds Anything"<<std::endl;
}

std::string Animal::getType(void) const
{
	return (type);
}
