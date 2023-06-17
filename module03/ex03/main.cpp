#include "DiamondTrap.hpp"

int main(void)
{
	{
		DiamondTrap a("A");
		DiamondTrap b("B");

		a.attack("B");
		b.takeDamage(30);
		b.beRepaired(20);
		b.attack("A");
		a.takeDamage(100);
		a.beRepaired(120);

		a.guardGate();
		b.guardGate();
		a.highFivesGuys();
		b.highFivesGuys();
		a.whoAmI();
		b.whoAmI();

		DiamondTrap c(b);
		c.whoAmI();
		c.attack("A");
		c.beRepaired(20);
		b.beRepaired(20);
	}
	{
		ClapTrap *a = new DiamondTrap("A");
		a->attack("A");
		a->takeDamage(50);
		a->beRepaired(30);
		delete a;
	}
	
	return (0);
}