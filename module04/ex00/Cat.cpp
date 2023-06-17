#include "Cat.hpp"

Cat::Cat()
{
	std::cout<<"Cat Constructor Called"<<std::endl;
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout<<"Cat Destructor Called"<<std::endl;
}

Cat::Cat(const Cat &cat)
{
	std::cout<<"Cat Copy Constructor Called"<<std::endl;
	(*this) = cat;
}

Cat& Cat::operator=(const Cat &cat)
{
	std::cout<<"Cat Copy Assignment operator Called"<<std::endl;
	if (this != &cat) {
		this->type = cat.type;
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout<<"Cat Sounds Meow Meow"<<std::endl;
}
