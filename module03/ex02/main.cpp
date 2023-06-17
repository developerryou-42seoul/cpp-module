#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap a("A");
	FragTrap b("B");

	a.attack("B");
	b.takeDamage(30);
	b.beRepaired(20);
	b.attack("A");
	a.takeDamage(100);
	a.beRepaired(120);

	a.highFivesGuys();
	b.highFivesGuys();

	FragTrap c(b);
	c.beRepaired(20);
	b.beRepaired(20);
	return (0);
}