#include "Dog.hpp"

Dog::Dog()
{
	std::cout<<"Dog Constructor Called"<<std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout<<"Dog Destructor Called"<<std::endl;
}

Dog::Dog(const Dog &dog)
{
	std::cout<<"Dog Copy Constructor Called"<<std::endl;
	(*this) = dog;
}

Dog& Dog::operator=(const Dog &dog)
{
	std::cout<<"Dog Copy Assignment operator Called"<<std::endl;
	if (this != &dog) {
		this->type = dog.type;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout<<"Dog Sounds Bark Bark"<<std::endl;
}
