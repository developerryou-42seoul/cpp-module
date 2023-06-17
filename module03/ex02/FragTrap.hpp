#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &fragTrap);
	FragTrap& operator=(const FragTrap &fragTrap);
	~FragTrap(void);

	void highFivesGuys(void);
};

#endif
