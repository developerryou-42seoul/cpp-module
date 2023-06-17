#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
protected:
	std::string type;
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal &animal);
	WrongAnimal& operator=(const WrongAnimal &animal);
	void makeSound(void) const;
	std::string getType(void) const;
};

#endif