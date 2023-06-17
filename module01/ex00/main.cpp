#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	Zombie *heap = newZombie("heap zombie");
	heap->announce();
	randomChump("stack zombie");
	delete heap;
}
