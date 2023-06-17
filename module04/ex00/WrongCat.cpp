#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout<<"WrongCat Constructor Called"<<std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout<<"WrongCat Destructor Called"<<std::endl;
}

WrongCat::WrongCat(const WrongCat &cat)
{
	std::cout<<"WrongCat Copy Constructor Called"<<std::endl;
	(*this) = cat;
}

WrongCat& WrongCat::operator=(const WrongCat &cat)
{
	std::cout<<"WrongCat Copy Assignment operator Called"<<std::endl;
	if (this != &cat) {
		this->type = cat.type;
	}
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout<<"WrongCat Sounds Meow Meow"<<std::endl;
}
