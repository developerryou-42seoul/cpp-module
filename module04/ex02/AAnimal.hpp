#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {
protected:
	std::string type;
public:
	AAnimal();
	virtual ~AAnimal() = 0;
	AAnimal(const AAnimal &animal);
	AAnimal& operator=(const AAnimal &animal);
	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
};

#endif