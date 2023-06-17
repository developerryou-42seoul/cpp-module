#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	{
		// Test default brain
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout<<std::endl;
		delete dog;
		delete cat;
		std::cout<<std::endl;
		system("leaks brain");
		std::cout<<std::endl;
	}

	{
		// Test deep copy
		Dog dog;
		Cat cat;

		std::cout<<std::endl<<"Copies"<<std::endl;
		Dog dog_copy(dog);
		Cat cat_copy(cat);
		dog_copy.setIdeas("Dog Copy", 0);
		cat_copy.setIdeas("Cat Copy", 0);
		dog_copy.setIdeas("Dog Copy", 1);
		cat_copy.setIdeas("Cat Copy", 1);

		std::cout<<std::endl<<"Compare"<<std::endl;
		std::cout<<"Dog\t\tDog Copy\tCat\t\tCat Copy"<<std::endl;
		for (int i = 0; i < 4; i++)
		{
			std::cout<<dog.getIdeas(i)<<"\t"<<dog_copy.getIdeas(i)<<"\t"
			<<cat.getIdeas(i)<<"\t"<<cat_copy.getIdeas(i)<<std::endl;
		}
		std::cout<<std::endl;
		system("leaks brain");
		std::cout<<std::endl;
	}

	{
		// Test array of animals
		const Animal* arr[4];

		std::cout<<std::endl;
		for (int i = 0; i < 2; i++)
			arr[i] = new Dog();
		std::cout<<std::endl;
		for (int i = 2; i < 4; i++)
			arr[i] = new Cat();
		std::cout<<std::endl;

		for (int i = 0; i < 4; i++)
		{
			arr[i]->makeSound();
		}
		for (int i = 0; i < 4; i++)
			delete arr[i];
		std::cout<<std::endl;

		std::cout<<std::endl;
		system("leaks brain");
		std::cout<<std::endl;
	}
	return 0;
}