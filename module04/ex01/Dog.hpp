#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
private:
	Brain *brain;
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog &dog);
	Dog& operator=(const Dog &dog);
	virtual void makeSound(void) const;
	Brain *getBrain(void) const;
	std::string getIdeas(int n) const;
	void setIdeas(std::string idea, int n);
};

#endif