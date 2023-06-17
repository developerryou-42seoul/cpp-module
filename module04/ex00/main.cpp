#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	std::cout << std::endl;

	delete meta;
	meta = NULL;
	delete dog;
	dog = NULL;
	delete cat;
	cat = NULL;
		
	std::cout << std::endl;
	const WrongAnimal* wrong = new WrongCat();
	
	std::cout << std::endl;
	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();

	std::cout << std::endl;
	delete wrong;
	wrong = NULL;

	return 0;
}