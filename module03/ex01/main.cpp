#include "ScavTrap.hpp"

int main(void)
{
	{
		ScavTrap a("A");
		ScavTrap b("B");

		a.attack("B");
		b.takeDamage(20);
		b.beRepaired(20);
		b.attack("A");
		a.takeDamage(100);
		a.beRepaired(120);

		a.guardGate();
		b.guardGate();
	}
	{
		ClapTrap *a = new ScavTrap("A");
		ClapTrap *b = new ScavTrap("B");

		a->attack("B");
		b->takeDamage(20);
		b->beRepaired(20);
		b->attack("A");
		a->takeDamage(100);
		a->beRepaired(120);

		delete a;
		delete b;
	}
	return (0);
}