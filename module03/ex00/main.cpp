#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);
	b.attack("A");
	a.takeDamage(12);
	a.beRepaired(12);

	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.beRepaired(9500);
	b.beRepaired(1000);
	b.beRepaired((unsigned int)2147483647 * 2);
	b.attack("A");
	b.attack("A");
	b.attack("A"); // out of energy

	return (0);
}