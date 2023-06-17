#include "Dog.hpp"

Dog::Dog()
{
	std::cout<<"Dog Constructor Called"<<std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout<<"Dog Destructor Called"<<std::endl;
	delete this->brain;
}

Dog::Dog(const Dog &dog)
{
	std::cout<<"Dog Copy Constructor Called"<<std::endl;
	this->type = dog.type;
	this->brain = new Brain(*(dog.getBrain()));
}

Dog& Dog::operator=(const Dog &dog)
{
	std::cout<<"Dog Copy Assignment operator Called"<<std::endl;
	if (this != &dog) {
		this->type = dog.type;
		if (this->brain)
			delete (this->brain);
		this->brain = new Brain(*(dog.getBrain()));
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout<<"Dog Sounds Bark Bark"<<std::endl;
}

Brain* Dog::getBrain(void) const
{
	return (brain);
}

std::string Dog::getIdeas(int n) const
{
	return (brain->getIdeas(n));
}

void Dog::setIdeas(std::string idea, int n)
{
	brain->setIdeas(idea, n);
}
