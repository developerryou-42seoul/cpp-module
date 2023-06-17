#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	//const AAnimal* meta = new AAnimal(); // Can not compiled
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	std::cout << std::endl;
	//std::cout << meta->getType() << " " << std::endl;
	//meta->makeSound();
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	std::cout << std::endl;

	//delete meta;
	//meta = NULL;
	delete dog;
	dog = NULL;
	delete cat;
	cat = NULL;
		
	return 0;
}