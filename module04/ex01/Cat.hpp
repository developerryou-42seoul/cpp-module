#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
private:
	Brain *brain;
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat &cat);
	Cat& operator=(const Cat &cat);
	virtual void makeSound(void) const;
	Brain *getBrain(void) const;
	std::string getIdeas(int n) const;
	void setIdeas(std::string idea, int n);
};

#endif