#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# define MAX_HP 10000UL

class ClapTrap
{
protected:
	std::string _name;
	unsigned int _hit_points;
	unsigned int _energy_points;
	unsigned int _attack_damage;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clapTrap);
	ClapTrap& operator=(const ClapTrap &clapTrap);
	virtual ~ClapTrap(void);

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
