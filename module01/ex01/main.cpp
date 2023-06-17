#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
	Zombie *arr = zombieHorde(5, "array zombie");
	for (int i=0; i<5; i++)
	{
		arr[i].announce();
	}
	delete []arr;
}
