#include "Cat.hpp"

Cat::Cat()
{
	std::cout<<"Cat Constructor Called"<<std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout<<"Cat Destructor Called"<<std::endl;
	delete this->brain;
}

Cat::Cat(const Cat &cat)
{
	std::cout<<"Cat Copy Constructor Called"<<std::endl;
	this->type = cat.type;
	this->brain = new Brain(*(cat.getBrain()));
}

Cat& Cat::operator=(const Cat &cat)
{
	std::cout<<"Cat Copy Assignment operator Called"<<std::endl;
	if (this != &cat) {
		this->type = cat.type;
		if (this->brain)
			delete (this->brain);
		this->brain = new Brain(*(cat.getBrain()));
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout<<"Cat Sounds Meow Meow"<<std::endl;
}

Brain* Cat::getBrain(void) const
{
	return (brain);
}

std::string Cat::getIdeas(int n) const
{
	return (brain->getIdeas(n));
}

void Cat::setIdeas(std::string idea, int n)
{
	brain->setIdeas(idea, n);
}
