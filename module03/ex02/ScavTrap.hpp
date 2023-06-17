#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &clapTrap);
	ScavTrap& operator=(const ScavTrap &clapTrap);
	~ScavTrap(void);

	void attack(const std::string& target);
	void guardGate(void);
};

#endif
