#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
private:
	std::string ideas[100];
public:
	Brain(void);
	Brain(const Brain& obj);
	Brain& operator=(const Brain& obj);
	~Brain(void);
	std::string getIdeas(int n) const;
	void setIdeas(std::string idea, int n);
};

#endif