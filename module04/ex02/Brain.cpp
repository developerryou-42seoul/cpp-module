#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout<<"Brain Constructor Called"<<std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "brain cell";
}

Brain::Brain(const Brain& obj)
{
	std::cout<<"Brain Copy Constructor Called"<<std::endl;
	(*this) = obj;
}

Brain& Brain::operator=(const Brain& obj)
{
	std::cout<<"Brain Copy Assignment operator Called"<<std::endl;
	if (this != &obj) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout<<"Brain Destructor Called"<<std::endl;
}

std::string Brain::getIdeas(int n) const
{
	return this->ideas[n];
}

void Brain::setIdeas(std::string idea, int n)
{
	this->ideas[n] = idea;
}
